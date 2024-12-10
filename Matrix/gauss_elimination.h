#ifndef GAUSS_ELIMINATION_H
#define GAUSS_ELIMINATION_H

// Gauss Eliminasyonu ile ��z�m
int gauss_elimination(double** matrix, double* result, int n);

// Sat�r indirgeme (Row reduction)
void row_reduce(double** matrix, double* result, int n);

#endif

