#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

#define TELL cout <<
#define ASK cin >>
#define MIN 5
#define MAX 50

int random(int tol, int ig)
{
    return (tol + rand() % (ig - tol + 1));
}

string jelszogen(int db, int hossz)
{
    int jelhossz = 0;
    string jelszo;
    char randchar;
    bool ok = false;

    for (int i = 0; i < hossz; i++)
    {
        randchar = random(33, 126);
        for (int j = 0; j <= jelhossz; j++)
        {
            if (randchar == jelszo[j])
                randchar = random(33, 126);
            else
                ok = true;
        }
        if (ok)
        {
            jelszo += randchar;
            jelhossz++;
            if (jelhossz == hossz)
                return jelszo;
        }
        ok = false;
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
    string jelszo, beker;
    TELL "Hány karakterből álljon a jelszó?" << endl;
    hossz = szamBeker(MIN, MAX);
    TELL "Hány darab jelszót generáljunk?" << endl;
    db = szamBeker(1, 500);
    do
    {
        string hasonlit = "\0";
        jelszo = jelszogen(db, hossz);
        aktdb++;

        TELL "A(z) " << aktdb << ". generált jelszó: " << jelszo << endl;

    } while (aktdb < db);

    return 0;
}