#include <stdio.h>
#include <stdlib.h>
#include "matrix_operations.h"
#include "vector_operations.h"
#include "gauss_elimination.h"

// Dinamik matris oluþturma fonksiyonu
double** create_matrix(int rows, int cols) {
    double** matrix = (double**)malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (double*)malloc(cols * sizeof(double));
    }
    return matrix;
}

// Dinamik vektör oluþturma fonksiyonu
double* create_vector(int size) {
    return (double*)malloc(size * sizeof(double));
}

// Matrisin belleðini serbest býrakma fonksiyonu
void free_matrix(int rows, double** matrix) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Vektörün belleðini serbest býrakma fonksiyonu
void free_vector(double* vector) {
    free(vector);
}

int main() {
    int choice, n, m;
    double** matrix;
    double* result;
    
    // Menü
    do {
        printf("\n---- Lineer Cebir Programi ----\n");
        printf("1. Matris Carpimi\n");
        printf("2. Matris Transpozu\n");
        printf("3. Matrisin Tersi\n");
        printf("4. Gauss Eliminasyonu\n");
        printf("5. Vektor Islemleri\n");
        printf("6. Cikis\n");
        printf("Seciminizi yapin: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Matris Çarpýmý
                printf("Birinci matrisin satir sayisini girin: ");
                scanf("%d", &n);
                printf("Birinci matrisin sutun sayisini girin: ");
                scanf("%d", &m);
                
                matrix = create_matrix(n, m);
                printf("Birinci matrisi girin:\n");
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        scanf("%lf", &matrix[i][j]);
                    }
                }
                
                printf("Ikinci matrisin satir sayisini girin: ");
                scanf("%d", &m);
                printf("Ikinci matrisin sutun sayisini girin: ");
                scanf("%d", &n);
                
                double** matrix2 = create_matrix(n, m);
                printf("Ikinci matrisi girin:\n");
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        scanf("%lf", &matrix2[i][j]);
                    }
                }
                
                double** result_matrix = create_matrix(n, m);
                matrix_multiply(matrix, matrix2, result_matrix, n, m);
                
                printf("Matris Carpimi Sonucu:\n");
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        printf("%.2f ", result_matrix[i][j]);
                    }
                    printf("\n");
                }
                
                free_matrix(matrix, n);
                free_matrix(matrix2, n);
                free_matrix(result_matrix, n);
                break;

            case 2: // Matris Transpozu
                printf("Matrisin satir sayisini girin: ");
                scanf("%d", &n);
                printf("Matrisin sutun sayisini girin: ");
                scanf("%d", &m);
                
                matrix = create_matrix(n, m);
                printf("Matrisin elemanlarini girin:\n");
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        scanf("%lf", &matrix[i][j]);
                    }
                }
                
                double** transpose_matrix = create_matrix(m, n);
                matrix_transpose(matrix, transpose_matrix, n, m);
                
                printf("Matrisin Transpozu:\n");
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n; j++) {
                        printf("%.2f ", transpose_matrix[i][j]);
                    }
                    printf("\n");
                }
                
                free_matrix(matrix, n);
                free_matrix(transpose_matrix, m);
                break;

            case 3: // Matrisin Tersi
                printf("Matrisin boyutunu girin (NxN): ");
                scanf("%d", &n);
                
                matrix = create_matrix(n, n);
                printf("Matrisin elemanlarini girin:\n");
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        scanf("%lf", &matrix[i][j]);
                    }
                }
                
                result = create_vector(n);
                int result_code = matrix_inverse(matrix, result, n);
                
                if (result_code == 0) {
                    printf("Matrisin Tersi:\n");
                    for (int i = 0; i < n; i++) {
                        printf("%.2f ", result[i]);
                    }
                    printf("\n");
                } else {
                    printf("Matrisin tersi bulunamadi.\n");
                }
                
                free_matrix(matrix, n);
                free_vector(result);
                break;

            case 4: // Gauss Eliminasyonu
                printf("Denklem sistemi boyutunu girin: ");
                scanf("%d", &n);
                
                matrix = create_matrix(n, n + 1); // Sonuçlarý da içeriyor
                result = create_vector(n);
                
                printf("Denklem sistemini girin (Nx(N+1) matris):\n");
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n + 1; j++) {
                        scanf("%lf", &matrix[i][j]);
                    }
                }
                
                int gauss_code = gauss_elimination(matrix, result, n);
                
                if (gauss_code == 0) {
                    printf("Denklem sistemi cozuldu:\n");
                    for (int i = 0; i < n; i++) {
                        printf("x%d = %.2f\n", i + 1, result[i]);
                    }
                } else {
                    printf("Denklem sistemi cozulmedi.\n");
                }
                
                free_matrix(matrix, n);
                free_vector(result);
                break;

            case 5: // Vektör Ýþlemleri
                printf("Vektör islemleri (Dot Product, Cross Product) secildi.\n");
                // Vektör iþlemleri fonksiyonu burada çalýþtýrýlacak
                break;

            case 6: // Çýkýþ
                printf("Programdan cikiliyor...\n");
                break;

            default:
                printf("Gecersiz secim!\n");
                break;
        }

    } while (choice != 6);

    return 0;
}

