#include <stdio.h>
#include <math.h>
#include "vector_operations.h"

// Nokta çarpımı (Dot product)
double dot_product(int size, double* vectorA, double* vectorB) {
    if (!vectorA || !vectorB || size <= 0) {
        return 0.0;
    }
    double result = 0.0;
    for (int i = 0; i < size; i++) {
        result += vectorA[i] * vectorB[i];
    }
    return result;
}

// Çapraz çarpım (3 boyutlu vektörler için)
void cross_product(double* vectorA, double* vectorB, double* result) {
    if (!vectorA || !vectorB || !result) {
        return;
    }
    result[0] = vectorA[1] * vectorB[2] - vectorA[2] * vectorB[1];
    result[1] = vectorA[2] * vectorB[0] - vectorA[0] * vectorB[2];
    result[2] = vectorA[0] * vectorB[1] - vectorA[1] * vectorB[0];
}

// Vektör normu / büyüklüğü
double vector_magnitude(int size, double* vector) {
    if (!vector || size <= 0) {
        return 0.0;
    }
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += vector[i] * vector[i];
    }
    return sqrt(sum);
}

// Vektör ölçekleme
void scale_vector(int size, double* vector, double scalar) {
    if (!vector || size <= 0) {
        return;
    }
    for (int i = 0; i < size; i++) {
        vector[i] *= scalar;
    }
}
