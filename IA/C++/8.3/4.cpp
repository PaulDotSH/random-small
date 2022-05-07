#include <iostream>
#include <sstream>
#include "cstring"

class Carte{
public:
    Carte(char* titlu, char* autor) {
        size_t len = strlen(titlu);
        m_Titlu = new char[len+1];
        strncpy(m_Titlu,titlu,len);
        m_Titlu[len]=0;
        len = strlen(autor);
        m_Autor = new char[len+1];
        strncpy(m_Autor,autor,len);
        m_Autor[len]=0;
    }

    Carte(const Carte& c) {
        size_t len = strlen(c.m_Titlu);
        m_Titlu = new char[len+1];
        strncpy(m_Titlu,c.m_Titlu,len);
        m_Titlu[len]=0;
        len = strlen(c.m_Autor);
        m_Autor = new char[len+1];
        strncpy(m_Autor,c.m_Autor,len);
        m_Autor[len]=0;
    }

    Carte operator= (Carte const& c) {
        return {c.m_Titlu,c.m_Autor};
    }

    ~Carte() {
        delete[] m_Autor;
        delete[] m_Titlu;
    }

    friend std::ostream& operator<< (std::ostream& stream, const Carte& c) {
        stream << c.m_Titlu;
        return stream;
    }

private:

    char* m_Titlu;
    char* m_Autor;
};

class Persoana{
public:
    Persoana(char* nume) {
        size_t len = strlen(nume);
        m_Nume = new char[len+1];
        strncpy(m_Nume,nume,len);
        m_Nume[len]=0;
    }

    Persoana(const Persoana& p) {
        size_t len = strlen(p.m_Nume);
        m_Nume = new char[len+1];
        strncpy(m_Nume,p.m_Nume,len);
        m_Nume[len]=0;
    }

    Persoana operator=(Persoana const& p) {
        return {p.m_Nume};
    }

    ~Persoana() { delete[] m_Nume; }

    friend std::ostream& operator<< (std::ostream& stream, const Persoana& p) {
        stream << p.m_Nume;
        return stream;
    }

    //Nu imi imaginez de ce primim si nr de zile daca nu facem nimic cu el ¯\_(ツ)_/¯
    char* scrieReview(const Carte& c, int numarZile) {
        std::stringstream stream;
        stream<<"Reviewul pentru cartrea "<<c<<" trebuie terminat in doua saptamani";

        int len = strlen(stream.str().c_str());
        char* tmp = new char[len+1];
        strncpy(tmp,stream.str().c_str(),len);
        tmp[len]=0;
        return tmp;
    }

private:
    char* m_Nume;
};

#define STR_LENGTH 256

int main() {
    char Titlu[STR_LENGTH], Autor[STR_LENGTH], Nume[STR_LENGTH];
    std::cin.getline(Titlu, STR_LENGTH-1);
    std::cin.getline(Autor, STR_LENGTH-1);
    Carte c = Carte(Titlu,Autor);
    Persoana p = Persoana(Nume);
    std::cout << p.scrieReview(c,0);
}

