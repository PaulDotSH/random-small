#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* make_copy(char * array){
    char* copy = malloc(strlen(array)+1);
    char* base = copy;
    while (*array != '\0') {
        *copy = *array;
        copy++;
        array++;
    }
    return base;
}


int main()
{
    char* str = "Hello World!";
    printf("%s\n",make_copy(str));
}