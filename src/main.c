#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#include "functions.h"

int main(void){
	printf("Hello word\n");

	DoubleLinkedList *list;
	DoubleLinkedListElem *maillon;

	list = newDoubleLinkedList();

	maillon = newDoubleLinkedListItem(10);
	insertItemAtDoubleLinkedListTail(list, maillon);

	displayDoubleList(list);
	printf("\n");

	return 0;
}

