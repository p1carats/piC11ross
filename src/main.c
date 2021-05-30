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

	//newMap(jeu);
	//getHint(jeu);

	//displayMap(jeu);
	//showHint(jeu);

	//printf("\n");

	//createFile(jeu, "db.txt");
	readFile(jeu, "db.txt");
    showHint(jeu);
    printf("%d\n", checkHint(jeu));


    free(tab);
    for (int i = 0; i < taille; i++){
        free(listX[i]);
        free(listY[i]);
        free(valeur[i]);
        free(test[i]);
    }

    free(listX);
    free(listY);
    free(valeur);
    free(test);
    free(jeu);

	return 0;
}