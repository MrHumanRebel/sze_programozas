#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

// Teszt kódsorozatok
//  55*3355#29999#334#337777#99996665553#2#333881 1 1
//  55*3355#29999#334#337777#9999*6665553#2#333881 1 1
//  55*3355#29999#334#337777#99996665553#2#333*881 1 1

string kod, uzenet;
char kodtabla[11][5];

void decode()
{
    int szamlalo = 0;
    int akt;
    for (long unsigned int i = 0; i <= kod.length(); i++)
    {
        switch (kod[i])
        {
        case ('1'):
            akt = 0;
            break;
        case ('2'):
            akt = 1;
            break;
        case ('3'):
            akt = 2;
            break;
        case ('4'):
            akt = 3;
            break;
        case ('5'):
            akt = 4;
            break;
        case ('6'):
            akt = 5;
            break;
        case ('7'):
            akt = 6;
            break;
        case ('8'):
            akt = 7;
            break;
        case ('9'):
            akt = 8;
            break;
        case ('*'):
            akt = 9;
            break;
        case ('0'):
            akt = 10;
            break;
        case ('#'):
            akt = 11;
            break;
        }

        if (kod[i] == kod[i + 1])
        {
            szamlalo++;
        }
        else
        {
            if ((kod[i] != kod[i + 1] && kod[i + 1] == '*') or
                (kod[i] == kod[i + 1] && kod[i + 2] == '*') or
                (kod[i] == kod[i + 1] == kod[i + 2] && kod[i + 3] == '*') or
                (kod[i] == kod[i + 1] == kod[i + 2] == kod[i + 3] && kod[i + 4] == '*'))
            {
                uzenet += kodtabla[akt][szamlalo];
                szamlalo = 0;
            }
            else
            {
                uzenet += tolower(kodtabla[akt][szamlalo]);
                szamlalo = 0;
            }
        }
    }
}
void kodtablazat()
{
    string aktstring;
    for (int i = 0; i <= 11; i++)
    {
        if (i == 0)
            aktstring = ".,-?!1";
        if (i == 1)
            aktstring = "ABC2";
        if (i == 2)
            aktstring = "DEF3";
        if (i == 3)
            aktstring = "GHI4";
        if (i == 4)
            aktstring = "JKL5";
        if (i == 5)
            aktstring = "MNO6";
        if (i == 6)
            aktstring = "PQRS7";
        if (i == 7)
            aktstring = "TUV8";
        if (i == 8)
            aktstring = "WXYZ9";
        if (i == 9)
            aktstring = "";
        if (i == 10)
            aktstring = "+0";
        if (i == 11)
            aktstring = " #";
        for (long unsigned int j = 0; j <= aktstring.length(); j++)
        {
            kodtabla[i][j] = aktstring[j];
        }
    }
}

void olvasas()
{
    string filename;
    ifstream kodsorozat;
    filename = "/mnt/c/Users/szeke/uni/sze_programozas/anyagok/sajat_feladatok/smskod.txt";
    /*
    cout << "Adja meg a dekódolandó kódsorozatot tartalmazó fájl elérési útját! " << endl;
    getline(cin, filename);
    */
    kodsorozat.open(filename);
    if (!kodsorozat.is_open())
    {
        cout << "Ilyen fájl nem létezik!" << endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        kodsorozat >> kod;
    }
}

void iras()
{
    ofstream uzenetki;
    string irashely;
    /*
    cout << "Adja meg a dekodolt üzenetet tartalmazó fájl kívánt elérési útját! " << endl;
    getline(cin, irashely);
    */
    irashely = "/mnt/c/Users/szeke/uni/sze_programozas/anyagok/sajat_feladatok/szoveg.txt";
    uzenetki.open(irashely);
    uzenetki << uzenet;
    uzenetki.close();
}

void beker()
{
    cout << "Adja meg a dekódolandó kódsorozatot!" << endl;
    getline(cin, kod);
}

int main()
{
    olvasas();
    // beker();
    kodtablazat();
    decode();
    cout << uzenet;
    iras();
    return 0;
}