#include "solver.h"

static unsigned long column_extract(unsigned long s[], int x, int h) {
  unsigned long col = 0;
  for (int y = 0; y < h; y++) {
    col |= ((s[y] >> x) & 1UL) << y;
  }
  return col;
}