#include <stdio.h>

int main(){
    int r,g,b;
    scanf("%d %d %d",&r,&g,&b);
    if (r>255 || g>255 || b>255)
    {
        printf("intrari invalide\n"); return 0;
    }

    printf("%d %d %d",255-r,255-g,255-b);
}

