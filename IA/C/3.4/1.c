#include <stdio.h>
#include <string.h>

int max(int* v, int len) {
    int max = v[0];
    for (int i = 1; i < len; i++) {
        if (v[i] > max) {
            max = v[i];
        }
    }
    return max;
}   

float average(int* v, int len) {
    float sum = 0;
    for (int i = 0; i < len; i++) {
        sum += v[i];
    }
    return sum / len;
}

int div400(int* v, int len) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (v[i] % 400 == 0) {
            count++;
        }
    }
    return count;
}

int verifyDescending(int* v, int len, int j, int k) {
    for(int i=j; i<k-2; i++)
        if(v[i]<=v[i+1])
            return 0;
    return 1;
}

void printFromTo(int* v, int len, int j, int k) {
    for (int i = j; i < k; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main(){
    int n,aux;
    scanf("%d", &n);
    int v[n];
    for (int i=0; i<n; i++) {
        scanf("%d", &aux);
        v[i]=aux;
    }
    int j,k;
    scanf("%d",&j);
    scanf("%d",&k);
    k++;
    printf("max=%d\n", max(v,n));
    printf("media=%.2f\n", average(v,n));
    printf("nr. divizibile cu 4 si 100=%d\n", div400(v,n));
    verifyDescending(v,n,j,k) ? printf("da: "),printFromTo(v,n,j,k) : printf("nu\n");
} 
