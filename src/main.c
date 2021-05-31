#include "main.h"

int main(void) {
    srand(time(NULL));

    int size = 5;
    int *tab = malloc(sizeof(int) * size * size);
    int **listX = malloc(sizeof(int*) * size);
    int **listY = malloc(sizeof(int*) * size);

    char **test = malloc(sizeof(char*) * 10);
    int **valeur = malloc(sizeof(int*) * 10);

    for (int p = 0; p < 10; p++) {
        test[p] = malloc(sizeof(char) * 10);
        valeur[p] = malloc(sizeof(int) * 10);
    }

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
    displayMap(picross);
    printf("\n%d\n", checkHint(picross));
    printf("")
    free(tab);

    for (int i = 0; i < size; i++) {
        free(listX[i]);
        free(listY[i]);
        free(valeur[i]);
        free(test[i]);
    }
    free(listX);
    free(listY);
    free(valeur);
    free(test);
    free(picross);
    return 0;
}