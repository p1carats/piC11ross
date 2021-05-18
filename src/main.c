#include <stdlib.h>
#include <stdio.h>
#include "main.h"

int main(void){
	printf("Hello word\n");
	return 0;
}

DListNode* newMaillon (void) {

	DListNode* maillon = (DListNode*)malloc(sizeof(*maillon));
	if (maillon == NULL) {
		return NULL;
	}

	maillon->(*tab) = { 0 };
	maillon->next = NULL;
	maillon->back = NULL;

	return maillon;
}