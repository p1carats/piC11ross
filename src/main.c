#include "main.h"

int main(void){
	srand(time(NULL));

	int taille = 5;
	int *tab = malloc(sizeof(int) * taille * taille);
	int **listX = malloc(sizeof(int*) * taille);
	int **listY = malloc(sizeof(int*) * taille);

	int i;

	for (i = 0; i < taille; i++){
		listX[i] = malloc(sizeof(int*) * taille);
	}

	for (i = 0; i < taille; i++){
		listY[i] = malloc(sizeof(int*) * taille);
	}

	Jeu *jeu;
	jeu = newJeu(taille, tab, listX, listY);

	newMap(jeu);
	displayMap(jeu);

	getHint(jeu);
	showHint(jeu);


	//forPython(taille, ListX, ListY);

	return 0;
}

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

int showHint(Jeu *jeu){
	if (jeu != NULL){

		for(int i = 0; i < jeu->size; i++){

			for(int j = 0; j < jeu->size; j++){
				printf("%d ", jeu->listX[i][j]);
			}

			printf("\n");
		}

		return 0;
	}else{
		return -1;
	}
}

void forPython(int taille, DoubleLinkedList *ListX, DoubleLinkedList *ListY){
	printf("'''%d\n", taille);
	printf("%d\n",taille);
	displayDoubleListForPython(ListY, taille);
	printf("\n");
	displayDoubleListForPython(ListX, taille);
	printf("'''\n");
}

//test