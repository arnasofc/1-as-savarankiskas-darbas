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

int main() {

    ifstream input("input.txt");

    int kiekNamuDarbu = 1;
    double sum = 0;

    string vardasT;
    string pavardeT;
    double namuDarbaiT;
    double egzaminasT;

    vector< string > vardas;
    vector< string > pavarde;
    vector< double > namuDarbai;
    vector< double > egzaminas;

    // Skip first line
    string line;
    getline(input, line);

    // Read second line
    while (input >> pavardeT >> vardasT >> namuDarbaiT >> egzaminasT) {
        vardas.push_back(vardasT);
        pavarde.push_back(pavardeT);
        for (int i = 0; i < 5; i++)
        {
            sum += namuDarbaiT;
            namuDarbai.push_back(sum);
        }
        egzaminas.push_back(egzaminasT);
    }

    for (int i = 0; i < kiekNamuDarbu; i++)
    {
        cout << pavarde[i] << " " << vardas[i] << " " << namuDarbai[i] << " " << egzaminas[i];
    }


}