#include "solver.h"

int checkGrid(Game *picross, int *tab, int *pos) {
  if (pos[0] > picross->size || pos[1] > picross->size) { // If pos is out of bounds
    return -1;
  }
  
  // si la case est noire, on peut admettre que la taille soit inferieur ou égale
  // vérifie la ligne
  // vérifie la cohérence de la ligne si on est en bout de ligne
  if (pos[1] == (picross->size - 1)) {
    int *tabTmp = malloc(sizeof(int) * picross->size);
    int *hintTmp = malloc(sizeof(int) * picross->size);
    int i;
    
    for (i = 0; i < picross->size; i++) {
      tabTmp[i] = tab[pos[0] * picross->size + i];
    }
    countLine(tabTmp, hintTmp, picross->size);
    for (i = 0; i < picross->size; i++) {
      if (hintTmp[i] != picross->listX[pos[0]][i]) {
        return -2;
      }
    }
    free(tabTmp);
    free(hintTmp);
  }
  
  // get hints of pose
  int *tabHint = malloc(sizeof(int) * picross->size);
  countLine(tab, tabHint, picross->size);
  
  // vérifie si le nombre de groupe de nombre est inferieur ou égal
  int nb = 0;
  int nbEnCours = 0;
  int i;
  for (i = 0; i < picross->size; i++) {
    if (tabHint[i] != 0) {
      nbEnCours++;
    }
  }
  for (i = 0; i < picross->size; i++) {
    if (picross->listX[pos[0]][i] != 0) {
      nb++;
    }
  }
  if (nbEnCours > nb) {
    return -4;
  }
  free(tabHint);
  
  // vérifie le nombre de 1 dans le groupe actuel
  if (tab[pos[0] * picross->size + pos[1]] == 1) { 
    int i;
    int paquet = 0;
    int position = pos[0] * picross->size + pos[1];
    int existe = -5;
    while (position > -1 && tab[position] == 1) { // On compte le nombre de 1 à gauche
      paquet++;
      position -= 1;
    }
    for (i = 0; i < picross->size; i++) {
      if (picross->listX[pos[0]][i] >= paquet) {
        existe = 1;
      }
    }
    if (existe == -5) {
      return existe;
    }
  }
  
	// vérifie la colonne
  int *tabTmp = malloc(sizeof(int) * picross->size);
  int *hintTmp = malloc(sizeof(int) * picross->size);
  for (i = 0; i < picross->size; i++){
    tabTmp[i] = tab[pos[1] + i * picross->size];
  }
  countLine(tabTmp, hintTmp, picross->size);
  nb = 0;
  nbEnCours = 0;
  for (i = 0; i < picross->size; i++) {
    if (hintTmp[i] != 0) {
      nbEnCours++;
    }
  }
  for (i = 0; i < picross->size; i++) {
    if (picross->listY[pos[1]][i] != 0) {
      nb++;
    }
  }
  if (nbEnCours > nb) {
    return -6;
  }
  free(tabHint);
  free(hintTmp);
  return 0;
}