#include <iostream>

class NrComplex{
public:
    NrComplex(int real, int imaginar) : re(real), im(imaginar) { instante++; }

    NrComplex() {}

    //aparent nu
    //~NrComplex() { instante--; }

    static NrComplex Adunare(NrComplex& a, NrComplex& b) {
        return NrComplex(a.re+b.re,a.im+b.im);
    }

    void Afisare() {
        im<0 ? std::cout << re << im << "i\n" : std::cout << re << "+" << im << "i\n";
        //im>0 : std::cout<<re<<"+"<<im  std::cout<<
    }

    static void AfisareNrInstante();

private:
    int re, im;
    static int instante;
};

int NrComplex::instante = 1;

void NrComplex::AfisareNrInstante() {
    std::cout << instante << "\n";
}

void Citire(NrComplex& nr) {
    int r,c;
    std::cin >> r >> c;
    nr = NrComplex(r,c);
}

int main(){
    NrComplex a,b;
    Citire(a);
    Citire(b);
    NrComplex c = NrComplex::Adunare(a,b);
    c.Afisare();
    NrComplex::AfisareNrInstante();
} 
