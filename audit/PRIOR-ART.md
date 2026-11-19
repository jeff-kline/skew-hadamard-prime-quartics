# Prior art and credit

This is a bounded comparison with the closest known constructions. It is not a
claim of global novelty. The searches are logged in
[searches/prior-art-search-2026-11-18.md](searches/prior-art-search-2026-11-18.md).

## The four orders

**Claim:** we found no earlier published construction of a skew Hadamard
matrix of order 4040, 5192, 5960 or 6216.

| Source | What it records | Bearing |
|---|---|---|
| Cati–Pasechnik, arXiv:2411.18897v2, Table 5 | $505(11)$, $649(4)$, $745(6)$, $777(4)$ | the new matrices lower each exponent to at most 3 |
| Đoković–Seberry census (PDF dated 2025-05-28) | 505, 649, 745, 777 undecided | concerns the half-orders 2020, 2596, 2980, 3108; a skew matrix there would give these orders by doubling |
| `vatskishan03/Hadamard` (latest commit 2026-11-06) and the November 2026 report | no skew entry at these orders or their halves | consistent |
| Egan–Kotsireas–London–Ó Catháin, arXiv:2610.27175v2 | survey to November 2026 | nothing at these orders |

Constructions checked against the four orders and their halves:

- **Paley I and one doubling:** $N-1$ and $N/2-1$ are not prime powers
  ($4039=7\cdot577$, $2019=3\cdot673$; $5191=29\cdot179$, $2595=3\cdot5\cdot173$;
  $5959=59\cdot101$, $2979=3^2\cdot331$; $6215=5\cdot11\cdot113$,
  $3107=13\cdot239$).
- **Products with amicable matrices:** each order has 2-adic valuation 3, so a
  product of two factors divisible by 4 is impossible, and the factor 2 needs a
  skew matrix at the half-order.
- **Wallis–Whiteman four-block series:** needs a field of order $9\bmod16$; all
  four primes are $17\bmod32$ and are not powers of a smaller base.
- **Momihara–Xiang:** at $p\equiv17\pmod{32}$ their families have eight sets,
  and their matrix corollaries use two or four.
- **Seberry's orthogonal-design formula $mb(b-1)$:** no admissible $b>2$ at the
  first three orders. At 6216 the cases $(b,m)=(4,518),(8,111)$, and $(4,259)$
  at 3108, still require specific designs whose existence is not known.

## The binomial test and the quartic forms

- **Lehmer (1976)** gives the general necessary and sufficient cyclotomic test
  for supplementary unions of classes, so a test for any prescribed pattern
  predates this work. **Lehmer (1974)** gives eight skew blocks at index 16 for
  $p\equiv17\pmod{32}$.
- **Lehmer (1954), Whiteman (1957), Evans–Hill (1979)** give order-16
  cyclotomic numbers in terms of Jacobi-sum parameters.
- **Hudson–Williams (1984)** evaluate order-16 binomial coefficients through
  Jacobi sums; their worked example at $p=113$ is prior arithmetic data.
- **Wallis (1972) §6** and **Szekeres (1969)** were checked: neither gives four
  half-size skew blocks at these parameters.

We found no source that selects four skew half-size index-16 blocks over a
prime field by these four polynomials in one binomial ratio, or that describes
the selected primes by these quartic forms.

## Credit

- **Momihara and Xiang**: the bordered array (Proposition 1.3) and a
  quadratic-extension identity for cyclotomic half-intervals (Proposition 3.1).
- **Turyn (1971)** and **Momihara (2020)**: the odd-degree construction, as
  recast in the predecessor release.
- **The author's earlier searches** found the four prime-field certificates in
  November 2026.

## Residuals

- The two papers on dicyclic relative difference sets noted in the predecessor
  release were seen only in publisher preview; the full text was not openly
  accessible at the time of writing.
- Papers citing Momihara–Xiang were not screened (rate limited).
- Unpublished or unindexed constructions cannot be excluded.
