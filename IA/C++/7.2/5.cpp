#include <iostream>
#include <cstring>
#include "vector"

#define MAX_SIZE 256

class Emisiune{
public:
    Emisiune(char* _nume, int _durata) : durata(_durata) {
        nume = new char[strlen(_nume)+1];
        strcpy(nume,_nume);
    }
    ~Emisiune() {
        delete[] nume;
    }
    void Afisare() {
        std::cout << "Emisiune: " << nume << "; Durata: " << durata << "\n";
    }
    int durata;
private:
    char* nume;
};
Emisiune* citire(){
    int durata;
    char inp[100];
    std::cin.get();
    std::cin.getline(inp,100);
    std::cin >> durata;

    return new Emisiune(inp,durata);
}
int main(){
    int n; //numarul de emisiuni
    std::cin >> n;
    std::vector<Emisiune*> emisiuni;
    emisiuni.reserve(n);

    for(int i=0; i<n; i++){
        emisiuni.emplace_back(citire());
    }
    int min;
    std::cin>>min;
    for (auto& emisiune : emisiuni) {
        if (emisiune->durata > min)
            emisiune->Afisare();
    }
} 
