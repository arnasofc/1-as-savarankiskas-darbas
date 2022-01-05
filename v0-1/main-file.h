#include <iostream> // Input ir Output konsolei
#include <fstream> // Darbas su failais
#include <iomanip> // Output'o lygiavimui
#include <vector> // Vectoriai
#include<numeric> // Vectoriaus sumavimui
#include <algorithm> // Vectoriaus rusiavimui ir skaiciavimams
#include <sstream> // Eiluciu ir stulpeliu failo skaiciavimui
using namespace std; // Std pasalinimui

class uzduotis {
public:
    const char separator = ' ';
    const int nameWidth = 18;

    // Darbui su failais ir kitka
    string dummy; // placeholder
    int howManyLines = 0; // Kiek yra faile eiluciu
    int howManyWords = 0; // Kiek yra faile zodziu/skaiciu

    // Failo duomenu ivedimui
    string vardasT;
    string pavardeT;
    double egzaminasT;

    // Failo duomenu saugojimas vectoriuje
    vector< string > vardasV;
    vector< string > pavardeV;
    vector< double > namaiV; // Namu darbai
    vector< double > egzaminasV;

    // Namu darbu ivedimui is failo
    double temp; // Placeholder

    // Is string i integer konvertavimui
    string laikom;

    //vidurkio skaiciavimui
    double hold;
    double hold2;
    vector< double > averageV; // Vectoriuje laikomi rezultatai V

    //Mediano skaiciavimui
    double hold3;
    vector< double > averageM; // Vectoriuje laikomi rezultatai M

    //finalgrade skaiciavimui
    double vidurkisG;
    double vidurkisGM;
    vector < double > galutinisV;  // Vectoriuje laikomi rezultatai V
    vector < double > galutinisM;  // Vectoriuje laikomi rezultatai M

    vector <string> surusiuotas;

    void input();
    double lineInfo(); // Skaiciuoja kiek is viso yra eiluciu ir kiek zodziu/skaiciu vienoj eilutej
    double rusiavimas();
    double vidurkisV(); // Vidurkio skaiciavimas
    double vidurkisM(); // Mediano skaiciavimas
    double finalGradeV(double, double); // Galutinis balas V
    double finalGradeM(double, double); // Galutinis balas M
    void output();
};

double uzduotis::lineInfo() {
    fstream inputLines("kursiokai.txt", ios::in);
    // SKaiciuojam kiek eiluciu yra
    if (inputLines.is_open()) {
        // Remove first line
        getline(inputLines, dummy);
        while (getline(inputLines, dummy)) {
            howManyLines++;
            stringstream ss(dummy);
            while (ss >> dummy) {
                ++howManyWords;
            }
        }
        howManyWords = howManyWords / howManyLines;
        howManyWords = howManyWords - 3;
        inputLines.close();
    }
    else {
        cout << "Something went wrong! Check if kursiokai.txt exist!";
    }
}

double uzduotis::rusiavimas() {
    fstream inputLines("kursiokai.txt", ios::in);
    // SKaiciuojam kiek eiluciu yra
    if (inputLines.is_open()) {
        // Remove first line
        getline(inputLines, dummy);
        while (getline(inputLines, dummy)) {
            surusiuotas.push_back(dummy);
        }

        sort(surusiuotas.begin(), surusiuotas.end());

        ofstream outfile("tempfile.txt");
        for (int i = 0; i < howManyLines; i++)
        {
            outfile << surusiuotas[i] << endl;
        }
        outfile.close();
        inputLines.close();
    }
    else {
        cout << "Something went wrong! Check if kursiokai.txt exist!";
    }
}

double uzduotis::vidurkisV() {
    namaiV.erase(std::remove(namaiV.begin(), namaiV.end(), 0), namaiV.end());
    hold = accumulate(namaiV.begin(), namaiV.end(), 0);
    hold2 = hold / namaiV.size();
    averageV.push_back(hold2);
}

double uzduotis::finalGradeV(double vidurkis, double egzaminas) {
    vidurkisG = 0.4 * vidurkis + 0.6 * egzaminas;
    galutinisV.push_back(vidurkisG);
}

double uzduotis::vidurkisM() {
    namaiV.erase(std::remove(namaiV.begin(), namaiV.end(), 0), namaiV.end());
    sort(namaiV.begin(), namaiV.end());
    hold3 = (namaiV.size() % 2 == 0 ? (namaiV[namaiV.size() / 2] + namaiV[(namaiV.size() / 2) - 1]) / 2 : namaiV[namaiV.size() / 2]);
    averageM.push_back(hold3);
    namaiV.clear();
}

double uzduotis::finalGradeM(double vidurkis, double egzaminas) {
    vidurkisGM = 0.4 * vidurkis + 0.6 * egzaminas;
    galutinisM.push_back(vidurkisGM);
}

void uzduotis::input() {
    fstream input("tempfile.txt", ios::in);

    if (input.is_open()) {
        for (int p = 0; p < howManyLines; p++)
        {
            input >> pavardeT;
            pavardeV.push_back(pavardeT);

            input >> vardasT;
            vardasV.push_back(vardasT);

            input >> egzaminasT;
            egzaminasV.push_back(egzaminasT);

            for (int i = 0; i < howManyWords; i++)
            {
                input >> laikom;
                stringstream parser(laikom);
                int x = 0;
                parser >> x;
                namaiV.push_back(x);
            }

            vidurkisV();
            finalGradeV(averageV[p], egzaminasV[p]);

            vidurkisM();
            finalGradeM(averageM[p], egzaminasV[p]);

            namaiV.clear();
            getline(input, dummy);
        }
        input.close();
    }
    else {
        cout << "Something went wrong! Check if kursiokai.txt exist!";
    }
}

void uzduotis::output() {
    cout << endl;
    cout << "Pavarde           " << "Vardas            " << "Egzaminas         " << "Galutinis (Med.)  " << "Galutinis (Vid.)" << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < howManyLines; i++)
    {
        cout << left << setw(nameWidth) << setfill(separator) << pavardeV[i];
        cout << left << setw(nameWidth) << setfill(separator) << vardasV[i];
        cout << left << setw(nameWidth) << setfill(separator) << setprecision(2) << fixed << egzaminasV[i];
        cout << left << setw(nameWidth) << setfill(separator) << setprecision(2) << fixed << galutinisM[i];
        cout << left << setw(nameWidth) << setfill(separator) << setprecision(2) << fixed << galutinisV[i];
        cout << endl;
    }
    cout << endl;
}