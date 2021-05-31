#include "solver.h"

int checkGrid(Game *picross, int *tab, int pos) {
  if (pos >= picross->size * picross->size) {
    return -1; // if pos is out of bounds
  }

  int posX = pos % picross->size;
  int posY = (int) pos / picross->size;

  printf("X : %d Y : %d\n", posX, posY);
  // checks lines + consistency of the line if we are at the end of the line
  // if the square is black, the size can be assumed to be less than or equal to
  if (pos == (picross->size * picross->size) - 1) {
    int *tabTmp = malloc(sizeof(int) * picross->size);
    int *hintTmp = malloc(sizeof(int) * picross->size);
    int i;
    
    for (i = 0; i < picross->size; i++) {
      tabTmp[i] = tab[posX * picross->size + i];
    }
    countLine(tabTmp, hintTmp, picross->size);
    for (i = 0; i < picross->size; i++) {
      if (hintTmp[i] != picross->listX[posX][i]) {
        printf("hintTmp : %d", hintTmp[i]);
        return -2;
      }
    }
    free(tabTmp);
    free(hintTmp);
  }
  
  // get hints of pose
  int *tabHint = malloc(sizeof(int) * picross->size);
  countLine(tab, tabHint, picross->size);
  
  // check whether the number of number groups is less than or equal to
  int nb = 0;
  int nbEnCours = 0;
  int i;
  for (i = 0; i < picross->size; i++) {
    if (tabHint[i] != 0) {
      nbEnCours++;
    }
  }
  for (i = 0; i < picross->size; i++) {
    if (picross->listX[posX][i] != 0) {
      nb++;
    }
  }
  if (nbEnCours > nb) {
    return -4;
  }
  free(tabHint);
  
  // checks the number of 1's in the current group
  if (tab[posX * picross->size + posY] == 1) {
    int i;
    int paquet = 0;
    int position = posX * picross->size + posY;
    int existe = -5;
    while (position > -1 && tab[position] == 1) { // count the number from 1 to the left
      paquet++;
      position -= 1;
    }
    for (i = 0; i < picross->size; i++) {
      if (picross->listX[posX][i] >= paquet) {
        existe = 1;
      }
    }
    if (existe == -5) {
      return existe;
    }
  }
  
	// check the column
  int *tabTmp = malloc(sizeof(int) * picross->size);
  int *hintTmp = malloc(sizeof(int) * picross->size);
  for (i = 0; i < picross->size; i++){
    tabTmp[i] = tab[posY + i * picross->size];
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
    if (picross->listY[posY][i] != 0) {
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

int solver (Game *picross, int pos){
  if (checkGrid(picross, picross->map, pos) == 0){ // If all is okey
    pos++;
    picross->map[pos] = 1;
  }else{ // else
    if (picross->map[pos] == 0){
      picross->map[pos] = 1;
    }else{
      picross->map[pos] = 0;
    }
  }

  if (pos < picross->size * picross->size - 1) solver(picross, pos);

  return 0;
}