#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

#define TELL cout <<
#define ASK cin >>
#define MIN 5
#define MAX 20

int random(int tol, int ig)
{
    return (tol + rand() % (ig - tol + 1));
}

string jelszogen(int db, int hossz)
{
    int jelhossz = 0, szam;
    string jelszo;
    char kisbetu, nagybetu;
    bool ok = false;

    for (int i = 0; i < hossz; i++)
    {
        kisbetu = random(97, 122);
        for (int j = 0; j <= jelhossz; j++)
        {
            if (kisbetu == jelszo[j])
                kisbetu = random(97, 122);
            else
                ok = true;
        }
        if (ok)
        {
            jelszo += kisbetu;
            jelhossz++;
            if (jelhossz == hossz)
                return jelszo;
        }
        ok = false;

        nagybetu = random(65, 90);
        for (int j = 0; j <= jelhossz; j++)
        {
            if (nagybetu == jelszo[j])
                nagybetu = random(65, 90);
            else
                ok = true;
        }
        if (ok)
        {
            jelszo += nagybetu;
            jelhossz++;
            if (jelhossz == hossz)
                return jelszo;
        }
        ok = false;

        szam = random(0, 9);
        for (int j = 0; j <= jelhossz; j++)
        {
            if (szam == jelszo[j])
                szam = random(0, 9);
            else
                ok = true;
        }
        if (ok)
        {
            jelszo += to_string(szam);
            jelhossz++;
            if (jelhossz == hossz)
                return jelszo;
        }
    }
    return jelszo;
}

int szamBeker(int min, int max)
{
    bool szambe_ok = false;
    int akt;
    do
    {
        ASK akt;
        if (akt >= min && akt <= max)
            szambe_ok = true;
        else
            TELL "Adjon meg " << min << "-től " << max << "-ig tartományba tartozó számot!" << endl;
    } while (szambe_ok == false);
    return akt;
}

int main()
{
    int db, hossz, aktdb = 0;
    string jelszo;
    TELL "Hány karakterből álljon a jelszó?" << endl;
    hossz = szamBeker(5, 20);
    TELL "Hány darab jelszót generáljunk?" << endl;
    db = szamBeker(1, 500);
    do
    {
        jelszo = jelszogen(db, hossz);
        TELL jelszo << endl;
        aktdb++;

    } while (aktdb < db);

    return 0;
}