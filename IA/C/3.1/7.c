#include <stdio.h>

int linear_search(int val, int len, int* arr) {
    for (int i = len; i > -1; i--) 
        if (arr[i] == val)
            return ++i;
    return -1;
}

int main(){
    int n,aux;
    scanf("%d",&n);
    int v[n];
    for (int i=0; i<n; i++) {
        scanf("%d",&aux);
        v[i]=aux;
    }
    int k;
    scanf("%d",&k);
    printf("%d\n",linear_search(k,n,v));
} 
