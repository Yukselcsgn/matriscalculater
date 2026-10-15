#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix_operations.h"
#include "utils.h"

// Matris çarpımı: result = matrixA * matrixB
void matrix_multiply(int rowsA, int colsA, int colsB, double** matrixA, double** matrixB, double** result) {
    if (!matrixA || !matrixB || !result) {
        return;
    }
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0.0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

// Matris transpozu
void transpose_matrix(int rows, int cols, double** matrix, double** result) {
    if (!matrix || !result) {
        return;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

// Matrisin tersi (Gauss-Jordan Eliminasyonu)
// 0 dönerse başarılı, -1 dönerse matris tekildir (determinant 0, tersi yok).
int matrix_inverse(int n, double** matrix, double** inverse) {
    if (n <= 0 || !matrix || !inverse) {
        return -1;
    }

    // Geçici n x (2n) genişletilmiş matris oluştur: [A | I]
    double** aug = create_matrix(n, 2 * n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            aug[i][j] = matrix[i][j];
            aug[i][j + n] = (i == j) ? 1.0 : 0.0;
        }
    }

    // Gauss-Jordan eliminasyonu
    for (int i = 0; i < n; i++) {
        // En büyük pivot elemanı bul (kısmi pivotlama)
        int max_row = i;
        double max_val = fabs(aug[i][i]);
        for (int k = i + 1; k < n; k++) {
            if (fabs(aug[k][i]) > max_val) {
                max_val = fabs(aug[k][i]);
                max_row = k;
            }
        }

        // Pivot sıfıra çok yakınsa, matris tekildir
        if (max_val < 1e-12) {
            free_matrix(aug, n);
            return -1;
        }

        // Satırları takasla
        if (max_row != i) {
            swap_rows(2 * n, aug, i, max_row);
        }

        // Pivot satırını normalize et (pivotu 1 yap)
        double pivot = aug[i][i];
        for (int j = 0; j < 2 * n; j++) {
            aug[i][j] /= pivot;
        }

        // Diğer tüm satırları sıfırla
        for (int k = 0; k < n; k++) {
            if (k != i) {
                double factor = aug[k][i];
                for (int j = 0; j < 2 * n; j++) {
                    aug[k][j] -= factor * aug[i][j];
                }
            }
        }
    }

    // Sağ taraftaki [I | A^-1] matrisini inverse'e kopyala
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inverse[i][j] = aug[i][j + n];
        }
    }

    free_matrix(aug, n);
    return 0;
}

// Matris determinantı (Gauss Eliminasyonu ile)
double matrix_determinant(int n, double** matrix) {
    if (n <= 0 || !matrix) {
        return 0.0;
    }

    // Orijinal matrisi bozmamak için kopyasını oluştur
    double** temp = create_matrix(n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = matrix[i][j];
        }
    }

    double det = 1.0;
    for (int i = 0; i < n; i++) {
        int max_row = i;
        double max_val = fabs(temp[i][i]);
        for (int k = i + 1; k < n; k++) {
            if (fabs(temp[k][i]) > max_val) {
                max_val = fabs(temp[k][i]);
                max_row = k;
            }
        }

        if (max_val < 1e-12) {
            free_matrix(temp, n);
            return 0.0;
        }

        if (max_row != i) {
            swap_rows(n, temp, i, max_row);
            det = -det;
        }

        det *= temp[i][i];

        for (int k = i + 1; k < n; k++) {
            double factor = temp[k][i] / temp[i][i];
            for (int j = i; j < n; j++) {
                temp[k][j] -= factor * temp[i][j];
            }
        }
    }

    free_matrix(temp, n);
    return det;
}
