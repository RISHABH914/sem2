#include <stdio.h>
#include <stdlib.h>

static inline int* multiplyMatricesModC(const int* A, int rA, int cA, const int* B, int rB, int cB, int mod) {
    if (cA != rB) return NULL;
    int* C = (int*) malloc(rA * cB * sizeof(int));
    if (!C) return NULL;

    for (int i = 0; i < rA; i++) {
        for (int j = 0; j < cB; j++) {
            long sum = 0;
            for (int k = 0; k < cA; k++)
                sum = (sum + ((long)A[i * cA + k] * B[k * cB + j]) % mod) % mod;
            C[i * cB + j] = (int)(sum % mod);
        }
    }
    return C;
}

static inline void printMatrixC(const int* mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%d ", mat[i * cols + j]);
        printf("\n");
    }
}

int main() {
    int n, m, x;
    scanf("%d %d %d", &n, &m, &x);

    // ✅ Correct size: n * n
    int* arr = (int*) calloc(n * n, sizeof(int));  
    if (!arr) return 1;  // Memory allocation failure

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        arr[(a - 1) * n + (b - 1)] = 1;
        arr[(b - 1) * n + (a - 1)] = 1;
    }

    // ✅ Fix: Matrix size should be n × n
    int* res = arr;  
    for (int i = 1; i < x; i++) {  // Start from 1 since arr^1 is arr itself
        int* temp = multiplyMatricesModC(res, n, n, arr, n, n, x + 1);
        if (i > 1) free(res);  // Free previous matrix to prevent memory leak
        res = temp;
    }

    printMatrixC(res, n, n);

    // ✅ Free allocated memory
    free(arr);
    free(res);

    return 0;
}
