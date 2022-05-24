#include <iostream>
#include <fstream>
using namespace std;

#define TELL cout <<
#define ASK cin >>
#define MAX 32

int keres(string alapanyag[], string mikell[], int alapdb, int mikelldb, bool vaneotthon[])
{
    int i;
    int talalat = 0;
    for (i = 0; i < mikelldb; i++)
    {
        for (int j = 0; j < alapdb; j++)
        {
            if (mikell[i] == alapanyag[j])
            {
                talalat++;
                vaneotthon[i] = true;
            }
        }
    }
    return talalat;
}

string beolv()
{
    string input;
    getline(cin, input);
    return input;
}

int beker(string tomb[])
{
    int i = 0;
    string input;
    do
    {
        input = beolv();
        tomb[i] = input;
        i++;
    } while (input != "#");
    return i;
}

void adatokKiir(string adatok[], int meret, string fajlnev)
{
    ofstream fajl(fajlnev);
    if (fajl.is_open())
    {
        for (int i = 0; i < meret; i++)
        {
            fajl << adatok[i] << endl;
        }

        fajl.close();
    }
}

int olvas(string tomb[], string fajlnev)
{
    int i = 0;

    // Deklarássál együtt megpróbálja meg is nyitni
    ifstream fajl(fajlnev);
    string aktSor;

    if (fajl.is_open())
    {
        while (getline(fajl, aktSor))
        {
            tomb[i] = aktSor;
            i++;
        }
    }
    else
    {
        TELL "Milyen alapanyagok allnak rendelkezesre? Befejezes #-tel." << endl;
        int hanyvan = beker(tomb) - 1;
        adatokKiir(tomb, hanyvan, "/home/szeke/uni/sze_programozas/mintavizsgak/2018-19_2/01_receptek/alapanyagok.txt");
    }

    return i;
}

int main()
{
    string alapanyagok[MAX];
    string mikell[MAX];

    int hanyvan = olvas(alapanyagok, "/home/szeke/uni/sze_programozas/mintavizsgak/2018-19_2/01_receptek/alapanyagok.txt");

    TELL "Etel neve: ";
    string aktetel = beolv();
    if (aktetel == "#")
    {
        TELL "Kilepes." << endl;
        return 0;
    }

    TELL "Milyen alapanyagokra van szukseg? Befejezes #-tel." << endl;
    int hanykell = beker(mikell) - 1;
    bool vaneotthon[hanykell];
    for (int i = 0; i < hanykell; i++)
    {
        vaneotthon[i] = false;
    }

    int talalat = keres(alapanyagok, mikell, hanyvan, hanykell, vaneotthon);

    if (hanykell == talalat)
        TELL "A(z) " << aktetel << " elkeszitheto." << endl;
    else
    {
        TELL "A(z) " << aktetel << " nem keszitheto el.\nAz alabbi alapanyagok hianyoznak:" << endl;
        for (int i = 0; i < hanykell; i++)
        {
            if (vaneotthon[i] == false)
                TELL mikell[i] << endl;
        }
    }

    return 0;
}