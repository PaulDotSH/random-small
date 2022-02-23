#include <stdio.h> 
#include <string.h>
int main()
{
    char v[128] = {0},inp[150];
	gets(inp);
    for (int i=0; i<sizeof(inp); i++) {
        if (inp[i]=='\0') break;
        if (inp[i]>='A' && inp[i]<='Z') inp[i]=inp[i]+32;
        v[inp[i]]++;
    }
    for (int i=0; i<sizeof(v); i++) if (v[i]) printf("%c %d\n",i,v[i]);
	return 0;
}