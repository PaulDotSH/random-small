#include <stdio.h>

int func(int n, int m)
{
    int p=1;
    if(!(n>=m && n>=1 && m>=1)) return 0;
    
    for(int i=n; i>=(n-m+1) ;i--)
        p*=i;
    return p;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    printf("A(%d,%d)=%d", n, m, func(n, m));
    return 0;
}
