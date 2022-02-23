void get_properties(int* array, int* min, int *max, int* num){
    *num=0;
    *min=array[0];
    *max=array[0];
    while (*array!=0) {
        if (*array<*min) {
            *min=*array;
        } else if (*array>*max) {
            *max=*array;
        }
        *num=(*num)+1;
        array++;
    }
}
