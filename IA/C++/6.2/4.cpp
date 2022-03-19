#include <iostream>
#include <string>

//std string& cause we don't want a copy, and we modify it
void lower(std::string& str) {
    for (int i = 0; i < str.length(); i++)
        str[i] = std::tolower(str[i]);
}

//we dont modify the string so let's make it const
int countSubstring(const std::string& str, const std::string& sub, int maxSearches)
{
    int count = 0;
    //from first occurence of the substring, until the offset is not a position (usually -1)
    //find the substring from the offset
    for (size_t offset = str.find(sub); offset != std::string::npos;
         offset = str.find(sub, offset + sub.length()))
    {
        count++;
        if (count>maxSearches)
            return count;
    }
    return count;
}

int main() {
    char substr[50];
    int x;
    std::cin.getline(substr,50);
    std::cin>>x;
    std::cin.ignore();
    std::string input;
    for (int i=0; i<x; i++) {
        getline(std::cin,input);
        std::string lwr = input;
        lower(lwr);
        if (countSubstring(lwr,substr,2)==2) {
            std::cout << input << std::endl;
        }
    }
    return 0;
}
 
