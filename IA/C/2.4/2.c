#include <stdio.h>

int factorial(int n)
{
    if (n==0) return 1;
    if (n==1) return 1;
    return n * factorial(n-1);
}

int isPrim(int n)
{
    return (factorial(n-1)+1)%n==0;
}

int main() {
    int n;
    scanf("%d",&n);
    isPrim(n) ? printf("%d este prim\n",n) : printf("%d nu este prim\n",n);
}
