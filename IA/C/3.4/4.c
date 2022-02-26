#include <stdio.h>
#include <string.h>

#define size 50

void citire(int** v, int n, int m) {
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            scanf("%d", &v[i][j]);
}

void afisare(int** v, int n, int m) {
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            printf("%d ", v[i][j]);
        printf("\n");
    }
}
#include "stdlib.h"

int** adunare(int** v, int** v2, int n, int m) {
    int** sum = malloc(size*sizeof(int**));
    for (int i=0; i<size; i++)
        sum[i] = malloc(size*sizeof(int));

    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            sum[i][j]=v[i][j]+v2[i][j];
    return sum;
}



int main() {
    int n,m,o,p;
    scanf("%d %d\n", &n, &m);
    int** v = malloc(size*sizeof(int**));
    int** v2 = malloc(size*sizeof(int**));
    for (int i=0; i<size; i++)
    {
        v[i] = malloc(size*sizeof(int));
        v2[i] = malloc(size*sizeof(int));
    }
    citire(v, n, m);
    scanf("%d %d\n", &o, &p);
    citire(v2, n, m);

    if (n!=o || m != p) {
        printf("matricile nu se pot aduna\n");
        return 0;
    }

    //afisare(v, n, m);

    afisare(adunare(v,v2,n,m),n,m);
} 
