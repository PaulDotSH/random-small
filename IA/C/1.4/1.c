#include<stdio.h>

int main(){
    int n=0,nr=0;
    scanf("%d",&n);
    while (n--)
    {
        int aux,p=1;
        scanf("%d",&aux);
        if (aux==0)
        {
            nr++;
            continue;
        }
        while (aux) p*=aux%10,aux/=10;
        if (p==0) nr++;
    }
    printf("%d",nr);
}

