// Use valgrind
#include "main.h"

int main(void){
	srand(time(NULL));

	int taille = 5;
	int *tab = malloc(sizeof(int) * taille * taille);
	int **listX = malloc(sizeof(int*) * taille);
	int **listY = malloc(sizeof(int*) * taille);

	char **test = malloc(sizeof(char*) * 5);

	for (int p = 0; p < 5; p++){
		test[p] = malloc(sizeof(char) * 50);
	}

	Jeu *jeu;
	jeu = newJeu(taille, tab, listX, listY);

	newMap(jeu);
	displayMap(jeu);

	getHint(jeu);
	showHint(jeu);
	createFile(jeu, "db.txt");

	int *tableau = malloc(sizeof(int) * jeu->size * jeu->size);
	int *pos = malloc(sizeof(int) * 2);

	for (int i = 0; i < jeu->size * jeu->size; i++) {
		tableau[i] = 0;
	}

	tableau[0] = 1;
	tableau[1] = 1;
	tableau[2] = 1;
	tableau[3] = 1;

	pos[0] = 0;
	pos[1] = 3;
	//printf("\n%d\n", checkGrid(jeu, tableau, pos));

	printf("\n");

	readFile(jeu, "db.txt");

	char buffer[250] = {"2,2,2;4,2;1;1;4"};

	convertCharToArray(buffer, ';', test);

	printf("ici : %s\n", test[0]);
	printf("ici : %s\n", test[1]);
	printf("ici : %s\n", test[2]);
	printf("ici : %s\n", test[3]);
	printf("ici : %s\n", test[4]);


	return 0;
}