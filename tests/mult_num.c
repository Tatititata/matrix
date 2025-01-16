#include "tests.h"
#include <check.h>

START_TEST(test_mult_num_0) {

  matrix_t mat1, res;
  int rows1 = 1 + rand() % 10;
  int cols1 = 2 + rand() % 10;
  int return_value1 = s21_create_matrix(rows1, cols1, &mat1);

  if (return_value1 == 0) {
    fill_matrix(&mat1);

    double number = (double)rand() / (double)RAND_MAX;

    int return_value_res = s21_mult_number(&mat1, number, &res);
    if (return_value_res == 0) {
      ck_assert_int_eq(return_value_res, 0);

      printf("-----------Matrix 1-----------\n");
      print_matrix(&mat1);
      printf("\n");

      printf("------------Result------------\n");
      print_matrix(&res);
      printf("\n");

      s21_remove_matrix(&mat1);
      s21_remove_matrix(&res);
    }
  }
}
END_TEST

START_TEST(test_mult_num_1) {

  matrix_t mat1, res;
  int rows1 = 1 + rand() % 10;
  int cols1 = 2 + rand() % 10;
  int return_value1 = s21_create_matrix(rows1, cols1, &mat1);

  if (return_value1 == 0) {
    fill_matrix(&mat1);

    double number = (double)rand() / (double)RAND_MAX;

    int return_value_res = s21_mult_number(&mat1, number, &res);
    if (return_value_res == 0) {
      ck_assert_int_eq(return_value_res, 0);

      printf("-----------Matrix 1-----------\n");
      print_matrix(&mat1);
      printf("\n");

      printf("------------Result------------\n");
      print_matrix(&res);
      printf("\n");

      s21_remove_matrix(&mat1);
      s21_remove_matrix(&res);
    }
  }
}
END_TEST

START_TEST(test_mult_num_2) {

  matrix_t mat1, res;
  int rows1 = 1 + rand() % 10;
  int cols1 = 2 + rand() % 10;
  int return_value1 = s21_create_matrix(rows1, cols1, &mat1);

  if (return_value1 == 0) {
    fill_matrix(&mat1);

    double number = 0;

    int return_value_res = s21_mult_number(&mat1, number, &res);
    if (return_value_res == 0) {
      ck_assert_int_eq(return_value_res, 0);

      printf("-----------Matrix 1-----------\n");
      print_matrix(&mat1);
      printf("\n");

      printf("------------Result------------\n");
      print_matrix(&res);
      printf("\n");

      s21_remove_matrix(&mat1);
      s21_remove_matrix(&res);
    }
  }
}
END_TEST

START_TEST(test_mult_num_3) {

  matrix_t mat1, res;
  int rows1 = 1 + rand() % 10;
  int cols1 = 2 + rand() % 10;
  int return_value1 = s21_create_matrix(rows1, cols1, &mat1);

  if (return_value1 == 0) {
    fill_matrix(&mat1);

    double number = -(double)rand() / (double)RAND_MAX;

    int return_value_res = s21_mult_number(&mat1, number, &res);
    if (return_value_res == 0) {
      ck_assert_int_eq(return_value_res, 0);

      printf("-----------Matrix 1-----------\n");
      print_matrix(&mat1);
      printf("\n");

      printf("------------Result------------\n");
      print_matrix(&res);
      printf("\n");

      s21_remove_matrix(&mat1);
      s21_remove_matrix(&res);
    }
  }
}

END_TEST

START_TEST(test_mult_num_4) {

  matrix_t mat1, res;
  int rows1 = 1 + rand() % 10;
  int cols1 = 2 + rand() % 10;
  int return_value1 = s21_create_matrix(rows1, cols1, &mat1);

  if (return_value1 == 0) {
    fill_matrix(&mat1);

    double number = 1.;

    int return_value_res = s21_mult_number(&mat1, number, &res);
    if (return_value_res == 0) {

      printf("-----------Matrix 1-----------\n");
      print_matrix(&mat1);
      printf("\n");

      printf("------------Result------------\n");
      print_matrix(&res);
      printf("\n");

      ck_assert_int_eq(s21_eq_matrix(&mat1, &res), 1);

      s21_remove_matrix(&mat1);
      s21_remove_matrix(&res);
    }
  }

  printf("-------End Mult_num Test-------\n");
  printf("-------------------------------\n");
  printf("\n");
}

END_TEST

Suite *mult_num() {
  Suite *s = suite_create("s21_mult_num_tests");
  TCase *tc_core = tcase_create("Mult num");
  tcase_add_test(tc_core, test_mult_num_0);
  tcase_add_test(tc_core, test_mult_num_1);
  tcase_add_test(tc_core, test_mult_num_2);
  tcase_add_test(tc_core, test_mult_num_3);
  tcase_add_test(tc_core, test_mult_num_4);
  suite_add_tcase(s, tc_core);
  return s;
}