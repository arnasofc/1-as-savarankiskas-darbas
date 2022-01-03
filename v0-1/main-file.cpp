/*

    V0.2

*/
#include "main-file.h"

int main() {
    uzduotis d1;
    d1.lineInfo();
    d1.rusiavimas();
    d1.input();
    //  system("CLS");
    d1.output();
    remove("tempfile.txt");

    system("pause");
}