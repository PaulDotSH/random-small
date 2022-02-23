#include <iostream>

int main()
{
    //i can't image why the retarded stepik compiler doesn't let me use const char* instead of this shit
    //since it works fine that way on my pc
    char name[20];
    int h;
    float ps;
    std::cin>>name>>h>>ps;
    std::cout<<name<<" "<<h<<" "<<ps<<"\n";
}