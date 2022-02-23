#include <stdio.h>

int isPrim(int n) {
    if (n<2) return 0;
    if (n==2) return 1;
    if (n%2==0) return 0;
    for (int i=3; i<n/2; i+=2) {
        if (n%i==0) return 0;
    }
    return 1;
}

int main()
{
    int n, m,c=0;
    scanf("%d %d", &n, &m);

    int v[m-n+1];
    for (int i=n; i<m+1; i++) {
        if (isPrim(i)==0) continue;

        v[c]=i;
        c++;
    }

    printf("%d\n",c);
    for (int i=0; i<c; i++) {
        printf("%d ",v[i]);
    }
    printf("\n");
}
 
