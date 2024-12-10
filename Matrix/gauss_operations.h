#ifndef GAUSS_OPERATIONS_H
#define GAUSS_OPERATIONS_H

// Gerekli baþlýk dosyalarý
#include <stdbool.h>

// Fonksiyon bildirimleri
bool gaussian_elimination(int rows, int cols, double** matrix, double* solutions);
void backward_substitution(int rows, int cols, double** matrix, double* solutions);

#endif

