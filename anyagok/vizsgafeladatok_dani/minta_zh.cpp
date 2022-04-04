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

void cserel(char karakterek[TOMBMAX], int db)
{
    int aktkar;
    for (int i = 0; i < 21; i++)
    {
        bool aktmegvan = false;
        for (int j = 0; j < db; j++)
        {
            // Magánhangzók
            if (i <= 5)
            {
                if (aktmegvan == false)
                {
                    if (karakterek[j] == mahangzok[i])
                    {
                        karakterek[j]++;
                        aktmegvan = true;
                    }
                }
            }

            // Mássalhangzók
            if (aktmegvan == false)
            {
                if (karakterek[j] == 'Z' or karakterek[j] == 'z')
                {
                    karakterek[j] = '!';
                }
                else if (karakterek[j] == mshangzok[i])
                {
                    aktkar = karakterek[j] + 2;
                    karakterek[j] = aktkar;
                    aktmegvan = true;
                }
            }
        }
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
    TELL db << endl;
    ujkarsor(karakterek, db);
    kiir(karakterek, db);

    return 0;
}