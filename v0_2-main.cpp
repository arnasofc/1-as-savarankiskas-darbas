#include <iostream> // Input ir Output konsolei
#include <fstream> // Darbas su failais
#include <iomanip> // Output'o lygiavimui
#include <vector> // Vectoriai
#include<numeric> // Vectoriaus sumavimui
#include <algorithm> // Vectoriaus rusiavimui ir skaiciavimams
#include <sstream> // Eiluciu ir stulpeliu failo skaiciavimui
#include <chrono>

using namespace std; // Std pasalinimui
using namespace std::chrono;
typedef high_resolution_clock Clock;
typedef Clock::time_point ClockTime;

class versijadu {
public:
    ofstream sarasas1{ "sarasai/sarasas1.txt", ios_base::app };
    ofstream sarasas2{ "sarasai/sarasas2.txt", ios_base::app };
    ofstream sarasas3{ "sarasai/sarasas3.txt", ios_base::app };
    ofstream sarasas4{ "sarasai/sarasas4.txt", ios_base::app };
    ofstream sarasas5{ "sarasai/sarasas5.txt", ios_base::app };

    ofstream sarasas1_vargsiukai{ "final-sarasai/sarasas1-vargsiukai.txt", ios_base::app };
    ofstream sarasas1_kietiakiai{ "final-sarasai/sarasas1-kietiakiai.txt", ios_base::app };

    ofstream sarasas2_vargsiukai{ "final-sarasai/sarasas2-vargsiukai.txt", ios_base::app };
    ofstream sarasas2_kietiakiai{ "final-sarasai/sarasas2-kietiakiai.txt", ios_base::app };

    ofstream sarasas3_vargsiukai{ "final-sarasai/sarasas3-vargsiukai.txt", ios_base::app };
    ofstream sarasas3_kietiakiai{ "final-sarasai/sarasas3-kietiakiai.txt", ios_base::app };

    ofstream sarasas4_vargsiukai{ "final-sarasai/sarasas4-vargsiukai.txt", ios_base::app };
    ofstream sarasas4_kietiakiai{ "final-sarasai/sarasas4-kietiakiai.txt", ios_base::app };

    ofstream sarasas5_vargsiukai{ "final-sarasai/sarasas5-vargsiukai.txt", ios_base::app };
    ofstream sarasas5_kietiakiai{ "final-sarasai/sarasas5-kietiakiai.txt" , ios_base::app };

    int max;

    void sarasas1_gen();
    void sarasas2_gen();
    void sarasas3_gen();
    void sarasas4_gen();
    void sarasas5_gen();
    void sarasutikrinimas();

    const char separator = ' ';
    const int nameWidth = 18;

    // Darbui su failais ir kitka
    string dummy; // placeholder

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

    //vidurkio skaiciavimui
    double hold;
    double hold2;
    vector< double > averageV; // Vectoriuje laikomi rezultatai V

    //Mediano skaiciavimui
    double hold3;
    vector< double > averageM; // Vectoriuje laikomi rezultatai M

    // Is string i integer konvertavimui
    string laikom;

    //finalgrade skaiciavimui
    double vidurkisG;
    double vidurkisGM;
    vector < double > galutinisV;  // Vectoriuje laikomi rezultatai V
    vector < double > galutinisM;  // Vectoriuje laikomi rezultatai M

    void printExecutionTime(ClockTime, ClockTime, string);
    void resetVectors();

    void vidurkisV(); // Vidurkio skaiciavimas
    void vidurkisM(); // Mediano skaiciavimas
    void finalGradeV(double, double); // Galutinis balas V
    void finalGradeM(double, double); // Galutinis balas M

    void input_main(int, string);
    void input_output(int, ofstream&, ofstream&);

    void output_sarasas1();
    void output_sarasas2();
    void output_sarasas3();
    void output_sarasas4();
    void output_sarasas5();

    void resetSarasus();
    void output_sarasu_gen();
    void output_rusiavimas();


    ClockTime start_time;
    ClockTime end_time;
    ClockTime start_time2;
    ClockTime end_time2;
    ClockTime start_time3;
    ClockTime end_time3;
    ClockTime start_time4;
    ClockTime end_time4;
    void spartos_analize();
};

void versijadu::printExecutionTime(ClockTime start_time, ClockTime end_time, string text)
{
    auto execution_time_ms = duration_cast<milliseconds>(end_time - start_time).count();
    auto execution_time_sec = duration_cast<seconds>(end_time - start_time).count();
    auto execution_time_min = duration_cast<minutes>(end_time - start_time).count();
    auto execution_time_hour = duration_cast<hours>(end_time - start_time).count();
    cout << text << execution_time_hour << " Hours " << execution_time_min % 60 << " Minutes " << execution_time_sec % 60 << " Seconds " << execution_time_ms % 60 << " Milliseconds" << endl;
}

void versijadu::resetVectors() {
    pavardeV.clear();
    vardasV.clear();
    egzaminasV.clear();
    galutinisM.clear();
    galutinisV.clear();

    namaiV.clear();
    averageV.clear();
    averageM.clear();
}

void versijadu::sarasas1_gen() {
    max = 10;
    srand(time(0));

    sarasas1 << "Pavarde      " << "Vardas       " << "Egz      " << "ND1 - ND5" << endl;
    sarasas1 << "------------------------------------------------" << endl;

    cout << "Sarasas 1 is being generated..." << endl;
    for (int i = 1; i <= 1000; i++)
    {
        sarasas1 << "Pavarde" << i << " ";
        sarasas1 << setw(10) << "Vardas" << i << " ";
        sarasas1 << setw(6) << rand() % max + 1 << " ";
        sarasas1 << setw(8) << rand() % max + 1 << " ";
        sarasas1 << rand() % max + 1 << " ";
        sarasas1 << rand() % max + 1 << " ";
        sarasas1 << rand() % max + 1 << " ";
        sarasas1 << rand() % max + 1 << endl;
    }
    cout << "Sarasas 1 has been generated." << endl;
    cout << endl;

    sarasas1.close();
}

void versijadu::sarasas2_gen() {
    max = 10;
    srand(time(0));

    sarasas2 << "Pavarde      " << "Vardas       " << "Egz      " << "ND1 - ND5" << endl;
    sarasas2 << "------------------------------------------------" << endl;

    cout << "Sarasas 2 is being generated..." << endl;
    for (int i = 1; i <= 10000; i++)
    {
        sarasas2 << "Pavarde" << i << " ";
        sarasas2 << setw(10) << "Vardas" << i << " ";
        sarasas2 << setw(6) << rand() % max + 1 << " ";
        sarasas2 << setw(8) << rand() % max + 1 << " ";
        sarasas2 << rand() % max + 1 << " ";
        sarasas2 << rand() % max + 1 << " ";
        sarasas2 << rand() % max + 1 << " ";
        sarasas2 << rand() % max + 1 << endl;
    }
    cout << "Sarasas 2 has been generated." << endl;
    cout << endl;

    sarasas2.close();
}

void versijadu::sarasas3_gen() {
    max = 10;
    srand(time(0));

    sarasas3 << "Pavarde      " << "Vardas       " << "Egz      " << "ND1 - ND5" << endl;
    sarasas3 << "------------------------------------------------" << endl;

    cout << "Sarasas 3 is being generated..." << endl;
    for (int i = 1; i <= 100000; i++)
    {
        sarasas3 << "Pavarde" << i << " ";
        sarasas3 << setw(10) << "Vardas" << i << " ";
        sarasas3 << setw(6) << rand() % max + 1 << " ";
        sarasas3 << setw(8) << rand() % max + 1 << " ";
        sarasas3 << rand() % max + 1 << " ";
        sarasas3 << rand() % max + 1 << " ";
        sarasas3 << rand() % max + 1 << " ";
        sarasas3 << rand() % max + 1 << endl;
    }
    cout << "Sarasas 3 has been generated." << endl;
    cout << endl;

    sarasas3.close();
}

void versijadu::sarasas4_gen() {
    max = 10;
    srand(time(0));

    sarasas4 << "Pavarde      " << "Vardas       " << "Egz      " << "ND1 - ND5" << endl;
    sarasas4 << "------------------------------------------------" << endl;

    cout << "Sarasas 4 is being generated..." << endl;
    for (int i = 1; i <= 1000000; i++)
    {
        sarasas4 << "Pavarde" << i << " ";
        sarasas4 << setw(10) << "Vardas" << i << " ";
        sarasas4 << setw(6) << rand() % max + 1 << " ";
        sarasas4 << setw(8) << rand() % max + 1 << " ";
        sarasas4 << rand() % max + 1 << " ";
        sarasas4 << rand() % max + 1 << " ";
        sarasas4 << rand() % max + 1 << " ";
        sarasas4 << rand() % max + 1 << endl;
    }
    cout << "Sarasas 4 has been generated." << endl;
    cout << endl;

    sarasas4.close();
}

void versijadu::sarasas5_gen() {
    max = 10;
    srand(time(0));

    sarasas5 << "Pavarde      " << "Vardas       " << "Egz      " << "ND1 - ND5" << endl;
    sarasas5 << "------------------------------------------------" << endl;

    cout << "Sarasas 5 is being generated..." << endl;
    for (int i = 1; i <= 10000000; i++)
    {
        sarasas5 << "Pavarde" << i << " ";
        sarasas5 << setw(10) << "Vardas" << i << " ";
        sarasas5 << setw(6) << rand() % max + 1 << " ";
        sarasas5 << setw(8) << rand() % max + 1 << " ";
        sarasas5 << rand() % max + 1 << " ";
        sarasas5 << rand() % max + 1 << " ";
        sarasas5 << rand() % max + 1 << " ";
        sarasas5 << rand() % max + 1 << endl;
    }
    cout << "Sarasas 5 has been generated." << endl;
    cout << endl;

    sarasas5.close();
}

void versijadu::resetSarasus() {
    ofstream sarasas1{ "sarasai/sarasas1.txt" };
    ofstream sarasas2{ "sarasai/sarasas2.txt" };
    ofstream sarasas3{ "sarasai/sarasas3.txt" };
    ofstream sarasas4{ "sarasai/sarasas4.txt" };
    ofstream sarasas5{ "sarasai/sarasas5.txt" };

    ofstream sarasas1_vargsiukai{ "final-sarasai/sarasas1-vargsiukai.txt" };
    ofstream sarasas1_kietiakiai{ "final-sarasai/sarasas1-kietiakiai.txt" };
    ofstream sarasas2_vargsiukai{ "final-sarasai/sarasas2-vargsiukai.txt" };
    ofstream sarasas2_kietiakiai{ "final-sarasai/sarasas2-kietiakiai.txt" };
    ofstream sarasas3_vargsiukai{ "final-sarasai/sarasas3-vargsiukai.txt" };
    ofstream sarasas3_kietiakiai{ "final-sarasai/sarasas3-kietiakiai.txt" };
    ofstream sarasas4_vargsiukai{ "final-sarasai/sarasas4-vargsiukai.txt" };
    ofstream sarasas4_kietiakiai{ "final-sarasai/sarasas4-kietiakiai.txt" };
    ofstream sarasas5_vargsiukai{ "final-sarasai/sarasas5-vargsiukai.txt" };
    ofstream sarasas5_kietiakiai{ "final-sarasai/sarasas5-kietiakiai.txt" };
}

void versijadu::sarasutikrinimas() {
    start_time = Clock::now();
    ifstream sarasas1_tikrinimas("sarasai/sarasas1.txt");
    ifstream sarasas2_tikrinimas("sarasai/sarasas2.txt");
    ifstream sarasas3_tikrinimas("sarasai/sarasas3.txt");
    ifstream sarasas4_tikrinimas("sarasai/sarasas4.txt");
    ifstream sarasas5_tikrinimas("sarasai/sarasas5.txt");

    sarasas1_tikrinimas.seekg(0, ios::end);
    sarasas2_tikrinimas.seekg(0, ios::end);
    sarasas3_tikrinimas.seekg(0, ios::end);
    sarasas4_tikrinimas.seekg(0, ios::end);
    sarasas5_tikrinimas.seekg(0, ios::end);

    if (sarasas1_tikrinimas.tellg() == 0 || sarasas2_tikrinimas.tellg() == 0 || sarasas3_tikrinimas.tellg() == 0 || sarasas4_tikrinimas.tellg() == 0 || sarasas5_tikrinimas.tellg() == 0) {
        cout << "!--- Kadangi sarasas/ai yra tusti, jis/e vistiek bus sugeneruoti." << endl;
        cout << "Please wait..." << endl;
        cout << endl;
    }

    if (sarasas1_tikrinimas.tellg() == 0) {
        cout << "Sarasas 1 is empty." << endl;
        sarasas1_gen();
    }
    if (sarasas2_tikrinimas.tellg() == 0) {
        cout << "Sarasas 2 is empty." << endl;
        sarasas2_gen();
    }
    if (sarasas3_tikrinimas.tellg() == 0) {
        cout << "Sarasas 3 is empty." << endl; // paskui pasalinti komentara
        sarasas3_gen(); // paskui pasalinti komentara
    }
    if (sarasas4_tikrinimas.tellg() == 0) {
        cout << "Sarasas 4 is empty." << endl; // paskui pasalinti komentara
        sarasas4_gen(); // paskui pasalinti komentara
    }
    if (sarasas5_tikrinimas.tellg() == 0) {
        cout << "Sarasas 5 is empty." << endl; // paskui pasalinti komentara
        sarasas5_gen(); // paskui pasalinti komentara
    }
    end_time = Clock::now();
}

void versijadu::vidurkisV() {
    namaiV.erase(std::remove(namaiV.begin(), namaiV.end(), 0), namaiV.end());
    hold = accumulate(namaiV.begin(), namaiV.end(), 0);
    hold2 = hold / namaiV.size();
    averageV.push_back(hold2);
}

void versijadu::finalGradeV(double vidurkis, double egzaminas) {
    vidurkisG = 0.4 * vidurkis + 0.6 * egzaminas;
    galutinisV.push_back(vidurkisG);
}

void versijadu::vidurkisM() {
    namaiV.erase(std::remove(namaiV.begin(), namaiV.end(), 0), namaiV.end());
    sort(namaiV.begin(), namaiV.end());
    hold3 = (namaiV.size() % 2 == 0 ? (namaiV[namaiV.size() / 2] + namaiV[(namaiV.size() / 2) - 1]) / 2 : namaiV[namaiV.size() / 2]);
    averageM.push_back(hold3);
    namaiV.clear();
}

void versijadu::finalGradeM(double vidurkis, double egzaminas) {
    vidurkisGM = 0.4 * vidurkis + 0.6 * egzaminas;
    galutinisM.push_back(vidurkisGM);
}

void versijadu::input_main(int iki, string sarasas) {
    start_time2 = Clock::now();
    fstream input(sarasas, ios::in);
    if (input.is_open()) {

        getline(input, dummy);
        getline(input, dummy);

        for (int p = 0; p < iki; p++)
        {
            input >> pavardeT;
            pavardeV.push_back(pavardeT);

            input >> vardasT;
            vardasV.push_back(vardasT);

            input >> egzaminasT;
            egzaminasV.push_back(egzaminasT);

            for (int i = 0; i < 5; i++)
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
        cout << "Something went wrong! Check if sarasas[i].txt exist!";
    }
    end_time2 = Clock::now();
}

void versijadu::input_output(int iki, ofstream& vargsiukai, ofstream& kietiakiai) {
    start_time4 = Clock::now();
    vargsiukai << "Pavarde           " << "Vardas            " << "Egzaminas         " << "Galutinis (Med.)  " << "Galutinis (Vid.)" << endl;
    vargsiukai << "----------------------------------------------------------------------------------------" << endl;

    kietiakiai << "Pavarde           " << "Vardas            " << "Egzaminas         " << "Galutinis (Med.)  " << "Galutinis (Vid.)" << endl;
    kietiakiai << "----------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < iki; i++)
    {
        if (galutinisV[i] < 5.00) {
            vargsiukai << left << setw(nameWidth) << setfill(separator) << pavardeV[i];
            vargsiukai << left << setw(nameWidth) << setfill(separator) << vardasV[i];
            vargsiukai << left << setw(nameWidth) << setfill(separator) << setprecision(2) << fixed << egzaminasV[i];
            vargsiukai << left << setw(nameWidth) << setfill(separator) << setprecision(2) << fixed << galutinisM[i];
            vargsiukai << left << setw(nameWidth) << setfill(separator) << setprecision(2) << fixed << galutinisV[i];
            vargsiukai << endl;
        }

        if (galutinisV[i] >= 5.00) {
            kietiakiai << left << setw(nameWidth) << setfill(separator) << pavardeV[i];
            kietiakiai << left << setw(nameWidth) << setfill(separator) << vardasV[i];
            kietiakiai << left << setw(nameWidth) << setfill(separator) << setprecision(2) << fixed << egzaminasV[i];
            kietiakiai << left << setw(nameWidth) << setfill(separator) << setprecision(2) << fixed << galutinisM[i];
            kietiakiai << left << setw(nameWidth) << setfill(separator) << setprecision(2) << fixed << galutinisV[i];
            kietiakiai << endl;
        }
    }
    resetVectors();
    end_time4 = Clock::now();
}

void versijadu::output_sarasas1() {
    cout << "Sarasas 1 - Vargsiukai and Kietiakiai is progress..." << endl;
    input_main(1000, "sarasai/sarasas1.txt");
    input_output(1000, sarasas1_vargsiukai, sarasas1_kietiakiai);
    cout << "Sarasas 1 splicing is completed." << endl;
    cout << endl;
}

void versijadu::output_sarasas2() {
    cout << "Sarasas 2 - Vargsiukai and Kietiakiai is progress..." << endl;
    input_main(10000, "sarasai/sarasas2.txt");
    input_output(10000, sarasas2_vargsiukai, sarasas2_kietiakiai);
    cout << "Sarasas 2 splicing is completed." << endl;
    cout << endl;
}

void versijadu::output_sarasas3() {
    cout << "Sarasas 3 - Vargsiukai and Kietiakiai is progress..." << endl;
    input_main(100000, "sarasai/sarasas3.txt");
    input_output(100000, sarasas3_vargsiukai, sarasas3_kietiakiai);
    cout << "Sarasas 3 splicing is completed." << endl;
    cout << endl;
}

void versijadu::output_sarasas4() {
    cout << "Sarasas 4 - Vargsiukai and Kietiakiai is progress..." << endl;
    input_main(1000000, "sarasai/sarasas4.txt");
    input_output(1000000, sarasas4_vargsiukai, sarasas4_kietiakiai);
    cout << "Sarasas 4 splicing is completed." << endl;
    cout << endl;
}

void versijadu::output_sarasas5() {
    cout << "Sarasas 5 - Vargsiukai and Kietiakiai is progress..." << endl;
    input_main(10000000, "sarasai/sarasas5.txt");
    input_output(10000000, sarasas5_vargsiukai, sarasas5_kietiakiai);
    cout << "Sarasas 5 splicing is completed." << endl;
    cout << endl;
}

void versijadu::output_sarasu_gen() {
    start_time = Clock::now();
    sarasas1_gen();
    sarasas2_gen();
    sarasas3_gen(); // paskui pasalinti komentara
    sarasas4_gen(); // paskui pasalinti komentara
    sarasas5_gen(); // paskui pasalinti komentara
    end_time = Clock::now();
}

void versijadu::output_rusiavimas() {
    start_time3 = Clock::now();
    output_sarasas1();
    output_sarasas2();
    output_sarasas3(); // paskui pasalinti komentara
    output_sarasas4(); // paskui pasalinti komentara
    output_sarasas5(); // paskui pasalinti komentara
    end_time3 = Clock::now();
}

void versijadu::spartos_analize() {
    printExecutionTime(start_time, end_time, "Failu (Sarasu) kurimas:                            ");
    printExecutionTime(start_time2, end_time2, "Duomenu nuskaitymas is failu:                      ");
    printExecutionTime(start_time3, end_time3, "Studentu rusiavimas i du naujus failus:            ");
    printExecutionTime(start_time4, end_time4, "Surusiuotu studentu isvedimas i du naujus failus:  ");
}

int main(int argc, char const* argv[])
{
    // system("CLS");
    cout << endl;
    cout << "!--- Make sure folders named 'sarasai' and 'final-sarasai' are created otherwise program won't work!" << endl;
    cout << endl;

    versijadu v2;
    string ans;
    string answ;

    cout << "Ar norite sugeneruoti 5 naujus sarasus? (y/n) ";
    cin >> ans;

    if (ans == "y" || ans == "Y") {
        cout << "Please wait..." << endl;
        cout << endl;
        v2.resetSarasus();
        v2.output_sarasu_gen();
    }
    else if (ans == "n" || ans == "N") {
        v2.sarasutikrinimas();
    }
    else {
        cout << "Something wen't wrong!";
        cout << endl;
        system("pause");
        return 0;
    }

    cout << "Ar norite isrusiuoti sarasus i 'Vargsiukus' ir 'Kietiakius'? (y/n) ";
    cin >> answ;

    if (answ == "y" || answ == "Y") {
        cout << "Please wait..." << endl;
        cout << endl;
        v2.output_rusiavimas();
        cout << endl;
        v2.spartos_analize();
        cout << endl;
        cout << "Job has been completed." << endl;
        cout << endl;
    }
    else if (answ == "n" || answ == "N") {
        cout << endl;
        v2.spartos_analize();
        cout << endl;
        cout << "Job has been completed." << endl;
        cout << endl;
    }
    else {
        cout << "Something wen't wrong!" << endl;
        cout << endl;
        system("pause");
        return 0;
    }

    // system("pause");
    return 0;
}