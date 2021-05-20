#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

typedef struct jeu {
	int size;
	int *map;
	int **listX;
	int **listY;
} Jeu;

int newMap(Jeu *jeu);
int displayMap(Jeu *jeu);
int countLine(int *tab, int *retour, int size);
int getHint(Jeu *jeu);