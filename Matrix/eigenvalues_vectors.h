#ifndef EIGENVALUES_VECTORS_H
#define EIGENVALUES_VECTORS_H

// Simetrik matrisler için Jacobi rotasyonu ile özdeğer ve özvektör hesaplama
// matrix: n x n boyutunda simetrik matris
// eigenvalues: n elemanlı özdeğer dizisi
// eigenvectors: n x n boyutunda özvektörler matrisi (sütunlar özvektörleri temsil eder)
// Dönüş: 0 = Başarılı, -1 = Simetrik değil veya yakınsamadı
int eigenvalue_vector(double** matrix, double* eigenvalues, double** eigenvectors, int n);

#endif
