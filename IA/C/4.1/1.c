 #include <stdio.h>

void interschimba(int* a, int* b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    interschimba(&a,&b);
    printf("%d %d", a, b);
}
