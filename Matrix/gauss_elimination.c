#include <stdio.h>
#include <math.h>
#include "gauss_elimination.h"

// Gauss Eliminasyonu ile çözüm
int gauss_elimination(double** matrix, double* result, int n) {
    double temp;
    for (int i = 0; i < n; i++) {
        // Pivot elemanýný bul
        if (matrix[i][i] == 0) {
            return 0; // Eðer sýfýr pivot varsa, çözüm yoktur.
        }
        
        // Pivot elemanýný 1 yap
        temp = matrix[i][i];
        for (int j = 0; j < n; j++) {
            matrix[i][j] /= temp;
        }
        result[i] /= temp;

        // Diðer satýrlarda bu satýrý sýfýrlamak için
        for (int j = i + 1; j < n; j++) {
            temp = matrix[j][i];
            for (int k = i; k < n; k++) {
                matrix[j][k] -= matrix[i][k] * temp;
            }
            result[j] -= result[i] * temp;
        }
    }

    // Geriye doðru çözümleme
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            temp = matrix[j][i];
            matrix[j][i] -= matrix[i][i] * temp;
            result[j] -= result[i] * temp;
        }
    }

    return 1; // Baþarýlý çözüm
}

// Satýr indirgeme
void row_reduce(double** matrix, double* result, int n) {
    double temp;
    for (int i = 0; i < n; i++) {
        // Pivot bulma
        if (matrix[i][i] == 0) {
            printf("Sýfýr pivot hatasý!\n");
            return;
        }

        // Satýrý indirgeme
        for (int j = 0; j < n; j++) {
            matrix[i][j] /= matrix[i][i];
        }
        result[i] /= matrix[i][i];

        // Diðer satýrlarda sýfýrlama
        for (int k = 0; k < n; k++) {
            if (k != i) {
                temp = matrix[k][i];
                for (int j = 0; j < n; j++) {
                    matrix[k][j] -= matrix[i][j] * temp;
                }
                result[k] -= result[i] * temp;
            }
        }
    }
}

