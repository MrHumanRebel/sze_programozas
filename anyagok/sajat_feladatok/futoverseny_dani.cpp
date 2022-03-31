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
            csakido[db].masodperc = aktMperc;

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
        int aktOraKezd = 0;
        int aktPercKezd = 0;
        int aktMpercKezd = 0;
        for (int i = 0; i <= db_2; i++)
        {
            if (futok[versenyzoDb].sorszam == idoadatok[i].sorszam)
            {
                ellpontDb++;
                // Kezdőpont meghatározása
                if (kezdEllpont == -1)
                    kezdEllpont = idoadatok[i].ellszam;

                // Óra
                if (aktOraKezd == 0)
                    aktOraKezd += csakido[i].ora;
                else
                {
                    aktOra += csakido[i].ora;
                }

                // Perc
                if (aktPercKezd == 0)
                    aktPercKezd += csakido[i].perc;
                else
                {
                    aktPerc += csakido[i].perc;
                }

                // Mperc
                if (aktMpercKezd == 0)
                    aktMpercKezd += csakido[i].masodperc;
                else
                {
                    aktMperc += csakido[i].masodperc;
                }

                // Óra protections
                if (aktPerc >= 60)
                {
                    aktPerc -= 60;
                    aktOra += 1;
                }
                if (aktMperc >= 60)
                {
                    aktMperc -= 60;
                    aktPerc += 1;
                }
                // Eltelt idő  !!BETA!!
                /*aktOra = csakido[i].ora - aktOraKezd;
                aktPerc = csakido[i].perc - aktPercKezd;
                aktMperc = csakido[i].masodperc - aktMpercKezd;*/
            }
            idoadatok[versenyzoDb].ellszamdb = ellpontDb;
        }
        idoadatok[versenyzoDb].befido += to_string(aktOra);
        idoadatok[versenyzoDb].befido += ':';
        idoadatok[versenyzoDb].befido += to_string(aktPerc);
        idoadatok[versenyzoDb].befido += ':';
        idoadatok[versenyzoDb].befido += to_string(aktMperc);
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