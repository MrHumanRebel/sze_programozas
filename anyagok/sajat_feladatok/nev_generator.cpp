#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
#define TELL cout <<
#define ASK cin >>

int main()
{
    string filename;
    int i, db = 0;
    ifstream nevek;
    // cin.getline(filename);
    TELL "Hány darab angol nevet szeretne printelni?" << endl;
    ASK db;
    filename = "/home/szeke/uni/sze_programozas/anyagok/sajat_feladatok/names.txt";
    nevek.open(filename);
    if (!nevek.is_open())
    {
        TELL "Ilyen fájl nem létezik!" << endl;
        exit(EXIT_FAILURE);
    }

    string akt;
    string elozo;
    nevek >> akt;
    while (db < 9118 && i <= db && nevek.good())
    {
        elozo = akt;
        nevek >> akt;
        TELL akt << " " << elozo << endl;
        i++;
    }

    return 0;
}