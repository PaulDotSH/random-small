#include <stdio.h>
#include <stdlib.h>

int product(int n) {
    if (n==0) return 1;
    if (n%10 == 0) return 0;
    return n%10 * product(n/10);
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",product(n));
}
 
