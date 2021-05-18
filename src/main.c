#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "main.h"
#include "functions.h"
#include "generator.h"

int main(void){
	srand(time(NULL));
	printf("Hello world\n");

	DoubleLinkedList *list;
	DoubleLinkedListElem *maillon;

	list = newDoubleLinkedList();

	maillon = newDoubleLinkedListItem(10);
	insertItemAtDoubleLinkedListTail(list, maillon);

	displayDoubleList(list);
	printf("\n");

	int tab[100];

	newMap(tab, 10);
	displayMap(tab, 10);

	return 0;
}


