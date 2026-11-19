/* Certificates for the four prime-field orders (paper, Table 2 and Theorem 2).
   For each prime p, primitive root b and four 16-bit masks: the set B_i holds
   b^j (j = 0..p-2) when bit (j mod 16) of mask i is zero. Checks that b is a
   primitive root, that every B_i has size (p-1)/2, which B_i are skew, and
   that the four sets together have exactly p-3 ordered differences at every
   nonzero residue. Direct enumeration of all ordered pairs; no Fourier data.
   Independent of matrices.cpp. Exit status is nonzero on any failure. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int check(int p, int b, const unsigned mask[4]) {
  int *cls = malloc(sizeof(int) * p);
  long *d = calloc(p, sizeof(long));
  char *in = malloc(p);
  int m = (p - 1) / 2, ok = 1, skew = 0;
  for (int x = 0; x < p; x++) cls[x] = -1;
  long x = 1;
  for (int j = 0; j < p - 1; j++) {
    if (cls[x] != -1) { ok = 0; break; }        /* b is not primitive */
    cls[x] = j % 16;
    x = x * b % p;
  }
  if (x != 1) ok = 0;
  for (int i = 0; i < 4 && ok; i++) {
    int size = 0, meet = 0;
    for (int y = 1; y < p; y++) { in[y] = !((mask[i] >> cls[y]) & 1u); size += in[y]; }
    in[0] = 0;
    for (int y = 1; y < p; y++) if (in[y] && in[p - y]) meet++;
    if (size != m) ok = 0;
    if (meet == 0) skew++;
    if (i == 0 && meet != 0) ok = 0;              /* the first block must be skew */
    for (int u = 1; u < p; u++) if (in[u])
      for (int v = 1; v < p; v++) if (in[v]) d[(u - v + p) % p]++;
  }
  long lo = d[1], hi = d[1];
  for (int t = 2; t < p; t++) { if (d[t] < lo) lo = d[t]; if (d[t] > hi) hi = d[t]; }
  if (lo != p - 3 || hi != p - 3) ok = 0;
  printf("p=%d b=%d masks=%u,%u,%u,%u skew-blocks=%d differences-at-nonzero=[%ld,%ld] p-3=%d order=%d %s\n",
         p, b, mask[0], mask[1], mask[2], mask[3], skew, lo, hi, p - 3, 4 * (p + 1),
         ok ? "PASS" : "FAIL");
  free(cls); free(d); free(in);
  return ok;
}

int main(void) {
  const unsigned m1009[4] = {255, 13973, 48322, 47288};
  const unsigned m1297[4] = {765, 31425, 21866, 38610};
  const unsigned m1489[4] = {765, 13916, 7507, 25542};
  const unsigned m1553[4] = {11475, 13005, 19125, 21675};
  int ok = check(1009, 11, m1009) & check(1297, 10, m1297)
         & check(1489, 14, m1489) & check(1553, 3, m1553);
  /* Control: changing one bit of the last mask must break the difference condition. */
  const unsigned bad[4] = {11475, 13005, 19125, 21675 ^ 3u};
  printf("control (1553, last mask altered): ");
  int c = check(1553, 3, bad);
  return (ok && !c) ? 0 : 1;
}
