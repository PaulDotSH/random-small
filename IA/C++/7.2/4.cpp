#include <iostream>
#include <cmath>
#include <cstring>

#define MAX_SIZE 256

class Emisiune{
public:
    Emisiune(char* _nume, int _durata) : durata(_durata) {
        nume = new char[strlen(_nume)];
        strcpy(nume,_nume);
    }
    ~Emisiune() {
        delete[] nume;
    }
    void Afisare() {
        std::cout << "Emisiune: " << nume << "; Durata: " << durata << "\n";
    }
private:
    char* nume;
    int durata;
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
    for(int i=0; i<n; i++){
        Emisiune *e = citire();
        e->Afisare();
        delete e;
    }
} 
