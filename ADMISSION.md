# Admission record

**Current state:** ADMITTED

Current verdict: ADMITTED (2026-11-18)

**Version:** 0.1.0

**Tag:** `v0.1.0` → `35ed17b07cc387fc098b15d1a285006e6d9eab44`

**Version DOI:** [`10.5281/zenodo.24357696`](https://doi.org/10.5281/zenodo.24357696) · **Concept DOI:** `10.5281/zenodo.24357695` · **Record:** <https://zenodo.org/records/24357696>

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
| P1 prior work and credit | PARTIAL, residual accepted | `audit/PRIOR-ART.md`; searches of 2026-11-18/19 (GitHub code and repositories with a positive control, arXiv, the November 2026 survey and GSI report, the census, Cati–Pasechnik Table 5); Lehmer, Evans–Hill and Hudson–Williams compared. Residuals: two dicyclic relative-difference-set papers seen only in publisher preview (full text not openly accessible at the time of writing); papers citing Momihara–Xiang not screened (rate limited). The fast-follow scan is dated 2026-11-19 UTC and the tag the same day. The residual is the same kind the author accepted for the predecessor; the author approved this release with it |
| A1 claim and artifact consistency | PASS | The author delegated the prose checkpoint (2026-11-18). Four release audits (claims, end-to-end proof, citations, reproducibility); every finding and its disposition is in `audit/LEDGER.md` |
| R1 release and stewardship | PASS | See below |

## R1 — release and stewardship

| Check | Status | Evidence or residual |
|---|---|---|
| Reproduction | PASS | fresh `git archive` extraction of the draft: `make verify` 8 MATCH, PDF hash reproduced, manifest verified. The candidate was rechecked with `make verify` (8 MATCH) and a deterministic `make paper` |
| Artifact integrity | PASS | `MANIFEST.sha256` covers every tracked file; two consecutive paper builds are byte-identical |
| Hygiene | PASS | whole-tree scan for private paths, emails and private repository names; README math rendered by GitHub, every span recognized |
| Stewardship | PASS | `CORRECTIONS.md` |
| Immutable semantic tag | PASS | annotated `v0.1.0` (object `fd67366`) → `35ed17b`; tagger is the GitHub noreply identity |
| Public permanent archive with provider byte identity | PASS | the pinned GitHub `zipball/v0.1.0` (downloaded twice, identical) and the Zenodo file are byte-identical: 315,703 bytes, SHA-256 `e909ab2f9ee615f7d123fb84e8e20fb48d099eee5db7882f673dc02fde1ab13c`; Zenodo MD5 `dabacb29f21030a4191b96752db9c74d` |
| DOI resolves; living repository identifies the version | PASS | `doi.org/10.5281/zenodo.24357696` redirects to the Zenodo record; README, `CITATION.cff` and the living paper carry the version DOI |
| Archive metadata matches repository | PASS | title, creator Kline, Jeffery, version v0.1.0, publication date 2026-11-19 (UTC), license `gpl-3.0`, resource type software |
| Machine-readable citation | PASS | `CITATION.cff` with version DOI, concept DOI and `date-released: 2026-11-19` (Zenodo's date) |

**Admission verdict:** ADMITTED (2026-11-18). The P1 residual and the limits
stated in the README remain. No independent human expert has reviewed the
proofs.

## Archive verification

- Route: Zenodo GitHub integration; no manual deposit.
- Pinned before the GitHub Release: GitHub API `zipball/v0.1.0`, downloaded
  twice, identical, 315,703 bytes, SHA-256
  `e909ab2f9ee615f7d123fb84e8e20fb48d099eee5db7882f673dc02fde1ab13c`.
- Zenodo file `jeff-kline/skew-hadamard-prime-quartics-v0.1.0.zip`: identical
  to the pinned zipball.
- Separate determinism check: `git archive --format=zip v0.1.0`, generated
  twice, identical, 312,249 bytes, SHA-256
  `a567c5dece194b5a6054458bd99d25c75c1d723ca1c694d12c73b4dd06437e1e`; a
  different file from the provider zipball, not compared with it.
- Mechanical audit at the archived state, on the unchanged tagged tree:
  11 pass, 0 warnings, 0 fail.

## External actions and owners

| Action | Owner | Status |
|---|---|---|
| GitHub repository, push, public visibility, secret scanning and push protection | author authorization ("then go") | done 2026-11-18 |
| Zenodo enablement before the Release | author, in the Zenodo portal | done 2026-11-18 |
| Annotated tag `v0.1.0`, GitHub Release | author authorization | done 2026-11-19 02:49 UTC: Release "Version 0.1.0" |
| Public-site listing | author authorization | landing entry at <https://jeff-kline.github.io/>; Pages build and live HTML checked for title, blurb, repository link and version DOI before this record was pushed |
| Living-metadata update (this commit) | author authorization | pushed after the site listing was verified live |
