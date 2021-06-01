#include "main.h"

int main(void) {
  srand(time(NULL));
  
  int size = 5;
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