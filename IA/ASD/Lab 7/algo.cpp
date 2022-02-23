#include <bits/stdc++.h>
using namespace std;


//Vectorul cand e luat ca parametru e luat deja ca pointer si putem schimba valorile din el
void shellSort(int v[], int n) {
    int gap = n / 2;
    while (gap > 0) {
        for (int i = gap; i < n; i++) {
            int j = i;
            int temp = v[i];
            while (j >= gap && v[j - gap] > temp) {
                v[j] = v[j - gap];
                j -= gap;
            }
            v[j] = temp;
        }
        gap /= 2;
    }
}

int main() {
    int v[] = {10, 4, 8, 3, 5, 9, 7, 2, 6, 1};
    shellSort(v, 10);
    for (int i = 0; i < 10; i++) {
        cout << v[i] << " ";
    }
    return 0;
}
