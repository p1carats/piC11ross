#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct DoubleLinkedListElem {
	int *tab;
	struct DoubleLinkedListElem *previous;
	struct DoubleLinkedListElem *next;
} DoubleLinkedListElem;

typedef struct DoubleLinkedList {
	DoubleLinkedListElem *head;
	int size; // no. of links
	DoubleLinkedListElem *tail;
} DoubleLinkedList;

DoubleLinkedList *newDoubleLinkedList();
DoubleLinkedListElem *newDoubleLinkedListItem(int *value, int taille);

int displayDoubleList(DoubleLinkedList *liste, int taille);
int insertItemAtDoubleLinkedListTail(DoubleLinkedList *liste, DoubleLinkedListElem *newItem);
int getValueOfDoubleLinkedListItem(DoubleLinkedListElem *item, int *valeur, int taille);