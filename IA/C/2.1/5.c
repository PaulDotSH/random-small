#include <stdio.h>

int pow(int base, int exp)
{
    if(exp < 0)
        return -1;

    int result = 1;
    while (exp)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }

    return result;
}

//convert a number from decimal to binary
int transformare(int n){
    int ret = 0,i=0;
    while (n > 0) {
        ret += (n % 2) * (int)pow(10, i);
        n /= 2;
        i++;
    }
    return ret;
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d", transformare(n));
} 
