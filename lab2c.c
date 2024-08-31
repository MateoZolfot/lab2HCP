#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función para generar una matriz nxn con valores aleatorios entre 0 y 1
void generate_matrix(double** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = (double)rand() / RAND_MAX;
        }
    }
}

// Función para multiplicar dos matrices nxn
void multiply_matrices(double** a, double** b, double** result, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// Función para imprimir una matriz nxn
void print_matrix(double** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the dimension n for the nxn matrices: ");
    scanf("%d", &n);

    // Reservar memoria para las matrices
    double** A = (double**)malloc(n * sizeof(double*));
    double** B = (double**)malloc(n * sizeof(double*));
    double** C = (double**)malloc(n * sizeof(double*));

    for (int i = 0; i < n; i++) {
        A[i] = (double*)malloc(n * sizeof(double));
        B[i] = (double*)malloc(n * sizeof(double));
        C[i] = (double*)malloc(n * sizeof(double));
    }

    // Medir el tiempo para generar la primera matriz
    clock_t start_time = clock();
    generate_matrix(A, n);
    clock_t end_time = clock();
    double generation_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Time to generate a matrix: %f seconds\n", generation_time);

    // Generar la segunda matriz (no se mide el tiempo de esta para seguir las indicaciones)
    generate_matrix(B, n);

    // Medir el tiempo para la multiplicación de matrices
    start_time = clock();
    multiply_matrices(A, B, C, n);
    end_time = clock();
    double multiplication_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Time to do the product: %f seconds\n", multiplication_time);

    // Liberar memoria
    for (int i = 0; i < n; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);

    return 0;
}
