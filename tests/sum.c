#include "tests.h"
#include <check.h>

START_TEST(test_sum_0) {

  matrix_t mat1, mat2, res = {0};

  int rows = 1 + rand() % 10;
  int cols = 2 + rand() % 10;

  int return_value = s21_create_matrix(rows, cols, &mat1);
  if (!return_value) {
    return_value = s21_create_matrix(rows + 1, cols, &mat2);
    if (!return_value) {
      ck_assert_int_eq(s21_sum_matrix(&mat1, &mat2, &res), 2);
      s21_remove_matrix(&mat2);
    }
    s21_remove_matrix(&mat1);
  }
}
END_TEST

START_TEST(test_sum_1) {

  matrix_t mat, mat2, res = {0};

  int rows = 1 + rand() % 10;
  int cols = 2 + rand() % 10;

  int return_value = s21_create_matrix(rows, cols, &mat);
  if (!return_value) {
    fill_matrix(&mat);
    ck_assert_int_eq(s21_sum_matrix(&mat, &mat, &res), 0);
    ck_assert_int_eq(s21_mult_number(&mat, 2, &mat2), 0);
    ck_assert_int_eq(s21_eq_matrix(&mat2, &res), 1);
    s21_remove_matrix(&res);
    s21_remove_matrix(&mat2);

    s21_remove_matrix(&mat);
  }
}
END_TEST

START_TEST(test_sum_2) {

  matrix_t mat, mat_1, res = {0}, empty = {0};

  int rows = 1 + rand() % 10;
  int cols = 2 + rand() % 10;

  int return_value = s21_create_matrix(rows, cols, &mat);
  if (!return_value) {

    ck_assert_int_eq(s21_mult_number(&mat, -1, &mat_1), 0);
    ck_assert_int_eq(s21_sum_matrix(&mat, &mat_1, &res), 0);
    return_value = s21_create_matrix(rows, cols, &empty);
    if (!return_value) {
      ck_assert_int_eq(s21_eq_matrix(&empty, &res), 1);
      s21_remove_matrix(&empty);
    }
    s21_remove_matrix(&res);
    s21_remove_matrix(&mat_1);

    s21_remove_matrix(&mat);
  }
}
END_TEST


Suite *sum() {
  Suite *s = suite_create("s21_sum tests");
  TCase *tc_core = tcase_create("Sum");
  tcase_add_test(tc_core, test_sum_0);
  tcase_add_test(tc_core, test_sum_1);
  tcase_add_test(tc_core, test_sum_2);
  suite_add_tcase(s, tc_core);
  return s;
}