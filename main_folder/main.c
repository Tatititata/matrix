#include "../s21_matrix.h"

int main()

{
  matrix_t M, N, R;
  printf("s21_create_matrix %d\n", s21_create_matrix(2, 3, &M));
  printf("s21_create_matrix %d\n", s21_create_matrix(2, 3, &N));
  print_matrix(&M);
  print_matrix(&N);
  printf("s21_eq_matrix %d\n", s21_eq_matrix(&M, &N));
  printf("s21_ar_matrix %d\n", s21_sum_matrix(&M, &N, &R));
  print_matrix(&R);
  s21_remove_matrix(&M);
  s21_remove_matrix(&N);
  s21_remove_matrix(&R);
  return 0;
}