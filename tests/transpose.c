#include "tests.h"
#include <check.h>

START_TEST(test_transpose_0) {

  srand(time(0));
  matrix_t mat1, res;

  int rows1 = 1 + rand() % 10;
  int cols1 = 1 + rand() % 10;
  int return_value1 = s21_create_matrix(rows1, cols1, &mat1);

  if (return_value1 == 0) {
    fill_matrix(&mat1);
    printf("-----------Matrix-------------\n");
    print_matrix(&mat1);
    printf("\n");

    int return_value_res = s21_transpose(&mat1, &res);
    if (return_value_res == 0) {
      printf("----------Transposed----------\n");
      print_matrix(&res);
      printf("\n");
      s21_remove_matrix(&res);
      ck_assert_int_eq(mat1.rows == res.columns && mat1.columns == res.rows, 1);
    }
    s21_remove_matrix(&mat1);
  }
}
END_TEST

START_TEST(test_transpose_1) {

  matrix_t mat1, res;

  int rows1 = 1 + rand() % 10;
  int cols1 = 1 + rand() % 10;
  int return_value1 = s21_create_matrix(rows1, cols1, &mat1);

  if (return_value1 == 0) {
    fill_matrix(&mat1);
    printf("-----------Matrix-------------\n");
    print_matrix(&mat1);
    printf("\n");

    int return_value_res = s21_transpose(&mat1, &res);
    if (return_value_res == 0) {
      printf("----------Transposed----------\n");
      print_matrix(&res);
      printf("\n");
      s21_remove_matrix(&res);
      ck_assert_int_eq(mat1.rows == res.columns && mat1.columns == res.rows, 1);
    }
    s21_remove_matrix(&mat1);
  }
}
END_TEST

START_TEST(test_transpose_2) {

  matrix_t mat1, res;

  int rows1 = 1 + rand() % 10;
  int cols1 = 1 + rand() % 10;
  int return_value1 = s21_create_matrix(rows1, cols1, &mat1);

  if (return_value1 == 0) {
    fill_matrix(&mat1);
    printf("-----------Matrix-------------\n");
    print_matrix(&mat1);
    printf("\n");

    int return_value_res = s21_transpose(&mat1, &res);
    if (return_value_res == 0) {
      printf("----------Transposed----------\n");
      print_matrix(&res);
      printf("\n");
      s21_remove_matrix(&res);
      ck_assert_int_eq(mat1.rows == res.columns && mat1.columns == res.rows, 1);
    }
    s21_remove_matrix(&mat1);
  }

  printf("------End Transpose Test-------\n");
  printf("-------------------------------\n");
  printf("\n");
}

END_TEST

Suite *transpose() {
  Suite *s = suite_create("s21_transpose tests");
  TCase *tc_core = tcase_create("Transpose");
  tcase_add_test(tc_core, test_transpose_0);
  tcase_add_test(tc_core, test_transpose_1);
  tcase_add_test(tc_core, test_transpose_2);
  suite_add_tcase(s, tc_core);
  return s;
}