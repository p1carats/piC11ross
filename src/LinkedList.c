//
// Created by cyril on 18/05/2021.
//
#include "LinkedList.h"

// Function which create a new Double linked list and return a pointer
DoubleLinkedList *newDoubleLinkedList(){
	DoubleLinkedList *liste = (DoubleLinkedList*) malloc(sizeof(DoubleLinkedList));
	if (liste != NULL){
		liste->size = 0;
		liste->head = NULL;
		liste->tail = NULL;
		return liste;
	}else{
		return NULL;
	}
}

// Function which create a Double Linked List Element. Copy value into tab
DoubleLinkedListElem *newDoubleLinkedListItem(int *value, int taille){
	DoubleLinkedListElem *maillon = (DoubleLinkedListElem*) malloc(sizeof(DoubleLinkedListElem));
	if (maillon != NULL){
		maillon->tab = malloc(sizeof(int) * taille);
		for (int i = 0; i < taille; i++){
			maillon->tab[i] = value[i];
		}

		maillon->next = NULL;
		maillon->previous = NULL;
		return maillon;
	}else{
		return NULL;
	}
}

// Function which show a double linked list
int displayDoubleList(DoubleLinkedList *liste, int taille){
	DoubleLinkedListElem *elem;
	elem = liste->head;
	int retour = 0; // 0 : tout va bien | -1 : erreur

	if (liste != NULL){
		for (int i = 0; i < liste->size; i++){
			printf("%d) ", i);
			for (int j = 0; j < taille; j++){
				printf("%d ", elem->tab[j]);
			}
			elem = elem->next;
			printf("\n");
		}
		retour = 0;
	}else{
		retour = -1;
	}

	return retour;
}


// Function which insert a element into a double linked list
int insertItemAtDoubleLinkedListTail(DoubleLinkedList *liste, DoubleLinkedListElem *newItem){
	int retour = 0; // 0 : tout va bien | -1 : erreur
	if (liste != NULL && newItem != NULL){ // Si les 2 éléments existent
		if((liste->tail == NULL && liste->head == NULL) || liste->size == 0){ // Si la liste est vide
			liste->size = 1;
			liste->head = newItem;
			liste->tail = newItem;

			newItem->previous = NULL;
			newItem->next = NULL;

		}else{ // Si la liste contient déjà des choses
			newItem->previous = liste->tail;
			newItem->next = NULL;

			liste->size += 1;
			liste->tail->next = newItem; // L'avant dernier prend le dernier en Next
			liste->tail = newItem;
		}

		retour = 0;

	}else{
		retour = -1; //Impossible d'ajouter
	}

	return retour;
}


// Function which return the tab stored on an element
int getValueOfDoubleLinkedListItem(DoubleLinkedListElem *item, int *valeur, int taille){

	for (int i = 0; i < taille; i++){
		valeur[i] = item->tab[i];
	}

	return 0;

}

