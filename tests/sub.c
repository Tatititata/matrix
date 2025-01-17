#include "tests.h"
#include <check.h>

START_TEST(test_sub_0) {

  matrix_t mat, res = {0}, empty = {0};

  int rows = 1 + rand() % 10;
  int cols = 2 + rand() % 10;

  int return_value = s21_create_matrix(rows, cols, &mat);
  if (!return_value) {

    ck_assert_int_eq(s21_sub_matrix(&mat, &mat, &res), 0);
    return_value = s21_create_matrix(rows, cols, &empty);
    if (!return_value) {
      ck_assert_int_eq(s21_eq_matrix(&empty, &res), 1);
      s21_remove_matrix(&empty);
    }
    s21_remove_matrix(&res);
    s21_remove_matrix(&mat);
  }
}
END_TEST

Suite *sub() {
  Suite *s = suite_create("s21_sub tests");
  TCase *tc_core = tcase_create("Sub");
  tcase_add_test(tc_core, test_sub_0);
  suite_add_tcase(s, tc_core);
  return s;
}