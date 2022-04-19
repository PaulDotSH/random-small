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


int main(){
    NrComplex x,y;
    std::cin >> x >> y;
    std::cout << (x-y) << std::endl;
    y -= x;
    std::cout << y << std::endl;
}

