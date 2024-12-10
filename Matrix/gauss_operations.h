#ifndef GAUSS_OPERATIONS_H
#define GAUSS_OPERATIONS_H

// Gerekli ba�l�k dosyalar�
#include <stdbool.h>

// Fonksiyon bildirimleri
bool gaussian_elimination(int rows, int cols, double** matrix, double* solutions);
void backward_substitution(int rows, int cols, double** matrix, double* solutions);

#endif

