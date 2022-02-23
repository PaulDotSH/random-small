#include <dirent.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

//din cauza ca e c/cpp trebuie sa schimbi functia ca nu putem aveam de 2 ori main
int main() {
    DIR *d;
    struct dirent *dir;
    d = opendir(".");
    if (!d) {
        printf("Cv nu a mers bine");
	    exit(0);
    }
    while ((dir = readdir(d)) != NULL) {
        printf("Avem fisierul %s\n", dir->d_name);

        //citim doar fisiere .c si .cpp ca restul nu au EOF la final si mi lene sa caut alta metoda de citire
        char *dot = strrchr(dir->d_name, '.');
        if (dot && (!strcmp(dot, ".c") || !strcmp(dot, ".cpp"))) {
            FILE* ptr;
            char ch;
            ptr = fopen(dir->d_name, "r");
            do {
                ch = fgetc(ptr);
                printf("%c", ch);
            } while (ch != EOF);
            free(ptr);
            printf("\n");
        }
    }
    closedir(d);
    exit(0);
}
