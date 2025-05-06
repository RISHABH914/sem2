#include <stdio.h>
#include <stdlib.h>

#define MODULO 1000000007  // Default modulo, will be updated dynamically

// Function to multiply two matrices A and B modulo MOD
static inline int* multiplyMatricesMod(const int* A, const int* B, int n, int mod) {
    int* C = (int*) calloc(n * n, sizeof(int));  // Allocate and initialize to zero
    if (!C) return NULL;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            long sum = 0;
            for (int k = 0; k < n; k++) {
                sum = (sum + (long)A[i * n + k] * B[k * n + j]) % mod;
            }
            C[i * n + j] = (int)sum;
        }
    }
    return C;
}

// Function to exponentiate matrix A to power k using binary exponentiation
static int* matrixExponentiation(int* base, int n, int exp, int mod) {
    // Create an identity matrix
    int* result = (int*) calloc(n * n, sizeof(int));
    if (!result) return NULL;
    for (int i = 0; i < n; i++) 
        result[i * n + i] = 1;

    int* temp = base;  // Start with base matrix

    while (exp > 0) {
        if (exp % 2 == 1) {
            int* newResult = multiplyMatricesMod(result, temp, n, mod);
            free(result);
            result = newResult;
        }
        int* newTemp = multiplyMatricesMod(temp, temp, n, mod);
        if (temp != base) free(temp);
        temp = newTemp;
        exp /= 2;
    }

    return result;
}

// Function to print the final matrix
static inline void printMatrix(const int* mat, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", mat[i * n + j]);
        printf("\n");
    }
}

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    int* adjacencyMatrix = (int*) calloc(n * n, sizeof(int));
    if (!adjacencyMatrix) return 1;  // Memory allocation failure

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;  // Convert 1-based to 0-based index
        adjacencyMatrix[u * n + v] = 1;
        adjacencyMatrix[v * n + u] = 1;  // Since it's undirected
    }

    // Compute A^k using matrix exponentiation
    int* result = matrixExponentiation(adjacencyMatrix, n, k, MODULO);

    // Print the final result
    printMatrix(result, n);

    free(adjacencyMatrix);
    free(result);

    return 0;
}
