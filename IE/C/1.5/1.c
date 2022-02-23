// #include <string.h>
// #include <stdio.h>
// #include <stdlib.h>

// struct person
// {
//     char* name;
//     int age;
// };


struct person make_person(char *s, int age){
    struct person tmp;
    const char* p = malloc(strlen(s));
    strcpy(p,s);
    tmp.name = p;
    tmp.age = age;
    return tmp;
}

// int main(){
//     char s[50], *pc;
//     int age;
//     struct person p;
//     scanf("%s", s);
//     scanf("%d", &age);
//     p = make_person(s, age);
//     strcpy(s, "Make a copy!!!");
//     printf("%s %d", p.name, p.age);
// }