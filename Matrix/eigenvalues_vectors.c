#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "eigenvalues_vectors.h"
#include "utils.h"

// Jacobi rotasyonu ile simetrik matrislerin özdeğer ve özvektörlerini hesaplama
int eigenvalue_vector(double** matrix, double* eigenvalues, double** eigenvectors, int n) {
    if (!matrix || !eigenvalues || !eigenvectors || n <= 0) {
        return -1;
    }

    // Orijinal matrisi korumak için yerel kopyasını al
    double** a = create_matrix(n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = matrix[i][j];
        }
    }

    // Matrisin simetrik olup olmadığını kontrol et
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (fabs(a[i][j] - a[j][i]) > 1e-6) {
                printf("Uyari: Jacobi metodu yalnizca simetrik matrisler icin gecerlidir!\n");
                free_matrix(a, n);
                return -1;
            }
        }
    }

    // Özvektör matrisini birim matris (Identity) olarak başlat
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            eigenvectors[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }

    double tolerance = 1e-10;
    int max_iterations = 100 * n * n;
    int iter = 0;

    while (iter < max_iterations) {
        // Köşegen dışındaki mutlak en büyük elemanı bul (p, q)
        int p = 0, q = 1;
        double max_val = 0.0;

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (fabs(a[i][j]) > max_val) {
                    max_val = fabs(a[i][j]);
                    p = i;
                    q = j;
                }
            }
        }

        // Toleransın altına indiyse yakınsama sağlandı
        if (max_val < tolerance) {
            break;
        }

        // Jacobi rotasyon açısını hesapla
        double apq = a[p][q];
        double theta = (a[q][q] - a[p][p]) / (2.0 * apq);
        double t;
        if (theta >= 0.0) {
            t = 1.0 / (theta + sqrt(1.0 + theta * theta));
        } else {
            t = -1.0 / (-theta + sqrt(1.0 + theta * theta));
        }

        double c = 1.0 / sqrt(1.0 + t * t);
        double s = t * c;

        // Köşegen elemanlarını güncelle
        a[p][p] -= t * apq;
        a[q][q] += t * apq;
        a[p][q] = 0.0;
        a[q][p] = 0.0;

        // Diğer elemanları güncelle
        for (int k = 0; k < n; k++) {
            if (k != p && k != q) {
                double akp = a[k][p];
                double akq = a[k][q];
                a[k][p] = a[p][k] = c * akp - s * akq;
                a[k][q] = a[q][k] = s * akp + c * akq;
            }
        }

        // Özvektör matrisini güncelle (sütun rotasyonu)
        for (int k = 0; k < n; k++) {
            double vkp = eigenvectors[k][p];
            double vkq = eigenvectors[k][q];
            eigenvectors[k][p] = c * vkp - s * vkq;
            eigenvectors[k][q] = s * vkp + c * vkq;
        }

        iter++;
    }

    // Köşegen değerleri özdeğerlerdir
    for (int i = 0; i < n; i++) {
        eigenvalues[i] = a[i][i];
    }

    free_matrix(a, n);
    return 0;
}
