// Headers
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

#define TELL cout <<
#define ASK cin >>
#define TOMBMAX 256

bool vege = false;

char mshangzok[21]{'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};
char mahangzok[5]{'a', 'e', 'i', 'o', 'u'};

int karsorBeker(char karakterek[TOMBMAX])
{
    string akt;
    TELL "Adja meg a karaktersorozatot!" << endl;
    getline(cin, akt);
    int db = akt.length();
    for (int i = 0; i <= TOMBMAX; i++)
    {
        if (akt[i] == '\n')
        {
            TELL "KILÉP";
            vege = true;
        }
        else
            karakterek[i] = akt[i];
    }
    return db;
}

void kiir(char karakterek[TOMBMAX], int db)
{
    for (int i = 0; i <= db; i++)
    {
        TELL karakterek[i];
    }
}

void cserel(char karakterek[TOMBMAX], int db)
{
    int aktkar;
    int szamlalo = 0;
    // Magánhangzók
    while (szamlalo < 7)
    {
        for (int i = 0; i < db; i++)
        {
            if (karakterek[i] == 'Z' or karakterek[i] == 'z')
            {
                karakterek[i] = '!';
            }
            else if (karakterek[i] == mahangzok[szamlalo])
            {

                aktkar = karakterek[i];
                TELL aktkar << endl;
                aktkar++;
                TELL aktkar << endl;
                karakterek[i] = aktkar;
            }
            else if (karakterek[i] == mahangzok[szamlalo])
            {
            }
        }
        szamlalo++;
    }

    // Mássalhangzók
    szamlalo = 0;

    while (szamlalo < 27)
    {
        for (int i = 0; i <= db; i++)
        {
            if (karakterek[i] == mshangzok[szamlalo])
            {
                aktkar = karakterek[i];
                aktkar = aktkar + 2;
                karakterek[i] = aktkar;
            }
        }
        szamlalo++;
    }
}

void ujkarsor(char karakterek[TOMBMAX], int db)
{
    int aktkar;
    // Kisbetűs variánsok
    cserel(karakterek, db);
    // Nagybetűs variánsok
    for (int i = 0; i <= 21; i++)
    {
        aktkar = mshangzok[i];
        aktkar = toupper(aktkar);
        mshangzok[i] = aktkar;
    }
    for (int i = 0; i <= 5; i++)
    {
        aktkar = mahangzok[i];
        aktkar = toupper(aktkar);
        mahangzok[i] = aktkar;
    }
    cserel(karakterek, db);
}

int main()
{
    char karakterek[TOMBMAX];
    int db = 0;
    db = karsorBeker(karakterek);
    ujkarsor(karakterek, db);
    kiir(karakterek, db);

    return 0;
}