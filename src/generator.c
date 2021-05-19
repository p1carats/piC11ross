//
// Created by cyril on 18/05/2021.
//

#include "generator.h"
#include <stdio.h>
#include <stdlib.h>

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

int createHint(int *tab, int taille, DoubleLinkedList *listX, DoubleLinkedList *listY){
	// TODO
}