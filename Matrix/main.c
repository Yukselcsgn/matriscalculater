#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "matrix_operations.h"
#include "matrix_transpose.h"
#include "gauss_elimination.h"
#include "vector_operations.h"
#include "eigenvalues_vectors.h"

// Vektör işlemleri alt menüsü
void handle_vector_operations() {
    int subchoice;
    printf("\n--- Vektor Islemleri Menusu ---\n");
    printf("1. Nokta Carpimi (Dot Product)\n");
    printf("2. Capraz Carpim (Cross Product - 3 Boyutlu)\n");
    printf("3. Vektor Normu (Uzunluk)\n");
    printf("4. Vektoru Skaler ile Olcekleme\n");
    printf("Seciminizi yapin: ");
    if (scanf("%d", &subchoice) != 1) return;

    if (subchoice == 1) {
        int size;
        printf("Vektor boyutunu girin: ");
        if (scanf("%d", &size) != 1 || size <= 0) return;

        double* v1 = create_vector(size);
        double* v2 = create_vector(size);

        printf("1. Vektor elemanlarini girin:\n");
        for (int i = 0; i < size; i++) scanf("%lf", &v1[i]);

        printf("2. Vektor elemanlarini girin:\n");
        for (int i = 0; i < size; i++) scanf("%lf", &v2[i]);

        double dot = dot_product(size, v1, v2);
        printf("\nNokta Carpimi Sonucu: %.4f\n", dot);

        free_vector(v1);
        free_vector(v2);
    } else if (subchoice == 2) {
        double* v1 = create_vector(3);
        double* v2 = create_vector(3);
        double* res = create_vector(3);

        printf("1. Vektor elemanlarini girin (3 eleman):\n");
        for (int i = 0; i < 3; i++) scanf("%lf", &v1[i]);

        printf("2. Vektor elemanlarini girin (3 eleman):\n");
        for (int i = 0; i < 3; i++) scanf("%lf", &v2[i]);

        cross_product(v1, v2, res);
        printf("\nCapraz Carpim Sonucu:\n");
        printf("[ %.4f, %.4f, %.4f ]\n", res[0], res[1], res[2]);

        free_vector(v1);
        free_vector(v2);
        free_vector(res);
    } else if (subchoice == 3) {
        int size;
        printf("Vektor boyutunu girin: ");
        if (scanf("%d", &size) != 1 || size <= 0) return;

        double* v = create_vector(size);
        printf("Vektor elemanlarini girin:\n");
        for (int i = 0; i < size; i++) scanf("%lf", &v[i]);

        double mag = vector_magnitude(size, v);
        printf("\nVektorun Normu (Uzunlugu): %.4f\n", mag);

        free_vector(v);
    } else if (subchoice == 4) {
        int size;
        double scalar;
        printf("Vektor boyutunu girin: ");
        if (scanf("%d", &size) != 1 || size <= 0) return;

        double* v = create_vector(size);
        printf("Vektor elemanlarini girin:\n");
        for (int i = 0; i < size; i++) scanf("%lf", &v[i]);

        printf("Skaler carpani girin: ");
        if (scanf("%lf", &scalar) != 1) {
            free_vector(v);
            return;
        }

        scale_vector(size, v, scalar);
        printf("\nOlceklenmis Vektor:\n");
        for (int i = 0; i < size; i++) {
            printf("%.4f ", v[i]);
        }
        printf("\n");

        free_vector(v);
    } else {
        printf("Gecersiz alt secim!\n");
    }
}

int main() {
    int choice;

    do {
        printf("\n====================================\n");
        printf("       LINEER CEBIR HESAPLAYICI     \n");
        printf("====================================\n");
        printf("1. Matris Carpimi\n");
        printf("2. Matris Transpozu\n");
        printf("3. Matrisin Tersi ve Determinanti\n");
        printf("4. Gauss Eliminasyonu (Ax = b Cozumu)\n");
        printf("5. Vektor Islemleri\n");
        printf("6. Ozdeger ve Ozvektorler (Jacobi Metodu)\n");
        printf("7. Cikis\n");
        printf("Seciminizi yapin (1-7): ");

        if (scanf("%d", &choice) != 1) {
            printf("Gecersiz giris yapildi!\n");
            break;
        }

        switch (choice) {
            case 1: { // Matris Çarpımı
                int rA, cA, rB, cB;
                printf("\n--- Matris Carpimi ---\n");
                printf("1. Matrisin satir sayisini girin: ");
                scanf("%d", &rA);
                printf("1. Matrisin sutun sayisini girin: ");
                scanf("%d", &cA);

                printf("2. Matrisin satir sayisini girin: ");
                scanf("%d", &rB);
                printf("2. Matrisin sutun sayisini girin: ");
                scanf("%d", &cB);

                if (cA != rB) {
                    printf("\nHata: 1. matrisin sutun sayisi (%d), 2. matrisin satir sayisina (%d) esit olmalidir!\n", cA, rB);
                    break;
                }

                double** matrixA = create_matrix(rA, cA);
                printf("1. Matris elemanlarini girin (%d x %d):\n", rA, cA);
                for (int i = 0; i < rA; i++) {
                    for (int j = 0; j < cA; j++) {
                        scanf("%lf", &matrixA[i][j]);
                    }
                }

                double** matrixB = create_matrix(rB, cB);
                printf("2. Matris elemanlarini girin (%d x %d):\n", rB, cB);
                for (int i = 0; i < rB; i++) {
                    for (int j = 0; j < cB; j++) {
                        scanf("%lf", &matrixB[i][j]);
                    }
                }

                double** result_matrix = create_matrix(rA, cB);
                matrix_multiply(rA, cA, cB, matrixA, matrixB, result_matrix);

                printf("\nMatris Carpimi Sonucu (%d x %d):\n", rA, cB);
                print_matrix(rA, cB, result_matrix);

                free_matrix(matrixA, rA);
                free_matrix(matrixB, rB);
                free_matrix(result_matrix, rA);
                break;
            }

            case 2: { // Matris Transpozu
                int rows, cols;
                printf("\n--- Matris Transpozu ---\n");
                printf("Matrisin satir sayisini girin: ");
                scanf("%d", &rows);
                printf("Matrisin sutun sayisini girin: ");
                scanf("%d", &cols);

                double** matrix = create_matrix(rows, cols);
                printf("Matrisin elemanlarini girin:\n");
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        scanf("%lf", &matrix[i][j]);
                    }
                }

                double** transpose = create_matrix(cols, rows);
                matrix_transpose(matrix, transpose, rows, cols);

                printf("\nMatrisin Transpozu (%d x %d):\n", cols, rows);
                print_matrix(cols, rows, transpose);

                free_matrix(matrix, rows);
                free_matrix(transpose, cols);
                break;
            }

            case 3: { // Matrisin Tersi ve Determinantı
                int n;
                printf("\n--- Matrisin Tersi ve Determinanti ---\n");
                printf("Kare matrisin boyutunu girin (NxN): ");
                scanf("%d", &n);

                if (n <= 0) {
                    printf("Gecersiz boyut!\n");
                    break;
                }

                double** matrix = create_matrix(n, n);
                printf("Matris elemanlarini girin:\n");
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        scanf("%lf", &matrix[i][j]);
                    }
                }

                double det = matrix_determinant(n, matrix);
                printf("\nMatrisin Determinanti: %.4f\n", det);

                double** inverse = create_matrix(n, n);
                int status = matrix_inverse(n, matrix, inverse);

                if (status == 0) {
                    printf("\nMatrisin Tersi:\n");
                    print_matrix(n, n, inverse);
                } else {
                    printf("\nMatris tekildir (determinant 0), tersi yoktur.\n");
                }

                free_matrix(matrix, n);
                free_matrix(inverse, n);
                break;
            }

            case 4: { // Gauss Eliminasyonu (Ax = b)
                int n;
                printf("\n--- Gauss Eliminasyonu (Ax = b) ---\n");
                printf("Bilinmeyen sayisini girin (N): ");
                scanf("%d", &n);

                if (n <= 0) {
                    printf("Gecersiz boyut!\n");
                    break;
                }

                // Genişletilmiş katsayılar matrisi: N satır, (N+1) sütun [A | b]
                double** aug_matrix = create_matrix(n, n + 1);
                double* solutions = create_vector(n);

                printf("Genisletilmis matrisi girin (Her satirda N katsayi ve 1 sonuc degeri):\n");
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n + 1; j++) {
                        scanf("%lf", &aug_matrix[i][j]);
                    }
                }

                int success = gauss_elimination(aug_matrix, solutions, n);

                if (success) {
                    printf("\nDenklem Sistemi Cozuldu:\n");
                    for (int i = 0; i < n; i++) {
                        printf("x%d = %.4f\n", i + 1, solutions[i]);
                    }
                } else {
                    printf("\nDenklem sistemi cozumsuz veya sonsuz cozumlu (tekil pivot)!\n");
                }

                free_matrix(aug_matrix, n);
                free_vector(solutions);
                break;
            }

            case 5: { // Vektör İşlemleri
                handle_vector_operations();
                break;
            }

            case 6: { // Özdeğer ve Özvektörler
                int n;
                printf("\n--- Ozdeger ve Ozvektorler (Jacobi Metodu) ---\n");
                printf("Simetrik matrisin boyutunu girin (NxN): ");
                scanf("%d", &n);

                if (n <= 0) {
                    printf("Gecersiz boyut!\n");
                    break;
                }

                double** matrix = create_matrix(n, n);
                printf("Simetrik matris elemanlarini girin:\n");
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        scanf("%lf", &matrix[i][j]);
                    }
                }

                double* eigenvalues = create_vector(n);
                double** eigenvectors = create_matrix(n, n);

                int res = eigenvalue_vector(matrix, eigenvalues, eigenvectors, n);

                if (res == 0) {
                    printf("\nOzdegerler:\n");
                    for (int i = 0; i < n; i++) {
                        printf("lambda_%d = %.4f\n", i + 1, eigenvalues[i]);
                    }

                    printf("\nOzvektorler (Her sutun bir ozvektordur):\n");
                    print_matrix(n, n, eigenvectors);
                } else {
                    printf("Ozdeger hesaplamasi basarisiz oldu.\n");
                }

                free_matrix(matrix, n);
                free_vector(eigenvalues);
                free_matrix(eigenvectors, n);
                break;
            }

            case 7: {
                printf("\nProgramdan cikiliyor. Iyi gunler!\n");
                break;
            }

            default: {
                printf("Gecersiz secim! Lutfen 1-7 arasinda bir secim yapin.\n");
                break;
            }
        }

    } while (choice != 7);

    return 0;
}
