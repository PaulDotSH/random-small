#include "stdio.h"
#include <math.h>

void fct(int* v, int n, double *sum, double *med, double *avg) {
    *sum=0.0;
    *avg=0.0;
    for (int i=0; i<n; i++) {
        (*sum)+=v[i];
    }
    *med=(*sum)/n;
    for (int i=0; i<n; i++) {
        (*avg)+=(v[i]-*med)*(v[i]-*med);
    }
    *avg=sqrt(*avg/(n-1));
}

int main() {
    int n;
    scanf("%d",&n);
    int v[n];
    for (int i=0; i<n; i++) {
        scanf("%d",&v[i]);
    }
    double sum,med,avg;
    fct(v,n,&sum,&med,&avg);
    printf("%d\n%.2lf\n%.2lf\n",(int)sum,med,avg);
}
