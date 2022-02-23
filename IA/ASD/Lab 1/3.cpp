#include <bits/stdc++.h>

using namespace std;

int main()
{
    float x,aux=0;
    cin>>x;
    if (x>=0)
    {
        while (x>1)
        {
            x--;
            aux++;
        }
    }
    else
    {
        while (x<0)
        {
            x++;
            aux++;
        }
        aux*=-1;
    }

    cout<<aux;
} 
