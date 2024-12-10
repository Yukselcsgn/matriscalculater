#include <stdio.h>
#include <math.h>
#include "vector_operations.h"

// Nokta çarpýmý
double dot_product(int size, double* vectorA, double* vectorB) {
    double result = 0.0;
    for (int i = 0; i < size; i++) {
        result += vectorA[i] * vectorB[i];
    }
    return result;
}

// Çapraz çarpým
void cross_product(double* vectorA, double* vectorB, double* result) {
    result[0] = vectorA[1] * vectorB[2] - vectorA[2] * vectorB[1];
    result[1] = vectorA[2] * vectorB[0] - vectorA[0] * vectorB[2];
    result[2] = vectorA[0] * vectorB[1] - vectorA[1] * vectorB[0];
}

// Vektör normu
double vector_magnitude(int size, double* vector) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += vector[i] * vector[i];
    }
    return sqrt(sum);
}

// Vektör ölçekleme
void scale_vector(int size, double* vector, double scalar) {
    for (int i = 0; i < size; i++) {
        vector[i] *= scalar;
    }
}

