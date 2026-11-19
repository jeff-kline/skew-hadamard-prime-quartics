# Prior-art and fast-follow search, 2026-11-18/19

Each search is logged with its date and query. A failed or rate-limited
search is recorded as NOT PERFORMED, not as a negative result.

## GitHub (2026-11-19T02:22Z, `gh` CLI, authenticated)

- **Positive control:** `gh search code 1528 skew hadamard` returned
  `vatskishan03/Hadamard` files (`skew/1528/README.md` and others). Code
  search is working.
- `gh search code 4040 skew hadamard`, and the same for 5192, 5960 and 6216:
  no hits. `gh search code 4040 skew`: only unrelated hits.
- `gh search repos skew hadamard`, limit 50: the author's repositories, a
  weighing-matrix repository (Paley I and doubling to order 108) and one
  unrelated repository.
- `vatskishan03/Hadamard/skew/`, listing at the latest commit (2026-11-06): no
  entry for 4040, 5192, 5960 or 6216, nor for the half-orders 2020, 2596, 2980
  or 3108.

## arXiv (2026-11-18, export API)

- `all:"skew Hadamard"`, 25 newest of 40: no title or abstract mentions these
  orders or their odd parts (search logged with the predecessor release).
- Egan, Kotsireas, London and Ó Catháin, arXiv:2610.27175v2 (updated
  2026-11-03), full text searched for "skew": none of these orders.

## Sources read in the relevant parts

- Cati–Pasechnik, arXiv:2411.18897v2, Table 5: $505(11)$, $649(4)$, $745(6)$,
  $777(4)$.
- Đoković–Seberry census of skew orders $4v$, $v$ odd $<2500$ (PDF dated
  2025-05-28): 505, 649, 745 and 777 are undecided, concerning the half-orders.
- The November 2026 report and pinned skew index of Generalised
  Superintelligence: neither the four orders nor their halves.
- Momihara–Xiang, arXiv:1801.08776: Propositions 1.1–1.4, Theorem 1.5,
  Proposition 3.1.
- Lehmer 1974 and 1976; Wallis 1972 §6; Szekeres 1969; Lehmer 1954; Whiteman
  1957; Evans–Hill 1979 §3; Hudson–Williams 1984, Theorem 5.1 and §19.
- Koukouvinos–Stylianou 2008 (full text supplied by the author).
