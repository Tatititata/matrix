#include "s21_matrix.h"

int s21_create_matrix(int rows, int col, matrix_t *M) {
  int res = 0;
  if (col < 1 || rows < 1) {
    res = 1;
  } else {
    M->matrix = malloc(rows * col * sizeof(double) + rows * sizeof(double *));
    if (M->matrix) {
      double *ptr = (double *)(M->matrix + rows);
      for (int i = 0; i < rows; i++) {
        M->matrix[i] = ptr + col * i;
        for (int j = 0; j < col; j++)
          M->matrix[i][j] = 0;
      }
      M->rows = rows;
      M->columns = col;
    }
  }
  return res;
}

void s21_remove_matrix(matrix_t *M) {
  if (M != NULL) {
    if (M->matrix)
      free(M->matrix);
  }
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int res = 1;
  if (valid(A) && valid(B) && equal_size(A, B)) {
    for (int i = 0; (i < A->rows) && res; i++)
      for (int j = 0; (j < A->columns) && res; j++)
        res *= (fabs(A->matrix[i][j] - B->matrix[i][j]) < EPS);
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
  int res = 2;
  if (valid(A) && valid(B) && equal_size(A, B)) {
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
  int res = 2;
  if (valid(A)) {
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
  int res = 2;
  if (valid(A) && valid(B) && A->columns == B->rows) {
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
  int res = 2;
  if (valid(A)) {
    res = s21_create_matrix(A->columns, A->rows, R); // if OK res = 0
    if (!res) {
      for (int i = 0; i < A->columns; i++)
        for (int j = 0; j < A->rows; j++)
          R->matrix[i][j] = A->matrix[j][i];
    }
  }
  return res;
}

int s21_determinant(matrix_t *M, double *det) {
  int res = 0;
  if (!valid(M) || (M->columns != M->rows)) {
    res = 2;
  } else {
    if (M->rows == 1)
      *det = M->matrix[0][0];
    else if (M->rows == 2)
      *det =
          M->matrix[0][0] * M->matrix[1][1] - M->matrix[1][0] * M->matrix[0][1];
    else
      *det = determinant(M);
  }
  return res;
}

double determinant(matrix_t *M) {
  matrix_t A;
  s21_create_matrix(M->rows, M->columns, &A);
  for (int i = 0; i < M->rows; i++)
    for (int j = 0; j < M->columns; j++)
      A.matrix[i][j] = M->matrix[i][j];
  double det = 1.0;
  for (int c = 0; c < A.rows; c++) {
    int idx_of_max = c;
    for (int r = c + 1; r < A.rows; r++) {
      if (fabs(A.matrix[r][c]) > fabs(A.matrix[idx_of_max][c]))
        idx_of_max = r;
    }
    if (idx_of_max != c) {
      swap(&(A.matrix[c]), &(A.matrix[idx_of_max]));
      det *= (-1);
    }
    if (A.matrix[c][c] != 0) {
      for (int i = c + 1; i < A.rows; i++) {
        double tmp = A.matrix[c][i] / A.matrix[c][c];
        for (int j = c + 1; j < A.rows; j++)
          A.matrix[j][i] -= A.matrix[j][c] * tmp;
      }
    }
  }
  for (int i = 0; i < A.rows; i++)
    det *= A.matrix[i][i];
  if ((float)det == 0)
    det = 0;
  s21_remove_matrix(&A);
  return det;
}

int s21_calc_complements(matrix_t *M, matrix_t *R) {
  int res = 0;
  if (valid(M) && !s21_create_matrix(M->rows, M->rows, R)) {
    if (M->columns == 1)
      R->matrix[0][0] = 1;
    else if (M->columns == 2) {
      R->matrix[0][0] = M->matrix[1][1];
      R->matrix[1][1] = M->matrix[0][0];
      R->matrix[0][1] = -M->matrix[1][0];
      R->matrix[1][0] = -M->matrix[0][1];
    } else
      minor(M, R);

  } else
    res = 2;
  return res;
}

void minor(matrix_t *M, matrix_t *R) // rows > 2
{
  matrix_t A;
  if (!s21_create_matrix(M->rows - 1, M->rows - 1, &A)) {
    for (int i = 0; i < M->rows; i++)
      for (int j = 0; j < M->rows; j++) {
        for (int k = 0; k < M->rows - 1; k++)
          for (int p = 0; p < M->rows - 1; p++)
            A.matrix[k][p] = M->matrix[k + (k >= i)][p + (p >= j)];
        double det = 0;
        s21_determinant(&A, &det);
        R->matrix[i][j] = det * pow((-1.), (i + j));
      }
    s21_remove_matrix(&A);
  }
}

int s21_inverse_matrix(matrix_t *M, matrix_t *I) {
  double det = 0;
  int res = s21_determinant(M, &det); // if OK res = 0
  if (!res && det) {
    matrix_t A;
    if (!s21_calc_complements(M, &A)) {
      matrix_t B;
      if (!s21_transpose(&A, &B)) {
        s21_mult_number(&B, 1. / det, I);
        s21_remove_matrix(&B);
      } else
        res = 1;
      s21_remove_matrix(&A);
    } else
      res = 1;
  }
  return res;
}

void swap(double **a, double **b) {
  double *tmp = *a;
  *a = *b;
  *b = tmp;
}

int valid(const matrix_t *M) {
  return (M && M->columns > 0 && M->rows > 0 && M->matrix);
}

int equal_size(const matrix_t *A, const matrix_t *B) {
  return (A->columns == B->columns) && (A->rows == B->rows);
}

void fill_matrix(matrix_t *M) {
  for (int i = 0; i < M->rows; i++)
    for (int j = 0; j < M->columns; j++)
      M->matrix[i][j] = 20 * (double)rand() / (double)RAND_MAX - 10.0;
}

void print_matrix(const matrix_t *M) {
  if (valid(M)) {
    for (int i = 0; i < M->rows; i++) {
      for (int j = 0; j < M->columns; j++)
        printf("%.10lf ", M->matrix[i][j]);
      printf("\n");
    }
  }
}