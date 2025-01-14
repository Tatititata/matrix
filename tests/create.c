#include "tests.h"
#include <check.h>

START_TEST(test_create_0) {

  matrix_t mat;
  srand(time(0));
  int rows = 1 + rand() % 10;
  int cols = 1 + rand() % 10;
  int return_value = s21_create_matrix(rows, cols, &mat);
  if (return_value == 0) {
    for (int i = 0; i < mat.rows; i++)
      for (int j = 0; j < mat.columns; j++)
        mat.matrix[i][j] = rand() % 10;
    print_matrix(&mat);
    s21_remove_matrix(&mat);
    ck_assert_int_ne(rows * cols, 0);
  }
}
END_TEST

START_TEST(test_create_1) {
  matrix_t mat;
  int rows = rand() % 10;
  int cols = -1 - rand() % 10;
  ck_assert_int_eq(s21_create_matrix(rows, cols, &mat), 1);
}
END_TEST

START_TEST(test_create_2) {
  matrix_t mat;
  int rows = 0;
  int cols = 0;
  ck_assert_int_eq(s21_create_matrix(rows, cols, &mat), 1);
}
END_TEST

START_TEST(test_create_3) {
  matrix_t mat;
  int rows = -1 - rand() % 10;
  int cols = rand() % 10;
  ck_assert_int_eq(s21_create_matrix(rows, cols, &mat), 1);
}
END_TEST

Suite *create() {
  Suite *s = suite_create("s21_create tests");
  TCase *tc_core = tcase_create("Create");
  tcase_add_test(tc_core, test_create_0);
  tcase_add_test(tc_core, test_create_1);
  tcase_add_test(tc_core, test_create_2);
  tcase_add_test(tc_core, test_create_3);
  suite_add_tcase(s, tc_core);
  return s;
}