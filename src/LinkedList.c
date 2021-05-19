#include "LinkedList.h"

// creates a new double linked list and return a pointer
DoubleLinkedList *newDoubleLinkedList() {
	DoubleLinkedList *liste = (DoubleLinkedList*) malloc(sizeof(DoubleLinkedList));
	if (liste != NULL) {
		liste->size = 0;
		liste->head = NULL;
		liste->tail = NULL;
		return liste;
	} else {
		return NULL;
	}
}

// creates a double linked list and copy its values into tab
DoubleLinkedListElem *newDoubleLinkedListItem(int *value, int taille){
	DoubleLinkedListElem *maillon = (DoubleLinkedListElem*) malloc(sizeof(DoubleLinkedListElem));
	if (maillon != NULL) {
		maillon->tab = malloc(sizeof(int) * taille);
		for (int i = 0; i < taille; i++) {
			maillon->tab[i] = value[i];
		}
		maillon->next = NULL;
		maillon->previous = NULL;
		return maillon;
	} else {
		return NULL;
	}
}

// shows the previous double linked list
int displayDoubleList(DoubleLinkedList *liste, int size) {
	DoubleLinkedListElem *elem;
	elem = liste->head;
	int retour = 0; // everything's fine
	if (liste != NULL) {
		for (int i = 0; i < liste->size; i++) {
			printf("%d) ", i);
			for (int j = 0; j < size; j++) {
				if (elem->tab[j] != 0) {
					printf("%d ", elem->tab[j]);
				}
			}
			elem = elem->next;
			printf("\n");
		}
		retour = 0;
	} else {
		retour = -1; // error
	}
	return retour;
}

// Function which insert a element into a double linked list
int insertItemAtDoubleLinkedListTail(DoubleLinkedList *liste, DoubleLinkedListElem *newItem) {
	int retour = 0; // everything's fine
	if (liste != NULL && newItem != NULL) { // if the two elements exists
		if ((liste->tail == NULL && liste->head == NULL) || liste->size == 0) { // if the list's empty
			liste->size = 1;
			liste->head = newItem;
			liste->tail = newItem;
			newItem->previous = NULL;
			newItem->next = NULL;
		} else { // if the list isn't empty = if it already contains an item
			newItem->previous = liste->tail;
			newItem->next = NULL;
			liste->size += 1;
			liste->tail->next = newItem; // the second last one takes the last one in ->next
			liste->tail = newItem;
		}
		retour = 0;
	} else {
		retour = -1; // error
	}
	return retour;
}

// returns the tab stored on an element
int getValueOfDoubleLinkedListItem(DoubleLinkedListElem *item, int *valeur, int taille) {
	for (int i = 0; i < taille; i++) {
		valeur[i] = item->tab[i];
	}
	return 0;
}