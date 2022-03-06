#include "stdio.h"
#include "stdlib.h"

void afis(int* v, int len) {
    int* _=v;
    int i=0;
    while (i++!=len)
        printf("%d;",*_++);
}

void _(int* v, int len) {
    int ___=0;
    for (int i=1; i<len-1; i++) {
        if (v[i]==(float)(v[i-1]+v[i+1])/2)
        {
            ___=1;
            break;
        }
    }
    if (___==0) return;
    
    for (int i=1; i<len-1; i++) {
        if (v[i]==(float)(v[i-1]+v[i+1])/2)
            printf("%d;",v[i]);
    }

    printf("\n");
}

void reverse(int* v, int len) {
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        int tmp = v[i];
        v[i] = v[j];
        v[j] = tmp;
    }
}

int main() {
    int n;
    scanf("%d",&n);
    int* v = malloc(n * sizeof(int));
    for (int i=0; i<n; i++)
        scanf("%d",&v[i]);
    afis(v,n);
    printf("\n");
    _(v,n);

    reverse(v,n);
    afis(v,n);
}
