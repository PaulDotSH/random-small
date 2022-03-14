#include "stdio.h"

typedef struct student student;
struct student {
    char nume[50];
    int nota;
};

void ReadStudenti(student studenti[], int n, int* prezenti) {
    char ch;
    //fflush is undefined behaviour
    while ((ch = getchar()) != '\n' && ch != EOF);
    char tmp[10];
    for (int i=0; i<n; i++) {
        fgets(studenti[i].nume,50,stdin);
        //stergem \n de la final
        studenti[i].nume[strcspn(studenti[i].nume, "\n")] = 0;
        fgets(tmp,50,stdin);
        if (strcmp(tmp,"ABS\n")!=0) {
            studenti[i].nota = atoi(tmp);
            (*prezenti)++;
        } else {
            i--;
            n--;
        }
    }
}

int main() {
    int n, prezenti = 0;
    scanf("%d",&n);
    student studenti[n];
    ReadStudenti(studenti,n,&prezenti);
    printf("Prezenti: %d\n",prezenti);
    printf("Statistica\n");

    int note[11] = {0};
    for (int i=0; i<prezenti; i++) {
        note[studenti[i].nota]++;
    }

    for (int i=10; i>0; i--) {
        if (note[i]!=0) {
            printf("Nota %d - %d student(i)\n",i,note[i]);
        }
    }

    int k;
    scanf("%d",&k);

    if (note[k]==0) {
        printf("Nota %d: niciun student\n",k);
        return 0;
    }
    printf("Nota 9: ");
    for (int i=0; i<prezenti; i++) {
        if (studenti[i].nota==k) {
            printf("%s;", studenti[i].nume);
        }
    }
    printf("\n");
} 
