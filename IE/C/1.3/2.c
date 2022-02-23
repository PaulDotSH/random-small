#include <stdio.h> 
#include <string.h>
int main()
{
    char v[128] = {0},inp[150];
	gets(inp);
    printf("%c",inp[0]);
    for (int i=1; i<strlen(inp); i++) {
        if (inp[i]!=inp[i-1]) printf("%c",inp[i]);
    }
    printf("\n");
    return 0;
}