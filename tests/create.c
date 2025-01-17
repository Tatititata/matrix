#include "tests.h"
#include <check.h>

START_TEST(test_create_0) {

  matrix_t mat;

  int rows = 0;
  int cols = 1 + rand() % 10;

  ck_assert_int_eq(s21_create_matrix(rows, cols, &mat), 1);
}
END_TEST

START_TEST(test_create_1) {

  matrix_t mat;

  int rows = 1 + rand() % 10;
  int cols = 0;
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
  int cols = 1 + rand() % 10;
  ck_assert_int_eq(s21_create_matrix(rows, cols, &mat), 1);
}
END_TEST

START_TEST(test_create_4) {

  matrix_t mat;

  int rows = 1 + rand() % 10;
  int cols = -1 - rand() % 10;
  ck_assert_int_eq(s21_create_matrix(rows, cols, &mat), 1);
}
END_TEST

START_TEST(test_create_5) {

  matrix_t mat;

  int rows = 1 + rand() % 10;
  int cols = 1 + rand() % 10;
  ck_assert_int_eq(s21_create_matrix(rows, cols, &mat), 0);
  s21_remove_matrix(&mat);
}
END_TEST

Suite *create() {
  Suite *s = suite_create("s21_create tests");
  TCase *tc_core = tcase_create("Create");
  tcase_add_test(tc_core, test_create_0);
  tcase_add_test(tc_core, test_create_1);
  tcase_add_test(tc_core, test_create_2);
  tcase_add_test(tc_core, test_create_3);
  tcase_add_test(tc_core, test_create_4);
  tcase_add_test(tc_core, test_create_5);
  suite_add_tcase(s, tc_core);

  return s;
}