#ifndef VECTOR_OPERATIONS_H
#define VECTOR_OPERATIONS_H

// Nokta çarpýmý
double dot_product(int size, double* vectorA, double* vectorB);

// Çapraz çarpým
void cross_product(double* vectorA, double* vectorB, double* result);

// Vektör normu
double vector_magnitude(int size, double* vector);

// Vektör ölçekleme
void scale_vector(int size, double* vector, double scalar);

#endif

