# Skew Hadamard matrices of orders 4040, 5192, 5960 and 6216

Jeffery Kline

**Status: release candidate for version 0.1.0.** The claims are frozen
and audited (see [ADMISSION.md](ADMISSION.md)). There is no tag, archive or
DOI yet, so there is no stable citation. This is the sequel to
[*A skew Hadamard matrix of order 2120*](https://github.com/jeff-kline/skew-hadamard-2120)
([doi:10.5281/zenodo.24356140](https://doi.org/10.5281/zenodo.24356140)).

The paper is [paper/main.pdf](paper/main.pdf); its source is
[paper/main.tex](paper/main.tex).

## Introduction

A Hadamard matrix $H$ of order $N$ is skew if $H+H^{\mathsf T}=2I$. For each
odd number $m$, the database of Cati and Pasechnik records the least power of
two $2^t$ for which a skew matrix of order $2^t m$ is known.

This paper gives skew Hadamard matrices of orders 4040, 5192, 5960 and 6216,
that is $2^3$ times 505, 649, 745 and 777. The table records larger orders for
all four odd parts. At 505 the recorded power drops from $2^{11}$ to $2^3$.

Each matrix comes from a prime field with $p$ elements, $p\equiv17\pmod{32}$:
$p=1009$, $1297$, $1489$ and $1553$. Four sets, each a union of eight of the
sixteen classes of sixteenth powers, go into the bordered array of Momihara
and Xiang. The array needs only the first set to be skew. The certificates
are integer difference counts that a short program checks directly.

The paper then asks which primes work. For each of four fixed patterns of
sets, the answer is an exact test: compute one ratio of binomial coefficients
modulo $p$ and check one polynomial; the pattern works, for a suitable
primitive root, exactly when the polynomial vanishes. For three of the
patterns, the primes that pass are exactly the primes $p\equiv17\pmod{32}$
of the form $u^4+8u^2v^2+8v^4$, of the form $u^4+16u^2v^2+32v^4$, and (for the
third pattern) of either form $49u^4+80u^2v^2+32v^4$ or
$u^4+80u^2v^2+1568v^4$. Of the four primes above, only 1553 passes; the other
three use sets of which only the first is skew. Up to $250\,000$ the test selects 33 of the 1373
candidate primes. When all four sets are skew, as at $p=1553$ and for every
prime the test selects, the construction extends to skew Hadamard matrices of
order $4(p^n+1)$ for every $n\ge1$.

## What is new

The previous release gave a skew Hadamard matrix of order 2120 and the
odd-degree extension used here. Momihara and Xiang gave the bordered array and
eight-set cyclotomic families at these primes; Lehmer gave the general test
for unions of cyclotomic classes; Evans and Hill, and Hudson and Williams,
gave the order-16 cyclotomic numbers and binomial-coefficient formulas. New
here:

1. **Principal result: skew Hadamard matrices of orders 4040, 5192, 5960 and
   6216** (paper Theorem 2). Each lowers the least known power of two in the
   Cati–Pasechnik table for its odd part: from $2^{11}$, $2^4$, $2^6$ and $2^4$
   to $2^3$.
2. **An exact binomial test** (Theorem 3). For each of four fixed patterns of
   four skew sets and a prime $p=16h+1$ with $h$ odd, the pattern works for
   some primitive root if and only if
   $Y=\binom{8h}{3h}/\binom{8h}{h}$ satisfies $Y^2-2Y-1$, $Y^2+2Y-1$,
   $Y^2-14Y-1$ or $17Y^4-44Y^3+66Y^2-52Y+17$ (one polynomial per pattern)
   vanishes modulo $p$. The test covers these four patterns only.
3. **Quartic forms** (Theorem 4). The primes that pass the first three tests
   are exactly the primes $p\equiv17\pmod{32}$ represented by the quartic
   forms listed above. There are $O(\sqrt x)$ of them up to $x$. A
   prime-values heuristic predicts 8.8, 6.2 and 6.1 up to $250\,000$; the
   counts are 9, 7 and 6. For the first form, infinitely many would follow from
   the standard conjecture on prime values of one-variable polynomials.
4. **All extension degrees** (Theorem 5). A quadratic-extension step, combined
   with the earlier odd-degree construction, extends a four-set skew seed over a
   field of order $q\equiv1\pmod4$ to every degree $n\ge1$. For every prime the
   test selects this gives skew Hadamard matrices of order $4(p^n+1)$ for all
   $n$, and it extends the previous release's family $4(23^{2n}+1)$ from odd
   $n$ to every $n$. No priority is claimed for these orders when $n\ge2$.

Not new:

- The bordered array (Momihara and Xiang, Proposition 1.3) and the odd-degree
  extension (Turyn, as recast in the previous release).
- Lehmer's general difference-count test for unions of cyclotomic classes, and
  the order-16 cyclotomic numbers and binomial-coefficient evaluations of
  Evans–Hill and Hudson–Williams. The arithmetic data for $p=113$ appear in
  Hudson–Williams.
- A quadratic-extension identity of the same kind for cyclotomic
  half-intervals (Momihara and Xiang, Proposition 3.1).
- The orders $4(p^n+1)$ for $n\ge2$. No priority is claimed for them.

These statements rest on a bounded comparison recorded in
[audit/PRIOR-ART.md](audit/PRIOR-ART.md). We have not found skew Hadamard
matrices of orders 4040, 5192, 5960 or 6216 in the sources checked. This is
not a claim of global novelty.

## Earlier work

- **Kline (2026)**, *A skew Hadamard matrix of order 2120*,
  [doi:10.5281/zenodo.24356140](https://doi.org/10.5281/zenodo.24356140):
  order 2120, the odd-degree extension and the four-set minimum for
  all-skew families over primes $p\equiv3\pmod4$.
- **Cati and Pasechnik (2024; v2 2025)**,
  [*A database of constructions of Hadamard matrices*](https://arxiv.org/abs/2411.18897),
  Table 5: $505(11)$, $649(4)$, $745(6)$ and $777(4)$.
- **Momihara and Xiang (2018)**,
  [*Skew Hadamard difference families and skew Hadamard matrices*](https://arxiv.org/abs/1801.08776):
  the bordered arrays and the eight-set cyclotomic families for
  $p\equiv17\pmod{32}$.
- **Lehmer (1974, 1976)**: supplementary difference sets from cyclotomy and
  the general existence test.
- **Evans and Hill (1979)**, *The cyclotomic numbers of order sixteen*, Math.
  Comp. 33, and **Hudson and Williams (1984)**, *Binomial coefficients and
  Jacobi sums*, Trans. Amer. Math. Soc. 281.
- **Đoković and Seberry (2025)**: the census of skew orders $4v$ with $v$ odd,
  which lists the half-orders 2020, 2596, 2980 and 3108 as undecided.

## Evidence and limits

| Claim | Status |
|---|---|
| Lemma 1 (bordered array) | proved on paper |
| Theorem 2: the four orders | certified computation: direct difference counts, and every row pair of the four completed matrices |
| Theorem 3 (binomial test) | proved on paper, with polynomial identities and resultants checked in PARI/GP |
| Theorem 4 (quartic forms) | proved on paper |
| The 33 selected primes up to $250\,000$ | certified computation, checked a second way by difference counts on one shift from each class of sixteenth powers |
| Theorem 5 (all degrees) | proved on paper |
| Counting estimates | heuristic; the $O(\sqrt x)$ bound is proved |
| Priority at the four orders | bounded search; see [audit/PRIOR-ART.md](audit/PRIOR-ART.md) |

Limits:

- We give no quartic-form description of the fourth test.
- Whether infinitely many primes pass any of the tests is open.
- The test concerns four fixed patterns, not every choice of sets.
- The half-orders 2020, 2596, 2980 and 3108 remain open.

## Reproduce

The certificates need a C compiler, a C++17 compiler and PARI/GP; the paper
needs pdfLaTeX.

```sh
make verify   # about thirty seconds on one core
make paper    # builds paper/main.pdf
```

`make verify` writes each output to `build/certificates/` and prints `MATCH`
for each file that equals its pinned copy in `evidence/`.
[VERIFICATION.md](VERIFICATION.md) maps each certificate to the step of the
paper it checks.

## Role of AI

AI assisted the derivations, the computer verification, the literature search
and the exposition under the author's direction. Process-separated AI reviews
checked the proofs and certificates; they are not independent expert peer
review, and no independent human expert has examined the proofs. The audits
and their dispositions are in [audit/LEDGER.md](audit/LEDGER.md).

## License

GPL-3.0-only. See [LICENSE](LICENSE).
