#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "main.h"


int main(void){
	srand(time(NULL));

	int tab[100];

	newMap(tab, 10);
	displayMap(tab, 10);

	return 0;
}


