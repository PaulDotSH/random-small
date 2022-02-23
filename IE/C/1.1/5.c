//#include <math.h>
#include <stdio.h>

int main() {
	int x;
	scanf("%d",&x);
	int aux=0,foo=x;
	while (foo!=0) {
		aux=(10*aux)+(foo%10);
		foo/=10;
	}
	printf(aux==x ? "true\n" : "false\n");
	//get length of x
	//nrcif=log10(x)+1;
}