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
        TELL "Karakter: " << karakterek[i] << endl;
    }
}

void cserel(char karakterek[TOMBMAX], int db)
{
    int aktkar;
    int szamlalo = 0;
    bool ms_nagy = false;
    bool ma_nagy = false;

    do
    { // Magánhangzók
        while (szamlalo < 7)
        {
            for (int i = 0; i <= db; i++)
            {
                if (karakterek[i] == 'Z' or karakterek[i] == 'z')
                {
                    karakterek[i] = '!';
                }
                else if (karakterek[i] == mahangzok[szamlalo])
                {
                    aktkar = karakterek[i];
                    aktkar++;
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
    } while (ms_nagy == false and ma_nagy == false);

    // Nagybetűs variánsok
    for (int i = 0; i <= 21; i++)
    {
        mshangzok[i] = aktkar;
        aktkar = toupper(aktkar);
        mshangzok[i] = aktkar;
        bool ms_nagy = true;
    }
    for (int i = 0; i <= 5; i++)
    {
        mahangzok[i] = aktkar;
        aktkar = toupper(aktkar);
        mahangzok[i] = aktkar;
        bool ma_nagy = true;
    }
}

int main()
{
    char karakterek[TOMBMAX];
    int db = 0;
    db = karsorBeker(karakterek);
    cserel(karakterek, db);
    kiir(karakterek, db);

    return 0;
}