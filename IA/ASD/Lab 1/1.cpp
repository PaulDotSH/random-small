#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n1,n2,n3,n;
    cin>>n1>>n2>>n3;
    if (n1>n2)
        n=(n3+n1)/2;
    else
        n=(n3+n2)/2;
    cout<<n;
}