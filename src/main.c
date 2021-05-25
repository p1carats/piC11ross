#include "main.h"

int main(void){
	srand(time(NULL));

	int taille = 5;
	int *tab = malloc(sizeof(int) * taille * taille);
	int **listX = malloc(sizeof(int*) * taille);
	int **listY = malloc(sizeof(int*) * taille);

	Jeu *jeu;
	jeu = newJeu(taille, tab, listX, listY);

	newMap(jeu);
	displayMap(jeu);

	getHint(jeu);
	showHint(jeu);
	createFile(jeu, "bite.txt");

	int *tableau = malloc(sizeof(int) * jeu->size * jeu->size);
	int *pos = malloc(sizeof(int) * 2);

	for (int i = 0; i < jeu->size; i++){
		tableau[i] = jeu->map[i];
		if (i % 5 == 3){
			if (tableau[i] == 1) {
				tableau[i] = 0;
			}else{
				tableau[i] = 1;
			}
		}
	}

	pos[0] = 0;
	pos[1] = 3;
	printf("\n%d\n", checkGrid(jeu, tableau, pos));

	return 0;
}