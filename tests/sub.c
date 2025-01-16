#include "tests.h"
#include <check.h>

START_TEST(test_sub_0) {

  matrix_t mat1, mat2, res;
  srand(time(0));
  int rows1 = 1 + rand() % 10;
  int cols1 = 2 + rand() % 10;
  printf("rows %d, cols %d\n", rows1, cols1);
  int return_value1 = s21_create_matrix(rows1, cols1, &mat1);

  int rows2 = rows1 + 1;
  int cols2 = cols1 + 1;
  int return_value2 = s21_create_matrix(rows2, cols2, &mat2);
  printf("rows %d, cols %d\n", rows2, cols2);

  if (return_value1 == 0 && return_value2 == 0) {
    for (int i = 0; i < mat1.rows; i++)
      for (int j = 0; j < mat1.columns; j++)
        mat1.matrix[i][j] = rand() % 10;
    printf("-----------Matrix 1-----------\n");
    print_matrix(&mat1);
    printf("\n");

    for (int i = 0; i < mat2.rows; i++)
      for (int j = 0; j < mat2.columns; j++)
        mat2.matrix[i][j] = rand() % 10;
    printf("-----------Matrix 2-----------\n");
    print_matrix(&mat2);
    printf("\n");

    ck_assert_int_eq(s21_sub_matrix(&mat1, &mat2, &res), 1);
    ck_assert_int_eq((mat1.rows == mat2.rows) && (mat1.columns == mat2.columns),
                     0);

    s21_remove_matrix(&mat1);
    s21_remove_matrix(&mat2);
  }
}
END_TEST

START_TEST(test_sub_1) {

  matrix_t mat1, mat2, res;
  srand(time(0));
  int rows1 = 1 + rand() % 10;
  int cols1 = 1 + rand() % 10;
  int return_value1 = s21_create_matrix(rows1, cols1, &mat1);

  int rows2 = rows1;
  int cols2 = cols1;
  int return_value2 = s21_create_matrix(rows2, cols2, &mat2);

  if (return_value1 == 0 && return_value2 == 0) {
    for (int i = 0; i < mat1.rows; i++)
      for (int j = 0; j < mat1.columns; j++)
        mat1.matrix[i][j] = rand() % 10;
    printf("-----------Matrix 1-----------\n");
    print_matrix(&mat1);
    printf("\n");

    for (int i = 0; i < mat2.rows; i++)
      for (int j = 0; j < mat2.columns; j++)
        mat2.matrix[i][j] = rand() % 10;
    printf("-----------Matrix 2-----------\n");
    print_matrix(&mat2);
    printf("\n");

    int return_value_res = s21_sub_matrix(&mat1, &mat2, &res);
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

START_TEST(test_sub_2) {

  matrix_t mat1, mat2, res;
  srand(time(0));
  int rows1 = 1 + rand() % 11;
  int cols1 = 1 + rand() % 11;
  int return_value1 = s21_create_matrix(rows1, cols1, &mat1);

  int rows2 = rows1;
  int cols2 = cols1;
  int return_value2 = s21_create_matrix(rows2, cols2, &mat2);

  if (return_value1 == 0 && return_value2 == 0) {
    for (int i = 0; i < mat1.rows; i++)
      for (int j = 0; j < mat1.columns; j++)
        mat1.matrix[i][j] = rand() % 10;
    printf("-----------Matrix 1-----------\n");
    print_matrix(&mat1);
    printf("\n");

    for (int i = 0; i < mat2.rows; i++)
      for (int j = 0; j < mat2.columns; j++)
        mat2.matrix[i][j] = rand() % 10;
    printf("-----------Matrix 2-----------\n");
    print_matrix(&mat2);
    printf("\n");

    int return_value_res = s21_sub_matrix(&mat1, &mat2, &res);
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
  printf("---------End Sub Test----------\n");
  printf("-------------------------------\n");
  printf("\n");
}

END_TEST

Suite *sub() {
  Suite *s = suite_create("s21_sub tests");
  TCase *tc_core = tcase_create("Sub");
  tcase_add_test(tc_core, test_sub_0);
  tcase_add_test(tc_core, test_sub_1);
  tcase_add_test(tc_core, test_sub_2);
  suite_add_tcase(s, tc_core);
  return s;
}