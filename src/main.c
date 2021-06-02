#include "main.h"

int main(int argc, char *argv[]) {
  srand(time(NULL));

  int size, retour;

  if (argc != 3){
    printf("Menu d'aide :\n- Pour generer -g size\n- Pour resoudre -s name.txt\n");
    return -1;
  }else{
    if (argv[1][1] == 's'){
        printf("Solving ...\n");
        retour = solving(argv[2]);
      return retour;
    }else if (argv[1][1] == 'g'){
      size = atoi(argv[2]);
      if (size == 5 || size == 10 || size == 15 || size == 20) {
        printf("Creating ...\n");
        retour = generateur(size);
      }else{
        printf("ERREUR les tailles possibles sont 10, 15 et 20 !\nMenu d'aide :\n- Pour generer -g size\n- Pour resoudre -s name.txt\n");
        retour = -1;
      }
      return retour;
    }else{
      printf("ERREUR\nMenu d'aide :\n- Pour generer -g size\n- Pour resoudre -s name.txt\n");
      return -1;
    }
  }
}

int generateur(int size){

  int *tab = malloc(sizeof(int) * size * size);
  int **listX = malloc(sizeof(int*) * size);
  int **listY = malloc(sizeof(int*) * size);
  int retour = 0;

  Game *picross;
  picross = newGame(size, tab, listX, listY);

  retour = newMap(picross);
  retour = getHint(picross);
  retour = showMap(picross);
  retour = showHint(picross);
  retour = createFile(picross, "picross.txt");

  for (int i = 0; i < size; i++) {
    free(listX[i]);
    free(listY[i]);
  }
  free(tab);
  free(listX);
  free(listY);
  free(picross);

  return retour;

}

int solving(char *name) {

  int size, continuer = 0;
  Game *picross = NULL;
  int **listX = NULL;
  int **listY = NULL;
  int *tab = NULL;

  if (getSize(name, &size) != 0){
    continuer = -1;
  }else{

    tab = malloc(sizeof(int) * size * size);
    listX = malloc(sizeof(int *) * size);
    listY = malloc(sizeof(int *) * size);

    picross = newGame(size, tab, listX, listY);
  }

  if (continuer == 0) {
    if (readFile(picross, name) != 0) {
      printf("ERREUR NOM DU FICHIER !\n");
      continuer = -1;
    }
  }

  if (continuer == 0) {
    if (showHint(picross) != 0) {
      continuer = -1;
    }
  }

  if (continuer == 0) {

    for (int i = 0; i < picross->size * picross->size; i++){
      picross->map[i] = 0;
    }

    if (solver(picross, 0) != 0) {
      continuer = -1;
    }
  }

  if (continuer == 0) {
    for (int i = 0; i < size; i++) {
      free(listX[i]);
      free(listY[i]);
    }
    free(tab);
    free(listX);
    free(listY);
    free(picross);
  }

  return continuer;

}

