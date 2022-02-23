#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* concat(char *s, char *t){
    int lens = strlen(s), lent = strlen(t);
    char *result = malloc(lens+lent-1); //bcs we have 2 \0 and we only need 1
    int i=0;
    while (i<lens) {
        result[i] = s[i];
        i++;
    }
    int j=0;
    while (j<lent) {
        result[i] = t[j];
        i++;
        j++;
    }

    return result;
}

// int main()
// {
//     printf("%s\n", concat("Hello", "World!"));
// }
