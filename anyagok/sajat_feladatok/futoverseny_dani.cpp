#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

#define TELL cout <<
#define ASK cin >>

#define FUTOMAX 10
#define IDOMAX 20

struct futo
{
    int sorszam;
    string nev;
};

struct ido
{
    int ora;
    int perc;
    int masodperc;
};

struct idoadat
{
    string sorszam;
    int ellszam;
    // ido befido;
};

string filename_futo;
string filename_ido;

int futo_olvasas(futo futok[FUTOMAX])
{
    filename_futo = "/mnt/c/Users/szeke/uni/sze_programozas/anyagok/sajat_feladatok/futok_nevei.txt";
    // filename_futo = "/home/szeke/uni/sze_programozas/anyagok/sajat_feladatok/futok_nevei.txt";

    ifstream futokInput;
    futokInput.open(filename_futo);

    if (!futokInput.is_open())
    {
        cout << "Ilyen fájl nem létezik!" << endl;
        exit(EXIT_FAILURE);
    }

    string akt;
    int db = 0;
    while (getline(futokInput, akt))
    {
        int szokozHelye = akt.find(' ');
        int aktSorszam = stoi(akt.substr(0, szokozHelye));
        string aktNev = akt.substr(szokozHelye + 1);
        futok[db].sorszam = aktSorszam;
        futok[db].nev = aktNev;
        db++;
    }
    futokInput.close();
    return db;
}

int ido_olvasas(ido csakido[IDOMAX], idoadat idoadatok[IDOMAX])
{
    filename_ido = "/mnt/c/Users/szeke/uni/sze_programozas/anyagok/sajat_feladatok/idomeres.txt";
    // filename_ido = "/home/szeke/uni/sze_programozas/anyagok/sajat_feladatok/idomeres.txt";

    ifstream idoInput;
    idoInput.open(filename_ido);

    if (!idoInput.is_open())
    {
        cout << "Ilyen fájl nem létezik!" << endl;
        exit(EXIT_FAILURE);
    }

    string akt;
    int db = 0;
    while (getline(idoInput, akt))
    {
        if (akt.length() != 1)
        {
            int szokozHelye = akt.find(' ');

            int aktSorszam = stoi(akt.substr(0, szokozHelye));
            szokozHelye += 1;
            int aktEllszam = stoi(akt.substr(szokozHelye, 1));
            szokozHelye += 2;
            int aktOra = stoi(akt.substr(szokozHelye, 2));
            szokozHelye += 3;
            int aktPerc = stoi(akt.substr(szokozHelye, 2));
            szokozHelye += 3;
            int aktMperc = stoi(akt.substr(szokozHelye, 2));
            // int aktBefido = 0;

            csakido[db].ora = aktOra;
            csakido[db].perc = aktPerc;
            csakido[db].masodperc = aktMperc;

            idoadatok[db].ellszam = aktEllszam;
            idoadatok[db].sorszam = aktSorszam;
            // idoadatok[db].befido = aktBefido;
            db++;
        }
        }
    idoInput.close();
    return db;
}

void teszt(futo futok[FUTOMAX], int db, ido csakido[IDOMAX], idoadat idoadatok[IDOMAX], int db_2)
{
    for (int i = 0; i < db; i++)
    {
        TELL futok[i].sorszam << ' ' << futok[i].nev << endl;
    }
    for (int i = 0; i < db_2; i++)
    {
        TELL csakido[i].ora << ' ' << csakido[i].perc << ' ' << csakido[i].masodperc << endl;
    }
    for (int i = 0; i < db_2; i++)
    {
        TELL idoadatok[i].sorszam << ' ' << idoadatok[i].ellszam << endl;
    }
}

int main()
{
    futo futok[FUTOMAX];
    ido csakido[IDOMAX];
    idoadat idoadatok[IDOMAX];

    int db = futo_olvasas(futok);
    int db_2 = ido_olvasas(csakido, idoadatok);
    teszt(futok, db, csakido, idoadatok, db_2);
    return 0;
}