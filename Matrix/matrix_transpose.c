#include <stdio.h>
#include "matrix_transpose.h"

// Matrisin transpozunu hesapla
void matrix_transpose(double** matrix, double** result, int rows, int cols) {
    if (!matrix || !result) {
        return;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}
