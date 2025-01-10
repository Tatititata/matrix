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
  int res = 1;
  if (valid(A) && valid(B) && equal_size(A, B)) {
    for (int i = 0; i < A->rows && res; i++)
      for (int j = 0; j < A->columns && res; j++)
        res *= ((A->matrix[i][j] - B->matrix[i][j]) < EPS);
  } else
    res = 0;
  return res;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *R) {
  return (matrix_arithmetics(A, B, R, '+'));
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *R) {
  return (matrix_arithmetics(A, B, R, '-'));
}

int matrix_arithmetics(matrix_t *A, matrix_t *B, matrix_t *R, char sign) {
  int res = 1;
  if (valid(A) && valid(B) && equal_size(A, B)) {
    if (R->matrix) {
      s21_remove_matrix(R);
    }
    res = s21_create_matrix(A->rows, A->columns, R); // if OK res = 0
    if (!res) {
      for (int i = 0; i < A->rows; i++)
        for (int j = 0; j < A->columns; j++)
          if (sign == '+')
            R->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
          else if (sign == '-')
            R->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
    }
  }
  return res;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *R) {
  int res = 1;
  if (valid(A)) {
    if (R->matrix) {
      s21_remove_matrix(R);
    }
    res = s21_create_matrix(A->rows, A->columns, R); // if OK res = 0
    if (!res) {
      for (int i = 0; i < A->rows; i++)
        for (int j = 0; j < A->columns; j++)
          R->matrix[i][j] = A->matrix[i][j] * number;
    }
  }
  return res;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *R) {
  int res = 1;
  if (valid(A) && valid(B) && A->columns == B->rows) {
    if (R->matrix) {
      s21_remove_matrix(R);
    }
    res = s21_create_matrix(A->rows, B->columns, R); // if OK res = 0
    if (!res) {
      for (int i = 0; i < A->rows; i++)
        for (int j = 0; j < B->columns; j++)
          for (int k = 0; k < A->columns; k++)
            R->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
    }
  }
  return res;
}

int s21_transpose(matrix_t *A, matrix_t *R) {
  int res = 1;
  if (valid(A)) {
    if (R->matrix) {
      s21_remove_matrix(R);
    }
    res = s21_create_matrix(A->columns, A->rows, R); // if OK res = 0
    if (!res) {
      for (int i = 0; i < A->columns; i++)
        for (int j = 0; j < A->rows; j++)
          R->matrix[i][j] = A->matrix[j][i];
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

int equal_size(matrix_t *A, matrix_t *B) {
  return A->columns == B->columns && A->rows == B->rows;
}
