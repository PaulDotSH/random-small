#include <stdio.h>

int main() {
    int inp;
    scanf("%d",&inp);

    if (inp&1) { //X1
        if ((inp>>1)&1) { //11
            printf("Americano");
        } else { //01
            printf("Long Coffee");
        }
    } else { //X0
        if ((inp>>1)&1) { //10
            printf("Cappucino");
        } else { //00
            printf("Espresso");
        }
    }
    printf(", ");

    //There should be a better way to do this...
    if ((inp>>2)&1) { //XX1
        if ((inp>>3)&1) //X11
        {
            if ((inp>>4)&1) //111
                printf("7");
            else //011
                printf("3");
        }
        else //X01
        {
            if ((inp>>4)&1) //101
                printf("5");
            else //001
                printf("1");
        }
    } else { //XX0
        if ((inp>>3)&1) //X10
        {
            if ((inp>>4)&1) //110
                printf("6");
            else //010
                printf("2");
        }
        else //X00
        {
            if ((inp>>4)&1) //100
                printf("4");
            else
                printf("0"); //000
        }
    }
    
    printf(" sugar, ");

    if ((inp>>5)&1) {
        printf("with");
    } else {
        printf("no");
    }
    printf(" lid\n");

    return 0;
}