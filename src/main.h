#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "generator.h"

void forPython(int taille, DoubleLinkedList *ListX, DoubleLinkedList *ListY);
Jeu* newJeu(int size, int *map, int **listX, int **listY);
int showHint(Jeu *jeu);