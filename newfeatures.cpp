#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <stdlib.h>
#include<numeric>
#include <algorithm> 
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
    vector < double > galutinisM;

    string vardas;
    string pavarde;
    double egzaminas;

    double vidurkisG;
    double vidurkisGM;

    int state = 2;
    int statePazymiuKiekiui = 1;
    string statePazymiuKiekiuiKlausimas;

    string answer;
    string answerND;
    double n;

    int suma;
    double temp;

    void input();
    double namuDarbams();
    double egzaminoIvedimas();
    double vidurkisV();
    double vidurkisM();
    double finalGradeM(double, double);
    double finalGradeV(double, double);
    void print();
};

void dienynas::input() {

    cout << "Kiek studentu pildysite? ";
    cin >> studentai;

    cout << "Ar norite naudoti vidurkio isvedimui mediana y/n? ";
    cin >> answer;

    for (int i = 0; i < studentai; i++)
    {
        cout << "Iveskite varda: ";
        cin >> vardas;
        vardasV.push_back(vardas);

        cout << "Iveskite pavarde: ";
        cin >> pavarde;
        pavardeV.push_back(pavarde);

        if (answer == "y" || answer == "Y") {
            state = 1;
        }
        else if (answer == "n" || answer == "N") {
            state = 2;
        }
        else {
            cout << "Something went wrong.";
            exit(EXIT_FAILURE);
        }

        cout << "Ar yra zinomas padarytu namu darbu skaicius (n) y/n? "; // WORKING HERE
        cin >> answerND;

        if (answerND == "y" || answerND == "Y") {
            cout << "Kiek namu darbu padare? ";
            cin >> namuDarbai;
            namuDarbams();
        }
        else if (answerND == "n" || answerND == "N") {
            if (statePazymiuKiekiui == 1) {
                for (int k = 1; k <= 100; k++)
                {
                    cout << k << " Namu darbo pazymys: ";
                    cin >> suma;
                    namaiV.push_back(suma);

                    cout << "Ar norite ivesti dar viena namu darba y/n?";
                    cin >> statePazymiuKiekiuiKlausimas;

                    if (statePazymiuKiekiuiKlausimas == "y" || statePazymiuKiekiuiKlausimas == "Y") {

                    }
                    else if (statePazymiuKiekiuiKlausimas == "n" || statePazymiuKiekiuiKlausimas == "N") {
                        break;
                    }
                    else {
                        cout << "Something went wrong.";
                        exit(EXIT_FAILURE);
                    }
                }
            }
            else {
                cout << "Something went wrong.";
                exit(EXIT_FAILURE);
            }
        }
        else {
            cout << "Something went wrong.";
            exit(EXIT_FAILURE);
        }

        if (state == 1) {
            vidurkisM();
            egzaminoIvedimas();
            finalGradeM(average[i], egzaminasV[i]);
        }
        else if (state == 2) {
            vidurkisV();
            egzaminoIvedimas();
            finalGradeV(average[i], egzaminasV[i]);
        }
        else {
            cout << "Something went wrong.";
            exit(EXIT_FAILURE);
        }
    }
}

double dienynas::egzaminoIvedimas() {
    cout << "Iveskite egzamino bala: ";
    cin >> egzaminas;
    egzaminasV.push_back(egzaminas);
}

double dienynas::namuDarbams() {
    for (int k = 1; k <= namuDarbai; k++)
    {
        cout << k << " Namu darbo pazymys: ";
        cin >> suma;
        namaiV.push_back(suma);
    }
}

double dienynas::vidurkisV() {
    temp = accumulate(namaiV.begin(), namaiV.end(), 0) / namaiV.size();
    average.push_back(temp);
    namaiV.clear();

}

double dienynas::vidurkisM() {
    sort(namaiV.begin(), namaiV.end());
    n = (namaiV.size() % 2 == 0 ? (namaiV[namaiV.size() / 2] + namaiV[(namaiV.size() / 2) - 1]) / 2 : namaiV[namaiV.size() / 2]);

    average.push_back(n);
    namaiV.clear();
}

double dienynas::finalGradeM(double vidurkis, double egzaminas) {
    vidurkisGM = 0.4 * vidurkis + 0.6 * egzaminas;
    galutinisM.push_back(vidurkisGM);
}

double dienynas::finalGradeV(double vidurkis, double egzaminas) {
    vidurkisG = 0.4 * vidurkis + 0.6 * egzaminas;
    galutinisV.push_back(vidurkisG);
}

void dienynas::print() {
    const char separator = ' ';
    const int nameWidth = 18;

    cout << endl;
    if (state == 1) {
        cout << "Pavarde           " << "Vardas            " << "Galutinis (Med.)" << endl;
    }
    else if (state == 2) {
        cout << "Pavarde           " << "Vardas            " << "Galutinis (Vid.)" << endl;
    }
    else {
        cout << "Something went wrong!";
        exit(EXIT_FAILURE);
    }
    cout << "---------------------------------------------------" << endl;

    for (int i = 0; i < studentai; i++)
    {
        cout << left << setw(nameWidth) << setfill(separator) << pavardeV[i];
        cout << left << setw(nameWidth) << setfill(separator) << vardasV[i];
        if (state == 1) {
            cout << left << setw(nameWidth) << setfill(separator) << setprecision(2) << fixed << galutinisM[i];
        }
        else if (state == 2) {
            cout << left << setw(nameWidth) << setfill(separator) << setprecision(2) << fixed << galutinisV[i];
        }
        else {
            cout << "Something went wrong!";
            exit(EXIT_FAILURE);
        }
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