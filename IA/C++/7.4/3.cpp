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
    }

    static void AfisareNrInstante();

    friend NrComplex Inmultire(NrComplex& a, NrComplex& b);

private:
    int re, im;
    static int instante;
};

int NrComplex::instante = 1;

void NrComplex::AfisareNrInstante() {
    std::cout << instante << "\n";
}

NrComplex Inmultire(NrComplex &a, NrComplex &b) {
    return NrComplex(a.re*b.re-a.im*b.im,a.re*b.im+a.im*b.re);
}

void Citire(NrComplex& nr) {
    int r,c;
    std::cin >> r >> c;
    nr = NrComplex(r,c);
}

//(a1a2-b1b2)+(a1b2+a2b1)i

int main(){
    NrComplex a,b;
    Citire(a);
    Citire(b);
    NrComplex c = Inmultire(a,b);
    c.Afisare();
}

