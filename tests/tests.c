#include "tests.h"

void run_case(Suite(*test_case)) {
  SRunner *sr = srunner_create(test_case);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);
}

void run_tests() {
  Suite *suite_cases[] = {

      // create(),

      // sum(),

      // sub(),

      // equal(),

      // mult_num(),

      // mult(),

      // transpose(),

      // det(),

      comp(),

      NULL};

  for (Suite **test_case = suite_cases; *test_case != NULL; test_case++)
    run_case(*test_case);
}

int main() {
  srand(time(0));
  run_tests();
  return 0;
}
