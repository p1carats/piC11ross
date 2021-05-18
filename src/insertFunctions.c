//
// Created by cyril on 07/04/2021.
//

#include "functions.h"

// insertion d'un élément en queue de liste chaînée bilatère
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

// insertion d'un élément en tête de liste chaînée bilatère
int insertItemAtDoubleLinkedListHead(DoubleLinkedList *liste, DoubleLinkedListElem *newItem){
	int retour = 0; // 0 : tout va bien | -1 : erreur
	if (liste != NULL && newItem != NULL){ // Si les 2 éléments existent
		if((liste->tail == NULL && liste->head == NULL) || liste->size == 0){ // Si la liste est vide
			liste->size = 1;
			liste->head = newItem;
			liste->tail = newItem;

			newItem->previous = NULL;
			newItem->next = NULL;

		}else{ // Si la liste contient déjà des choses
			newItem->previous = NULL;
			newItem->next = liste->head;

			liste->head->previous = newItem;
			liste->head = newItem;
			liste->size += 1;
		}

		retour = 0;

	}else{
		retour = -1; //Impossible d'ajouter
	}

	return retour;
}

// insertion d'un élément après un autre élément
int insertItemAfterItem(DoubleLinkedList *liste, DoubleLinkedListElem *item, DoubleLinkedListElem *newItem){
	int retour = 0; // 0 : tout va bien | -1 : erreur
	if (liste != NULL && newItem != NULL && item != NULL && newItem != NULL){ // Si les 4 éléments existent
		if (liste->tail == item){ // Si l'élément est en bout de chaine
			insertItemAtDoubleLinkedListTail(liste, newItem);
		}else{ // Sinon
			DoubleLinkedListElem *tmp;
			tmp = item->next;
			item->next = newItem;
			newItem->previous = item;
			newItem->next = tmp;
			tmp->previous = newItem;
			liste->size += 1;
		}

		retour = 0;

	}else{
		retour = -1; //Impossible d'ajouter
	}

	return retour;
}

// insertion d'un élément avant un autre élément
int insertItemBeforeItem(DoubleLinkedList *liste, DoubleLinkedListElem *item, DoubleLinkedListElem *newItem){
	int retour = 0; // 0 : tout va bien | -1 : erreur
	if (liste != NULL && newItem != NULL && item != NULL && newItem != NULL){ // Si les 4 éléments existent
		if (liste->head == item){ // Si l'élément est en tête
			insertItemAtDoubleLinkedListHead(liste, newItem);
		}else{ // Sinon
			DoubleLinkedListElem *tmp;
			tmp = item->previous;
			item->previous = newItem;
			newItem->next = item;
			newItem->previous = tmp;
			tmp->next = newItem;
			liste->size += 1;
		}

		retour = 0;

	}else{
		retour = -1; //Impossible d'ajouter
	}

	return retour;
}

// insère un nouvel élément contenant "value" en nième position
int insertItemAtIndexIntoLinkedList(DoubleLinkedList *liste, int index, int value){
	int retour = 0; // 0 : tout va bien | -1 : erreur
	if (liste != NULL && liste->size >= index){ // On verifie que la liste a au moins n positions
		DoubleLinkedListElem *maillon = newDoubleLinkedListItem(value);

		if(liste->size == index){ // Si c'est le cas, on met l'élément en queue
			insertItemAtDoubleLinkedListTail(liste, maillon);
		}else{ // Sinon
			DoubleLinkedListElem *maillon = newDoubleLinkedListItem(value);
			DoubleLinkedListElem *tmp = liste->head;
			DoubleLinkedListElem *tmpNext;
			int rang = 1;
			while (rang != index){ // On se place un élément avant
				tmp = tmp->next;
				rang++;
			}

			tmpNext = tmp->next;
			tmp->next = maillon;
			maillon->previous = tmp;
			maillon->next = tmpNext;
			tmpNext->previous = maillon;
			liste->size += 1;

		}

		retour = 0;

	}else{
		retour = -1; //Impossible d'ajouter
	}

	return retour;
}