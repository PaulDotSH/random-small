#include<stdio.h>
#include<math.h>

int main()
{
    int i=3;
    double precizie,s0,s1,aux;
    scanf("%lf",&precizie);
    s0=2;
    s1=2.25;//default e int
    while(s1-s0>precizie)
    {
        s0=s1;
        s1=pow(1+(double)1/i,i);
        i++;
    }
    printf("limita=%lf\n",s1);
    return 0;
} 
