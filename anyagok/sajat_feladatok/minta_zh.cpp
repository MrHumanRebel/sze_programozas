#include <iostream>
#include <stdlib.h>

using namespace std;
#define TELL cout <<
#define ASK cin >>
#define TOMBMAX 256

char mshangzok[21]{'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};
char mahangzok[5]{'a', 'e', 'i', 'o', 'u'};
int ms_db = 0, ma_db = 0, space_db = 0, egyeb_db = 0, tulcsordul = 0;

/* Tesztek:

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
    TELL "\nÁtkódolt: ";
    for (int i = 0; i <= db; i++)
    {
        TELL karakterek[i];
    }
    TELL "\n\nAz összes karakter: " << db << endl;
    TELL "Ebből:\n\tMagánhangzó: " << ma_db << "\n\tSzóköz: " << space_db << "\n\tMássalhangzó: " << ms_db << "\n\tEgyéb: " << (egyeb_db = db - ms_db - ma_db - space_db) << endl;
    if (tulcsordul == 0)
    {
        TELL "Nincs túlcsordulás!" << endl;
    }
    else
    {
        TELL tulcsordul << " db túlcsordulás található!" << endl;
    }
}

void cserel(char karakterek[TOMBMAX], int db)
{
    for (int i = 0; i < db; i++)
    {
        bool ok = false;

        // Ismeretlen karakter BETA
        if (!isalpha(karakterek[i]) && karakterek[i] != ' ')
        {
            karakterek[i] = '*';
            ok = true;
        }
        // Szóköz
        else if (karakterek[i] == ' ')
        {
            karakterek[i] = '_';
            ok = true;
            space_db++;
        }
        // Speciális eset
        else if (karakterek[i] == 'Z' or karakterek[i] == 'z' or karakterek[i] == 'y' or karakterek[i] == 'Y')
        {
            karakterek[i] = '!';
            ok = true;
            tulcsordul++;
            ms_db++;
        }
        else
        {
            for (int j = 0; j < 21; j++)
            {
                if (j < 5) // Magánhangzók
                {
                    if (karakterek[i] == mahangzok[j])
                    {
                        karakterek[i]++;
                        ok = true;
                        ma_db++;
                    }
                }

                if (ok == false) // Mássalhangzók
                {
                    if (karakterek[i] == mshangzok[j])
                    {
                        int aktkar = karakterek[i] + 2;
                        karakterek[i] = aktkar;
                        ok = true;
                        ms_db++;
                    }
                }
            }
        }
    }
}

void ujkarsor(char karakterek[TOMBMAX])
{
    int aktkar;
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
}

int main()
{
    char karakterek[TOMBMAX];
    int db = karsorBeker(karakterek);
    cserel(karakterek, db);
    ujkarsor(karakterek);
    cserel(karakterek, db);
    kiir(karakterek, db);
    return 0;
}