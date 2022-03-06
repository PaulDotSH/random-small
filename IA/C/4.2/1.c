#include "stdio.h"
#include "stdlib.h"

int isElInVector(int* v, int len, int el) {
    for (int i=0; i<len; i++)
        if (v[i]==el) return 1;
    return 0;
}

int** eliminare(int ** mat, int n, int m, int *lungimiLinii) {
    int** _mat = (int**) malloc(n * sizeof(int*));
    for (int i=0; i<n; i++) {
        int v[100]={0},k=0;
        for (int j=0; j<m; j++) {
            if (!isElInVector(v,k,mat[i][j])) {
                v[k++]=mat[i][j];
            }
        }

        _mat[i] = (int*) malloc(k*sizeof(int));
        for (int j=0; j<k; j++) {
            _mat[i][j]=v[j];
        }
        lungimiLinii[i]=k;
    }

    return _mat;
}

int main() {

    int** mat, **newMat, *lungimi;
    int n, m;
    scanf("%d %d", &n, &m);

    mat = (int**) malloc(n * sizeof(int*));
    lungimi = (int*)malloc(n * sizeof(int));
    for (int i=0; i<n ; i++)
        mat[i] = (int*) malloc(m* sizeof(int));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%d",&mat[i][j]);

    newMat = eliminare(mat, n, m, lungimi);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < lungimi[i]; j++) {
            printf("%d;", newMat[i][j]);
        }
        printf("\n");
    }
}
