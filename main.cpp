#include <cmath>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stdlib.h>
#include<numeric>
using namespace std;

class dienynas {
public:

    int studentai;
    int namuDarbai;

    vector< string > vardasV;
    vector< string > pavardeV;

    vector< double > namaiV;
    vector< double > average;
    vector < double > egzaminasV;
    vector < double > galutinisV;

    string vardas;
    string pavarde;
    double egzaminas;

    double vidurkisG;

    int suma;
    int temp;

    void input();
    double finalGradeV(double, double);
    void print();
};

void dienynas::input() {

    cout << "Kiek studentu pildysite? " << endl;
    cin >> studentai;

    for (int i = 0; i < studentai; i++)
    {
        cout << "Iveskite varda: ";
        cin >> vardas;
        vardasV.push_back(vardas);

        cout << "Iveskite pavarde: ";
        cin >> pavarde;
        pavardeV.push_back(pavarde);

        cout << "Kiek namu darbu padare? ";
        cin >> namuDarbai;

        for (int k = 1; k <= namuDarbai; k++)
        {
            cout << k << " Namu darbo pazymys: ";
            cin >> suma;
            namaiV.push_back(suma);
            temp = accumulate(namaiV.begin(), namaiV.end(), 0) / namuDarbai;
        }

        average.push_back(temp);
        namaiV.clear();

        cout << "Iveskite egzamino bala: ";
        cin >> egzaminas;
        egzaminasV.push_back(egzaminas);

        finalGradeV(average[i], egzaminasV[i]);
    }
}


double dienynas::finalGradeV(double vidurkis, double egzaminas) {
    vidurkisG = 0.4 * vidurkis + 0.6 * egzaminas;
    galutinisV.push_back(vidurkisG);
}

void dienynas::print() {
    const char separator = ' ';
    const int nameWidth = 18;

    cout << endl;
    cout << "Pavarde           " << "Vardas            " << "Galutinis (Vid.)" << endl;
    cout << "---------------------------------------------------" << endl;

    for (int i = 0; i < studentai; i++)
    {
        cout << left << setw(nameWidth) << setfill(separator) << pavardeV[i];
        cout << left << setw(nameWidth) << setfill(separator) << vardasV[i];
        cout << left << setw(nameWidth) << setfill(separator) << setprecision(2) << fixed << galutinisV[i];
        cout << endl;
    }

    cout << endl;
    cout << endl;
}

int main() {
    dienynas d1;

    d1.input();
    system("CLS");
    d1.print();
}