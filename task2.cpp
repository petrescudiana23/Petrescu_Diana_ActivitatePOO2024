#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Mar {
public:
    static int nrMere;
    string culoare;
    const int greutate; // greutatea este constantă
    char* soi;

    Mar() : greutate(150) { // Constructor implicit
        nrMere++;
        soi = new char[30];
        strcpy(soi, "Ionatan");
        culoare = "Roșu";
    }

    Mar(string culoare, char* soi, int greutateNoua) : greutate(greutateNoua) {
        nrMere++;
        this->culoare = culoare;
        this->soi = new char[strlen(soi) + 1];
        strcpy(this->soi, soi);
    }

    Mar(const Mar& m) : greutate(m.greutate) { // Constructor de copiere
        nrMere++;
        culoare = m.culoare;
        soi = new char[strlen(m.soi) + 1];
        strcpy(soi, m.soi);
    }

    ~Mar() { // Destructor
        nrMere--;
        delete[] soi;
    }

    static int getMere() {
        return nrMere;
    }

    void afisare() {
        cout << "Nr mere: " << nrMere << endl;
        cout << "Culoare: " << culoare << endl;
        cout << "Soi: " << soi << endl;
        cout << "Greutate: " << greutate << "g" << endl;
    }
};

class Banana {
public:
    static int nrBanane;
    int* lungime;
    const string coaja;
    bool dulce;

    Banana() : coaja("Galbenă") {
        nrBanane++;
        lungime = new int(20);
        dulce = true;
    }

    Banana(int* lungime, string coajaNoua, bool dulce) : coaja(coajaNoua) {
        nrBanane++;
        this->lungime = new int(*lungime);
        this->dulce = dulce;
    }

    Banana(const Banana& b) : coaja(b.coaja) {
        nrBanane++;
        lungime = new int(*b.lungime);
        dulce = b.dulce;
    }

    ~Banana() {
        nrBanane--;
        delete lungime;
    }

    static int getBanane() {
        return nrBanane;
    }

    void afisare() {
        cout << "Nr banane: " << nrBanane << endl;
        cout << "Lungime: " << *lungime << " cm" << endl;
        cout << "Coajă: " << coaja << endl;
        cout << "Dulce: " << (dulce ? "Da" : "Nu") << endl;
    }
};

class Cireasa {
public:
    static int nrCirese;
    int dimensiune;
    const string gust;
    char* culoare;

    Cireasa() : gust("Dulce") {
        nrCirese++;
        dimensiune = 10;
        culoare = new char[30];
        strcpy(culoare, "Roșu");
    }

    Cireasa(int dimensiune, string gustNou, char* culoareNoua) : gust(gustNou) {
        nrCirese++;
        this->dimensiune = dimensiune;
        this->culoare = new char[strlen(culoareNoua) + 1];
        strcpy(this->culoare, culoareNoua);
    }

    Cireasa(const Cireasa& c) : gust(c.gust) {
        nrCirese++;
        dimensiune = c.dimensiune;
        culoare = new char[strlen(c.culoare) + 1];
        strcpy(culoare, c.culoare);
    }

    ~Cireasa() {
        nrCirese--;
        delete[] culoare;
    }

    static int getCirese() {
        return nrCirese;
    }

    void afisare() {
        cout << "Nr cirese: " << nrCirese << endl;
        cout << "Dimensiune: " << dimensiune << " mm" << endl;
        cout << "Gust: " << gust << endl;
        cout << "Culoare: " << culoare << endl;
    }
};

int Mar::nrMere = 0;
int Banana::nrBanane = 0;
int Cireasa::nrCirese = 0;

int main() {
    Mar* m1 = new Mar();
    Mar m2("Verde", (char*)"Golden", 180);
    Mar m3(m2);
    cout << Mar::getMere() << endl;
    m1->afisare();
    m2.afisare();
    m3.afisare();

    Banana* b1 = new Banana();
    int* lungime = new int(25);
    Banana b2(lungime, "Verde-Galbenă", false);
    Banana b3(b2);
    cout << "Nr banane: " << Banana::getBanane() << endl;
    b1->afisare();
    b2.afisare();
    b3.afisare();

    Cireasa* c1 = new Cireasa();
    Cireasa c2(8, "Acru-Dulce", (char*)"Violet");
    Cireasa c3(c2);
    c1->afisare();
    c2.afisare();
    c3.afisare();
    cout << "Nr cirese: " << Cireasa::getCirese() << endl;

    

    return 0;
}
