#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

// Matris �arp�m�
void matrix_multiply(int rowsA, int colsA, int colsB, double** matrixA, double** matrixB, double** result);

// Matris transpozesi
void transpose_matrix(int rows, int cols, double** matrix, double** result);

// Matris olu�turma ve serbest b�rakma
double** allocate_matrix(int rows, int cols);
void free_matrix(int rows, double** matrix);

#endif

