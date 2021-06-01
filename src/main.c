#include "main.h"

int main(int argc, char *argv[]) {
  srand(time(NULL));

  int size, arg = 0; // grid size, both algorithmically and given
  char filename; // filename (will be defined later)

  if (argc == 2) {
    // minimal set of args required to make the program works
    sscanf(argv[1], "%d", &arg);
    if (arg != 10 && arg != 15 && arg!= 20) {
      printf("Incorrect given argument!\n");
      return 1;
    } else {
      size = arg;
    }
    // set default filename
    filename = "picross.txt";
  } else if (argc >= 3 && argc <= 6) {
    // case where user launched the program while specifying both size of the grid and some other arg
    // first stage: parsing grid size, same code as above
    sscanf(argv[1], "%d", &arg);
    if (arg != 10 && arg != 15 && arg!= 20) {
      printf("Incorrect given argument!\n");
      return 1;
    } else {
      size = arg;
    }
    // second stage: finding which arg has been given (yeah I like pain) // parsing file name
    char str;
    int i;
    for (int i = 1; i < argc; i++) {
      if (strcmp(argv[i], "-f") == 0) {
        if (i >= argc) {
          exit(1);
        }
        filename = argv[++i];
      } else if (strcmp(argv[i], "-h" && "--help") == 0) {
        printf("Picross v1.0.0-dev.1\nCopyright (c) 2021 Junia. All rights reserved.\n Usage:\n\n");
        printf("program.out <int> ; specify the size of the grid you want (choose between 10, 15, or 20)\n");
        printf("-f (or --file) <file> ; specify the name of the file you want (txt file only for the moment)\n");
        printf("-v (or --verbose) ; enable developer/debugging mode and prints almost everything\n");
        printf("-g (or --generate) ; generate a random grid without solving/testing it (at your own risk)");
        printf("-s (or --solve) ; solve a pre-generated grid (must have specified a file before)");
        printf("-h (or --help) ; prints this message!\n")
      } else if (strcmp(argv[i], "-v" && "--verbose") == 0) {
        printf("Debug mode enabled ")
      } else if (strcmp(argv[i], "-g" && "--generate") == 0) {
        // generate
      } else if (strcmp(argv[i], "-s" && "--solve") == 0) {
        // solve
      } else {
        char my_args[j++] = argv[i];
      }
    }
  } else {
    // something unexpected happened, most likely not enough args were given
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
  //showMap(picross);
  //showHint(picross);
  //printf("\n");
  //createFile(picross, filename);
  
  readFile(picross, filename);
  showHint(picross);
  //showMap(picross);
  //printf("\n%d\n", checkHint(picross));
  //printf("\n%d\n", checkGrid(picross, picross->map, 1));
  //printf("\n%d\n", solver(picross, 0));
  showMap(picross);
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