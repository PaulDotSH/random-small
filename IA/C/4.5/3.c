#include "stdio.h"
#include "stdlib.h"

void _(int** matrix, int n, int m) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            matrix[i][j]=i+j;
        }
    }
}

void afisare(int** matrix, int n, int m) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            printf("%d;",matrix[i][j]);
        }
        printf("\n");
    }
}

int** transpose(int** matrix, int n, int m) {
    int** transposed = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        transposed[i] = (int*)malloc(n * sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
    return transposed;
}

int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    int** matrix = malloc(n * sizeof(int*));
    for (int i=0; i<n; i++) {
        matrix[i] = malloc(m * sizeof(int));
    }

    _(matrix,n,m);

    afisare(matrix,n,m);

    int** transposed = transpose(matrix,n,m);
    printf("transpusa\n");
    afisare(transposed,m,n);
}

