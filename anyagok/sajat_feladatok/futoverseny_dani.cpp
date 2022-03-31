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
    int mperc;
};

struct idoadat
{
    int sorszam;
    int ellszam;
    int ellszamdb;
    string befido;
};

string filename_futo;
string filename_ido;

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

void szamol(futo futok[FUTOMAX], ido csakido[IDOMAX], idoadat idoadatok[IDOMAX], int db, int db_2)
{
    int versenyzoDb = 0;
    while (versenyzoDb < db)
    {
        int kezdEllpont = -1;
        int ellpontDb = 0;
        int aktOra = 0;
        int aktPerc = 0;
        int aktMperc = 0;
        int elozoOra = 0;
        int elozoPerc = 0;
        int elozoMperc = 0;
        int kezdOra = 0;
        int kezdPerc = 0;
        int kezdMperc = 0;
        int ora = 0;
        int perc = 0;
        int mperc = 0;
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
                {
                    aktOra = csakido[i].ora;
                    kezdOra = csakido[i].ora;
                }
                else
                {
                    elozoOra = aktOra;
                    aktOra = csakido[i].ora;
                }

                // Perc
                if (aktPerc == 0)
                {
                    aktPerc = csakido[i].perc;
                    kezdPerc = csakido[i].perc;
                }
                else
                {
                    elozoPerc = aktPerc;
                    aktPerc = csakido[i].perc;
                }

                // Mperc
                if (aktMperc == 0)
                {
                    aktMperc = csakido[i].mperc;
                    kezdMperc = csakido[i].mperc;
                }
                else
                {
                    elozoMperc = aktMperc;
                    aktMperc = csakido[i].mperc;
                }

                // Eltelt idő
                ora += aktOra - elozoOra;
                perc += aktPerc - elozoPerc;
                mperc += aktMperc - elozoMperc;
            }
            idoadatok[versenyzoDb].ellszamdb = ellpontDb;
        }
        ora -= kezdOra;
        perc -= kezdPerc;
        mperc -= kezdMperc;
        // Lower protections
        if (perc < 0)
        {
            TELL "Perc < 0" << endl;
            perc = abs(perc);
            ora += 1;
        }
        if (mperc < 0)
        {
            TELL "Mperc < 0" << endl;
            mperc = abs(mperc);
            perc += 1;
        }
        // Upper protections
        if (perc >= 60)
        {
            TELL "Perc > 60" << endl;
            perc -= 60;
            ora += 1;
        }
        if (mperc >= 60)
        {
            TELL "Mperc > 60" << endl;
            mperc -= 60;
            perc += 1;
        }
        idoadatok[versenyzoDb].befido += to_string(ora);
        idoadatok[versenyzoDb].befido += ':';
        idoadatok[versenyzoDb].befido += to_string(perc);
        idoadatok[versenyzoDb].befido += ':';
        idoadatok[versenyzoDb].befido += to_string(mperc);
        versenyzoDb++;
    }
}

void kiir(futo futok[FUTOMAX], ido csakido[IDOMAX], idoadat idoadatok[IDOMAX], int db, int db_2)
{
    TELL "A versenyzők:\n"
        << endl;
    for (int i = 0; i < db; i++)
    {
        TELL futok[i].sorszam << ' ' << futok[i].nev << endl;
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
    szamol(futok, csakido, idoadatok, db, db_2);
    kiir(futok, csakido, idoadatok, db, db_2);

    return 0;
}