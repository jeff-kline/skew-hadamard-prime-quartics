#!/bin/sh
# Run every certificate and write its output to the directory given as $1.
# Environment: CC (C compiler), CXX (C++17 compiler), GP (PARI/GP).
# About twenty seconds on one core, most of it in matrices.cpp.
set -eu
out=${1:?output directory}
CC=${CC:-cc}
CXX=${CXX:-c++}
GP=${GP:-gp}
mkdir -p "$out/bin"
"$CC" -O2 -o "$out/bin/four-orders" code/four-orders.c
"$CXX" -std=c++17 -O3 -o "$out/bin/matrices" code/matrices.cpp
"$CXX" -std=c++17 -O2 -o "$out/bin/ratio-scan" code/ratio-scan.cpp
"$CXX" -std=c++17 -O2 -o "$out/bin/ratio-templates" code/ratio-templates.cpp
if command -v shasum >/dev/null 2>&1; then sha256() { shasum -a 256; }; else sha256() { sha256sum; }; fi

# 1. Difference counts for the four orders, with a failing control.
"$out/bin/four-orders" > "$out/four-orders.txt"

# 2. The four completed matrices: diagonal, skewness and every row pair;
#    then a SHA-256 fingerprint of each emitted sign matrix.
"$out/bin/matrices" > "$out/matrices.txt" 2>&1
for n in 4040 5192 5960 6216; do
  printf '%s %s\n' "$n" "$("$out/bin/matrices" --emit "$n" 2>/dev/null | sha256 | cut -d' ' -f1)"
done > "$out/matrix-hashes.txt"

# 3. Theorem 4: the binomial test for every eligible prime below 250000.
"$out/bin/ratio-scan" 250000 > "$out/ratio-scan.txt" 2> "$out/ratio-scan-count.txt"

# 4. Theorem 4, independently: difference counts in the sixteen shift classes
#    for every prime the scan selects.
"$out/bin/ratio-templates" < "$out/ratio-scan.txt" > "$out/ratio-witnesses.txt"

# 5. Theorem 4 proof: polynomial identities and resultants.
"$GP" -q code/template-identities.gp < /dev/null > "$out/template-identities.txt"

# 6. Theorem 5 and the counting section: quartic-form enumeration and estimates.
"$GP" -q code/quartic-counts.gp < /dev/null > "$out/quartic-counts.txt"
