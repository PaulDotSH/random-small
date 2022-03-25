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

    Emisiune(const Emisiune& other) : durata(other.durata) {
        nume = new char[strlen(other.nume)+1];
        strcpy(nume,other.nume);
    }

    ~Emisiune() {
        delete[] nume;
    }
    void Afisare() {
        std::cout << "Emisiune: " << nume << "; Durata: " << durata << "\n";
    }
    int durata;

    char& operator[](int index) {
        return nume[index];
    }

    void ModificareLitera(char&& c, int index){
        nume[index] = c;
    }

private:
    char* nume;
};



Emisiune* citire(){
    int durata;
    char inp[100];
    std::cin.getline(inp,100);
    std::cin >> durata;
    std::cin.get();
    return new Emisiune(inp,durata);
}

void fct(Emisiune a){
    a.ModificareLitera('X',0);
    std::cout << "fct: "; a.Afisare();
}

int main(){
    Emisiune *e = citire();
    std::cout<<"e: ";e->Afisare();
    Emisiune* f = citire();
    std::cout<<"f: ";f->Afisare();
    Emisiune b = *e;
    b.ModificareLitera('A',1);
    std::cout<<"b: ";b.Afisare();
    std::cout<<"e: ";e->Afisare();
    fct(*f);
    std::cout<<"f: ";f->Afisare();
} 
