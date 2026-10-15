#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

// Dinamik matris oluşturma
double** create_matrix(int rows, int cols) {
    if (rows <= 0 || cols <= 0) {
        return NULL;
    }
    double** matrix = (double**)malloc(rows * sizeof(double*));
    if (!matrix) {
        fprintf(stderr, "Bellek tahsisi basarisiz.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < rows; i++) {
        matrix[i] = (double*)malloc(cols * sizeof(double));
        if (!matrix[i]) {
            fprintf(stderr, "Bellek tahsisi basarisiz.\n");
            for (int k = 0; k < i; k++) {
                free(matrix[k]);
            }
            free(matrix);
            exit(EXIT_FAILURE);
        }
    }
    return matrix;
}

// Dinamik matris serbest bırakma
void free_matrix(double** matrix, int rows) {
    if (!matrix) {
        return;
    }
    for (int i = 0; i < rows; i++) {
        if (matrix[i]) {
            free(matrix[i]);
        }
    }
    free(matrix);
}

// Dinamik vektör oluşturma
double* create_vector(int size) {
    if (size <= 0) {
        return NULL;
    }
    double* vector = (double*)malloc(size * sizeof(double));
    if (!vector) {
        fprintf(stderr, "Bellek tahsisi basarisiz.\n");
        exit(EXIT_FAILURE);
    }
    return vector;
}

// Vektör serbest bırakma
void free_vector(double* vector) {
    if (vector) {
        free(vector);
    }
}

// Matris yazdırma
void print_matrix(int rows, int cols, double** matrix) {
    if (!matrix) {
        return;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%8.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Vektör yazdırma
void print_vector(int size, double* vector) {
    if (!vector) {
        return;
    }
    for (int i = 0; i < size; i++) {
        printf("v[%d] = %8.2f\n", i + 1, vector[i]);
    }
}

// Matris başlangıç değeri ile doldurma
void initialize_matrix(int rows, int cols, double** matrix, double value) {
    if (!matrix) {
        return;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = value;
        }
    }
}

// Satır takaslama
void swap_rows(int cols, double** matrix, int row1, int row2) {
    if (!matrix || row1 == row2) {
        return;
    }
    for (int i = 0; i < cols; i++) {
        double temp = matrix[row1][i];
        matrix[row1][i] = matrix[row2][i];
        matrix[row2][i] = temp;
    }
}
