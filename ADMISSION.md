# Admission record

**Current state:** DRAFT

Current verdict: NOT YET ADMITTED

**Version:** 0.1.0 (draft)

**Standard:** [A Public Standard for This Work](https://jeff-kline.github.io/posts/research-program/index.html)

Admission is a project release decision. It is not peer review, a correctness
certificate, or proof of global novelty.

**Scope set by the author.** On 2026-11-18 the author asked for a release of
the four prime-field orders and the binomial and quartic-form criteria, as a
sequel to [skew-hadamard-2120](https://github.com/jeff-kline/skew-hadamard-2120),
with plain prose and no figures. The author delegated the prose checkpoint to
the release agent ("you run the prose, keep it plain, and then go") and
approved the repository name `skew-hadamard-prime-quartics`.

## Principal claim

There are explicit skew Hadamard matrices of orders 4040, 5192, 5960 and 6216
(paper Theorem 2). We found no earlier published constructions at these
orders. The recorded least exponents for the odd parts 505, 649, 745 and 777
drop to at most three.

Further results:

- an exact binomial test for four fixed patterns (Theorem 3);
- quartic-form descriptions of the primes passing three of the tests, with an
  $O(\sqrt x)$ count (Theorem 4);
- extension of all-skew seeds to every degree (Theorem 5).

Limits: the fourth test has no quartic-form description; infinitude of the
selected primes is open; no priority is claimed for orders $4(p^n+1)$ with
$n\ge2$.

## Gates

| Gate | Status | Evidence or residual |
|---|---|---|
| P1 prior work and credit | IN PROGRESS | `audit/PRIOR-ART.md`; searches of 2026-11-18/19 |
| A1 claim and artifact consistency | IN PROGRESS | release audits pending |
| R1 release and stewardship | IN PROGRESS | `make verify` and `make paper` pass locally; no tag, archive or DOI |
