#include <stdio.h>

//shit code dar e tarziu si sunt lazy af
int main() {
    int nu1,ni1,nu2,ni2;
    scanf("%d %d %d %d",&nu1,&ni1,&nu2,&ni2);
    if (ni1==0 || ni2==0) {
        printf("numitorul nu poate fi 0 !!!\n");
        return 0;
    }
    int _nu1=nu1;
    int _nu2=nu2;
    int _ni1=ni1;
    int _ni2=ni2;
    nu1*=ni2;
    nu2*=ni1;
    int _tmp = ni2;
    ni2*=ni1;
    ni1*=_tmp;

    int tmp = nu1+nu2;
    int tmp2 = ni1;
    for (int i=2; i<(tmp/2)+1; i++)
    {
        while (tmp%i==0) tmp/=i,tmp2/=i;
    }
    printf("suma=%d/%d\n",tmp,tmp2);

    tmp = _nu1*_nu2;
    tmp2 = _ni1*_ni2;

    for (int i=2; i<(tmp/2)+2; i++)
    {
        while (tmp%i==0) tmp/=i,tmp2/=i;
    }
    printf("produsul=%d/%d\n",tmp,tmp2);
} 
