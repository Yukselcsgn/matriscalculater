#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>

// Fonksiyon bildirimleri
double** create_matrix(int rows, int cols);
void free_matrix(double** matrix, int rows);
void print_matrix(int rows, int cols, double** matrix);
void initialize_matrix(int rows, int cols, double** matrix, double value);
void swap_rows(int cols, double** matrix, int row1, int row2);

#endif

