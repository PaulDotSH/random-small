int my_strlen(char *s){
    char *p=s;
    int i=0;
    while(*p++!='\0')
        i++;
    return i;
}