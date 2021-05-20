#include "generator.h"

// creates a new map, takes as arguments an empty tab and its dimension
int newMap(Jeu *jeu) {
	int size = jeu->size;
	for (int i = 0; i < size * size; i++) {
		int alea = rand() % 10;
		if (alea > 3) { // 2 out of 3 odds
			jeu->map[i] = 1;
		} else {
			jeu->map[i] = 0;
		}
	}
	return 0;
}

// displays a map, takes as arguments a tab and its dimension
int displayMap(Jeu *jeu) {
	int size = jeu->size;
	for (int i = 0; i < size * size; i++) {
		if (i % size == 0 && i != 0) {
			printf("\n");
		}
		printf("%d", jeu->map[i]);
	}
	printf("\n");
	return 0;
}

// returns a tab with the number of "package", takes as argument two tabs (both having the same dimension)
int countLine(int *tab, int *retour, int size) {
	int index = 0;
	int tabIndex = 0;

	for (int i = 0; i < size; i++) {
		retour[i] = 0;
	}

	for (int i = 0; i < size; i++) {
		if (tab[i] == 1) {
			index++;
		} else if(index > 0) { // only if tab[i] == 0 and index > 0
			retour[tabIndex] = index;
			tabIndex++;
			index = 0;
		}
	}

	if (index > 0 && tab[size - 1] == 1) {
		retour[tabIndex] = index;
	}

	return 0;
}

// jeu[0] => int *tab, jeu[1] => int size, size, jeu[1] => int **listX, jeu[2] => int **listY
int getHint(Jeu *jeu) {

	int size = jeu->size;
	int *tabTmp = malloc(sizeof(int *) * size);
	int *tabReturn =  malloc(sizeof(int *) * size);

	if (tabTmp == NULL || tabReturn == NULL) {
		return -1;
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			tabTmp[j] = jeu->map[j + i * size];
		}

		countLine(tabTmp, tabReturn, size);

		jeu->listX[i] = tabReturn;
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			tabTmp[j] = jeu->map[j * size + i];
		}

		countLine(tabTmp, tabReturn, size);

		jeu->listY[i] = tabReturn;
	}

	return 0;
}