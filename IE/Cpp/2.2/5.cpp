#include <iostream>
#include <dirent.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

class str
{
private:
    char* s;
public:
    str(const char* p)
    {
        std::cout << "str::str(const char*);\n";
        int len = strlen(p);
        s = (char*)(malloc(len + 1));
        memcpy(s,p,len);
    }
    str(const str& other) {
        std::cout << "str::str(const str&);\n";
        s = (char*)malloc(strlen(other.s));
        strcpy(s,other.s);
    }
    str(): s(nullptr) {}
    const char* rep() { return s; }
    void rep(const char* p) {
        delete[] s;
        s = (char*) p;
    }
};

//we use a reference to not make a copy of the object for no reason
void f(str& s) { std::cout << "String = " << s.rep();}


 
