#ifndef GAUSS_ELIMINATION_H
#define GAUSS_ELIMINATION_H

// Gauss Eliminasyonu ile Ax = b denklem sistemini çözme
// matrix: n x (n + 1) genişletilmiş matris [A | b]
// result: n elemanlı çözüm vektörü [x1, x2, ..., xn]
// Dönüş: 1 = Başarılı çözüm, 0 = Çözümsüz veya sonsuz çözümlü
int gauss_elimination(double** matrix, double* result, int n);

#endif
