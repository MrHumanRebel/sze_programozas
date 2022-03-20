#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

#define MAX 20

void olvasas()
{
    string futoadat[MAX][MAX]; // Futó sorszáma, Futó neve
    string filename;           // Fájl elérési útja

    string idoadat[MAX][MAX][MAX][MAX][MAX]; // Futó sorszáma, Ellenőrző pont sorszáma, Óra, Perc, Másodperc
    string filename_2;                       // Fájl elérési útja

    filename = "/home/szeke/uni/sze_programozas/anyagok/sajat_feladatok/futok_nevei.txt";
    filename_2 = "/home/szeke/uni/sze_programozas/anyagok/sajat_feladatok/futok_nevei.txt";

    /* cout<<"Adja meg a \"futok_nevei.txt\" elérési útját!"<<endl;
    cin.getline(filename);

    cout<<"Adja meg a \"idomeres_nevei.txt\" elérési útját!"<<endl;
    cin.getline(filename_2);*/

    ifstream futok;
    futok.open(filename);

    if (!futok.is_open())
    {
        cout << "Ilyen fájl nem létezik!" << endl;
        exit(EXIT_FAILURE);
    }

    string akt;
    futok >> akt;
    int aktszam;
    long unsigned int i = 0;
    int j = 0;

    while (i <= sizeof(futok) && futok.good())
    {
        stringstream darab(akt);
        darab >> aktszam;
        if (isdigit(aktszam))
        {
            futoadat[i][j] += akt;
            j++;
        }
        i++;
    }
}

int main()
{
    return 0;
}