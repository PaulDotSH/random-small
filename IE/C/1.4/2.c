#include <string.h>

//gasim inceputul si finalul sirului
//dupa parcurgem sirul cu ambii pointeri si interschimbam caracterele
//ne oprim cand ajungem la mijloc
void my_strrev(char * array) {
    char *start = array;
    char *end = array + strlen(array) - 1;

    while (start < end) {
        char temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
}