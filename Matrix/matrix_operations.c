#include <stdio.h>
#include <stdlib.h>
#include "matrix_operations.h"

// Matris çarpýmý
void matrix_multiply(int rowsA, int colsA, int colsB, double** matrixA, double** matrixB, double** result) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0.0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

// Matris transpozesi
void transpose_matrix(int rows, int cols, double** matrix, double** result) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

// Matris oluþturma
double** allocate_matrix(int rows, int cols) {
    double** matrix = (double**)malloc(rows * sizeof(double*));
    if (!matrix) {
        fprintf(stderr, "Bellek tahsisi baþarýsýz.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < rows; i++) {
        matrix[i] = (double*)malloc(cols * sizeof(double));
        if (!matrix[i]) {
            fprintf(stderr, "Bellek tahsisi baþarýsýz.\n");
            exit(EXIT_FAILURE);
        }
    }

    return matrix;
}

// Matris serbest býrakma
void free_matrix(int rows, double** matrix) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

