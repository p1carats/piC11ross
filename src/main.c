#include <stdlib.h>
#include <stdio.h>


typedef struct DListNode {
	int tab[10];
	struct DListNode* next;
	struct DListNode* previous;
}DListNode;


typedef struct DList {
	int length;
	struct DListNode* begin;
	struct DListNode* end; 
}DList;



int main() {
	printf("Hello word");
	return 0;
}