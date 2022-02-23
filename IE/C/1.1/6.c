#include <stdio.h>

int main() {
	int x,c=0;
	scanf("%d",&x);
	for (int i=2; i<=x; i++)
	{
		if (x%i!=0) continue;
		c=0;
		do {
			x/=i;
			c++;
		} while (x%i==0);
		printf("%d %d\n",i,c);
	}



}