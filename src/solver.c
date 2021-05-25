#include "solver.h"

int checkGrid(Jeu *jeu, int *tab, int *pos){
	if (pos[0] > jeu->size || pos[1] > jeu->size){ // If pos is out of bounds
		return -1;
	}

	if (pos[0] == (jeu->size - 1) && (pos[1] == (jeu->size - 1))){ // If pos is at the end
		for (int i = 0; i < jeu->size; i++){
			if (jeu->map[i] != tab[i]){
				return -2;
			}
		}
	}

	// Verifie la ligne :

	// Verifie la cohérence de la ligne si on est en bout de ligne
	if (pos[1] == (jeu->size - 1)){

		int *tabTmp = malloc(sizeof(int) * jeu->size);
		int *hintTmp = malloc(sizeof(int) * jeu->size);
		int i;

		for (i = 0; i < jeu->size; i++){
			tabTmp[i] = tab[pos[0] * jeu->size + i];
		}

		countLine(tabTmp, hintTmp, jeu->size);

		for (i = 0; i < jeu->size; i++){
			if (hintTmp[i] != jeu->listX[pos[0]][i]){
				return -3;
			}
		}
	}

	// get hints of pose
	int *tabHint = malloc(sizeof(int) * jeu->size);
	countLine(tab, tabHint, jeu->size);

	// Verifie si le nombre de groupe de nombre est inferieur ou égal

	int nb = 0;
	int nbEnCours = 0;
	int i;

	for (i = 0; i < jeu->size; i++){
		if (tabHint[i] != 0) {
			nbEnCours++;
		}
	}

	for (i = 0; i < jeu->size; i++){
		if (jeu->listX[pos[0]][i] != 0) {
			nb++;
		}
	}

	if (nbEnCours > nb){
		return -4;
	}

	// Verifie le nombre de 1 dans le groupe actuel

	if (tab[pos[0] * jeu->size + pos[1]] == 1){
		int paquet = 0;
		int position = pos[0] * jeu->size + pos[1];
		int i;
		int existe = -5;

		while (position > -1 && tab[position] == 1){ // On compte le nombre de 1 à gauche
			paquet++;
			position -= 1;
		}

		for (i = 0; i < jeu->size; i++){
			if (jeu->listX[pos[0]][i] >= paquet){
				existe = 1;
			}
		}

		if (existe == -5) {
			return existe;
		}

	}

	// Verifie la colone :


	int *tabTmp = malloc(sizeof(int) * jeu->size);
	int *hintTmp = malloc(sizeof(int) * jeu->size);

	for (i = 0; i < jeu->size; i++){
		tabTmp[i] = tab[pos[1] + i * jeu->size];
	}

	countLine(tabTmp, hintTmp, jeu->size);

	nb = 0;
	nbEnCours = 0;

	for (i = 0; i < jeu->size; i++){
		if (hintTmp[i] != 0) {
			nbEnCours++;
		}
	}

	for (i = 0; i < jeu->size; i++){
		if (jeu->listY[pos[1]][i] != 0) {
			nb++;
		}
	}

	if (nbEnCours > nb){
		return -6;
	}



	return 0;
}
