#include <stdio.h>
#include <stdlib.h>

typedef struct jeu {
	int size;
	int *map;
	int **listX;
	int **listY;
} Jeu;

Jeu* newJeu(int size, int *map, int **listX, int **listY);
int newMap(Jeu *jeu);
int displayMap(Jeu *jeu);
int countLine(int *tab, int *retour, int size);
int getHint(Jeu *jeu);
int showHint(Jeu *jeu);