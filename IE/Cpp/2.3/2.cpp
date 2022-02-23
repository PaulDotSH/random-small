#include <iostream>

struct C
{
    int c;

    C(int i) { this->c = i; std::cout << "C::C(" << i << ")" << std::endl; }

    static C c0;

    static void f(C c);
};

C C::c0 = 0;

C c1 = 1;

void C::f(C c)
{
    //c = c.c;
}

int main()
{
    C::f(10);
    C::f(10);
    C::f(20);
    return 0;
}

//idk daca e bine sa mi bag pl daca nu devin din ce in ce mai trash ex