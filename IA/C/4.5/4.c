#include "stdio.h"
#include "stdlib.h"

void getMinMax(int* v, int len, int* min, int* max) {
    *min=v[0];
    *max=v[0];
    for (int i=0; i<len; i++) {
        if (v[i]>*max)
            *max=v[i];
        if (v[i]<*min)
            *min=v[i];
    }
}

int main() {
    int n;
    scanf("%d",&n);
    int* v = malloc(n * sizeof(int));
    for (int i=0; i<n; i++)
        scanf("%d",&v[i]);

    int* min = malloc(sizeof(int)), *max = malloc(sizeof(int));
    getMinMax(v,n,min,max);
    printf("min=%d\nmax=%d\n",*min,*max);
}

