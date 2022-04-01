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
    int ora, perc, mperc;
};

struct idoadat
{
    int sorszam, ellszam, ellszamdb;
    string befido;
};

string filename_futo, filename_ido;

int futo_olvasas(futo futok[FUTOMAX])
{
    // filename_futo = "/mnt/c/Users/szeke/uni/sze_programozas/anyagok/sajat_feladatok/futok_nevei.txt";
    filename_futo = "/home/szeke/uni/sze_programozas/anyagok/sajat_feladatok/futok_nevei.txt";

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
    // filename_ido = "/mnt/c/Users/szeke/uni/sze_programozas/anyagok/sajat_feladatok/idomeres.txt";
    filename_ido = "/home/szeke/uni/sze_programozas/anyagok/sajat_feladatok/idomeres.txt";

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

            csakido[db].ora = aktOra;
            csakido[db].perc = aktPerc;
            csakido[db].mperc = aktMperc;

            idoadatok[db].ellszam = aktEllszam;
            idoadatok[db].sorszam = aktSorszam;
            db++;
        }
    }
    idoInput.close();
    return db;
}

void rendez(ido csakido[IDOMAX], idoadat idoadatok[IDOMAX], int db_2)
{
    int csere;
    for (int i = 0; i <= db_2; i++)
    {
        for (int j = 0; j <= db_2; j++)
        {
            if (idoadatok[j].ellszam >= idoadatok[j + 1].ellszam)
            {
                // Ellszám csere
                csere = idoadatok[j].ellszam;
                idoadatok[j].ellszam = idoadatok[j + 1].ellszam;
                idoadatok[j + 1].ellszam = csere;
                // Ellszámdb csere
                csere = idoadatok[j].ellszamdb;
                idoadatok[j].ellszamdb = idoadatok[j + 1].ellszamdb;
                idoadatok[j + 1].ellszamdb = csere;
                // Sorszám csere
                csere = idoadatok[j].sorszam;
                idoadatok[j].sorszam = idoadatok[j + 1].sorszam;
                idoadatok[j + 1].sorszam = csere;
                //Óra csere
                csere = csakido[j].ora;
                csakido[j].ora = csakido[j + 1].ora;
                csakido[j + 1].ora = csere;
                // Perc csere
                csere = csakido[j].perc;
                csakido[j].perc = csakido[j + 1].perc;
                csakido[j + 1].perc = csere;
                // Mperc csere
                csere = csakido[j].mperc;
                csakido[j].mperc = csakido[j + 1].mperc;
                csakido[j + 1].mperc = csere;
            }
        }
    }
}

void szamol(futo futok[FUTOMAX], ido csakido[IDOMAX], idoadat idoadatok[IDOMAX], int db, int db_2)
{
    int versenyzoDb = 0;
    while (versenyzoDb < db)
    {
        int kezdEllpont = -1;
        int ellpontDb = 0;
        int aktOra = 0, aktPerc = 0, aktMperc = 0;    // Aktuális beolvasott idő adat
        int kezdOra = 0, kezdPerc = 0, kezdMperc = 0; // Kezdő idő adat
        int ora = 0, perc = 0, mperc = 0;             // Számolt idő adat

        for (int i = 0; i <= db_2; i++)
        {
            if (futok[versenyzoDb].sorszam == idoadatok[i].sorszam)
            {
                ellpontDb++;
                // Kezdőpont meghatározása
                if (kezdEllpont == -1)
                    kezdEllpont = idoadatok[i].ellszam;

                // Óra
                if (aktOra == 0)
                    aktOra = kezdOra = csakido[i].ora;
                else
                    aktOra = csakido[i].ora;

                // Perc
                if (aktPerc == 0)
                    aktPerc = kezdPerc = csakido[i].perc;
                else
                    aktPerc = csakido[i].perc;

                // Mperc
                if (aktMperc == 0)
                    aktMperc = kezdMperc = csakido[i].mperc;
                else
                    aktMperc = csakido[i].mperc;

                // Eltelt idő
                if (ellpontDb == 6)
                {
                    ora = aktOra - kezdOra;
                    perc = aktPerc - kezdPerc;
                    mperc = aktMperc - kezdMperc;
                }
            }
            // Lower protections
            while (perc < 0)
            {
                perc += 60;
                ora -= 1;
            }
            while (mperc < 0)
            {
                mperc += 60;
                perc -= 1;
            }
            // Upper protections
            while (perc >= 60)
            {
                perc -= 60;
                ora += 1;
            }
            while (mperc >= 60)
            {
                mperc -= 60;
                perc += 1;
            }
            idoadatok[versenyzoDb].ellszamdb = ellpontDb; // Ellenőrző pontok
        }
        idoadatok[versenyzoDb].befido += to_string(ora) + ':' + to_string(perc) + ':' + to_string(mperc); // Kész adat tárolása kiírásra
        versenyzoDb++;
    }
}

void kiir(futo futok[FUTOMAX], ido csakido[IDOMAX], idoadat idoadatok[IDOMAX], int db, int db_2)
{
    TELL "A versenyzők:\n"
        << endl;
    for (int i = 0; i < db; i++)
    {
        TELL "A versenyző sorszáma: " << futok[i].sorszam << "\nNeve: " << futok[i].nev << "\nIdőeredménye: ";
        if (idoadatok[i].ellszamdb >= 6)
            TELL idoadatok[i].befido << "\n"
                                     << endl;
        else
            TELL "DNF\n"
                << endl;
    }
    TELL endl;
}

int main()
{
    futo futok[FUTOMAX];
    ido csakido[IDOMAX];
    idoadat idoadatok[IDOMAX];

    int db = futo_olvasas(futok);               // DB => Versenyzők száma
    int db_2 = ido_olvasas(csakido, idoadatok); // DB_2 => Időadat .txt sorok száma
    rendez(csakido, idoadatok, db_2);
    szamol(futok, csakido, idoadatok, db, db_2);
    kiir(futok, csakido, idoadatok, db, db_2);

    return 0;
}