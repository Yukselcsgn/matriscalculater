#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>

// Dinamik matris ve vektör bellek yönetimi
double** create_matrix(int rows, int cols);
void free_matrix(double** matrix, int rows);
double* create_vector(int size);
void free_vector(double* vector);

// Yazdırma ve yardımcı fonksiyonlar
void print_matrix(int rows, int cols, double** matrix);
void print_vector(int size, double* vector);
void initialize_matrix(int rows, int cols, double** matrix, double value);
void swap_rows(int cols, double** matrix, int row1, int row2);

#endif
