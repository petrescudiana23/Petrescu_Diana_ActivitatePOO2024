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
        culoare = "Roșu";
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

    string getCuloare() const { return culoare; }
    void setCuloare(string c) { culoare = c; }

    int getGreutate() const { return greutate; }
    void setGreutate(int g) { greutate = g; }

    char* getSoi() const { return soi; }
    void setSoi(char* s) {
        delete[] soi;
        soi = new char[strlen(s) + 1];
        strcpy(soi, s);
    }

    void afisare() const {
        cout << "Mar: Culoare = " << culoare << ", Greutate = " << greutate << "g, Soi = " << soi << endl;
    }

    friend void procesareMar(Mar& m);
};

int Mar::nrMere = 0;

class Banana {
private:
    static int nrBanane;
    int* lungime;
    string coaja;
    bool dulce;

public:
    Banana() : coaja("Galbenă") {
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
        cout << "Banana: Lungime = " << *lungime << "cm, Coajă = " << coaja << ", Dulce = " << (dulce ? "Da" : "Nu") << endl;
    }

    friend void procesareBanana(Banana& b);
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

    friend void procesareCireasa(Cireasa& c);
};

int Cireasa::nrCirese = 0;

// Funcții globale prietene
void procesareMar(Mar& m) {
    cout << "Procesăm mărul: " << m.getCuloare() << " de tip " << m.getSoi() << endl;
    m.setGreutate(m.getGreutate() + 10);
}

void procesareBanana(Banana& b) {
    cout << "Procesăm banana de " << b.getLungime() << " cm." << endl;
    b.setDulce(!b.isDulce());
}

int main() {
    Mar m1("Verde", (char*)"Golden", 180);
    Banana b1;
    Cireasa c1(8, "Acru-Dulce", (char*)"Violet");

    m1.afisare();
    procesareMar(m1);
    m1.afisare();

    b1.afisare();
    procesareBanana(b1);
    b1.afisare();

    c1.afisare();
    cout << "Număr de cireșe: " << Cireasa::getNrCirese() << endl;

    return 0;
}
