#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int max=-1,min=0,n,aux;

    scanf("%d",&n);
    while (n--) {
        scanf("%d",&aux);
        if (aux>0 && aux>max) max=aux;
        if (aux<0 && aux<min) min=aux;
    }

    max==-1 ? printf("nu exista\n") : printf("%d\n",max);
    min==0  ? printf("nu exista\n") : printf("%d\n",min);
}

