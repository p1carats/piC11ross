//
// Created by cyril on 18/05/2021.
//

#include "generator.h"


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
		retour[i] = 0;
	}

	for(int i = 0; i < taille; i++){
		if (tab[i] == 1){
			indice++;
		}else if(indice > 0){ // Si tab[i] == 0 et que indice > 0
			retour[indiceTab] = indice;
			indiceTab++;
			indice = 0;
		}
	}

	if(indice > 0 && tab[taille - 1] == 1){
		retour[indiceTab] = indice;
	}

	return 0;
}

int getHint(int *tab, int taille, DoubleLinkedList *ListX, DoubleLinkedList *ListY){

	int *tabTmp = malloc(sizeof(int) * taille);
	int *tabReturn =  malloc(sizeof(int) * taille);
	if (tabTmp == NULL || tabReturn == NULL){
		return -1;
	}

	for (int i = 0; i < taille; i++){
		for (int j = 0; j < taille; j++){
			tabTmp[j] = tab[j + i * 10];
		}

		countLine(tabTmp, tabReturn, taille);
		DoubleLinkedListElem *elem = newDoubleLinkedListItem(tabReturn, taille);
		insertItemAtDoubleLinkedListTail(ListX, elem);
	}

	for (int i = 0; i < taille; i++){
		for (int j = 0; j < taille; j++){
			tabTmp[j] = tab[j*10 + i];
		}

		countLine(tabTmp, tabReturn, taille);
		DoubleLinkedListElem *elem = newDoubleLinkedListItem(tabReturn, taille);
		insertItemAtDoubleLinkedListTail(ListY, elem);
	}

	return 0;

}