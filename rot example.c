#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAX_LEN 1024

int main() {
    char s[MAX_LEN];
    int x;
    scanf("%d\n", &x);
    fgets(s, MAX_LEN, stdin);

    if (x>26 || x<-26) x=x%26;

    if (x<0) x=26-(x*-1);

    if (x%26==0 || x==0)
    {
        printf("%s",s);
        return 0;
    }

    for (int i=0; i < strlen(s); i++)
    {
        int uppr = 0;
        if (s[i]>='A' && s[i]<='Z') uppr = 1,s[i]+=32;
        if (!(s[i]>='a' && s[i]<='z')) continue;
        
        // (s[i]+x>'z') ? s[i]='a'+((s[i]+x)-'z')-1 : s[i]+=x;
        if (s[i]+x>'z') { s[i]='a'+((s[i]+x)-'z')-1; } else s[i]+=x;

        if (uppr) s[i]-=32;
    }
    printf("%s",s);
}