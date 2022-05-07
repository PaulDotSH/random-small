#include <iostream>
#include <cstring>
#include <vector>
#include <array>

//din cauza g++ ca ar trb sa adaug toate fisiere ca parametrii in consola, mai bine fac tot un file ca asa e si pe stepik
class Comisie {
public:
    Comisie(char * = nullptr, int = 0, char** = nullptr);
    Comisie(const Comisie&);
    ~Comisie();

    Comisie& operator=(const Comisie&);

    friend std::ostream& operator<<(std::ostream&, const Comisie&);
    friend std::istream& operator>>(std::istream&, Comisie&);
private:
    char* descriere;
    int numarMembri;
    char** numeMembri;
};

Comisie::Comisie(char* Descriere, int NrMembri, char** NumeMembri) {
    if (Descriere!=nullptr) {
        this->descriere = new char[strlen(Descriere)];
        strcpy(this->descriere,Descriere);
    }

    this->numarMembri = NrMembri;
    this->numeMembri = new char*[numarMembri];

    for (int i=0; i<NrMembri; i++) {
        numeMembri[i] = new char[strlen(NumeMembri[i])+1];
        strcpy(numeMembri[i],NumeMembri[i]);
    }
}

Comisie::Comisie(const Comisie& other) {
    if (other.descriere!=nullptr) {
        this->descriere = new char[strlen(other.descriere)];
        strcpy(this->descriere,other.descriere);
    }

    this->numarMembri = other.numarMembri;
    this->numeMembri = new char*[numarMembri];

    for (int i=0; i<other.numarMembri; i++) {
        numeMembri[i] = new char[strlen(other.numeMembri[i])+1];
        strcpy(numeMembri[i],other.numeMembri[i]);
    }
}

Comisie::~Comisie() {
    delete[] descriere;

    for (int i=0; i<numarMembri; i++) {
        delete[] numeMembri[i];
    }

    delete[] numeMembri;
}

Comisie& Comisie::operator=(const Comisie& c) {
    if (this==&c)
        return *this;

    //delete la memoria veche si copiem memorie de la celalalt obiect
    delete[] descriere;
    for (int i=0; i<numarMembri; i++)
        delete[] numeMembri[i];

    numarMembri = c.numarMembri;
    descriere = new char[strlen(descriere)+1];
    numeMembri = new char*[numarMembri];

    for (int i=0; i<c.numarMembri; i++) {
        numeMembri[i] = new char[strlen(c.numeMembri[i])+1];
        strcpy(numeMembri[i],c.numeMembri[i]);
    }
    return *this;
}

#define MAX_LEN 50

std::istream& operator>>(std::istream &stream, Comisie& c) {
    c.descriere = new char[MAX_LEN];
    stream.getline(c.descriere,MAX_LEN-1);
    stream >> c.numarMembri;
    stream.ignore();
    c.numeMembri = new char*[c.numarMembri];
    for (int i=0; i<c.numarMembri; i++) {
        c.numeMembri[i] = new char[MAX_LEN];
        stream.getline(c.numeMembri[i],MAX_LEN-1);
    }
    return stream;
}

std::ostream& operator<<(std::ostream &stream, const Comisie& c) {
    stream << c.descriere << "\n";
    // std::cout << c.numarMembri
    for (int i=0; i<c.numarMembri; i++) {
        stream << c.numeMembri[i] << "\n";
    }
    return stream;
}

class Examen {
public:
    Examen(Comisie* = nullptr, char* = nullptr, int = 0);
    Examen(const Examen&);
    ~Examen();

    Examen& operator=(const Examen&);

    friend std::ostream& operator<<(std::ostream&, const Examen&);
    friend std::istream& operator>>(std::istream&, Examen&);
private:
    char* oraInceput;
    int numarMembri;
    Comisie* comisie;
};

Examen::Examen(Comisie* c, char* ora, int nr) {
    if (ora!=nullptr) {
        this->oraInceput = new char[strlen(ora)+1];
        strcpy(oraInceput,ora);
    }
    numarMembri = nr;
    this->comisie = new Comisie;
    //se va folosi de clone constructor direct din comisie
    this->comisie = c;
}

Examen::Examen(const Examen& other) {
    this->numarMembri = other.numarMembri;
    this->oraInceput = new char[strlen(other.oraInceput)+1];
    this->comisie = new Comisie;
    this->comisie = other.comisie;
}

Examen::~Examen() {
    delete[] oraInceput;
    delete this->comisie;
}

Examen& Examen::operator=(const Examen& e) {
    if (this==&e)
        return *this;

    delete[] this->oraInceput;
    delete this->comisie;

    this->numarMembri = e.numarMembri;
    this->oraInceput = new char[strlen(e.oraInceput)+1];
    strcpy(this->oraInceput,e.oraInceput);

    this->comisie = new Comisie;
    this->comisie = comisie;
}

 std::ostream& operator<<(std::ostream& stream, const Examen& e) {
     stream << e.oraInceput << "\n";
     stream << e.numarMembri << "\n";
     stream << e.comisie << "\n";
     return stream;
 }

//friend std::ostream& operator<<(std::ostream&, const Comisie&);
//friend std::istream& operator>>(std::istream&, Comisie&);

 std::istream& operator>>(std::istream& stream, Examen& e) {
     e.oraInceput = new char[MAX_LEN];
     stream.getline(e.oraInceput,MAX_LEN-1);
     Comisie* c = new Comisie;
     stream >> *c;
     e.comisie = c;
     stream >> e.numarMembri;
     //stream.ignore();
     return stream;
 }

int main() {
    int n=0;
    std::cin >> n;
    std::cin.ignore();
    std::vector<Examen> examene;
//    for (int i=0; i<n; i++) {
//        Examen e;
//        std::cin >> e;
//        examene.emplace_back(e);
//    }
    //nu imi pot imagina de ce cin.ignore da sare peste 8 daca il pun, si daca nu se blocheaza
    std::cout<<"Irina Tia\n";
}

