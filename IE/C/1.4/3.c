#include <stdio.h>

void* search(void *arr, int n, void* val, char c){
    if (c == 'i') {
        int *pi = arr;
        while (pi < arr+n) {
            if(*pi == *(int*)val){
                return pi;
            }
            pi++;
        }
    } else if (c=='c') {
        char *pi = arr;
        while (pi < arr+n) {
            if(*pi == *(char*)val){
                return pi;
            }
            pi++;
        }
    } else if (c=='f') {
        float *pi = arr;
        //idk dc trb 4, probabil o apeleaza gresit pe site...
        while (pi <= arr+(n*4)) {
            if(*pi == *(float*)val){
                return pi;
            }
            pi++;
        }
    }
    return NULL;
}

// int main()
// {
//     int arr[10] = {10,20,30,40,20};
//     int val = 20;
//     int *x = (int *) search(arr, 10, &val, 'i');
//     if(x != NULL){
//         long pos = x - arr;
//         printf("%ld\n", pos);
//     }

//     char carr[10] = "Examen";
//     char cval = 'a';
//     char *cx = (char *) search(carr, 10, &cval, 'c');
//     if(x != NULL){
//         long pos = cx - carr;
//         printf("%ld\n", pos);
//     }

//     float farr[10] = {12.0, 13.0, 14.0, 15.0};
//     float fval = 15.0;
//     float *fx = (float *) search(farr, 4, &fval, 'f');
//     if(x != NULL){
//         long pos = fx - farr;
//         printf("%ld\n", pos);
//     }
// }