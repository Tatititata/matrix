#include "s21_matrix.h"

int s21_create_matrix(int rows, int col, matrix_t *r) {
  int res = 0;
  if (col < 1 || rows < 1)
    res = 1;
  else {
    r->matrix = malloc(rows * col * sizeof(double) + rows * sizeof(double *));
    if (r->matrix) {
      double *ptr = (double *)(r->matrix + rows);
      for (int i = 0; i < rows; i++)
        r->matrix[i] = ptr + col * i;
      r->rows = rows;
      r->columns = col;
      fill_zeroes(r);
    }
  }
  return res;
}

void s21_remove_matrix(matrix_t *M) {
  if (M) {
    if (M->matrix)
      free(M->matrix);
  }
}

int valid(matrix_t *M) {
  return (M && M->columns > 0 && M->rows > 0 && M->matrix);
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int res = 0;
  if (valid(A) && valid(B)) {
    if (A->columns == B->columns && A->rows == B->rows) {
      for (int i = 0; i < A->rows && !res; i++)
        for (int j = 0; j < A->columns && !res; j++)
          res = (A->matrix[i][j] - B->matrix[i][j]) < EPS;
    }
  }
  return res;
}

void print_matrix(matrix_t *M) {
  if (valid(M)) {
    for (int i = 0; i < M->rows; i++) {
      for (int j = 0; j < M->columns; j++)
        printf("%lf ", M->matrix[i][j]);
      printf("\n");
    }
  }
}

void fill_zeroes(matrix_t *M) {
    for (int i = 0; i < M->rows; i++)
      for (int j = 0; j < M->columns; j++)
        M->matrix[i][j] = 0;
}
