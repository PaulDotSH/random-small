#include <stdio.h>

//Replace f(var) with "if (var>0) s+=var,c++;"
#define f(x) if (x>0) s+=x,c++;
int main() {
	//Initialise all the vars, we could have read it as a string then use an array for no code repetition but
	//technically we dont know this yet
	int a,b,x,y,s=0,c=0;
	//read all the vars
	scanf("%d %d %d %d",&a,&b,&x,&y);
	//process all the vars
	f(a)f(b)f(x)f(y)
	//we need %.2f to print with precision of 2, and we need to cast s/c to a float, else it will be an int
	if (c==0) {
		printf("0.00\n");
		return 0;
	}
	printf("%.2f\n",(float)s/c);
}

