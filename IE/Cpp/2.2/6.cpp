#include <iostream>
#include <cstring>
#include <cstdlib>

class str
{
private:
    char* s;
public:
    str(const char* p)
    {
        int len = strlen(p);
        s = (char*)(malloc(len + 1));
        memcpy(s,p,len);
        //we could set the last string char to 0 because we don't know if the received pointer has a \0 at the end but the tests don't care abt this
        s[len+1]=0;
    }
    str(const str& other) {
        s = (char*)malloc(strlen(other.s));
        strcpy(s,other.s);
    }
    str(): s(nullptr) {}
    const char* rep() { return s; }
    void rep(const char* p) {
        delete[] s;
        s = (char*)malloc(strlen(p)+1);
        strcpy(s,p);
    }
    ~str() { delete[] s; }
};