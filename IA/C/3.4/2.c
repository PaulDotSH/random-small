#include <stdio.h>
#include <string.h>

#define N 10
#define M 80

int max(char cuvinte[][M], int n){
   int i, len;
   int max = strlen(cuvinte[0]); //initializare cu primul element din tablou
   for (i=1; i<n; i++){
      len = strlen(cuvinte[i]);
      if (max < len) max = len;
   }
   return max;
}

void filtareCuvinte(char cuvinte[][M], int n, int len){
   int i;
   for (i=0; i<n; i++){
      if (len == strlen(cuvinte[i])) printf("%s\n",cuvinte[i]);
   }
}


int citire(char cuvinte[][M]){
   int i, n;
   //printf("numarul de cuvinte");
   scanf("%d", &n);
   for (i=0; i<n; i++){
       scanf("%s", cuvinte[i]);
   }
    return n;
}
int main(){
    char cuvinte[N][M];
    int n, _max;
    n = citire(cuvinte);
    _max = max(cuvinte, n);
    //printf("Cuvintele de dimensiune maxima %d sunt:\n",_max);
    filtareCuvinte(cuvinte,n, _max);    
} 
