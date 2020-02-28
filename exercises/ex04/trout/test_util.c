/*

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "util.h"
// #include "util.c"

#include "test_util.h"

int tests_run = 0;

static char *test1() {
  struct timeval out;
  struct timeval in;
  out.tv_usec = 1;
  out.tv_sec = 2;
  in.tv_usec = 3;
  in.tv_sec = 4;
  tv_sub(&out, &in);
  char *message = "test1 failed: tv_sub should return 999998";
  mu_assert(message, out.tv_usec == 999998);
  return 0;
}

static char *test2() {
  struct timeval out;
  struct timeval in;
  out.tv_usec = 8901;
  out.tv_sec = 12;
  in.tv_usec = 433;
  in.tv_sec = 490;
  tv_sub(&out, &in);
  char *message = "test2 failed: tv_sub should return 8468";
  mu_assert(message, out.tv_usec == 8468);
  return 0;
}


static char * all_tests() {
    mu_run_test(test1);
    mu_run_test(test2);
    return NULL;
}

int main(int argc, char **argv) {
    char *result = all_tests();
    if (result != NULL) {
        printf("%s\n", result);
    } else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}
