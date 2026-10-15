#ifndef GAUSS_OPERATIONS_H
#define GAUSS_OPERATIONS_H

#include <stdbool.h>

// Genişletilmiş matrisi üst üçgensel forma indirgeme
bool gaussian_elimination(int rows, int cols, double** matrix);

// Geriye yerine koyma ile bilinmeyenleri çözme
void backward_substitution(int rows, int cols, double** matrix, double* solutions);

#endif
