#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Mar {
private:
    static int nrMere;
    string culoare;
    int greutate;
    char* soi;

public:
    Mar() : greutate(150) {
        nrMere++;
        soi = new char[30];
        strcpy(soi, "Ionatan");
        culoare = "Rosu";
    }

    Mar(string culoare, char* soi, int greutate) : greutate(greutate) {
        nrMere++;
        this->culoare = culoare;
        this->soi = new char[strlen(soi) + 1];
        strcpy(this->soi, soi);
    }

    Mar(const Mar& m) : greutate(m.greutate) {
        nrMere++;
        culoare = m.culoare;
        soi = new char[strlen(m.soi) + 1];
        strcpy(soi, m.soi);
    }

    ~Mar() {
        nrMere--;
        delete[] soi;
    }

    static int getNrMere() {
        return nrMere;
    }

    string getCuloare() const {
        return culoare;
    }
    void setCuloare(string c) { 
        culoare = c; 
    }

    int getGreutate() const {
        return greutate;
    }
    void setGreutate(int g) {
        greutate = g; 
    }

    char* getSoi() const {
        return soi;
    }
    void setSoi(char* s) {
        delete[] soi;
        soi = new char[strlen(s) + 1];
        strcpy(soi, s);
    }

    void afisare() const {
        cout << "Mar: Culoare = " << culoare << ", Greutate = " << greutate << "g, Soi = " << soi << endl;
    }

    // Supraincarcarea operatorilor
    Mar& operator=(const Mar& m) {
        if (this != &m) {
            delete[] soi;
            greutate = m.greutate;
            culoare = m.culoare;
            soi = new char[strlen(m.soi) + 1];
            strcpy(soi, m.soi);
        }
        return *this;
    }

    bool operator==(const Mar& m) const {
        return (greutate == m.greutate && culoare == m.culoare && strcmp(soi, m.soi) == 0);
    }

    Mar operator+(int extraGreutate) const {
        Mar temp(*this);
        temp.greutate += extraGreutate;
        return temp;
    }

    Mar& operator++() { 
        greutate += 10;
        return *this;
    }

    friend void comparaMere(const Mar& m1, const Mar& m2);
};

int Mar::nrMere = 0;

class Banana {
private:
    static int nrBanane;
    int* lungime;
    string coaja;
    bool dulce;

public:
    Banana() : coaja("Galbena") {
        nrBanane++;
        lungime = new int(20);
        dulce = true;
    }

    Banana(int* lungime, string coaja, bool dulce) : coaja(coaja), dulce(dulce) {
        nrBanane++;
        this->lungime = new int(*lungime);
    }

    Banana(const Banana& b) : coaja(b.coaja), dulce(b.dulce) {
        nrBanane++;
        lungime = new int(*b.lungime);
    }

    ~Banana() {
        nrBanane--;
        delete lungime;
    }

    static int getNrBanane() {
        return nrBanane;
    }

    int getLungime() const { return *lungime; }
    void setLungime(int l) { *lungime = l; }

    string getCoaja() const { return coaja; }
    void setCoaja(string c) { coaja = c; }

    bool isDulce() const { return dulce; }
    void setDulce(bool d) { dulce = d; }

    void afisare() const {
        cout << "Banana: Lungime = " << *lungime << "cm, Coaja = " << coaja << ", Dulce = " << (dulce ? "Da" : "Nu") << endl;
    }

    // Supraincarcarea operatorilor
    Banana& operator=(const Banana& b) {
        if (this != &b) {
            delete lungime;
            lungime = new int(*b.lungime);
            coaja = b.coaja;
            dulce = b.dulce;
        }
        return *this;
    }

    Banana operator+(int extraLungime) const {
        Banana temp(*this);
        *temp.lungime += extraLungime;
        return temp;
    }

    bool operator>(const Banana& b) const {
        return *lungime > *b.lungime;
    }

    Banana operator--(int) { // Postfix --
        Banana temp(*this);
        (*lungime)--;
        return temp;
    }

    friend void schimbaDulceata(Banana& b);
};

int Banana::nrBanane = 0;

class Cireasa {
private:
    static int nrCirese;
    int dimensiune;
    string gust;
    char* culoare;

public:
    Cireasa() : gust("Dulce") {
        nrCirese++;
        dimensiune = 10;
        culoare = new char[30];
        strcpy(culoare, "Roșu");
    }

    Cireasa(int dimensiune, string gust, char* culoare) : gust(gust), dimensiune(dimensiune) {
        nrCirese++;
        this->culoare = new char[strlen(culoare) + 1];
        strcpy(this->culoare, culoare);
    }

    Cireasa(const Cireasa& c) : gust(c.gust), dimensiune(c.dimensiune) {
        nrCirese++;
        culoare = new char[strlen(c.culoare) + 1];
        strcpy(culoare, c.culoare);
    }

    ~Cireasa() {
        nrCirese--;
        delete[] culoare;
    }

    static int getNrCirese() {
        return nrCirese;
    }

    int getDimensiune() const { return dimensiune; }
    void setDimensiune(int d) { dimensiune = d; }

    string getGust() const { return gust; }
    void setGust(string g) { gust = g; }

    char* getCuloare() const { return culoare; }
    void setCuloare(char* c) {
        delete[] culoare;
        culoare = new char[strlen(c) + 1];
        strcpy(culoare, c);
    }

    void afisare() const {
        cout << "Cireasa: Dimensiune = " << dimensiune << "mm, Gust = " << gust << ", Culoare = " << culoare << endl;
    }

    // Supraincarcarea operatorilor
    Cireasa& operator=(const Cireasa& c) {
        if (this != &c) {
            delete[] culoare;
            dimensiune = c.dimensiune;
            gust = c.gust;
            culoare = new char[strlen(c.culoare) + 1];
            strcpy(culoare, c.culoare);
        }
        return *this;
    }

    Cireasa operator-(int reducereDimensiune) const {
        Cireasa temp(*this);
        temp.dimensiune -= reducereDimensiune;
        return temp;
    }

    bool operator<(const Cireasa& c) const {
        return dimensiune < c.dimensiune;
    }

    Cireasa operator++(int) { 
        Cireasa temp(*this);
        dimensiune++;
        return temp;
    }

    friend void schimbareCuloare(Cireasa& c);
};

int Cireasa::nrCirese = 0;

// Funcții prietene
void comparaMere(const Mar& m1, const Mar& m2) {
    cout << "Comparam marul 1 (" << m1.culoare << ") cu marul 2 (" << m2.culoare << ")." << endl;
}

void schimbaDulceata(Banana& b) {
    b.dulce = !b.dulce;
    cout << "Dulceata bananei a fost schimbata." << endl;
}

void schimbareCuloare(Cireasa& c) {
    c.setCuloare((char*)"Galben");
    cout << "Culoarea ciresei a fost schimbată." << endl;
}


int main() {
    Mar m1("Roșu", (char*)"Golden", 150), m2("Galben", (char*)"Ionatan", 200);
    Banana b1, b2;
    Cireasa c1, c2(12, "Acru", (char*)"Roz");

    m1.afisare();
    m1 = m2;
    m1.afisare();
    ++m1;
    m1.afisare();
    comparaMere(m1, m2);

    b1.afisare();
    b1 = b2;
    b1.afisare();
    schimbaDulceata(b1);
    b1.afisare();

    c1.afisare();
    c1 = c2;
    c1.afisare();
    schimbareCuloare(c1);
    c1.afisare();

    return 0;
}
