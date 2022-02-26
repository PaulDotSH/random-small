#include <string.h>
#include <stdio.h>

int suntAnagrame(char* cuv1, char* cuv2) {
    int litere0[26] = {0};
    int litere1[26] = {0};

    for (size_t i = 0; i < strlen(cuv1); i++) {
        if (cuv1[i] >= 'A' && cuv1[i] <= 'Z')
            cuv1[i]+=32;
        litere0[cuv1[i] - 'a']++;
    }
    for (size_t i = 0; i < strlen(cuv2); i++) {
        if (cuv2[i] >= 'A' && cuv2[i] <= 'Z')
            cuv2[i]+=32;
        litere1[cuv2[i] - 'a']++;
    }
    for (size_t i = 0; i < 26; i++) {
        if (litere0[i] != litere1[i])
            return 0;
    }
    if (strcmp(cuv1, cuv2) == 0)
        return 0;
    return 1;
}

int main(){
    int n,aux;

    char inp[50];
    fgets(inp,50,stdin);
    char inp2[50];
    fgets(inp2,50,stdin);
    //stepik is broken and sometimes inserts a trailing \n on fgets
    inp[strcspn(inp, "\n")] = 0;
    inp2[strcspn(inp2, "\n")] = 0;
    printf("%d\n",suntAnagrame(inp,inp2));
}
