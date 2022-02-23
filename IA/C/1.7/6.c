#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){
    int n,i=2;
    char* output =  (char*)malloc(200);
    scanf("%d",&n);
    if (n==0) {
        printf("0");
        return 0;
    }

    if (n==1) {
        printf("1");
        return 0;
    }
    while (n!=1) {
        int p=0;
        while (n%i==0)
        {
            p++;
            n/=i;
        }
        if (p==1) {
            char *a = (char*)malloc(100);
            sprintf(a,"%d*",i);
            output = strcat(output,a);
            //printf("%d*",i);
        }
        else if (p>1) {
            char* a = (char*)malloc(100);
            sprintf(a,"%d^%d*",i,p);
            output = strcat(output,a);
            //printf("%d^%d*",i,p);
        }
        i++;
    }
    int len = strlen(output)-1;
    if (output[len]=='*')
        output[len]=0;

    printf(output);

    //printf("\b");
}

