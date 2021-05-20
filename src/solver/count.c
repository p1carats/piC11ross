#include "solver.h"

static int count(unsigned long x, int *r) {
  int n = 0;
  int mode = 0;
  for (int i = 0; i < SIZE_MAX; i++) {
    if ((x >> i) & 1UL) {
      if (mode = 0) {
        r[n++] = 1;
        break;
      } else if (mode = 1) {
        r[n - 1]++;
        break;
      } else {
        mode = 1;
      }
    } else {
      mode = 0;
    }
  }
  return n;
}