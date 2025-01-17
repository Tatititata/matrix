#include "tests.h"
#include <check.h>

START_TEST(test_comp_0) {

  // for (int i = 0; i < 10; i++) {
  matrix_t mat, C, M, E;

  int rows = 1 + rand() % 10;

  int return_value = s21_create_matrix(rows, rows, &mat);

  if (return_value == 0) {
    fill_matrix(&mat);
    printf("-----------Matrix 1-----------\n");
    print_matrix(&mat);
    printf("\n");
    return_value = s21_inverse_matrix(&mat, &C);
    if (return_value == 0) {
      printf("----------Inversed----------\n");
      print_matrix(&C);
      printf("\n");

      return_value = s21_mult_matrix(&mat, &C, &M);
      if (return_value == 0) {
        printf("-------Multiplication-------\n");
        print_matrix(&M);
        printf("\n");
        return_value = s21_create_matrix(rows, rows, &E);
        if (return_value == 0) {
          for (int i = 0; i < rows; i++)
            E.matrix[i][i] = 1.;
          printf("-------------E-------------\n");
          print_matrix(&E);
          printf("\n");
          ck_assert_int_eq(s21_eq_matrix(&M, &E), 1);
          s21_remove_matrix(&E);
        }

        s21_remove_matrix(&M);
      }

      s21_remove_matrix(&C);
    }

    s21_remove_matrix(&mat);
  }
  // }
}
END_TEST

Suite *comp() {
  Suite *s = suite_create("s21_complement tests");
  TCase *tc_core = tcase_create("Complement");
  tcase_add_test(tc_core, test_comp_0);
  // tcase_add_test(tc_core, test_det_1);
  // tcase_add_test(tc_core, test_det_2);
  // tcase_add_test(tc_core, test_det_3);
  // tcase_add_test(tc_core, test_det_4);
  suite_add_tcase(s, tc_core);
  return s;
}