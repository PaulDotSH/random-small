int suma_cifre(int nr) {
    int s=0;
    if (nr<0) nr*=-1;
    while (nr) {
     s+=nr%10;
     nr/=10;
    }
    return s;
}

/**
* Citeste n numere si determina cea mai mare valoare a sumei cifrelor numerelor citite
* param n: numarul de numere care vor fi citite
* retrurn: cea mai mare valoare a sumei cifrelor numerelor citite
*/
int prelucrare_numere(int n){
    int max=0,aux;
    for (int i=0; i<n; i++) {
        scanf("%d",&aux);
        aux=suma_cifre(aux);
        if (aux>max)
            max=aux;
    }
    return max;
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n", prelucrare_numere(n));
    return 0;
} 
