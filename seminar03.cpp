#include<iostream>
using namespace std;

class Magazin {
public:
	string oras;
	int nrAngajati;
	float suprafata;
	const int anDeschidere;
	static int impozitM2;

	Magazin() :anDeschidere(2024), nrAngajati(2) {
		this->oras = "Bucuresti";
		this->suprafata = 50;
	}
	void afisare() {
		cout << "Oras:" << this->oras << endl;
	    cout << "Numar angajati:" << this->nrAngajati<< endl;
		cout << "Suprafata:" << this->suprafata << endl;
		cout << "An deschidere:" << this->anDeschidere << endl;
		cout << "Impozit pe m2:" << this->impozitM2 << endl;


	}
};

int Magazin::impozitM2 = 2; //initializarea unui atribut static

int main() {
	Magazin m1;
	m1.afisare();




	return 0;
}