#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x,y,s=0;
    cin>>x,y;
    while (x>=1)
    {
        if (x%2!=0)
            s+=y;
        x/=2;
        y*=2;
    }
    cout<<s;
} 
