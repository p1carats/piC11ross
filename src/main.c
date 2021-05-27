// Use valgrind
#include "main.h"

int main(void){
	srand(time(NULL));

	int taille = 5;
	int *tab = malloc(sizeof(int) * taille * taille);
	int **listX = malloc(sizeof(int*) * taille);
	int **listY = malloc(sizeof(int*) * taille);

	char **test = malloc(sizeof(char*) * 10);
	int **valeur = malloc(sizeof(int*) * 10);

	for (int p = 0; p < 10; p++){
		test[p] = malloc(sizeof(char) * 10);
		valeur[p] = malloc(sizeof(int) * 10);
	}

	Jeu *jeu;
	jeu = newJeu(taille, tab, listX, listY);

	newMap(jeu);
	getHint(jeu);

	//displayMap(jeu);
	//showHint(jeu);

	//printf("\n");

	createFile(jeu, "db.txt");
	readFile(jeu, "db.txt");

	//char buffer[250] = {"2,2,2,3;4,2;1;1;4"};

	//convertCharToArray(buffer, ';', test, 10);
	//convertArrayToInt(test, ',', valeur, 10);

	//printf("ici : %d\n", valeur[0][9]);

	return 0;
}