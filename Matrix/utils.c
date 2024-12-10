#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

// Dinamik matris olu�turma
double** create_matrix(int rows, int cols) {
    double** matrix = (double**)malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (double*)malloc(cols * sizeof(double));
    }
    return matrix;
}

// Dinamik matris serbest b�rakma
void free_matrix(double** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Matris yazd�rma
void print_matrix(int rows, int cols, double** matrix) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%8.3f ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Matris ba�lang�� de�eri ile doldurma
void initialize_matrix(int rows, int cols, double** matrix, double value) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = value;
        }
    }
}

// Sat�r de�i�tirme (Gaus eliminasyonu i�in gerekli)
void swap_rows(int cols, double** matrix, int row1, int row2) {
    for (int i = 0; i < cols; i++) {
        double temp = matrix[row1][i];
        matrix[row1][i] = matrix[row2][i];
        matrix[row2][i] = temp;
    }
}

