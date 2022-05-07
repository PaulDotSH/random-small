#include "iostream"

class NrComplex {
public:
    NrComplex(int r=0, int i=0) : re(r), im(i) {}
    friend NrComplex operator+ (const NrComplex&, const NrComplex&);
    friend std::ostream& operator<< (std::ostream&, const NrComplex&);
    friend std::istream& operator>> (std::istream&, NrComplex&);
    NrComplex& operator+= (const NrComplex&);
    friend NrComplex operator- (const NrComplex&, const NrComplex&);
    NrComplex& operator-=(const NrComplex&);


    NrComplex& operator++(); //prefixat
    NrComplex operator++(int); //postfixat

    int operator[](size_t pos) const;
private:
    int re, im;
};

NrComplex operator+(const NrComplex& first, const NrComplex& second) {
    return {first.re+second.re,first.im+second.im};
}

std::ostream &operator<<(std::ostream& stream, const NrComplex& nr) {
    stream << nr.re << " " << nr.im;
    return stream;
}

std::istream &operator>>(std::istream& stream, NrComplex& nr) {
    stream >> nr.re >> nr.im;
    return stream;
}

NrComplex &NrComplex::operator+=(const NrComplex &other) {
    this->re -= other.re;
    this->im -= other.im;
    return *this;
}

NrComplex operator-(const NrComplex& first, const NrComplex& second) {
    return {first.re-second.re,first.im-second.im};
}

NrComplex &NrComplex::operator-=(const NrComplex& other) {
    this->re -= other.re;
    this->im -= other.im;
    return *this;
}

NrComplex& NrComplex::operator++() { this->re++; return *this;}
NrComplex NrComplex::operator++(int) { NrComplex a = *this; this->re++; return a; }

int NrComplex::operator[](size_t pos) const {
    switch (pos) {
        case 1:
            return this->re;
        case 2:
            return this->im;
        default:
            return 0;
    }
}

int main(){
    NrComplex a;
    std::cin >> a;
    std::cout << a[1] << std::endl << a[2];
}

