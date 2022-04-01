#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

#define TELL cout <<
#define ASK cin >>

#define MIN 5
#define MAX 20

int random(int tol, int db)
{
    return ((rand() % tol) + db);
}

string jelszogen(int db, int hossz)
{
    int aktdb = 0;
    string jelszo;
    char kisbetu, nagybetu;
    int szam;
    do
    {
        for (int i = 0; i < hossz; i++)
        {
            kisbetu = random(97, 25);
            nagybetu = random(65, 25);
            szam = random(9, 0);
            TELL kisbetu << nagybetu << szam << endl;
        }

        aktdb++;

    } while (aktdb < db);

    return jelszo;
}

int szamBeker(int min, int max)
{
    bool szambe_ok = false;
    int akt;
    do
    {
        TELL "Adja meg a számot!" << endl;
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
    int db, hossz;
    TELL "Hány karakterből álljon a jelszó?" << endl;
    hossz = szamBeker(5, 20);
    TELL "Hány darab jelszót generáljunk?" << endl;
    db = szamBeker(1, 500);
    jelszogen(db, hossz);
    return 0;
}