#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

#include "utils.h"

// Matris çarpımı: result = matrixA * matrixB
// rowsA x colsA ile colsA x colsB çarpılır, result boyutu rowsA x colsB olur.
void matrix_multiply(int rowsA, int colsA, int colsB, double** matrixA, double** matrixB, double** result);

// Matris transpozu
void transpose_matrix(int rows, int cols, double** matrix, double** result);

// Matrisin tersi (Gauss-Jordan Eliminasyonu): 0 = Başarılı, -1 = Tekil matris (tersi yok)
int matrix_inverse(int n, double** matrix, double** inverse);

// Matris determinantı (Gauss Eliminasyonu ile)
double matrix_determinant(int n, double** matrix);

#endif
