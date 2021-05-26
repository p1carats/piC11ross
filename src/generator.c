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
		if (jeu->map[i] == 1){
			printf("#");
		}else{
			printf("-");
		}
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
			if (jeu->listX[i][j] != 0){
				printf("%d ", jeu->listX[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n_______________________________________________\n\n");

	for(int i = 0; i < jeu->size; i++){
		for(int j = 0; j < jeu->size; j++){
			if (jeu->listY[i][j] != 0){
				printf("%d ", jeu->listY[i][j]);
			}
		}
		printf("\n");
	}

	return 0;

}

int createFile(Jeu *jeu, char name[16]){

	FILE *file;
	char buffer[16] = {0};
	file = fopen(name, "w");
	int i,j;

	// On ecrit la taille
	sprintf(buffer, "%d", jeu->size);
	fputs(buffer, file);
	fputs(";", file);
	fputs(buffer, file);

	fputs("\n", file);

	// On ecrit la liste X
	for (i = 0; i < jeu->size; i++){
		for (j = 0; j < jeu->size; j++){
			if (jeu->listX[i][j] != 0 || j == 0){
				sprintf(buffer, "%d", jeu->listX[i][j]);
				fputs(buffer, file);
			}

			if (j + 1 < jeu->size){
				if (jeu->listX[i][j+1]){
					fputs(",", file);
				}
			}
		}
		if (i < jeu->size - 1) {
			fputs(";", file);
		}

	}

	fputs("\n", file);

	// On ecrit la liste Y
	for (i = 0; i < jeu->size; i++){
		for (j = 0; j < jeu->size; j++){
			if (jeu->listY[i][j] != 0 || j == 0){
				sprintf(buffer, "%d", jeu->listY[i][j]);
				fputs(buffer, file);
			}

			if (j + 1 < jeu->size){
				if (jeu->listY[i][j+1]){
					fputs(",", file);
				}
			}
		}

		if (i < jeu->size - 1) {
			fputs(";", file);
		}
	}

	fputs("\n", file);

	// On ecrit la map
	for (i = 0; i < jeu->size; i++){
		for (j = 0; j < jeu->size; j++){
			sprintf(buffer, "%d", jeu->map[i * jeu->size + j]);
			fputs(buffer, file);
		}
	}

	fclose(file);
	return 0;
}

int readFile(Jeu *jeu, char *name){

	FILE *file;
	char buffer[255] = {0};
	file = fopen(name, "r");
	int i = 0;
	int size;

	// Lecture de la taille
	fscanf(file, "%s", buffer);
	char nb[2] = {0};

	while(buffer[i] != ';'){
		nb[i] = buffer[i];
		i++;
	}

	sscanf(nb, "%d", &size);
	jeu->size = size;

	fscanf(file, "%s", buffer);

	char **array = malloc(sizeof(char*) * size * size);

	for (int p = 0; p < size * size; p++){
		array[p] = malloc(sizeof(char) * size * size);
	}

	convertCharToArray(buffer, ';', array, size*size);
	convertArrayToInt(array, ',', jeu->listX, size*size);

	printf("%s\n", buffer);

	fscanf(file, "%s", buffer);
	printf("%s\n", buffer);

	return 0;

}

int convertCharToArray(char *buffer, char separator, char **array, int size){

	int i = 0;
	int j;
	int index = 0;
	char *elem = malloc(sizeof(char) * size);

	while (buffer[i] != '\0') {

		for (j = 0; j < size; j++){
			elem[j] = 0;
		}

		int p = 0;
		while (buffer[i] != separator && buffer[i] != '\0') {
			elem[p] = buffer[i];
			p++;
			i++;
		}

		for (j = 0; j < size; j++){
			array[index][j] = elem[j];
		}

		index++;
		i++;
	}

	free(elem);
	return 0;
}

int convertArrayToInt(char **array, char separator, int **retour, int size){

	char *buffer = malloc(sizeof(char) * size);

	int i;

	for (i = 0; i < size; i++){ // Boucle pour chaque tableau

		int j;
		// Recuperation de la ligne sous la forme "3,2,1"
		for (j = 0; j < size; j++){
			buffer[j] = array[i][j];
		}

		int index = 0;
		j = 0;
		int p = 0;
		char *nb = malloc(sizeof(char) * size);

		// Transformation de la ligne en int
		while (buffer[j] != '\0') {

			index = 0;

			for (int q = 0; q < size; q++){
				nb[q] = 0;
			}

			while (buffer[j] != separator && buffer[j] != '\0') {
				nb[index] = buffer[j];
				index++;
				j++;
			}

			sscanf(nb, "%d", &retour[i][p]);
			p++;
			j++;
		}
	}

	return 0;
}