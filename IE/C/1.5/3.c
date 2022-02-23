void sort(struct person *array, int n){
    char temp[50];
    for (int i=0; i<n; i++){
        for (int j=0; j<n-1; j++){
            if (array[j].age == array[j+1].age) {
                if (strcmp(array[j].name, array[j+1].name) > 0) {
                    strcpy(temp, array[j].name);
                    strcpy(array[j].name, array[j+1].name);
                    strcpy(array[j+1].name, temp);
                }   
            } else if (array[j].age > array[j+1].age){
                struct person tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }
        }
    }
}
