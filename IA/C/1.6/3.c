#include <stdio.h>
#include <stdlib.h>

int main(){
    int nr;
    int* a = (int*)malloc(sizeof(int)*4);
    for (int i=0; i<4; i++) {
        scanf("%d",&nr);
        a[i]=nr;
    }

    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++)
            if (a[i]<a[j]) {
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
    }
    int dif = 1;
    for (int i=0; i<3; i++) {
        if (a[i]==a[i+1]) {
            dif = 0;
            break;
        }
    }

    printf("%d\nToate numerele sunt diferite? ",a[0]+a[3]);
    dif ? printf("da\n") : printf("nu\n");
}

