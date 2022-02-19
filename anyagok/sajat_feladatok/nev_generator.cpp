#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
    string filename;
    int i, db = 0;
    ifstream nevek;
    // cin.getline(filename);
    cout << "Hány darab angol nevet szeretne printelni?" << endl;
    cin >> db;
    filename = "/home/szeke/uni/sze_programozas/anyagok/sajat_feladatok/names.txt";
    nevek.open(filename);
    if (!nevek.is_open())
    {
        cout << "Ilyen fájl nem létezik!" << endl;
        exit(EXIT_FAILURE);
    }

    string akt;
    string elozo;
    nevek >> akt;
    while (i <= db && nevek.good())
    {
        elozo = akt;
        nevek >> akt;
        cout << akt << " " << elozo << endl;
        i++;
    }

    return 0;
}