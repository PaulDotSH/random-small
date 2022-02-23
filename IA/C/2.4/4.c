#include <stdio.h>

int factorial(int n)
{
    if (n==0) return 1;
    if (n==1) return 1;
    return n * factorial(n-1);
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    if (n>m) {
        printf("C(%d,%d)=0",n,m);
    }
    printf("C(%d,%d)=%d",n,m,factorial(n)/(factorial(m)*factorial(n-m)));

    return 0;
} 
