#include <stdio.h>

int main() {
	for (int b=2; b<27; b++)
		for (int a=2; a<b; a++)
			for (int c=b; c<21; c++)
				if (a*a+b*b==c*c) printf("%d %d %d\n",a,b,c);
}