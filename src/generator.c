//
// Created by cyril on 18/05/2021.
//

#include "generator.h"
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

// Function which create a map, need to give an empty tab and its dimension
int newMap(int *tab, int taille){

	for(int i = 0; i < taille * taille; i++){
		int alea = rand() % 10;

		if (alea > 5){
			tab[i] = 1;
		}else{
			tab[i] = 0;
		}
	}

	return 0;
}

// Function which display a map, need to give a tab and its dimension
int displayMap(int *tab, int taille){

	for(int i = 0; i < taille * taille; i++){
		if(i % taille == 0 && i != 0){
			printf("\n");
		}
		printf("%d", tab[i]);
	}

	printf("\n");

	return 0;
}

// Function which return a tab with the number of "package", need to give 2 tab with the same dimension and the dimension
int countLine(int *tab, int *retour, int taille){
	int indice = 0;
	int indiceTab = 0;

	for(int i = 0; i < taille; i++){
		if (tab[i] == 1){
			indice++;
		}else if(indice > 0){
			retour[indiceTab] = indice;
			indiceTab++;
			indice = 0;
		}
	}

	if(indice > 0){
		retour[indiceTab] = indice;
	}

	return 0;
}