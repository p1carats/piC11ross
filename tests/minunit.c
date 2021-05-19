#include <stdio.h>
#include "minunit.h"

#include "check_draft.h"
 
int tests_run = 0;

static char * all_tests() {
  mu_run_test(test_foo);
  mu_run_test(test_bar);
  return 0;
}
 
int main(int argc, char **argv) {
  char *result = all_tests();
  if (result != 0) {
    printf("%s\n", result);
  } else {
    printf("All tests passed!\n");
  }
  printf("Tests run: %d\n", tests_run);
  return result != 0;
}