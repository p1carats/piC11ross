#include "generator.h"

// creates a new Game structure with 4 arguments : size, map, listX and listY
Game* newGame(int size, int *map, int **listX, int **listY) {
  Game *picross = (Game*) malloc(sizeof(Game));
  if (picross != NULL) {
    picross->size = size;
    picross->map = map;
    picross->listX = listX;
    picross->listY = listY;
    for(int i = 0; i < picross->size; i++) {
      picross->listX[i] = malloc(sizeof(int) * picross->size);
      picross->listY[i] = malloc(sizeof(int) * picross->size);
      if (picross->listX[i] == NULL || picross->listY[i] == NULL) {
        return NULL;
      }
    }
    return picross;
  } else {
    return NULL;
  }
}

// creates a new map, takes as arguments an empty tab and its dimension
int newMap(Game *picross) {
  int size = picross->size;
  for (int i = 0; i < size * size; i++) {
    int alea = rand() % 10;
    if (alea > 3) { // 2 out of 3 odds
      picross->map[i] = 1;
    } else {
      picross->map[i] = 0;
    }
  }
  return 0;
}

// displays a map, takes as arguments a tab and its dimension
int displayMap(Game *picross) {
  int size = picross->size;
  for (int i = 0; i < size * size; i++) {
    if (i % size == 0 && i != 0) {
      printf("\n");
    }
    if (picross->map[i] == 1) {
      printf("#");
    } else {
      printf("-");
    }
  }
  printf("\n");
  return 0;
}

// returns a tab with the number of "package", takes as argument two tabs (both having the same dimension)
int countLine(int *tab, int *retour, int size) {
  int index = 0;
  int tabIndex = 0;
  
  for (int i = 0; i < size; i++) {
    retour[i] = 0;
  }
  
  for (int i = 0; i < size; i++) {
    if (tab[i] == 1) {
      index++;
    } else if (index > 0) { // only if tab[i] == 0 and index > 0
      retour[tabIndex] = index;
      tabIndex++;
      index = 0;
    }
  }
  if (index > 0 && tab[size - 1] == 1) {
    retour[tabIndex] = index;
  }
  return 0;
}

// assign to listX and listY their values
int getHint(Game *picross) {
  int *tabTmp = malloc(sizeof(int) * picross->size);
  int *tabReturn =  malloc(sizeof(int) * picross->size);
  if (tabTmp == NULL || tabReturn == NULL) {
    return -1;
  }
  for (int i = 0; i < picross->size; i++) {
    int j;
    *tabReturn = 0;
    *tabTmp = 0;
    for (j = 0; j < picross->size; j++) {
      tabTmp[j] = picross->map[j + i * picross->size];
    }
    countLine(tabTmp, tabReturn, picross->size);
    for(j = 0; j < picross->size; j++) {
      picross->listX[i][j] = tabReturn[j];
    }
  }
  for (int i = 0; i < picross->size; i++) {
    int j = 0;
    for (j = 0; j < picross->size; j++) {
      tabTmp[j] = picross->map[j * picross->size + i];
    }
    countLine(tabTmp, tabReturn, picross->size);
    for (j = 0; j < picross->size; j++) {
      picross->listY[i][j] = tabReturn[j];
    }
  }
  free(tabTmp);
  free(tabReturn);
  return 0;
}

// show values of listX and listY (for debugging)
int showHint(Game *picross) {
  if (picross == NULL) {
    return -1;
  }
    printf("Liste X : \n");
  for (int i = 0; i < picross->size; i++) {
    for (int j = 0; j < picross->size; j++) {
        printf("%d ", picross->listX[i][j]);
        if (j == picross->size - 1) printf("\n");
    }
  }
    printf("\nListe Y : \n");
  for (int i = 0; i < picross->size; i++) {
    for (int j = 0; j < picross->size; j++) {
        printf("%d ", picross->listY[i][j]);
        if (j == picross->size - 1) printf("\n");
    }
  }
    printf("\n");
  return 0;
}

int createFile(Game *picross, char name[16]) {
  FILE *file;
  char buffer[16] = {0};
  file = fopen(name, "w");
  int i,j;
  
  // write the size
  sprintf(buffer, "%d", picross->size);
  fputs(buffer, file);
  fputs(";", file);
  fputs(buffer, file);
  fputs("\n", file);
  
  // write listX
  for (i = 0; i < picross->size; i++) {
    for (j = 0; j < picross->size; j++) {
      if (picross->listX[i][j] != 0 || j == 0) {
        sprintf(buffer, "%d", picross->listX[i][j]);
        fputs(buffer, file);
      }
      if (j + 1 < picross->size) {
        if (picross->listX[i][j+1]) {
          fputs(",", file);
        }
      }
    }
    if (i < picross->size - 1) {
      fputs(";", file);
    }
  }
  fputs("\n", file);
  
  // write listY
  for (i = 0; i < picross->size; i++) {
    for (j = 0; j < picross->size; j++) {
      if (picross->listY[i][j] != 0 || j == 0) {
        sprintf(buffer, "%d", picross->listY[i][j]);
        fputs(buffer, file);
      }
      if (j + 1 < picross->size) {
        if (picross->listY[i][j+1]) {
          fputs(",", file);
        }
      }
    }
    if (i < picross->size - 1) {
      fputs(";", file);
    }
  }
  fputs("\n", file);
  
  // write the map
  for (i = 0; i < picross->size; i++) {
    for (j = 0; j < picross->size; j++) {
      sprintf(buffer, "%d", picross->map[i * picross->size + j]);
      fputs(buffer, file);
    }
  }
  fclose(file);
  return 0;
}

int readFile(Game *picross, char *name) { // can't read maps larger than 30*30 (hard-limit)
  FILE *file;
  char buffer[1000] = {0};
  file = fopen(name, "r");
  int i = 0;
  int size;
  
  // size reading
  fscanf(file, "%s", buffer);
  char nb[2] = {0};
  
  while(buffer[i] != ';') {
    nb[i] = buffer[i];
    i++;
  }
  sscanf(nb, "%d", &size);
  picross->size = size;
  
  if (picross->size > 30) { // if the map is too large
    picross->size = 0;
    picross->listX = NULL;
    picross->listY = NULL;
    picross->map = 0;
    return -1;
  }
  
  char **array = malloc(sizeof(char*) * size);
  
  for (int p = 0; p < size; p++) {
    array[p] = malloc(sizeof(char) * size * size);
  }
  
  // read listX
  fscanf(file, "%s", buffer);
  convertCharToArray(buffer, ';', array, size);
  convertArrayToInt(array, ',', picross->listX, size);
  
  // read listY
  fscanf(file, "%s", buffer);
  convertCharToArray(buffer, ';', array, size);
  convertArrayToInt(array, ',', picross->listY, size);
  
  // read map
  fscanf(file, "%s", buffer);
  convertCharToArray(buffer, ';', array, size*size);
  
  for(i = 0; i < size * size; i++) {
    if (array[0][i] == 48) {
      picross->map[i] = 0;
    } else if (array[0][i] == 49) {
      picross->map[i] = 1;
    }
  }
  
  for (i = 0; i < size; i++){
    free(array[i]);
  }
  free(array);
  fclose(file);
  return 0;
}

int convertCharToArray(char *buffer, char separator, char **array, int size) {
  int i = 0;
  int j;
  int index = 0;
  char *elem = malloc(sizeof(char) * size);
  while (buffer[i] != '\0' && index < 4) {
    for (j = 0; j < size; j++) {
      elem[j] = 0;
    }
    
    int p = 0;
    while (buffer[i] != separator && buffer[i] != '\0') {
      elem[p] = buffer[i];
      p++;
      i++;
    }
    
    for (j = 0; j < size; j++) {
      printf("index : %d, j : %d\n", index, j);
      array[index][j] = elem[j];
    }
    
    index++;
    i++;
  }
  free(elem);
  return 0;
}

int convertArrayToInt(char **array, char separator, int **retour, int size) {
  char *buffer = malloc(sizeof(char) * size);
  
  int i;
  int j;
  
  // loop for each table
  for (i = 0; i < size; i++) {
    // recovering the line as "3,2,1"
    for (j = 0; j < size; j++) {
      buffer[j] = array[i][j];
    }
    
    int index = 0;
    j = 0;
    int p = 0;
    char *nb = malloc(sizeof(char) * size * size);
    
    // transformation of the line to int
    while (buffer[j] != '\0') {
      for (int q = 0; q < size*size; q++) {
        nb[q] = 0;
      }
      while (buffer[j] != separator && buffer[j] != '\0') {
        nb[index] = buffer[j];
        index++;
        j++;
      }
      sscanf(nb, "%d", &retour[i][p]);
      p++;
      if (j < size - 1) j++;
    }
  }
  free(buffer);
  return 0;
}

int checkHint(Game *picross) {
  int retour = 0;
  int *tabTmp = malloc(sizeof(int) * picross->size);
  int *hintTmp = malloc(sizeof(int) * picross->size);
  
  for (int i = 0; i < picross->size; i++) {
    int j;
    for (j = 0; j < picross->size; j++) { // for X
      tabTmp[j] = picross->map[i * picross->size + j];
    }
    
    countLine(tabTmp, hintTmp, picross->size);
    
    for (j = 0; j < picross->size; j++) {
      if (hintTmp[j] != picross->listX[i][j]) {
        retour = -1;
      }
    }
    
    for (j = 0; j < picross->size; j++) { // for Y
      tabTmp[j] = picross->map[picross->size * j + i];
    }
    
    countLine(tabTmp, hintTmp, picross->size);
    
    for (j = 0; j < picross->size; j++) {
      if (hintTmp[j] != picross->listY[i][j]) {
        retour = -1;
      }
    }
  }
  free(tabTmp);
  free(hintTmp);
  return retour;
}