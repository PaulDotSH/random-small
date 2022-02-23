// #include <stdio.h>

// void f(int *t){
//      *t = (*t) * (*t);
// }

// void g(int *t){
//     *t =  (*t)/2;
// }

int apply(int cond, void (*f)(int*), void (*g)(int*), int* x){
    if (cond==0) {
        g(x);
        f(x);
        return *x;
    }
    f(x);
    g(x);
    return *x;
}

// int main(){

//     int a=10, cond=1;
//     apply(cond, f, g, &a);
//     printf("%d\n", a);
// }