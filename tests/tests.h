#ifndef MATRIX_TESTS
#define MATRIX_TESTS

#include "../s21_matrix.h"
#include <check.h>

Suite *create();
Suite *sum();
Suite *sub();  
Suite *mult_num(); 
Suite *mult();               
Suite *transpose();
Suite *det();
Suite *comp();


#endif