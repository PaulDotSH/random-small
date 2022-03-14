#include "stdlib.h"
#include "stdio.h"

typedef struct persoana persoana;
struct persoana{
    char *nume, * prenume;
    int varsta;
};

persoana citire() {
    persoana* p = malloc(sizeof(persoana));
    p->prenume = malloc(50);
    p->nume = malloc(50);
    scanf("%s %s %d",p->nume,p->prenume,&p->varsta);
    return *p;
}
void afisare(persoana* p) {
    printf("%s %s %d\n",p->prenume,p->nume,p->varsta);
}

int main() {
    int n;
    scanf("%d",&n);
    persoana* persoane = malloc(sizeof(persoana)*n);

    for (int i=0; i<n; i++) {
        persoane[i] = citire();
    }

    int a,b,ok=0;
    scanf("%d %d",&a,&b);

    for (int i=0; i<n; i++) {
        if (persoane[i].varsta >= a && persoane[i].varsta <= b) {
            ok=1;
            afisare(&persoane[i]);
        }
    }
    if (ok==0) {
        printf("Nu am gasit nicio persoana\n");
    }
} 
