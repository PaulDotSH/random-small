#include <stdio.h>
void convert_to_binary(int n)
{
    int i;
    int rem;
    int binary[100];
    int count = 0;
    while (n > 0)
    {
        rem = n % 2;
        n = n / 2;
        binary[count] = rem;
        count++;
    }
    for (i = count - 1; i >= 0; i--)
    {
        printf("%d", binary[i]);
    }
}
int main() {
    int x;
    scanf("%d",&x);
    convert_to_binary(x);
}