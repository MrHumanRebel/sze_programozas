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

string jelszogen(int db, int hossz, string szavak[])
{
    int jelhossz = 0, szam;
    string jelszo;
    char kisbetu, nagybetu;
    bool ok = false;

    for (int i = 0; i < hossz; i++)
    {
        int min = 122, max = 97;
        for (int x = 0; x < sizeof(szavak); x++)
        {
            for (int y = 0; y < szavak[x].length(); y++)
            {
                if (isalpha(szavak[x][y]) && islower(szavak[x][y]))
                {
                    if (szavak[x][y] < min)
                    {
                        min = szavak[x][y];
                    }
                    else if (szavak[x][y] > max)
                    {
                        max = szavak[x][y];
                    }
                }
            }
        }
        if (min == 122)
            min = 0;
        if (max == 97)
            max = 0;

        kisbetu = random(min, max);
        for (int j = 0; j <= jelhossz; j++)
        {
            if (kisbetu == jelszo[j])
                kisbetu = random(min, max);
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

        min = 90;
        max = 65;
        for (int x = 0; x < sizeof(szavak); x++)
        {
            for (int y = 0; y < szavak[x].length(); y++)
            {
                if (isalpha(szavak[x][y]) && isupper(szavak[x][y]))
                {
                    if (szavak[x][y] < min)
                    {
                        min = szavak[x][y];
                    }
                    else if (szavak[x][y] > max)
                    {
                        max = szavak[x][y];
                    }
                }
            }
        }
        if (min == 90)
            min = 0;
        if (max == 65)
            max = 0;

        nagybetu = random(min, max);
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

        min = 9;
        max = 0;
        for (int x = 0; x < sizeof(szavak); x++)
        {
            for (int y = 0; y < szavak[x].length(); y++)
            {
                if (isdigit(szavak[x][y]))
                {
                    if (szavak[x][y] < min)
                    {
                        min = szavak[x][y];
                    }
                    else if (szavak[x][y] > max)
                    {
                        max = szavak[x][y];
                    }
                }
            }
        }
        if (min == 9)
            min = 0;
        if (max == 0)
            max = 0;

        szam = random(min, max);
        for (int j = 0; j <= jelhossz; j++)
        {
            if (szam == jelszo[j])
                szam = random(min, max);
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

void kiir(string jelszavak[], int db, int hossz)
{
    ofstream jelszoki;
    string irashely = "/mnt/c/Users/szeke/uni/sze_programozas/anyagok/vizsgafeladatok_dani/generalt_v2.txt";
    jelszoki.open(irashely);

    for (int i = 0; i < db; i++)
    {
        int nagydb = 0, kisdb = 0, szamdb = 0;
        for (int j = 0; j < hossz; j++)
        {
            if (jelszavak[i][j] >= 'A' && jelszavak[i][j] <= 'Z')
            {
                nagydb++;
            }
            if (jelszavak[i][j] >= 'a' && jelszavak[i][j] <= 'z')
            {
                kisdb++;
            }
            if (jelszavak[i][j] >= '0' && jelszavak[i][j] <= '9')
            {
                szamdb++;
            }
        }
        jelszoki << jelszavak[i] << "\t"
                 << "Kisbetű: " << kisdb << "db  Nagybetű: " << nagydb << "db  Szám: " << szamdb << "db" << endl;
    }
    jelszoki.close();
}

int main()
{
    int db, hossz, aktdb = 0;
    string jelszo, beker;
    string jelszavak[500];
    string szavak[3];
    TELL "Hány karakterből álljon a jelszó?" << endl;
    hossz = szamBeker(MIN, MAX);
    TELL "Hány darab jelszót generáljunk?" << endl;
    db = szamBeker(1, 500);
    do
    {
        string hasonlit = "\0";
        for (int i = 1; i <= 3; i++)
        {
            TELL "Adja meg az " << i << " szót! ";
            ASK beker;
            szavak[i] = beker;
        }
        jelszo = jelszogen(db, hossz, szavak);
        jelszavak[aktdb] = jelszo;
        aktdb++;
        TELL "A(z) " << aktdb << ". generált jelszó: " << jelszo << endl;
        TELL "Adjon meg egy másik jelszót: ";
        ASK beker;
        if (jelszo.length() == beker.length())
        {
            TELL "A két jelszó hossza megegyezik!" << endl;
            for (size_t i = 0; i < jelszo.length(); i++)
            {
                beker[i] = toupper(beker[i]);
                jelszo[i] = toupper(jelszo[i]);
                if (jelszo[i] == beker[i])
                {
                    hasonlit += jelszo[i];
                }
                else
                    hasonlit += '*';
            }
            TELL hasonlit << endl;
        }
        else if (jelszo.length() < beker.length())
        {
            TELL "Az Ön által megadott jelszó hosszabb!" << endl;
        }
        else
            TELL "Az Ön által megadott jelszó rövidebb!" << endl;
        kiir(jelszavak, aktdb, hossz);

    } while (aktdb < db);

    return 0;
}