#include <iostream>
#include <string>
#include <cstring>

using namespace std;

// Definirea clasei Mar
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

    Mar(string culoare, const char* soi, int greutate) : greutate(greutate) {
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

    const char* getSoi() const { return soi; }
    void setSoi(const char* s) {
        delete[] soi;
        soi = new char[strlen(s) + 1];
        strcpy(soi, s);
    }

    void afisare() const {
        cout << "Mar: Culoare = " << culoare << ", Greutate = " << greutate << "g, Soi = " << soi << endl;
    }

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

    Mar& operator++() { // Prefix ++
        greutate += 10;
        return *this;
    }
};

int Mar::nrMere = 0;

// Definirea clasei CosFructe
class CosFructe {
private:
    int capacitate;
    string material;
    Mar mar; // relatie de tipul "has-a" (un cos de fructe are un mar)
    bool estePlin;

public:
    CosFructe() : capacitate(5), material("Plastic"), estePlin(false) {}

    CosFructe(int capacitate, string material, Mar mar) : capacitate(capacitate), material(material), mar(mar), estePlin(false) {}

    CosFructe(const CosFructe& c) : capacitate(c.capacitate), material(c.material), mar(c.mar), estePlin(c.estePlin) {}

    ~CosFructe() {}

    int getCapacitate() const { return capacitate; }
    void setCapacitate(int c) { capacitate = c; }

    string getMaterial() const { return material; }
    void setMaterial(string m) { material = m; }

    Mar getMar() const { return mar; }
    void setMar(Mar m) { mar = m; }

    bool getEstePlin() const { return estePlin; }
    void setEstePlin(bool p) { estePlin = p; }

    void afisare() const {
        cout << "Cos de fructe: Capacitate = " << capacitate << ", Material = " << material
            << ", Este plin = " << (estePlin ? "Da" : "Nu") << endl;
        mar.afisare();
    }

    // Operator de atribuire
    CosFructe& operator=(const CosFructe& c) {
        if (this != &c) {
            capacitate = c.capacitate;
            material = c.material;
            mar = c.mar;
            estePlin = c.estePlin;
        }
        return *this;
    }

    // Operator + pentru adăugarea unui mar suplimentar în coș
    CosFructe operator+(const Mar& m) {
        CosFructe temp(*this);
        if (temp.estePlin == false) {
            temp.mar = m;
            temp.estePlin = true;
        }
        return temp;
    }

    // Operator de comparare a capacității coșului
    bool operator>(const CosFructe& c) const {
        return capacitate > c.capacitate;
    }
};

// Main
int main() {
    // Creare obiecte Mar
    Mar mar1("Rosu", "Ionatan", 150);
    Mar mar2("Verde", "Granny Smith", 180);

    // Creare obiect CosFructe
    CosFructe cos1;
    CosFructe cos2(10, "Metal", mar2);

    // Modificare atribute CosFructe
    cos1.setMaterial("Plastic");
    cos1.setCapacitate(8);
    cos1.setEstePlin(true);

    // Afisare obiecte
    cout << "Cos 1:" << endl;
    cos1.afisare();

    cout << "\nCos 2:" << endl;
    cos2.afisare();

    // Supraincarcarea operatorilor
    cos1 = cos2; // operatorul de atribuire
    cout << "\nCos 1 dupa atribuire:" << endl;
    cos1.afisare();

    CosFructe cos3 = cos1 + mar1; // operatorul +
    cout << "\nCos 3 dupa adaugarea unui mar:" << endl;
    cos3.afisare();

    if (cos1 > cos2) {
        cout << "\nCos 1 are capacitatea mai mare decat Cos 2." << endl;
    }
    else {
        cout << "\nCos 1 nu are capacitatea mai mare decat Cos 2." << endl;
    }

    return 0;
}
