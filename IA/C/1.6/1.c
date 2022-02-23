#include <stdio.h>

int main(){
    int cif;
    scanf("%d",&cif);
    switch (cif) {
        case 0:
            printf("zero\nzero\n");
            break;
        case 1:
            printf("unu\none\n");
            break;
        case 2:
            printf("doi\ntwo\n");
            break;
        case 3:
            printf("trei\nthree\n");
            break;
        case 4:
            printf("patru\nfour\n");
            break;
        case 5:
            printf("cinci\nfive\n");
            break;
        case 6:
            printf("sase\nsix\n");
            break;
        case 7:
            printf("sapte\nseven\n");
            break;
        case 8:
            printf("opt\neight\n");
            break;
        case 9:
            printf("noua\nnine\n");
            break;
        default:
            printf("nu este cifra\n");
            break;
    }
}

