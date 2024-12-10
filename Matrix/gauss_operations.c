#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "gauss_operations.h"
#include "utils.h" // Matris i�lemleri i�in gerekli

// Gauss Eliminasyonu: Sat�r indirgeme
bool gaussian_elimination(int rows, int cols, double** matrix, double* solutions) {
    for (int i = 0; i < rows; i++) {
        // Pivot eleman s�f�r ise sat�r de�i�tirme
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
                printf("S�f�r pivot bulundu. Sistem ��z�ms�z veya sonsuz ��z�ml�.\n");
                return false;
            }
        }

        // Sat�r� normalize et
        double pivot = matrix[i][i];
        for (int j = 0; j < cols; j++) {
            matrix[i][j] /= pivot;
        }

        // Alt sat�rlar� s�f�rla
        for (int k = i + 1; k < rows; k++) {
            double factor = matrix[k][i];
            for (int j = 0; j < cols; j++) {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }
    return true;
}

// Geriye Yerle�tirme: ��z�mleri hesapla
void backward_substitution(int rows, int cols, double** matrix, double* solutions) {
    for (int i = rows - 1; i >= 0; i--) {
        solutions[i] = matrix[i][cols - 1];
        for (int j = i + 1; j < rows; j++) {
            solutions[i] -= matrix[i][j] * solutions[j];
        }
    }
}

