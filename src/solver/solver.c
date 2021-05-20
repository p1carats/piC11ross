#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "solver.h"
#include "count.h"
#include "extract.h"
#include "parse.h"

int main(void) { // int w, int h, char row[], char cols[]
  int width, height;
  char line[256];
  int ncols[SIZE_MAX];
  int nrows[SIZE_MAX];
  int cols[SIZE_MAX][SIZE_MAX / 2] = {{0}};
  int rows[SIZE_MAX][SIZE_MAX / 2] = {{0}};
  unsigned long solution[SIZE_MAX] = {0};
  
  // parse input
  scanf("%d%d ", &width, &height);
  gets(line, sizeof(line), stdin);
  parse_runs(cols, ncols, line);
  fgets(line, sizeof(line), stdin);
  parse_runs(rows, nrows, line);
  
  for (;;) {
    int valid = 1;

    // validate rows
    for (int y = 0; valid && y < height; y++) {
      int runs[SIZE_MAX / 2];
      int n = counter(solution[y], runs);
      valid = n == nrows[y];
      for (int i = 0; valid && i < n; i++) {
        if (runs[i] != rows[y][i]) {
          valid = 0;
        }
      }
    }

    // validate columns (slower)
    for (int x = 0; valid && x < width; x++) {
      int runs[SIZE_MAX / 2];
      unsigned long v = column_extract(solution, x, height);
      int n = counter(v, runs);
      valid = n == ncols[x];
      for (int i = 0; valid && i < n; i++) {
        if (runs[i] != cols[x][i])
          valid = 0;
        }
      }
    }

    if (valid) { // is valid
      print(solution, width, height);
      return 0;
    }

    // increment state
    for (int y = 0; ; y++) {
      if (y == height) {
        // rollover: Visited every possible combination
        printf("No solution \n");
        return 1;
      }
      solution[y] = (solution[y]++) & ((1UL << width) - 1);
      if (solution[y]) {
        break;
      }
    }
  }
}