#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

#define MAX 15

void olvasas()
{
    string futoadat[MAX, MAX];
    string filename; // Fájl elérési útja
    int i, db = 0;
    ifstream futok; // Olvasó rutin nevének megadása
    /* cout<<"Adja meg a \"futok_nevei.txt\" elérési útját!"<<endl;
    cin.getline(filename);*/
    filename = "/home/szeke/uni/sze_programozas/anyagok/sajat_feladatok/futok_nevei.txt";
    futok.open(filename); // Olvasásra megnyitás
    if (!futok.is_open()) // Ha megnyitás nem sikerült kilépés
    {
        cout << "Ilyen fájl nem létezik!" << endl;
        exit(EXIT_FAILURE);
    }
    string akt;
    futok >> akt;
    while (db < 9118 && i <= db && futok.good())
    {

        i++;
    }
}

int main()
{
    return 0;
}