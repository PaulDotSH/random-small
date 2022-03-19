#include <iostream>
#include <vector>
#include <algorithm>

void RemoveSubstr(std::string& str, const std::string& sub, int n) {
    auto size = sub.size();
    while (n--) {
        auto index = str.find(sub);
        str.replace(index,size,"");
    }
}

void RemoveSubstr(std::string& str, const std::string& sub) {
    RemoveSubstr(str,sub,1);
}

int main() {
    std::string substr, input;
    int x;
    getline(std::cin,substr);
    std::cin >> x;
    std::cin.ignore();
    getline(std::cin,input);

    auto copy = input;
    RemoveSubstr(copy,substr);
    std::cout << copy << std::endl;
    RemoveSubstr(input,substr,x);
    std::cout << input << std::endl;
} 
