#include <stdio.h>
#include <math.h>
#include "gauss_elimination.h"
#include "gauss_operations.h"

// Gauss Eliminasyonu ile Ax = b sistemini çözme
int gauss_elimination(double** matrix, double* result, int n) {
    if (!matrix || !result || n <= 0) {
        return 0;
    }

    if (!gaussian_elimination(n, n + 1, matrix)) {
        return 0; // Sistem tekil veya tutarsız
    }

    backward_substitution(n, n + 1, matrix, result);
    return 1; // Başarılı
}
