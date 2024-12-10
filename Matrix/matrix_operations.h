#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

// Matris çarpýmý
void matrix_multiply(int rowsA, int colsA, int colsB, double** matrixA, double** matrixB, double** result);

// Matris transpozesi
void transpose_matrix(int rows, int cols, double** matrix, double** result);

// Matris oluþturma ve serbest býrakma
double** allocate_matrix(int rows, int cols);
void free_matrix(int rows, double** matrix);

#endif

