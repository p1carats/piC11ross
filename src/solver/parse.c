#include "solver.h"

static void parse_runs(int runs[][SIZE_MAX / 2], int nruns[], char *line) {
  char *p = strtok(line, "\"");
  for (int n = 0; ; n++) {
    nruns[n] = 0;
    for (int e = 0; *p; e++) {
      runs[n][e] = strtol(p, &p, 10);
      if (*p) {
        p++;
      }
      if (runs[n][e]) {
        // zero is special
        nruns[n]++;
      }
    }
    p = strtok(0, "\"");
    if (!p || *p != ',') {
      break;
    }
    p = strtok(0, "\"");
  }
}