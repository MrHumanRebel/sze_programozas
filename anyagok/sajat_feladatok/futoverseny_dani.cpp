#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

#define FUTOMAX 10
#define IDOMAX 20

struct futoadat
{
    string sorszam[FUTOMAX];
    string nev[FUTOMAX];
};

struct idoadat
{
    string sorszam[FUTOMAX];
    int ellszam[IDOMAX];
    int ora[IDOMAX];
    int perc[IDOMAX];
    int masodperc[IDOMAX];
};

string filename_futo;
string filename_ido;

void olvasas()
{
    struct futoadat fu;
    struct idoadat id;
    //filename_futo = "/mnt/c/Users/szeke/uni/sze_programozas/anyagok/sajat_feladatok/futok_nevei.txt";
    //filename_ido = "/mnt/c/Users/szeke/uni/sze_programozas/anyagok/sajat_feladatok/idomeres.txt";
    filename_futo = "/home/szeke/uni/sze_programozas/anyagok/sajat_feladatok/futok_nevei.txt";
    filename_ido = "/home/szeke/uni/sze_programozas/anyagok/sajat_feladatok/idomeres.txt";

    /* cout<<"Adja meg a \"futok_nevei.txt\" elérési útját!"<<endl;
    cin.getline(filename);

    cout<<"Adja meg a \"idomeres_nevei.txt\" elérési útját!"<<endl;
    cin.getline(filename_2);*/

    ifstream futok;
    futok.open(filename_futo);

    if (!futok.is_open())
    {
        cout << "Ilyen fájl nem létezik!" << endl;
        exit(EXIT_FAILURE);
    }

    string akt;
    int x = 0;
    int y = 0;
    while (x <= FUTOMAX && futok.good())
    {
        getline(futok, akt);
        for (long unsigned int i = 0; i <= akt.length(); i++)
        {
            if (isdigit(akt[i]))
            {
                fu.sorszam[x] += akt[i];
                x++;
            }
            if (isalpha(akt[i]))
            {
                fu.nev[y] += akt[i];
                y++;
            }
        }
    }
    futok.close();
}

void teszt()
{
    for (int i = 0; i <= FUTOMAX; i++)
    {
        for (int j = 0; j <= FUTOMAX; j++)
        {
            cout << "Adat: " << endl;
        }
    }
}

int main()
{
    olvasas();
    teszt();
    return 0;
}