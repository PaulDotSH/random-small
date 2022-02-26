#include <stdio.h>
#include <string.h>

#define size 50

void citire(int** v, int n, int m) {
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            scanf("%d", &v[j][i]);
}

void afisare(int** v, int n, int m) {
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            (j!=m-1) ? printf("%d ", v[i][j]) : printf("%d",v[i][j]);

        printf("\n");
    }
}

void det_maxim(int** v, int n, int m) {
    int max=v[0][0], k=0;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
        {
            if (v[i][j]>max)
                max=v[i][j],k=0;
            if (v[i][j]==max) k++;
        }
    printf("max %d: ", max);
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            if (v[i][j]==max)
            {
                k--;
                k ? printf("linia %d coloana %d; ",i+1,j+1) : printf("linia %d coloana %d;",i+1,j+1);
            }

    printf("\n");
}


void constr_tab(int** v, int n, int m, int* sume) {
    for (int i=0; i<n; i++)
        sume[i]=0;

    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            sume[i]+=v[i][j];
    printf("sume:");
    for (int i=0; i<n; i++)
        printf(" %d",sume[i]);
    printf("\n");
}

void interschimbare(int** v, int n, int m, int o, int p) {
    int aux;
    o--;
    p--;
    for (int i=0; i<m; i++)
    {
        aux=v[i][o];
        v[i][o]=v[i][p];
        v[i][p]=aux;
    }
}

#include "stdlib.h"

void cauta(int** v, int n, int m, int k) {
    int* _ = malloc(sizeof(int)*n*m);
    for (int i=0; i<n*m; i++)
        _[i]=0;

    int* __ = malloc(sizeof(int)*n*m);
    for (int i=0; i<n*m; i++)
        __[i]=0;

    //printf("elementul %d se gaseste pe: linia %d coloana %d;\n",k,i+1,j+1);
    int kkk=0;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
        {
            if (v[i][j]==k)
                _[kkk]=i+1,__[kkk++]=j+1;
        }
    if (_[0]!=-1) {
        printf("elementul %d se gaseste pe:",k);
        for (int i=0; i<n*m; i++) {
            if (_[i]==0) break;
            printf(" linia %d coloana %d;",_[i],__[i]);
        }
        return;
    }
    printf("nu se gaseste\n");
}

int main() {
    int n,m;
    scanf("%d %d\n", &n, &m);
    int** v = malloc(size*sizeof(int**));
    for (int i=0; i<size; i++)
        v[i]= malloc(size*sizeof(int));

    citire(v, n, m);
    afisare(v, n, m);
    det_maxim(v, n, m);
    int* sume = malloc(sizeof(int)*size);
    constr_tab(v, n, m, sume);

    int o,p;
    scanf("%d %d", &o, &p);
    int k;
    scanf("%d",&k);
    interschimbare(v, n, m, o,p);
    afisare(v,n,m);
    cauta(v, n, m, k);
    return 0;
} 
