#include <stdio.h>

int main()
{
	char chr;
	scanf("%c",&chr);
	//If the character's ascii code is a lowercase one (between "a" and "z")
	if (chr >= 'a' && chr <= 'z')
	{
		//Convert it to a uppercase one
		chr+='A'-'a';
		printf("%c\n",chr);
		//exit
		return 0;
	}
	if (chr >= 'A' && chr <= 'Z')
	{
		//Convert it to a lowercase one
		chr-='A'-'a';
		printf("%c\n",chr);
		return 0;
	}
	//Print it as a number
	printf("%d\n",chr);
}