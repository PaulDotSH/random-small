#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct City City;
struct City {
    char name[20];
    float precipitatii;
    char zone;
};

City CitireOras() {
    char input[200];
    fgets(input,200,stdin);
    char* token = strtok(input," ");
    //City* oras = malloc(sizeof(City));
    City oras;
    int i=0;
    while (token != NULL) {
        switch (i) {
            case 0:
                strcpy(oras.name,token);
                break;
            case 1:
                oras.precipitatii = atof(token);
                break;
            case 2:
                oras.zone = token[0];
                break;
            default:
                printf("Erroare la citire\n");
                break;
        }
        i++;
        token = strtok(NULL," ");
    }
    return oras;
}

char* _(char c) {
    switch (c) {
        case 'E':
            return "Est";
        case 'V':
            return "Vest";
        case 'N':
            return "Nord";
        case 'S':
            return "Sud";
    }
    return "";
}

void AfisareOras(City oras) {
    printf("%s precipitatii=%.2f l %s",oras.name,oras.precipitatii,_(oras.zone));
    printf("\n");
}

char consoane[] = "bcdfghjklmnpqrstvwxyz";
int CountConsoane(char str[]) {
    char tmp;
    int c = 0;
    for (int i=0; i < strlen(str); i++) {
        if (str[i]>'A' && str[i]<'Z') {
            tmp = str[i]+32;
        } else tmp = str[i];

        if (strchr(consoane,tmp)!=0) {
            c++;
        }
    }
    return c;
}

int main() {
    int n;
    scanf("%d",&n);
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
    City orase[n];
    for (int i=0; i<n; i++) {
        orase[i] = CitireOras();
    }

    int nrConsoane;
    scanf("%d\n",&nrConsoane);
    for (int i=0; i<n; i++) {
        if (CountConsoane(orase[i].name)>=nrConsoane) {
            AfisareOras(orase[i]);
        }
    }
    scanf("%c",&ch);
    printf("In %s\n", _(ch));

    //Get max oras name len from that zone
    int maxLen = -1;
    for (int i=0; i<n; i++) {
        if (orase[i].zone==ch) {
            int _ = strlen(orase[i].name);
            if (_>maxLen) maxLen = _;
        }
    }
    
    for (int i=0; i<n; i++) {
        if (orase[i].zone!=ch)
            continue;
        int len = strlen(orase[i].name);
        printf("%s",orase[i].name);
        for (int j=0; j<maxLen-len; j++)
            printf(" ");
        printf(": ");

        for (int j=0; j<(int)orase[i].precipitatii; j++)
            printf("*");
        printf("\n");
    }
} 
