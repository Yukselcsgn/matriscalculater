#ifndef GAUSS_ELIMINATION_H
#define GAUSS_ELIMINATION_H

// Gauss Eliminasyonu ile çözüm
int gauss_elimination(double** matrix, double* result, int n);

// Satýr indirgeme (Row reduction)
void row_reduce(double** matrix, double* result, int n);

#endif

