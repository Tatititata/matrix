#ifndef MATRIX_TESTS
#define MATRIX_TESTS

#include "../s21_matrix.h"
#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Suite *create();
Suite *sum();
Suite *sub();
Suite *equal();
Suite *mult_num();
Suite *mult();
Suite *transpose();
Suite *det();
// Suite *comp();

#endif