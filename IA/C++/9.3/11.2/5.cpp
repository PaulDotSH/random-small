#include "iostream"
#include "list"

#define MAX_LEN 256


int main(){
    std::list<std::string> lista;

    char inp[MAX_LEN];
    for (int i=0; i<8; i++) {
        std::cin.getline(inp,MAX_LEN-1);
        lista.emplace_back(inp);
    }

    int i=1;
    for (auto& str : lista) {
        if (i++%2==0) std::cout << str << "\n";
    }
}

