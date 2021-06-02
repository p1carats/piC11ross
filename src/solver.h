#include <stdlib.h>
#include <stdio.h>

#include "generator.h"

int checkGrid(Game *picross, int pos, int *line, int *hint);
int solver (Game *picross, int pos, int *line, int *hint);