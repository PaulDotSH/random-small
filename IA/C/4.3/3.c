#include "stdio.h"
#include "stdlib.h"

int inversNr(int x) {
    int aux=0;
    while(x) {
        aux=aux*10+x%10;
        x/=10;
    }
    return aux;
}

int palindrom(int x) {
    return inversNr(x)==x;
}

/*
int munte(int nr) {
    nr=inversNr(nr);
    int lastCif=nr%10;
    nr/=10;
    int k=0;
    while (nr) {
        int currCif=nr%10;
        if (lastCif<=currCif) {
            if (k==2) {
                return 0;
            }
            k=1;
        } else {
            k=2;
        }
        lastCif=currCif;
        nr/=10;
    }
    return k==2;
}
*/


int munte(int nr){
    int pas = 0;
    if(nr%10 > nr%100/10)
        return 0;

    while(nr && pas == 0){
        if(nr < 10)
            return 0;
        
        if(nr%10 > nr%100/10)
            pas++;
       
        nr /= 10;
    }
    
    while(nr && pas == 1){
        if(nr%10 < nr%100/10)
            return 0;
        nr /= 10;
    }
    
    return 1;
}

int cautare(int *t, int n, int (*criteriu)(int)) {
    int lI=-1;
    for(int i=0; i<n; i++) {
        if ((*criteriu)(t[i])==1)
            lI=i;
    }
    return lI;
}

int main() {
    int n,lastMunte=-1,lastPalindom=-1;
    scanf("%d",&n);
    int* v = malloc(n * sizeof(int));
    for (int i=0; i<n; i++) {
        scanf("%d",&v[i]);
    }

    int cm,lp;
    for (int i=0; i<n; i++) {
        cm=cautare(v,n,munte);
        if (cm!=-1)
            lastMunte=cm;
        lp=cautare(v,n,palindrom);
        if (lp!=-1)
            lastPalindom=lp;
    }
    printf("%d\n%d\n",lastPalindom,lastMunte);
}
 
