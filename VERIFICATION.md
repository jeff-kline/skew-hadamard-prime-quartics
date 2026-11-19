# Verification record

## Environment of the pinned run (2026-11-18)

- macOS 26.6.2, x86_64, one core, run under `nice`.
- Apple clang 21.0.0, used as `cc -O2` and `c++ -std=c++17 -O3`.
- PARI/GP 2.17.4, from MacPorts, run with `-q -f` so that no user `.gprc` applies.
- pdfTeX 3.141592653-2.6-1.40.22 (TeX Live 2021).

The programs need no network and no precomputed tables. Their SHA-256 hashes
are in [MANIFEST.sha256](MANIFEST.sha256).

## Commands

```sh
make verify CC=cc CXX=c++ GP=gp
make paper
```

`make verify` runs [code/run-certificates.sh](code/run-certificates.sh). It
writes eight outputs to `build/certificates/` and compares each byte for byte
with its pinned copy in [evidence/](evidence/), printing one `MATCH` line per
file. It fails on any mismatch, or if the number of outputs differs. The total
running time is about thirty seconds, most of it in `matrices.cpp`.

## What each certificate checks

| Paper step | Program | Pinned output |
|---|---|---|
| Theorem 2: for each of the four primes, the primitive root, the set sizes, which sets are skew, and exactly $p-3$ ordered differences at every nonzero residue; a control with one altered mask fails | `four-orders.c` (direct enumeration) | `four-orders.txt` |
| Theorem 2: the four completed matrices; diagonal $+1$, opposite entries negatives, Hamming distance $N/2$ for all 58,708,656 row pairs | `matrices.cpp` | `matrices.txt` |
| SHA-256 of each emitted sign matrix (one line per row, `+` or `-`, border first) | `matrices.cpp --emit N` | `matrix-hashes.txt` |
| Theorem 3: the binomial ratio and the four polynomials for every prime $p\equiv17\pmod{32}$ below 250000 | `ratio-scan.cpp` | `ratio-scan.txt`, `ratio-scan-count.txt` |
| Theorem 3, independently: for each selected prime, difference counts $p-3$ in all sixteen shift classes, for some relabeling | `ratio-templates.cpp` | `ratio-witnesses.txt` |
| Theorem 3 proof: the fixed-quartet products and the 128 rotation resultants | `template-identities.gp` | `template-identities.txt` |
| Theorem 4 and the counting section: positive representations by the four quartic forms below 250000, agreement with the scan, and the leading estimates | `quartic-counts.gp` | `quartic-counts.txt` |

`four-orders.c` shares no code with `matrices.cpp` or with the scan programs.

## Paper build

`make paper` runs pdfLaTeX three times with a fixed `SOURCE_DATE_EPOCH` and
fails on any warning, overfull box or undefined reference. With the pdfTeX
version listed above, the release PDF `paper/main.pdf` has SHA-256

```text
b767ad23f997b28a88d0d868b07ba9ff2b8f3d09dab8bc6affba6169bafa0beb
```

Other TeX distributions embed different font and metadata bytes, so a
different PDF hash there is expected and is not a failure.
