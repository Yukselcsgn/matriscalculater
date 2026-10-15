#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "gauss_operations.h"
#include "utils.h"

// Gauss Eliminasyonu: Genişletilmiş matrisi üst üçgensel hale getirme
bool gaussian_elimination(int rows, int cols, double** matrix) {
    if (!matrix || rows <= 0 || cols <= rows) {
        return false;
    }

    for (int i = 0; i < rows; i++) {
        // En büyük mutlak değerli pivotu bul (Kısmi pivotlama)
        int max_row = i;
        double max_val = fabs(matrix[i][i]);
        for (int k = i + 1; k < rows; k++) {
            if (fabs(matrix[k][i]) > max_val) {
                max_val = fabs(matrix[k][i]);
                max_row = k;
            }
        }

        // Pivot sıfıra yakınsa, tekil sistem
        if (max_val < 1e-12) {
            return false;
        }

        // Satır takaslama
        if (max_row != i) {
            swap_rows(cols, matrix, i, max_row);
        }

        // Alt satırları sıfırla
        for (int k = i + 1; k < rows; k++) {
            double factor = matrix[k][i] / matrix[i][i];
            matrix[k][i] = 0.0;
            for (int j = i + 1; j < cols; j++) {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }
    return true;
}

// Geriye yerine koyma (Backward Substitution)
void backward_substitution(int rows, int cols, double** matrix, double* solutions) {
    if (!matrix || !solutions) {
        return;
    }

    for (int i = rows - 1; i >= 0; i--) {
        solutions[i] = matrix[i][cols - 1];
        for (int j = i + 1; j < rows; j++) {
            solutions[i] -= matrix[i][j] * solutions[j];
        }
        solutions[i] /= matrix[i][i];
    }
}
