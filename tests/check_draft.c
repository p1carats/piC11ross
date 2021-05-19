// boilerplate
int foo = 7;
int bar = 5;
 
static char * test_foo() {
  mu_assert("error, foo != 7", foo == 7);
  return 0;
}
 
static char * test_bar() {
  mu_assert("error, bar != 5", bar == 5);
  return 0;
}