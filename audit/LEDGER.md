# Audit ledger

This file is append-only. Each audit records its scope, what it checked, its
findings and their dispositions. The auditors are process-separated AI agents
in fresh contexts; they are not independent expert reviewers, and their
agreement is not peer review. Finding labels: error, gap, missing hypothesis,
sharpening, documentation.

## 2026-11-18 — reviews of the working drafts (before the release cycle)

The working notes behind this paper were reviewed in separate fresh contexts
before the release cycle. The records are summarized here; the raw files stay
with the working notes.

- Order 6216 (all-skew certificate): an isolated failure search (NOT-BROKEN,
  with a negative control that toggles one class) and a proof audit (VERIFIED).
- Orders 4040, 5192, 5960: a check that each quartet meets the hypotheses of
  Momihara–Xiang Proposition 1.3 (verified).
- The binomial test: an isolated failure search (NOT-BROKEN) and a proof audit
  (VERIFIED for the four template equivalences and the seven congruences).
- The quartic-form theorem: a proof audit of both implications for all three
  rules (no defect found; the fourth, quartic criterion is outside it).
- The quadratic-extension step: a proof audit (VERIFIED, with trace-compatible
  additive characters; the base frequency multiplier is $-2$).
- A prior-art check of the index-16 criterion against Lehmer, Evans–Hill,
  Hudson–Williams, Wallis and Szekeres (see `audit/PRIOR-ART.md`).

## 2026-11-18 — release preparation

- **Independent certificate.** `code/four-orders.c`, written for the release
  and sharing no code with the earlier checkers, counts all ordered
  differences for the four orders directly: $p-3$ at every nonzero residue,
  first set skew (all four at 1553). A control with one altered mask fails.
- **Matrices.** `code/matrices.cpp` rebuilds the four matrices and checks
  58,708,656 row pairs, the diagonal and skewness (about 7 s on one core).
- **Scan.** `code/ratio-scan.cpp` selects 33 of 1373 primes below 250000;
  `code/ratio-templates.cpp` confirms each by difference counts in the sixteen
  shift classes. The quartic-form lists in `code/quartic-counts.gp` agree with
  the scan for the first three rules.
- **Framing.** The working draft counted 2120 among "five improvements". The
  release counts the four new orders and cites the predecessor for 2120. The
  title is now the four orders.
- **Theorem numbers.** The README draft cited the binomial test, quartic forms
  and degree extension as Theorems 4, 5 and 6. The compiled numbers are 3, 4
  and 5 (theorems, lemma and proposition share one counter). Fixed before any
  audit.

## 2026-11-18 — release audits of the draft commit bf3e769

Four process-separated agents worked in fresh contexts, all read-only: claims
consistency (Sonnet), end-to-end proof (Fable, hand arithmetic only),
citations (Sonnet), and reproducibility (Sonnet; it ran only `make verify` and
`make paper` on a clean `git archive`).

### End-to-end proof

- **Verdict:** VERIFIED for Lemma 1, Theorem 2 (as a certificate), Theorems
  3–5, the counting section and Proposition 6. No error and no mathematical gap.
  The auditor independently derived the three rotation polynomials and the
  fixed-quartet relation $(Y-1)^2=2$.
- **Should-fix findings, all adopted:**
  - P-1 (documentation): "Four freely chosen masks satisfy the more general
    system" read as an assertion. Now: for four freely chosen masks, (1) is
    equivalent to the system.
  - P-2 (missing hypothesis): Proposition 6 used "seed" on an arbitrary group.
    The definition is now in its statement.
  - P-3 (documentation): "$4\nmid22$" replaced by
    $\mathrm{ord}_{23}(2)=11$ with the check $2^{11}=23\cdot89+1$.
  - P-4 (gap in exposition): the second sentence of Theorem 5 is now closed in
    its proof (odd rows give skew supports satisfying (1); Lemma 1 applies).
  - P-5 (sharpening): the recipe for Theorem 2 now states that each mask has
    eight set bits, so each set has $(p-1)/2$ elements.
  - P-6 (missing hypothesis): Theorem 3 now states "$p=16h+1$ prime, $h$ odd".
- **Optional notation clashes** (several letters reused across sections): not
  changed; each use is local to its section.

### Claims consistency

- **Verdict:** PARTIAL. Theorem numbers, counts and priority labels agree.
- **Must-fix findings and dispositions:**
  - C-1 (documentation): the README limit about $p=1873$ had no support in the
    repository, and the $p=241$ statement in the paper had no pinned output.
    Both removed. The README now says only that the test concerns four fixed
    patterns.
  - C-2 (missing hypothesis): the binomial test holds "for some primitive
    root", one polynomial per pattern. Added to the abstract, README and
    CITATION.cff.
  - C-3 (overclaim): infinitude under the prime-values conjecture is argued for
    the first form only. Reworded everywhere.
  - C-4 (documentation): README status against ADMISSION state. ADMISSION moves
    to CANDIDATE with this commit.
- **Optional findings adopted:**
  - The paper and README now say that only 1553 among the four orders is
    selected by Theorem 3.
  - README item 4 credits the quadratic step and disclaims priority for $n\ge2$.
  - "We give no quartic-form description" for the fourth test.
  - The third pattern's two forms are made explicit.
  - "Primes $p\equiv3\pmod4$" replaces "characteristic 3 mod 4".
  - The shift classes are explained.
  - "Cati and Pasechnik's table" replaces "the authors' table".
  - Cati–Pasechnik is dated v2 (2025) in CITATION.cff.
  - An unexplained phrase about antipodal class masks is removed.

### Citations

- **Verdict:** PARTIAL. Confirmed against the sources: Cati–Pasechnik Table 5
  (505(11), 649(4), 745(6), 777(4)); Momihara–Xiang Prop. 1.3, Theorem 1.5,
  Prop. 3.1; the census list (505, 649, 745, 777 undecided); Evans–Hill;
  bibliographic data of Lehmer 1974 and 1976, Turyn, Momihara and the
  predecessor DOI.
- **Must-fix finding and disposition:**
  - L-1 (error): the GSI report was cited as "Skew and symmetric Hadamard
    matrices". Corrected to "New families and orders of skew-Hadamard and
    symmetric Hadamard matrices" (16 November 2026).
- **Other:** Momihara now cites DOI 10.37236/9058. Hudson–Williams pages and
  the $p=113$ example were not openly reachable for this lane (HTTP 403); the
  earlier prior-art check read them from the author's copy.

### Reproducibility

- **Verdict:** PARTIAL. On a clean `git archive`: 8 of 8 MATCH, the PDF hash
  reproduced, the manifest verified (28 files).
- **Must-fix findings and dispositions:**
  - R-1 (documentation): the PARI/GP estimates printed 19 digits, which may
    differ across PARI versions. They now print with four decimals; evidence
    regenerated.
  - R-2 (documentation): `gp` now runs with `-f`, ignoring any user `.gprc`.
  - R-3 (documentation): theorem numbers in the comments of
    `code/run-certificates.sh` corrected.
- **Optional findings adopted:** timing comments say thirty seconds; stale
  header comments in `ratio-scan.cpp` and `ratio-templates.cpp` corrected;
  VERIFICATION.md names PARI/GP 2.17.4.
