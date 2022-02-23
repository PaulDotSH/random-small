#include <bits/stdc++.h>

using namespace std;
//Daca vrem sa gasim singura moneda mai grea putem schimba semnele din < in >

int main()
{
    int nrMonede=8;
    int Monede[nrMonede] = {0, 1, 1, 1, 1, 1};
    int MonedaCurenta=-1;

    //Luam o moneda care e de greutate normala
    if (Monede[0]==Monede[1])
    {
        MonedaCurenta=Monede[0];
        for (int i=1; i<nrMonede; i++)
            if(Monede[i]<MonedaCurenta) //Daca gasim moneda mai usoara oprim cautarea
            {
                MonedaCurenta=Monede[i];
                break;
            }
    }
    else
    {
        if (Monede[0]>Monede[1])
            MonedaCurenta=Monede[1];
        else
            MonedaCurenta=Monede[0];
    }
    cout<<"Moneda mai usoara este moneda cu greutatea "<<MonedaCurenta;
}