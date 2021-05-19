#include "main.h"



int main(void){
	srand(time(NULL));

	int tab[100];

	newMap(tab, 10);
	displayMap(tab, 10);

	DoubleLinkedList *ListX;
	DoubleLinkedList *ListY;

	ListY = newDoubleLinkedList();
	ListX = newDoubleLinkedList();

	getHint(tab, 10, ListX, ListY);

	printf("\nLine :\n");

	displayDoubleList(ListX, 10);
	printf("Column :\n");
	displayDoubleList(ListY, 10);
	return 0;
}


void test(void){
	DoubleLinkedList *list;
	DoubleLinkedListElem *maillon;
	DoubleLinkedListElem *maillon2;

	list = newDoubleLinkedList();
	int tab2[10];
	int tab1[10] = {0};
	int tab3[10];

	for (int i = 0; i < 10; i++){
		tab2[i] = i;
	}

	maillon = newDoubleLinkedListItem(tab1, 10);
	maillon2 = newDoubleLinkedListItem(tab2, 10);

	insertItemAtDoubleLinkedListTail(list, maillon);
	insertItemAtDoubleLinkedListTail(list, maillon2);
	displayDoubleList(list, 10);
	getValueOfDoubleLinkedListItem(maillon2, tab3, 10);

	for (int h = 0; h < 10; h++){
		printf("%d ", tab3[h]);
	}

	printf("\n");

}