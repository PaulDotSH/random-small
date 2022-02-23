#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct person{
    char * name;
    int age;
};


struct person make_person(char *s, int age){
    char* p = malloc(strlen(s));
    strcpy(p,s);
    struct person tmp = {p,age};
    return tmp;
}

int main(){
    char s[50];
    int age, i, n;
    struct person *p;
    struct person* persons = malloc(sizeof(struct person) * n);
    scanf("%d", &n);
    int tmp;
    for (int i=0; i<n; i++)
    {
        scanf("%s %d", &s, &tmp);
        printf("%s %d\n", s, tmp);
        persons[i] = make_person(s, tmp);
    }
}

/*
3
John 42
Mary 32
George 20
*/