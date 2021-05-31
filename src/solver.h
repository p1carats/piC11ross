#include <stdlib.h>
#include <stdio.h>

#include "generator.h"

int checkGrid(Game *picross, int *tab, int pos);
int solver (Game *picross, int pos);