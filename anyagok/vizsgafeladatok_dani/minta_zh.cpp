// Headers
#include <iostream>
#include <stdlib.h>

using namespace std;

#define TELL cout <<
#define ASK cin >>
#define TOMBMAX 256

char mshangzok[21]{'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};
char mahangzok[5]{'a', 'e', 'i', 'o', 'u'};

/* Tesz 1-2:

#Ebb3n N1nCS 1 db 'ipSŻ1l0n' illetv3 'Że' betU SEM!
#Ez 1 Hosszu-hoSSZu sz0v3g3s infOrmAcio!?@.Zh

*/

int karsorBeker(char karakterek[TOMBMAX])
{
    string akt;
    TELL "Adja meg a karaktersorozatot!" << endl;
    getline(cin, akt);
    int db = akt.length();
    for (int i = 0; i <= TOMBMAX; i++)
    {
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

int cserel(char karakterek[TOMBMAX], int db)
{
    int aktkar;
    int cseredb = 0;
    int tulcsordul = 0;
    for (int i = 0; i < db; i++)
    {
        bool aktmegvan = false;
        for (int j = 0; j < 21; j++)
        {
            // Szóköz és speciális eset
            if (karakterek[i] == ' ')
            {
                karakterek[i] = '_';
                aktmegvan = true;
                cseredb++;
            }
            else if (karakterek[i] == 'Z' or karakterek[i] == 'z')
            {
                karakterek[i] = '!';
                aktmegvan = true;
                cseredb++;
                tulcsordul++;
            }

            if (aktmegvan == false)
            { // Magánhangzók
                if (j <= 5)
                {
                    if (karakterek[i] == mahangzok[j])
                    {
                        karakterek[i]++;
                        aktmegvan = true;
                        cseredb++;
                    }
                }
            }

            // Mássalhangzók
            if (aktmegvan == false)
            {
                if (karakterek[i] == mshangzok[j])
                {
                    aktkar = karakterek[i] + 2;
                    karakterek[i] = aktkar;
                    aktmegvan = true;
                    cseredb++;
                }
            }
            /*
            // Ismeretlen
            if (aktmegvan == false and !isalpha(karakterek[i]) and !isdigit(karakterek[i]) and karakterek[i] != ' ')
            {
                karakterek[i] = '*';
                aktmegvan = true;
                cseredb++;
            }
            */
        }
    }
    return cseredb;
}

int ujkarsor(char karakterek[TOMBMAX], int db)
{
    int aktkar;
    // Kisbetűs variánsok
    int csereldb = cserel(karakterek, db);
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
    csereldb += cserel(karakterek, db);
    return csereldb;
}

int main()
{
    char karakterek[TOMBMAX];
    int db = 0, cseredb = 0;
    db = karsorBeker(karakterek);
    TELL "Karaterek száma: " << db << endl;
    cseredb = ujkarsor(karakterek, db);
    TELL "Cserék száma: " << cseredb << endl;
    kiir(karakterek, db);

    return 0;
}