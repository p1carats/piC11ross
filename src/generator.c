#include "generator.h"

// creates a new structure Jeu with 4 arguments : size, map, listX and listY
Jeu* newJeu(int size, int *map, int **listX, int **listY){
	Jeu *jeu = (Jeu*) malloc(sizeof(Jeu));

	if (jeu != NULL){

		jeu->size = size;
		jeu->map = map;
		jeu->listX = listX;
		jeu->listY = listY;

		return jeu;

	}else{

		return NULL;
	}
}

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

	for(int i = 0; i < jeu->size; i++){
		jeu->listX[i] = malloc(sizeof(int) * jeu->size);
		jeu->listY[i] = malloc(sizeof(int) * jeu->size);

		if (jeu->listX[i] == NULL || jeu->listY[i] == NULL){
			return -1;
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

// Assign to listX and listY their values
int getHint(Jeu *jeu) {

	int *tabTmp = malloc(sizeof(int) * jeu->size);
	int *tabReturn =  malloc(sizeof(int) * jeu->size);

	if (tabTmp == NULL || tabReturn == NULL) {
		return -1;
	}

	for (int i = 0; i < jeu->size; i++) {
		int j;

		*tabReturn = 0;
		*tabTmp = 0;

		for (j = 0; j < jeu->size; j++) {
			tabTmp[j] = jeu->map[j + i * jeu->size];
		}

		countLine(tabTmp, tabReturn, jeu->size);

		for(j = 0; j < jeu->size; j++){
			jeu->listX[i][j] = tabReturn[j];
		}

	}

	printf("\n");

	for (int i = 0; i < jeu->size; i++) {
		int j = 0;
		for (j = 0; j < jeu->size; j++) {
			tabTmp[j] = jeu->map[j * jeu->size + i];
		}

		countLine(tabTmp, tabReturn, jeu->size);

		for(j = 0; j < jeu->size; j++){
			jeu->listY[i][j] = tabReturn[j];
		}

	}

	free(tabTmp);
	free(tabReturn);

	return 0;
}

// show values of listX and listY (for debugging)
int showHint(Jeu *jeu){
	if (jeu == NULL) {
		return -1;
	}

	for(int i = 0; i < jeu->size; i++){
		for(int j = 0; j < jeu->size; j++){
			printf("%d ", jeu->listX[i][j]);
		}
		printf("\n");
	}
	printf("\n_______________________________________________\n\n");

	for(int i = 0; i < jeu->size; i++){
		for(int j = 0; j < jeu->size; j++){
			printf("%d ", jeu->listY[i][j]);
		}
		printf("\n");
	}

	return 0;

}