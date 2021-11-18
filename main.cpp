#include <cmath>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class dienynas {
public:
    string vardas[100];
    string pavarde[100];
    string vidurkis[100];
    string egzaminas[100];

    int studentai;
    double galutinisV;

    char pasirinkimas;

    void input();
    double finalGrade(double, double);
    void print();
};

void dienynas::input() {

    cout << "Iveskite kiek studentu pildysite: ";
    cin >> studentai;

    cin.ignore();

    for (int i = 0; i < studentai; i++)
    {
        cout << "Iveskite varda: ";
        getline(cin, vardas[i]);

        cout << "Iveskite pavarde: ";
        getline(cin, pavarde[i]);

        cout << "Iveskite vidurkio bala: ";
        getline(cin, vidurkis[i]);

        cout << "Iveskite egzamino bala: ";
        getline(cin, egzaminas[i]);
    }

}

double dienynas::finalGrade(double vidurkis, double egzaminas) {
    galutinisV = 0.4 * vidurkis + 0.6 * egzaminas;
    return galutinisV;
}

void dienynas::print() {
    const char separator = ' ';
    const int nameWidth = 18;

    cout << "Pavarde           " << "Vardas            " << "Galutinis (Vid.)" << endl;
    cout << "---------------------------------------------------" << endl;

    for (int i = 0; i < studentai; i++)
    {
        cout << left << setw(nameWidth) << setfill(separator) << pavarde[i];
        cout << left << setw(nameWidth) << setfill(separator) << vardas[i];
        cout << left << setw(nameWidth) << setfill(separator) << setprecision(2) << fixed << finalGrade(stoi(vidurkis[i]), stoi(egzaminas[i])) << endl;
    }

    cout << endl;
}

int main() {
    dienynas d1;

    d1.input();
    d1.print();

}