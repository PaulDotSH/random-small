//#include <stdio.h>

// int add2(int t){
//     return t+2;
// }

// int sub2(int t){
//     return t-2;
// }

int apply(int cond, int (*f)(int), int (*g)(int), int x){
    if (cond==0) {
        return g(f(x));
    }
    return f(g(x));
}


// int main(){

//     int res = apply(1, add2, sub2, 5);
//     printf("%d\n", res);

// }