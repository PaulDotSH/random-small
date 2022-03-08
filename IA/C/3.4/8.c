#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    fgets(str,100,stdin);
    char substr[50];
    fgets(substr,50,stdin);
    unsigned long len = strlen(substr)-1;
    if (substr[len]=='\n')
        substr[len]=0;

    char* result = strstr(str, substr);
    while (result!=NULL) {
        int position = result - str;

        //strcpy(result+position,result+position+len);
        for (int i=position; i < strlen(str); i++)
            str[i]=str[i+len+1];

        result = strstr(str, substr);

    }
    printf("%s",str);
} 
