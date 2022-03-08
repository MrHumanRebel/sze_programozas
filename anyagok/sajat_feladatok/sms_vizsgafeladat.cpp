#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

// Teszt kódsorozatok
//  55*3355#29999#334#337777#99996665553#2#333881 1 1
//  55*3355#29999#334#337777#9999*6665553#2#333881 1 1
//  55*3355#29999#334#337777#99996665553#2#333*881 1 1

string kod, uzenet;
char kodtabla[12][6]{
    {'.', ',', '-', '?', '!', '1'},
    {'A', 'B', 'C', '2'},
    {'D', 'E', 'F', '3'},
    {'G', 'H', 'I', '4'},
    {'J', 'K', 'L', '5'},
    {'M', 'N', 'O', '6'},
    {'P', 'Q', 'R', 'S', '7'},
    {'T', 'U', 'V', '8'},
    {'W', 'X', 'Y', 'Z', '9'},
    {'\0'},
    {'+', '0'},
    {' ', '#'}};

void decode()
{
    int szamlalo = 0;
    int akt;
    for (long unsigned int i = 0; i <= kod.length(); i++)
    {
        if (kod[i] == '1')
            akt = 0;
        else if (kod[i] == '2')
            akt = 1;
        else if (kod[i] == '3')
            akt = 2;
        else if (kod[i] == '4')
            akt = 3;
        else if (kod[i] == '5')
            akt = 4;
        else if (kod[i] == '6')
            akt = 5;
        else if (kod[i] == '7')
            akt = 6;
        else if (kod[i] == '8')
            akt = 7;
        else if (kod[i] == '9')
            akt = 8;
        else if (kod[i] == '*')
            akt = 9;
        else if (kod[i] == '0')
            akt = 10;
        else if (kod[i] == '#')
            akt = 11;

        if (kod[i] == kod[i + 1])
        {
            szamlalo++;
        }
        else if (szamlalo > 4)
            uzenet += ">";
        else if (kod[i + 1] == ' ')
        {
            uzenet += "\0";
            szamlalo = 0;
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

void olvasas()
{
    string filename;
    ifstream kodsorozat;
    kodsorozat >> std::noskipws;
    filename = "/home/szeke/uni/sze_programozas/anyagok/sajat_feladatok/smskod.txt"; //"/mnt/c/Users/szeke/uni/sze_programozas/anyagok/sajat_feladatok/smskod.txt";
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
        getline(kodsorozat, kod);
        kodsorozat.close();
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
    irashely = "/home/szeke/uni/sze_programozas/anyagok/sajat_feladatok/szoveg.txt"; //"/mnt/c/Users/szeke/uni/sze_programozas/anyagok/sajat_feladatok/szoveg.txt";
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
    decode();
    cout << uzenet;
    iras();
    return 0;
}