#include <stdio.h>

int main()
{
    int arr[5];
    int* pi = arr;
    int x;
    for(int i = 0; i < 5; i++){
        scanf("%d", pi++);
    }
    scanf("%d",&x);
    for(int i = 0; i < 5; i++){
        if (*(--pi)==x) { printf("%d\n",i); return 0; }
    }
    printf("-1\n");
}