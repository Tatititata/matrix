#include "tests.h"
#include <check.h>

START_TEST(test_eq_0) {

  matrix_t mat1, mat2;

  int rows = 2;
  int cols = 3;
  int return_value = s21_create_matrix(rows, cols, &mat1);

  if (!return_value) {

    return_value = s21_create_matrix(rows + 1, cols, &mat2);
    if (!return_value) {

      ck_assert_int_eq(s21_eq_matrix(&mat1, &mat2), 0);
      s21_remove_matrix(&mat2);
    }
    s21_remove_matrix(&mat1);
  }
}
END_TEST

Suite *equal() {
  Suite *s = suite_create("s21_equal tests");
  TCase *tc_core = tcase_create("Equal");
  tcase_add_test(tc_core, test_eq_0);
  suite_add_tcase(s, tc_core);
  return s;
}