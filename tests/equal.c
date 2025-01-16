#include "tests.h"
#include <check.h>

START_TEST(test_eq_0) {

  matrix_t mat1, mat2;
  srand(time(0));
  int rows1 = 1 + rand() % 10;
  int cols1 = 2 + rand() % 10;
  int return_value1 = s21_create_matrix(rows1, cols1, &mat1);
  int rows2 = rows1 + 1;
  int cols2 = cols1 + 1;
  int return_value2 = s21_create_matrix(rows2, cols2, &mat2);


  if (return_value1 == 0 && return_value2 == 0) {
    for (int i = 0; i < mat1.rows; i++)
      for (int j = 0; j < mat1.columns; j++){
        mat2.matrix[i][j] = mat1.matrix[i][j] = rand() % 10;}
    printf("-----------Matrix 1-----------\n");
    print_matrix(&mat1);
    printf("------------------------------\n");

    printf("-----------Matrix 2-----------\n");
    print_matrix(&mat2);
    printf("------------------------------\n");
    ck_assert_int_eq(s21_eq_matrix(&mat1, &mat2), 0);
    s21_remove_matrix(&mat1);
    s21_remove_matrix(&mat2);
  }
}
END_TEST

START_TEST(test_eq_1) {

  matrix_t mat1, mat2;
  srand(time(0));
  int rows1 = 1 + rand() % 10;
  int cols1 = 2 + rand() % 10;
  int return_value1 = s21_create_matrix(rows1, cols1, &mat1);

  int rows2 = rows1;
  int cols2 = cols1;
  int return_value2 = s21_create_matrix(rows2, cols2, &mat2);

  if (return_value1 == 0 && return_value2 == 0) {
    for (int i = 0; i < mat1.rows; i++)
      for (int j = 0; j < mat1.columns; j++){
        mat2.matrix[i][j] = mat1.matrix[i][j] = rand() % 10;}
    printf("-----------Matrix 1-----------\n");
    print_matrix(&mat1);
    printf("\n");

    printf("-----------Matrix 2-----------\n");
    print_matrix(&mat2);
    printf("\n");
    ck_assert_int_eq(s21_eq_matrix(&mat1, &mat2), 1);

  }
  s21_remove_matrix(&mat1);
  s21_remove_matrix(&mat2);
}

END_TEST

START_TEST(test_eq_2) {

  matrix_t mat1, mat2;
  srand(time(0));
  int rows1 = 1 + rand() % 10;
  int cols1 = 1 + rand() % 10;
  int return_value1 = s21_create_matrix(rows1, cols1, &mat1);

  int rows2 = rows1;
  int cols2 = cols1;
  int return_value2 = s21_create_matrix(rows2, cols2, &mat2);

  if (return_value1 == 0 && return_value2 == 0) {
    for (int i = 0; i < mat1.rows; i++)
      for (int j = 0; j < mat1.columns; j++){
        mat1.matrix[i][j] = rand() % 10;
        mat2.matrix[i][j] = mat1.matrix[i][j] + 1e-8;}
    printf("-----------Matrix 1-----------\n");
    print_matrix(&mat1);
    printf("\n");
    printf("-----------Matrix 2-----------\n");
    print_matrix(&mat2);
    printf("\n");
    ck_assert_int_eq(s21_eq_matrix(&mat1, &mat2), 1);

  }

  s21_remove_matrix(&mat1);
  s21_remove_matrix(&mat2);
  printf("--------End Equal test---------\n");
  printf("-------------------------------\n");
  printf("\n");
}

END_TEST

Suite *equal() {
  Suite *s = suite_create("s21_equal tests");
  TCase *tc_core = tcase_create("Equal");
  tcase_add_test(tc_core, test_eq_0);
  tcase_add_test(tc_core, test_eq_1);
  tcase_add_test(tc_core, test_eq_2);
  suite_add_tcase(s, tc_core);
  return s;
}