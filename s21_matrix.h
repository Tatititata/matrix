#ifndef S21_MATRIX
#define S21_MATRIX

#include <stdio.h>
#include <stdlib.h>

#define EPS 1e-7

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

void s21_remove_matrix(matrix_t *M);
void fill_zeroes(matrix_t *M);
void print_matrix(matrix_t *M);
int s21_create_matrix(int rows, int columns, matrix_t *result);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);
int valid(matrix_t *M);

// Реализуй основные действия с матрицами (частично описанные
// [выше](#операции-над-матрицами)): create_matrix (создание), remove_matrix
// (очистка и уничтожение), eq_matrix (сравнение), sum_matrix (сложение),
// sub_matrix (вычитание),
// mult_matrix (умножение),
// mult_number (умножение на число),
// transpose (транспонирование),
// determinant (вычисление определителя),
// calc_complements (вычисление матрицы алгебраических дополнений),
// inverse_matrix (поиск обратной матрицы).

#endif