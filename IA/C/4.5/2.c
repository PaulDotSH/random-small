#include "stdio.h"
#include "stdlib.h"

void afisare(int* v, int len) {
    printf("(");
    for (int i=0; i<len; i++) {
        if (i!=len-1)
            printf("%d, ",v[i]);
        else
            printf("%d)\n",v[i]);
    }
}

void ordonare(int* v, int len) {
    for(int i=0; i<len; i++) {
        for (int j=i; j<len; j++)
            if (v[i]>v[j]) {
                int aux=v[j];
                v[j]=v[i];
                v[i]=aux;
            }
    }
}

int main() {
    int n;
    scanf("%d",&n);
    int v[3];
    for (int i=0; i<n; i++) {
        for (int j=0; j<3; j++) {
            scanf("%d",&v[j]);
        }
        ordonare(v,3);
        afisare(v,3);
    }
} 
