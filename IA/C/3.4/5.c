#include <stdio.h>
#include <stdlib.h>

int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    if (n!=m) {
        printf("proprietatea nu poate fi verificata\n");
        return 0;
    }

    int v[100][100];
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%d",&v[i][j]);
        }
    }


    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (i<j && v[i][j]!=0) {
                printf("proprietatea nu este verificata");
                return 0;
            }
        }
    }

    printf("proprietatea este verificata");

//    for (int i=0; i<n; i++) {
//        for (int j=0; j<m; j++) {
//            printf("%d ",v[i][j]);
//        }
//        printf("\n");
//    }
} 
