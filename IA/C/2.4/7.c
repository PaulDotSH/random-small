 
#include <stdio.h>

int sum(int n) {
    int s=0;
    while (n) s+=n%10,n/=10;
    return s;
}

int main()
{
    int n, m,c=0;
    scanf("%d %d", &n, &m);

    if (n>m || n<0 || m<0)
    {
        printf("intrare invalida: numerele nu sunt pozitive; numerele nu reprezinta un interval valid\n");
        return 0;
    }

    int s=0;
    for (int i=n; i<m+1; i++) {
        s+=sum(i);
    }
    printf("%d\n",s);
}
