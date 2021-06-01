#include "main.h"

int main(int argc, char *argv[]) {
  srand(time(NULL));

  int size, arg = 0;

  if (argc == 2) {
    sscanf(argv, "%d", &arg);
    if (arg != 10 || arg != 15 || arg!= 20) {
      printf("Incorrect given argument!\n");
      return 1;
    } else {
      size = arg;
    }
  } else if (argc > 2) {
    printf("Too many values given by user.\n");
    return 1;
  } else {
    printf("Single value expected.\n");
    return 1;
  }
  
  int *tab = malloc(sizeof(int) * size * size);
  int **listX = malloc(sizeof(int*) * size);
  int **listY = malloc(sizeof(int*) * size);

  Game *picross;
  picross = newGame(size, tab, listX, listY);
  
  //newMap(picross);
  //getHint(picross);
  //displayMap(picross);
  //showHint(picross);
  //printf("\n");
  //createFile(picross, "db.txt");
  
  readFile(picross, "db.txt");
  showHint(picross);
  //displayMap(picross);
  //printf("\n%d\n", checkHint(picross));
  //printf("\n%d\n", checkGrid(picross, picross->map, 1));
  //printf("\n%d\n", solver(picross, 0));
  displayMap(picross);
  free(tab);
  
  for (int i = 0; i < size; i++) {
    free(listX[i]);
    free(listY[i]);
  }
  free(listX);
  free(listY);
  free(picross);
  return 0;
}