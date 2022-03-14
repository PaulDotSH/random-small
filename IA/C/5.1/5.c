#include "stdlib.h"
#include "stdio.h"

typedef struct persoana persoana;
struct persoana{
    char *nume, * prenume;
    int varsta;
};

persoana* citire() {
    persoana* p = malloc(sizeof(persoana));
    p->prenume = malloc(50);
    p->nume = malloc(50);
    scanf("%s %s %d",p->nume,p->prenume,&p->varsta);
    return p;
}
void afisare(persoana* p) {
    printf("%s %s %d",p->prenume,p->nume,p->varsta);
}

int main() {
    persoana* p = citire();
    afisare(p);
} 
