//
// Created by cyril on 07/04/2021.
//

#include <stdlib.h>
#include "functions.h"

// suppression et destruction d'un élément de liste chainée
int deleteDoubleLinkedListItem(DoubleLinkedList *liste, DoubleLinkedListElem *item){
	int retour;

	if (liste != NULL && item != NULL){
		DoubleLinkedListElem *tmpNext = item->next;
		DoubleLinkedListElem *tmpPrev = item->previous;

		tmpNext->previous = tmpPrev;
		tmpPrev->next = tmpNext;

		free(item);
		liste->size -= 1;
		retour = 0;
	}else{
		retour = -1;
	}

	return retour;
}

// destruction de tous les éléments d'une liste chaînée
int emptyDoubleLinkedList(DoubleLinkedList *liste){
	int retour;

	if(liste != NULL){
		int rang = 0;
		DoubleLinkedListElem *tmp = liste->head;
		DoubleLinkedListElem *next;

		while(rang != liste->size){ // On supprime d'abord les maillons
			next = tmp->next;
			free(tmp);
			tmp = next;
			rang++;
		}

		free(liste); // Puis la liste

		retour = 0;
	}else{
		retour = -1;
	}

	return retour;
}