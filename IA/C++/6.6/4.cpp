#include <iostream>
#include <vector>
#include <algorithm>

void RemoveLastSubstr(std::string& str, const std::string& sub, int n = 1) {
    auto size = sub.size();
    while (n--) {
        auto index = str.find_last_of(sub)-1;
        str.replace(index,size,"");
    }
}

int main() {
    std::string substr, input;
    int x;
    getline(std::cin,substr);
    std::cin >> x;
    std::cin.ignore();
    getline(std::cin,input);
    std::string copy = input;
    RemoveLastSubstr(input,substr);
    std::cout << input << std::endl;
    RemoveLastSubstr(copy,substr,x);
    std::cout << copy << std::endl;
}
 
