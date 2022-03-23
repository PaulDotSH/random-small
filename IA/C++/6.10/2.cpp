//class String
//{
//public:
//    void PrintLn() {
//        for (int i=0; i<len; i++)
//            printf("%c",m_Str[i]);
//        printf("\n");
//    }
//
//    String(const char* str) {
//        printf("Created\n");
//        len = strlen(str);
//        m_Str = new char[len];
//        strcpy(m_Str,str);
//    }
//
//    String& operator=(String other) {
//        printf("Copy operator\n");
//        len = other.len;
//        strcpy(m_Str,other.m_Str);
//        return *this;
//    }
//
//    String(const String& str) {
//        printf("Copy created\n");
//        len = str.len;
//        m_Str = new char[len];
//        strcpy(m_Str,str.m_Str);
//    }
//
//    ~String() {
//        delete[] m_Str;
//    }
//private:
//    char* m_Str;
//    size_t len;
//};
//
//int main() {
//    std::vector<String> v;
//    v.reserve(50);
//    for (int i=0; i<5; i++) {
//        char tmp[10];
//        sprintf(tmp,"%d",i);
//        v.emplace_back(String(tmp));
//    }
//    printf("--------------------\n");
//
//    for (auto& a : v) {
//        a.PrintLn();
//    }
//}

#include "bits/stdc++.h"
#include "stdio.h"
#include <ctime>

// Return if year is leap year or not.
bool isLeap(int y)
{
    if (y%100 != 0 && y%4 == 0 || y %400 == 0)
        return true;

    return false;
}

// Given a date, returns number of days elapsed
// from the  beginning of the current year (1st
// jan).
int offsetDays(int d, int m, int y)
{
    int offset = d;

    switch (m - 1)
    {
        case 11:
            offset += 30;
        case 10:
            offset += 31;
        case 9:
            offset += 30;
        case 8:
            offset += 31;
        case 7:
            offset += 31;
        case 6:
            offset += 30;
        case 5:
            offset += 31;
        case 4:
            offset += 30;
        case 3:
            offset += 31;
        case 2:
            offset += 28;
        case 1:
            offset += 31;
    }

    if (isLeap(y) && m > 2)
        offset += 1;

    return offset;
}

// Given a year and days elapsed in it, finds
// date by storing results in d and m.
void revoffsetDays(int offset, int y, int *d, int *m)
{
    int month[13] = { 0, 31, 28, 31, 30, 31, 30,
                      31, 31, 30, 31, 30, 31 };

    if (isLeap(y))
        month[2] = 29;

    int i;
    for (i = 1; i <= 12; i++)
    {
        if (offset <= month[i])
            break;
        offset = offset - month[i];
    }

    *d = offset;
    *m = i;
}

//problema worthless si bullshit
int mtm(const std::string& m) {
    if (m=="ianuarie") return 1;
    if (m=="februarie") return 2;
    if (m=="martie") return 3;
    if (m=="aprilie") return 4;
    if (m=="mai") return 5;
    if (m=="iunie") return 6;
    if (m=="iulie") return 7;
    if (m=="august") return 8;
    if (m=="septembrie") return 9;
    if (m=="octombrie") return 10;
    if (m=="noiembrie") return 11;
    if (m=="decembrie") return 12;
    return 0;
}

struct dmy {
    dmy(int d, int m, int y) : d(d), m(m), y(y) {}
    int d,m,y;
};

// Add x days to the given date.
dmy addDays(int d, int m, int y, int x)
{
    int offset1 = offsetDays(d, m, y);
    int remDays = isLeap(y) ? (366 - offset1) : (365 - offset1);

    // _y is going to store result year and
    // offset2 is going to store offset days
    // in result year.
    int _y, offset2;
    if (x <= remDays)
    {
        _y = y;
        offset2 = offset1 + x;
    }

    else
    {
        // x may store thousands of days.
        // We find correct year and offset
        // in the year.
        x -= remDays;
        _y = y + 1;
        int _d = isLeap(_y) ? 366 : 365;
        while (x >= _d)
        {
            x -= _d;
            _y++;
            _d = isLeap(_y) ? 366 : 365;
        }
        offset2 = x;
    }

    // Find values of day and month from
    // offset of result year.
    int _m, _d;
    revoffsetDays(offset2, _y, &_d, &_m);

    return dmy(_d,_m,_y);
}

std::vector<std::string> split (const std::string &s, char delim) {
    std::vector<std::string> result;
    std::stringstream ss(s);
    std::string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}

int main() {
    int d,m,y;
    char str[100];
    std::cin.getline(str,100);
    sscanf(str,"%d/%d/%d",&d,&m,&y);
    dmy output = addDays(d,m,y,5);
    printf("%d-%d-%d\n",output.m,output.d,output.y);

    std::cin.getline(str,100);
    auto out = split(str,' ');
    std::string copy;
    size_t i=0;
    for (auto& v : out) {
        i++;
        switch (i) {
            case 1:
                d = atoi(v.c_str());
                break;
            case 2:
                copy = v;
                break;
            case 3:
                y = atoi(v.c_str());
                break;
            default:
                break;
        }
    }
    output = addDays(d,mtm(copy),y,5);
    printf("%d-%d-%d\n",output.m,output.d,output.y);
    std::cin.getline(str,100);
    sscanf(str,"%d %d %d",&d,&m,&y);
    output = addDays(d,m,y,5);
    printf("%d-%d-%d\n",output.m,output.d,output.y);
}
