#include "tests.h"
#include <check.h>

START_TEST(test_mult_0) {

  matrix_t mat1, mat2, res;

  int rows1 = 5;
  int cols1 = 2;
  printf("rows %d, cols %d\n", rows1, cols1);
  int return_value1 = s21_create_matrix(rows1, cols1, &mat1);

  int rows2 = 4;
  int cols2 = 3;
  int return_value2 = s21_create_matrix(rows2, cols2, &mat2);
  printf("rows %d, cols %d\n", rows2, cols2);

  if (return_value1 == 0 && return_value2 == 0) {
    fill_matrix(&mat1);
    printf("-----------Matrix 1-----------\n");
    print_matrix(&mat1);
    printf("\n");

    for (int i = 0; i < mat2.rows; i++)
      for (int j = 0; j < mat2.columns; j++)
        mat2.matrix[i][j] = -(double)rand() / (double)RAND_MAX;
    printf("-----------Matrix 2-----------\n");
    print_matrix(&mat2);
    printf("\n");
    ck_assert_int_eq(s21_mult_matrix(&mat1, &mat2, &res), 2);
    ck_assert_int_eq((mat1.columns == mat2.rows), 0);

    s21_remove_matrix(&mat1);
    s21_remove_matrix(&mat2);
  }
}
END_TEST

START_TEST(test_mult_1) {

  matrix_t mat1, mat2, res;

  int rows1 = 1 + rand() % 10;
  int cols1 = 1 + rand() % 10;
  int return_value1 = s21_create_matrix(rows1, cols1, &mat1);

  int rows2 = cols1;
  int cols2 = 1 + rand() % 10;
  int return_value2 = s21_create_matrix(rows2, cols2, &mat2);

  if (return_value1 == 0 && return_value2 == 0) {
    for (int i = 0; i < mat1.rows; i++)
      for (int j = 0; j < mat1.columns; j++)
        mat1.matrix[i][j] = rand() % 10;
    printf("-----------Matrix 1-----------\n");
    print_matrix(&mat1);
    printf("\n");

    fill_matrix(&mat2);
    printf("-----------Matrix 2-----------\n");
    print_matrix(&mat2);
    printf("\n");
    int return_value_res = s21_mult_matrix(&mat1, &mat2, &res);
    if (return_value_res == 0) {
      printf("------------Result------------\n");
      print_matrix(&res);
      printf("\n");
      s21_remove_matrix(&res);
      ck_assert_int_ne(mat1.rows * mat1.columns * mat2.rows * mat2.columns, 0);
    }
  }
  s21_remove_matrix(&mat1);
  s21_remove_matrix(&mat2);
}

END_TEST

START_TEST(test_mult_2) {

  matrix_t mat1, mat2, res;

  int rows1 = 1 + rand() % 11;
  int cols1 = 1 + rand() % 11;
  int return_value1 = s21_create_matrix(rows1, cols1, &mat1);

  int rows2 = cols1;
  int cols2 = 1 + rand() % 10;
  int return_value2 = s21_create_matrix(rows2, cols2, &mat2);

  if (return_value1 == 0 && return_value2 == 0) {
    fill_matrix(&mat1);
    printf("-----------Matrix 1-----------\n");
    print_matrix(&mat1);
    printf("\n");

    for (int i = 0; i < mat2.rows; i++)
      for (int j = 0; j < mat2.columns; j++)
        mat2.matrix[i][j] = (double)rand() / (double)RAND_MAX * 2.0;
    printf("-----------Matrix 2-----------\n");
    print_matrix(&mat2);
    printf("\n");
    int return_value_res = s21_mult_matrix(&mat1, &mat2, &res);
    if (return_value_res == 0) {
      printf("------------Result------------\n");
      print_matrix(&res);
      printf("\n");
      s21_remove_matrix(&res);
      ck_assert_int_ne(mat1.rows * mat1.columns * mat2.rows * mat2.columns, 0);
    }
  }

  s21_remove_matrix(&mat1);
  s21_remove_matrix(&mat2);
}

END_TEST

START_TEST(test_mult_3) {

  matrix_t mat1, mat2, res;

  int rows1 = 1 + rand() % 11;
  int cols1 = rows1;
  int return_value1 = s21_create_matrix(rows1, cols1, &mat1);

  int rows2 = rows1;
  int cols2 = rows1;
  int return_value2 = s21_create_matrix(rows2, cols2, &mat2);

  if (return_value1 == 0 && return_value2 == 0) {
    for (int i = 0; i < mat1.rows; i++)
      mat1.matrix[i][i] = (double)rand() / (double)RAND_MAX;
    printf("-----------Matrix 1-----------\n");
    print_matrix(&mat1);
    printf("\n");

    for (int i = 0; i < mat2.rows; i++)
      mat2.matrix[i][i] = (double)rand() / (double)RAND_MAX;
    printf("-----------Matrix 2-----------\n");
    print_matrix(&mat2);
    printf("\n");
    int return_value_res = s21_mult_matrix(&mat1, &mat2, &res);
    if (return_value_res == 0) {
      printf("------------Result------------\n");
      print_matrix(&res);
      printf("\n");
      s21_remove_matrix(&res);
      ck_assert_int_ne(mat1.rows * mat1.columns * mat2.rows * mat2.columns, 0);
    }
  }

  s21_remove_matrix(&mat1);
  s21_remove_matrix(&mat2);
}

END_TEST

START_TEST(test_mult_4) {

  matrix_t mat1, mat2, res;

  int rows1 = 1 + rand() % 11;
  int cols1 = rows1;
  int return_value1 = s21_create_matrix(rows1, cols1, &mat1);

  int rows2 = rows1;
  int cols2 = rows1;
  int return_value2 = s21_create_matrix(rows2, cols2, &mat2);

  if (return_value1 == 0 && return_value2 == 0) {
    for (int i = 0; i < mat1.rows; i++)
      mat1.matrix[i][i] = 1.;

    printf("-----------Matrix 1-----------\n");
    print_matrix(&mat1);
    printf("\n");

    for (int i = 0; i < mat2.rows; i++)
      mat2.matrix[i][i] = (double)rand() / (double)RAND_MAX;

    printf("-----------Matrix 2-----------\n");
    print_matrix(&mat2);
    printf("\n");
    int return_value_res = s21_mult_matrix(&mat1, &mat2, &res);
    if (return_value_res == 0) {
      printf("------------Result------------\n");
      print_matrix(&res);
      printf("\n");

      ck_assert_int_ne(mat1.rows * mat1.columns * mat2.rows * mat2.columns, 0);
      ck_assert_int_eq(s21_eq_matrix(&mat2, &res), 1);
      s21_remove_matrix(&res);
    }
  }

  s21_remove_matrix(&mat1);
  s21_remove_matrix(&mat2);
  printf("---------End Mult Test---------\n");
  printf("-------------------------------\n");
  printf("\n");
}

END_TEST

Suite *mult() {
  Suite *s = suite_create("s21_mult tests");
  TCase *tc_core = tcase_create("Mult");
  tcase_add_test(tc_core, test_mult_0);
  tcase_add_test(tc_core, test_mult_1);
  tcase_add_test(tc_core, test_mult_2);
  tcase_add_test(tc_core, test_mult_3);
  tcase_add_test(tc_core, test_mult_4);
  suite_add_tcase(s, tc_core);
  return s;
}