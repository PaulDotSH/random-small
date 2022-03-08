#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d\n", &n);
    char inp[1000];
    fgets(inp,1000,stdin);

    char* token = strtok(inp," \"");

    int i=0;
    char words[n][100];
    while (i++!=n) {
        strcpy(words[i],token);
        token = strtok(NULL," \"");
    }

    int k;
    scanf("%d",&k);
    for (i=0; i<k; i++) {
        scanf("%d",&n);
        printf("%s ",words[n]);
    }
} 
