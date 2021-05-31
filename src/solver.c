#include "solver.h"

int checkGrid(Game *picross, int *tab, int *pos) {
    if (pos[0] > picross->size || pos[1] > picross->size) {
        return -1; // if pos is out of bounds
    }

    // checks lines + consistency of the line if we are at the end of the line
    // if the square is black, the size can be assumed to be less than or equal to
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
        if (picross->listX[pos[0]][i] != 0) {
            nb++;
        }
    }
    if (nbEnCours > nb) {
        return -4;
    }
    free(tabHint);

    // checks the number of 1's in the current group
    if (tab[pos[0] * picross->size + pos[1]] == 1) {
        int i;
        int paquet = 0;
        int position = pos[0] * picross->size + pos[1];
        int existe = -5;
        while (position > -1 && tab[position] == 1) { // count the number from 1 to the left
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

    // check the column
    int *tabTmp = malloc(sizeof(int) * picross->size);
    int *hintTmp = malloc(sizeof(int) * picross->size);
    for (i = 0; i < picross->size; i++) {
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