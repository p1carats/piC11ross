#include "main.h"

int main(void){
	srand(time(NULL));

	int taille = 20;
	int *tab = malloc(sizeof(int) * taille * taille);
	newMap(tab, taille);
	displayMap(tab, taille);

	DoubleLinkedList *ListX;
	DoubleLinkedList *ListY;

	ListY = newDoubleLinkedList();
	ListX = newDoubleLinkedList();

	getHint(tab, taille, ListX, ListY);

	forPython(taille, ListX, ListY);

	return 0;
}

void test(void){
	DoubleLinkedList *list;
	DoubleLinkedListElem *link1;
	DoubleLinkedListElem *link2;

	list = newDoubleLinkedList();
	int tab2[10];
	int tab1[10] = {0};
	int tab3[10];

	for (int i = 0; i < 10; i++){
		tab2[i] = i;
	}

	link1 = newDoubleLinkedListItem(tab1, 10);
	link2 = newDoubleLinkedListItem(tab2, 10);

	insertItemAtDoubleLinkedListTail(list, link1);
	insertItemAtDoubleLinkedListTail(list, link2);
	displayDoubleList(list, 10);
	getValueOfDoubleLinkedListItem(link2, tab3, 10);

	for (int h = 0; h < 10; h++){
		printf("%d ", tab3[h]);
	}

	printf("\n");
}

void forPython(int taille, DoubleLinkedList *ListX, DoubleLinkedList *ListY){
	printf("'''%d\n", taille);
	printf("%d\n",taille);
	displayDoubleListForPython(ListY, taille);
	printf("\n");
	displayDoubleListForPython(ListX, taille);
	printf("'''\n");
}