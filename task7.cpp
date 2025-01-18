#include <iostream>
#include <cstring>
using namespace std;

class Mar {
private:
    string culoare;
    int greutate;  // in grame
    char* soi;

public:
    Mar() : culoare("Rosu"), greutate(150) {
        soi = new char[20];
        strcpy(soi, "Ionatan");
    }

    Mar(string culoare, int greutate, const char* soi) : culoare(culoare), greutate(greutate) {
        this->soi = new char[strlen(soi) + 1];
        strcpy(this->soi, soi);
    }

    Mar(const Mar& m) : culoare(m.culoare), greutate(m.greutate) {
        soi = new char[strlen(m.soi) + 1];
        strcpy(soi, m.soi);
    }

    ~Mar() {
        delete[] soi;
    }

    // Getteri si setteri
    string getCuloare() const { return culoare; }
    void setCuloare(string culoare) { this->culoare = culoare; }

    int getGreutate() const { return greutate; }
    void setGreutate(int greutate) { this->greutate = greutate; }

    const char* getSoi() const { return soi; }
    void setSoi(const char* soi) {
        delete[] this->soi;
        this->soi = new char[strlen(soi) + 1];
        strcpy(this->soi, soi);
    }

    void afisare() const {
        cout << "Mar - Culoare: " << culoare << ", Greutate: " << greutate << "g, Soi: " << soi << endl;
    }
};

class CosFructe {
private:
    int capacitate;
    string material;
    Mar mar;
    bool estePlin;

public:
    CosFructe() : capacitate(5), material("Plastic"), estePlin(false) {}

    CosFructe(int capacitate, string material, const Mar& mar, bool estePlin)
        : capacitate(capacitate), material(material), mar(mar), estePlin(estePlin) {}

    // Getteri si setteri
    int getCapacitate() const { return capacitate; }
    void setCapacitate(int capacitate) { this->capacitate = capacitate; }

    string getMaterial() const { return material; }
    void setMaterial(string material) { this->material = material; }

    bool getEstePlin() const { return estePlin; }
    void setEstePlin(bool estePlin) { this->estePlin = estePlin; }

    void afisare() const {
        cout << "Cos Fructe - Capacitate: " << capacitate << ", Material: " << material << ", Este plin: " << (estePlin ? "Da" : "Nu") << endl;
        mar.afisare();
    }
};

class CosFructePlastik : public CosFructe {
private:
    string culoareCos;

public:
    CosFructePlastik() : CosFructe(), culoareCos("Alb") {}

    CosFructePlastik(int capacitate, string material, const Mar& mar, bool estePlin, string culoareCos)
        : CosFructe(capacitate, material, mar, estePlin), culoareCos(culoareCos) {}

    // Getter si setter pentru culoareCos
    string getCuloareCos() const { return culoareCos; }
    void setCuloareCos(string culoareCos) { this->culoareCos = culoareCos; }

    void afisare() const {
        CosFructe::afisare();
        cout << "Culoare cos: " << culoareCos << endl;
    }
};

class MarOrganic : public Mar {
private:
    bool certificatOrganic;

public:
    MarOrganic() : Mar(), certificatOrganic(true) {}

    MarOrganic(string culoare, int greutate, const char* soi, bool certificatOrganic)
        : Mar(culoare, greutate, soi), certificatOrganic(certificatOrganic) {}

    // Getter si setter pentru certificatOrganic
    bool getCertificatOrganic() const { return certificatOrganic; }
    void setCertificatOrganic(bool certificatOrganic) { this->certificatOrganic = certificatOrganic; }

    void afisare() const {
        Mar::afisare();
        cout << "Certificat Organic: " << (certificatOrganic ? "Da" : "Nu") << endl;
    }
};

int main() {
    // Crearea unui obiect Mar
    Mar m1("Verde", 180, "Granny Smith");
    m1.afisare();

    // Crearea unui obiect CosFructe
    CosFructe cos1(10, "Metal", m1, true);
    cos1.afisare();

    // Crearea unui obiect CosFructePlastik
    CosFructePlastik cosPlastik1(8, "Plastic", m1, false, "Rosu");
    cosPlastik1.afisare();

    // Crearea unui obiect MarOrganic
    MarOrganic marOrganic1("Galben", 120, "Golden", true);
    marOrganic1.afisare();

    // Demonstratie upcasting
    CosFructe* cosPtr = &cosPlastik1; // Upcasting: CosFructePtr -> CosFructePlastik
    cosPtr->afisare(); // Se apelează metoda `afisare()` din CosFructePlastik

    Mar* marPtr = &marOrganic1; // Upcasting: MarPtr -> MarOrganic
    marPtr->afisare(); // Se apelează metoda `afisare()` din MarOrganic

    return 0;
}
