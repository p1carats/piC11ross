#include "solver.h"

static long long boucle = 0;
static int nombreDeSolutions = 0;

int checkGrid(Game *picross, int pos, int *line, int *hint) {
  boucle++;
  if (pos >= picross->size * picross->size) {
    printf("\n-1\n");
    return -1; // if pos is out of bounds
  }

  int posX = pos % picross->size;
  int posY = (int) pos / picross->size;

  //printf("X : %d Y : %d\n", posX, posY);

  // On check la ligne

  int i;
  int nombreDePaquet = 0;
  int nombreActuel = 0;

  // On récupére la ligne en cours
  for (i = 0; i < picross->size; i++){
    line[i] = picross->map[posY * picross->size + i];
  }

  // On récupére les indices de la ligne en cours
  countLine(line, hint, picross->size);

  // On recupére le nombre de paquet de 1 sur la ligne actuellement
  for (i = 0; i < picross->size; i++){
    if (hint[i] != 0){
      nombreActuel++;
    }
  }

  //printf("%d %d %d => %d\n", hint[0], hint[1], hint[2], nombreActuel);

  // On recupére le nombre de paquet de 1 sur la ligne
  for (i = 0; i < picross->size; i++){
    if (picross->listX[posY][i] != 0){
      nombreDePaquet++;
    }
  }

  // On verifie que les deux concordes
  if (hint[nombreActuel] > picross->listX[posY][nombreActuel]){
    //printf("\n-2\n");
    return -2;
  }

  // On verifie que la ligne fasse la bonne taille
  if (posX == picross->size - 1) {
    for (i = 0; i < picross->size; i++) {
      //printf("hint[%d] : %d picross->listX[%d][%d] : %d\n", i, hint[i], picross->listX[posY][i], posY, i);
      if (hint[i] != picross->listX[posY][i]) {
        //printf("-4\n");
        return -4;
      }
    }
  }


  // On check la colonne
  nombreActuel = 0;
  nombreDePaquet = 0;

  // On récupére la colonne en cours
  for (i = 0; i < picross->size; i++){
    line[i] = picross->map[i * picross->size + posX];
    hint[i] = 0;
  }

  // On récupére les indices de la ligne en cours
  countLine(line, hint, picross->size);

  // On recupére le nombre de paquet de 1 sur la ligne actuellement
  for (i = 0; i < picross->size; i++){
    if (hint[i] != 0){
      nombreActuel += hint[i];
    }
  }

  // On recupére le nombre de paquet de 1 sur la ligne
  for (i = 0; i < picross->size; i++){
    if (picross->listY[posX][i] != 0){
      nombreDePaquet += picross->listY[posX][i];
    }
  }

  //printf("nombreActuel : %d, nombreDePaquet : %d\n", nombreActuel, nombreDePaquet);

  // On verifie que les deux concordes
  for (i = 0; i < picross->size; i++){
    if (nombreActuel > nombreDePaquet){
      //printf("\n-3\n");
      return -3;
    }
  }

  // On verifie que la ligne fasse la bonne taille
  if (posY == picross->size - 1) {
    for (i = 0; i < picross->size; i++) {
      //printf("hint : %d picross : %d\n",hint[i], picross->listY[posX][i]);
      if (hint[i] != picross->listY[posX][i]) {
        //printf("-5\n");
        return -5;
      }
    }
  }

  //printf("0\n");
  return 0;
}

int solver (Game *picross, int pos, int *line, int *hint) { // Il faut stocker la solution quelque part
  if (pos == picross->size * picross->size) {
    // when a solution is found
    if (checkGrid(picross, pos - 1, line, hint) == 0) {
      printf("\nSolution Trouvée\n");
      showMap(picross);
      printf("boucle : %lld\n", boucle);
      nombreDeSolutions++;
    }
  } else {
    // recursive calls
    if (pos == 0) {
      if (checkGrid(picross, pos, line, hint) == 0) {
        picross->map[pos] = 1;
        solver(picross, pos + 1, line, hint);
        picross->map[pos] = 0;
        solver(picross, pos + 1, line, hint);
      }
    } else if (checkGrid(picross, pos - 1, line, hint) == 0) {
      picross->map[pos] = 1;
      solver(picross, pos + 1, line, hint);
      picross->map[pos] = 0;
      solver(picross, pos + 1, line, hint);
    }
  }
  return nombreDeSolutions;
}