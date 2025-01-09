#include "../s21_matrix.h"

int main()

{
  matrix_t M, N;
  printf("s21_create_matrix %d\n", s21_create_matrix(2, 3, &M));
  printf("s21_create_matrix %d\n", s21_create_matrix(2, 3, &N));
  print_matrix(&M);
  print_matrix(&N);
  printf("s21_eq_matrix %d\n", s21_eq_matrix(&M, &N));
  s21_remove_matrix(&M);
  s21_remove_matrix(&N);
  return 0;
}