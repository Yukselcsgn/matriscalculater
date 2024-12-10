#include <stdio.h>
#include <math.h>
#include "eigenvalues_vectors.h"

// Jacobi rotasyonu ile �zde�er ve �zvekt�r hesaplama
int eigenvalue_vector(double** matrix, double* eigenvalues, double** eigenvectors, int n) {
    double tolerance = 1.0e-10;
    double max_off_diag = 0.0;
    double temp;
    
    // �lk olarak �zvekt�r matrisini birim matris olarak ayarla
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            eigenvectors[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }

    // Ana d�ng�: Jacobi rotasyonlar� ile matrisin �zde�erleri ve �zvekt�rleri hesaplanacak
    do {
        max_off_diag = 0.0;

        // Matrisin d�� ��gen k�sm�ndaki her ��e i�in
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                temp = fabs(matrix[i][j]);

                // E�er d�� ��gen ��esi tolerans de�erini a�arsa
                if (temp > max_off_diag) {
                    max_off_diag = temp;

                    // Jacobi rotasyonunu uygula
                    double tau, t, c, s;
                    tau = (matrix[j][j] - matrix[i][i]) / (2 * matrix[i][j]);
                    t = (tau >= 0) ? (1.0 / (tau + sqrt(1 + tau * tau))) : (-1.0 / (-tau + sqrt(1 + tau * tau)));
                    c = 1.0 / sqrt(1 + t * t);
                    s = c * t;

                    // Matrisin ��elerini g�ncelle
                    double temp_i_j = matrix[i][j];
                    matrix[i][j] = 0.0;
                    matrix[j][i] = 0.0;

                    for (int k = 0; k < n; k++) {
                        if (k != i && k != j) {
                            double temp_ik = matrix[i][k];
                            matrix[i][k] = c * temp_ik - s * matrix[j][k];
                            matrix[j][k] = s * temp_ik + c * matrix[j][k];
                            matrix[k][i] = matrix[i][k];
                        }
                    }

                    // �zvekt�rleri g�ncelle
                    for (int k = 0; k < n; k++) {
                        double temp_ik = eigenvectors[i][k];
                        eigenvectors[i][k] = c * temp_ik - s * eigenvectors[j][k];
                        eigenvectors[j][k] = s * temp_ik + c * eigenvectors[j][k];
                    }
                }
            }
        }
    } while (max_off_diag > tolerance);

    // �zde�erleri almak i�in matrisin diagonal�n� al
    for (int i = 0; i < n; i++) {
        eigenvalues[i] = matrix[i][i];
    }

    return 0; // Ba�ar�l�
}

