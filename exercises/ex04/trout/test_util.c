#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "util.h"
#include "minunit.h"

int tests_run = 0;
static char *test() {
  char* res = icmpcode_v4(0);
  char *message = "test failed";
  mu_assert(message, 0 == strcmp(res,"network unreachable"));
  res = icmpcode_v4(6);
  mu_assert(message, 0 == strcmp(res, "destination network unknown"));
    return NULL;
}

static char * all_tests() {
    mu_run_test(test);
    return NULL;
}

int main(int argc, char **argv) {
    char *result = all_tests();
    if (result != NULL) {
        printf("%s\n", result);
    } else {
        printf("ALL TESTS PASSED\n");
    }

    return result != 0;
}
