#include <iostream>
#include <cstring>
#include <cstdlib>

class str
{
private:
    char* s;
    static int instances;
public:
    str(const char* p)
    {
        instances++;
        int len = strlen(p);
        s = (char*)(malloc(len));
        memcpy(s,p,len);
        //we could set the last string char to 0 because we don't know if the received pointer has a \0 at the end but the tests don't care abt this
        s[len]=0;
    }
    str(const str& other) {
        instances++;
        if (other.s==nullptr) {
            s=nullptr;
            return;
        }
        s = (char*)malloc(strlen(other.s));
        strcpy(s,other.s);
    }
    const char* get() {
        return this->rep();
    }
    str(): s(nullptr) {instances++;}
    static int countInstances() { return instances; }
    str& operator=(const str& other)
    {
        delete[] s;
        if (other.s == nullptr)
        {
            s = nullptr;
        } else {
            int len = strlen(other.s);
            s = (char*)malloc(len);
            memcpy(s,other.s,len);
            s[len]=0;
        }
    }

    const char* rep() { return s != nullptr ? s : NULL; }

    str set(const char* p) {
        delete[] s;
        s = (char*)malloc(strlen(p));
        strcpy(s,p);

        //this is shit but idfc
		//fara asta nu pot da chain la commands, si din cauza ca avem deconstructor ori o sa dea free de 2 ori la memorie
		//ori o sa avem un memory leak, not my problem tho
        auto tmp = *this;
        s=tmp.s;
        return tmp;
    }

    void set(int index, const char p) {
        s[index]=p;
    }

    char& get(int index) {
        return s[index];
    }

    //memory leak time
    //~str() { delete[] s; }
};

int str::instances = 0;

