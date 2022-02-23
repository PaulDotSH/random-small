#include <stdio.h>

int main(){
    int n,c=0;
    scanf("%d",&n);
    while (n) {
        if (n%2==1) c++;
        n=n/2;
    }
    printf("%d\n",c);
}
