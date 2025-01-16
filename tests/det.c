#include "tests.h"
#include <check.h>

START_TEST(test_det_0) {

  matrix_t mat;

  int rows = 1 + rand() % 10;

  double det = 0;
  int return_value1 = s21_create_matrix(rows, rows, &mat);

  if (return_value1 == 0) {
    for (int i = 0; i < mat.rows; i++)
      mat.matrix[i][i] = 1.;
    printf("-----------Matrix 1-----------\n");
    print_matrix(&mat);
    printf("\n");

    ck_assert_int_eq(s21_determinant(&mat, &det), 0);
    ck_assert_double_eq(det, 1.);
    printf("determinant = %.30lf\n", det);
    s21_remove_matrix(&mat);
  }
}
END_TEST

START_TEST(test_det_1) {

  matrix_t mat;

  int rows = 2 + rand() % 10;

  double det = -1;
  int return_value1 = s21_create_matrix(rows, rows, &mat);

  if (return_value1 == 0) {
    double count = 1.;
    for (int i = 0; i < mat.rows; i++)
      for (int j = 0; j < mat.rows; j++) {
        mat.matrix[i][j] = count;
        count++;
      }
    printf("-----------Matrix 1-----------\n");
    print_matrix(&mat);
    printf("\n");

    ck_assert_int_eq(s21_determinant(&mat, &det), 0);
    ck_assert_double_eq(det, 0);
    printf("determinant = %.30lf\n", det);
    s21_remove_matrix(&mat);
  }
}
END_TEST

START_TEST(test_det_2) {

  matrix_t mat;

  int rows = 1 + rand() % 10;

  double det = 0;
  int return_value1 = s21_create_matrix(rows, rows + 1, &mat);

  if (return_value1 == 0) {
    double count = 1.;
    for (int i = 0; i < mat.rows; i++)
      for (int j = 0; j < mat.rows; j++) {
        mat.matrix[i][j] = count;
        count++;
      }
    printf("-----------Matrix 1-----------\n");
    print_matrix(&mat);
    printf("\n");

    ck_assert_int_eq(s21_determinant(&mat, &det), 2);
    ck_assert_double_eq(det, 0);
    printf("determinant = %.30lf\n", det);
    s21_remove_matrix(&mat);
  }
}
END_TEST

START_TEST(test_det_3) {

  matrix_t mat;

  int rows = 1 + rand() % 10;

  double det = -1;
  int return_value1 = s21_create_matrix(rows, rows, &mat);

  if (return_value1 == 0) {
    for (int i = 0; i < mat.rows; i++)
      for (int j = 0; j < mat.rows; j++) {
        mat.matrix[i][j] = 0;
      }
    printf("-----------Matrix 1-----------\n");
    print_matrix(&mat);
    printf("\n");

    ck_assert_int_eq(s21_determinant(&mat, &det), 0);
    ck_assert_double_eq(det, 0);

    printf("determinant = %.30lf\n", det);
    s21_remove_matrix(&mat);
  }
}
END_TEST

START_TEST(test_det_4) {

  for (int i = 0; i < 10; i++) {
    matrix_t mat;

    int rows = 1 + rand() % 10;

    double det = -1.;
    int return_value1 = s21_create_matrix(rows, rows, &mat);

    if (return_value1 == 0) {
      fill_matrix(&mat);
      printf("-----------Matrix 1-----------\n");
      print_matrix(&mat);
      printf("\n");

      ck_assert_int_eq(s21_determinant(&mat, &det), 0);

      printf("determinant = %.30lf\n", det);
      s21_remove_matrix(&mat);
    }
  }
}
END_TEST

Suite *det() {
  Suite *s = suite_create("s21_det tests");
  TCase *tc_core = tcase_create("Determinant");
  tcase_add_test(tc_core, test_det_0);
  tcase_add_test(tc_core, test_det_1);
  tcase_add_test(tc_core, test_det_2);
  tcase_add_test(tc_core, test_det_3);
  tcase_add_test(tc_core, test_det_4);
  suite_add_tcase(s, tc_core);
  return s;
}