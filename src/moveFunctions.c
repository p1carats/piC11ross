
//
// Created by cyril on 08/04/2021.
//

#include "functions.h"

// déplacement d'un élément après un autre élément
int moveDoubleLinkedListItemAfterItem(DoubleLinkedList *liste, DoubleLinkedListElem *item, DoubleLinkedListElem *itemDest){
	int retour = 0;

	if (liste != NULL && item != NULL && itemDest != NULL){

		DoubleLinkedListElem *tmpPrev;
		DoubleLinkedListElem *tmpNext;

		// On enlève item des maillons
		tmpPrev = item->previous;
		tmpNext = item->next;

		tmpPrev->next = tmpNext;
		tmpNext->previous = tmpPrev;

		// On rajoute item apres itemDest
		tmpNext = itemDest->next;
		itemDest->next = item;
		tmpNext->previous = item;
		item->previous = itemDest;
		item->next = tmpNext;


	}else{
		retour = -1;
	}

	return retour;
}