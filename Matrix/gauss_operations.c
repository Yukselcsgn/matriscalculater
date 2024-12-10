#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "gauss_operations.h"
#include "utils.h" // Matris iþlemleri için gerekli

// Gauss Eliminasyonu: Satýr indirgeme
bool gaussian_elimination(int rows, int cols, double** matrix, double* solutions) {
    for (int i = 0; i < rows; i++) {
        // Pivot eleman sýfýr ise satýr deðiþtirme
        if (fabs(matrix[i][i]) < 1e-9) {
            bool swapped = false;
            for (int k = i + 1; k < rows; k++) {
                if (fabs(matrix[k][i]) > 1e-9) {
                    swap_rows(cols, matrix, i, k);
                    swapped = true;
                    break;
                }
            }
            if (!swapped) {
                printf("Sýfýr pivot bulundu. Sistem çözümsüz veya sonsuz çözümlü.\n");
                return false;
            }
        }

        // Satýrý normalize et
        double pivot = matrix[i][i];
        for (int j = 0; j < cols; j++) {
            matrix[i][j] /= pivot;
        }

        // Alt satýrlarý sýfýrla
        for (int k = i + 1; k < rows; k++) {
            double factor = matrix[k][i];
            for (int j = 0; j < cols; j++) {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }
    return true;
}

// Geriye Yerleþtirme: Çözümleri hesapla
void backward_substitution(int rows, int cols, double** matrix, double* solutions) {
    for (int i = rows - 1; i >= 0; i--) {
        solutions[i] = matrix[i][cols - 1];
        for (int j = i + 1; j < rows; j++) {
            solutions[i] -= matrix[i][j] * solutions[j];
        }
    }
}

