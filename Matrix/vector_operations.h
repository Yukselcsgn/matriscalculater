#ifndef VECTOR_OPERATIONS_H
#define VECTOR_OPERATIONS_H

// Nokta �arp�m�
double dot_product(int size, double* vectorA, double* vectorB);

// �apraz �arp�m
void cross_product(double* vectorA, double* vectorB, double* result);

// Vekt�r normu
double vector_magnitude(int size, double* vector);

// Vekt�r �l�ekleme
void scale_vector(int size, double* vector, double scalar);

#endif

