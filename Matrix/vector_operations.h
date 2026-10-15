#ifndef VECTOR_OPERATIONS_H
#define VECTOR_OPERATIONS_H

// Nokta çarpımı (Dot product)
double dot_product(int size, double* vectorA, double* vectorB);

// Çapraz çarpım (Cross product - 3 boyutlu vektörler için)
void cross_product(double* vectorA, double* vectorB, double* result);

// Vektör normu (büyüklüğü / uzunluğu)
double vector_magnitude(int size, double* vector);

// Vektör ölçekleme (skaler ile çarpım)
void scale_vector(int size, double* vector, double scalar);

#endif
