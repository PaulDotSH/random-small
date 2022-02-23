#include<stdio.h>
#include<math.h>

int main()
{
    double precizie,s0,s1,a;
    scanf("%lf %lf",&a,&precizie);
    s0=a;
    s1=(s0+a/s0)/2;
    while(fabs(s0-s1)>precizie)
        {
            s0=s1;
            s1=(s0+a/s0)/2;
        }
        printf("limita=%lf\n",s1);
    return 0;
}

