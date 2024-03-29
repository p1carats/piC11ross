#include <stdio.h>
#include <stdlib.h>

typedef struct picross {
  int size;
  int *map;
  int **listX;
  int **listY;
} Game;

Game* newGame(int size, int *map, int **listX, int **listY);

int newMap(Game *picross);
int showMap(Game *picross);
int countLine(int *tab, int *retour, int size);
int getHint(Game *picross);
int showHint(Game *picross);
int createFile(Game *picross, char *name);
int getSize(char *name, int *size);
int readFile(Game *picross, char* name);
int readMap(char *buffer, int *out, int size);
int convertCharToArray(char *buffer, char separator, char **array, int size);
int convertArrayToInt(char **array, char separator, int **retour, int size);
int checkHint(Game *picross);