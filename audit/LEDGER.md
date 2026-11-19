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
