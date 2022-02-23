#include <stdio.h>

int main() {
    int x,s=0;
    scanf("%d",&x);
    while (x!=0) s=s+x%10,x/=10;
    printf("%d",s);
}

