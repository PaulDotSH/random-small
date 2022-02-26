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
#define MAX_STR_LEN 100
int main(){
    int n;
    scanf("%d\n", &n);
    char input[MAX_STR_LEN*n+n];
    fgets(input, MAX_STR_LEN*n+n, stdin);
    input[strcspn(input, "\n")] = 0;

    char *str = strtok(input, " ");
    char old[MAX_STR_LEN];
    for (size_t i = 1; i < n; i++) {
        strcpy(old, str);
        str = strtok(NULL, " ");
        if (suntAnagrame(old, str)==0)
        {
            printf("NU\n");
            return 0;
        }
    }
    printf("DA\n");   
}
