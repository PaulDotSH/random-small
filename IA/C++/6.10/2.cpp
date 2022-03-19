#include <iostream>
#include <vector>
#include <sstream>
#include <string>

void DatePlusDays( struct tm* date, int days )
{
    bool b = false;
    const time_t ONE_DAY = 24 * 60 * 60 ;
    if (date->tm_mon==12) b = true;

    time_t date_seconds = mktime( date ) + (days * ONE_DAY) ;

    *date = *localtime( &date_seconds ) ;
    if (b) date->tm_mon=12;
}

std::string modificareData(const char* str) {
    int d,m,y;
    sscanf(str,"%d/%d/%d",&d,&m,&y);

    struct tm date = { 0, 0, 0 } ;

    date.tm_year = y;
    date.tm_mon = m;
    date.tm_mday = d;

    DatePlusDays( &date, 5 ) ;

    char out[50];
    sprintf(out, "%d-%d-%d",date.tm_mday,date.tm_mon,date.tm_year);
    return std::string(out);
}

std::string modificareData(int zi, int luna, int an) {
    struct tm date = { 0, 0, 0 } ;

    date.tm_year = an;
    date.tm_mon = luna;
    date.tm_mday = zi;

    DatePlusDays( &date, 5 ) ;

    char out[50];
    sprintf(out, "%d-%d-%d",date.tm_mday,date.tm_mon,date.tm_year);
    return std::string(out);
}

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

std::string modificareData(const std::string& luna, int day, int year) {
    struct tm date = { 0, 0, 0 } ;

    date.tm_year = year;
    date.tm_mon = mtm(luna);
    date.tm_mday = day;

    DatePlusDays( &date, 5 ) ;

    char out[50];
    sprintf(out, "%d-%d-%d",date.tm_mday,date.tm_mon,date.tm_year);
    return std::string(out);
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
    std::string input;
    getline(std::cin,input);
    std::cout << modificareData(input.c_str()) << std::endl;
    getline(std::cin,input);
    auto out = split(input,' ');

    size_t i = 0;
    int d,m,y;
    std::string copy;
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
    std::cout << modificareData(copy, d,  y) << std::endl;


    scanf("%d %d %d",&d,&m,&y);
    std::cout << modificareData(d, m, y);
}
 
