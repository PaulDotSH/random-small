#include <stdio.h>
#include <stdlib.h>

int cif_max(long nr) {
    int max=nr%10,_=max;
    nr/=10;
    while (nr) {
        _=nr%10;
        if (_>max) max=_;
        nr/=10;
    }
    return max;
}

int nr_cif(long nr) {
    int k=0;
    while (nr) {
        k++;
        nr/=10;
    }
    return k;
}

void sortare(int* v, int len, int (*f)(long)) {
    for (int i=0; i<len; i++) {
        for (int j=i; j<len; j++) {
            int r1=f(v[i]);
            int r2=f(v[j]);
            if (r1==r2) {
                if (v[i]>v[j]) {
                    int aux=v[i];
                    v[i]=v[j];
                    v[j]=aux;
                }
            }

            if (r1>r2) {
                int aux=v[i];
                v[i]=v[j];
                v[j]=aux;
            }
        }
    }
}

void afisare(int* v, int len) {
    for (int i=0; i<len; i++) {
        printf("%d;",v[i]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d",&n);
    int v[n];
    for (int i=0; i<n; i++) {
        scanf("%d",&v[i]);
    }
    printf("cifra maxima: ");
    //afisare(v,n);
    sortare(v,n,cif_max);
    afisare(v,n);
    printf("nr. cifre: ");
    sortare(v,n,nr_cif);
    afisare(v,n);
} 
