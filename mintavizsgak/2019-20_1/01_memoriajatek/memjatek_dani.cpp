#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;
#define TELL cout <<
#define ASK cin >>
#define SOR_MAX 7
#define OSZL_MAX 7
int seed = 0;

int random(int tol, int ig)
{
    srand(time(NULL) + seed);
    return (tol + rand() % (ig - tol + 1));
}

int szamBeker(int min, int max)
{
    int szam;
    bool szamHibas = false;
    do
    {
        if (szamHibas)
            cout << "Nem megfelelő szám (tartomány: " << min << "-től " << max << "-ig)" << endl;

        cin >> szam;
        szamHibas = szam < min || szam > max;
    } while (szamHibas);

    return szam;
}

void iras(char tabla[SOR_MAX][OSZL_MAX], int sor, int oszl)
{
    ofstream allaski;
    string irashely;
    string akt;
    irashely = "/home/szeke/uni/sze_programozas/mintavizsgak/2019-20_1/01_memoriajatek/memoria.txt";
    allaski.open(irashely);
    for (int i = 0; i < sor; i++)
    {
        for (int j = 0; j < oszl; j++)
        {
            akt = tabla[i][j];
            if (j == OSZL_MAX - 1)
                allaski << "\n";
            allaski << akt;
        }
    }
    allaski.close();
}

void torol()
{
    for (int i = 0; i <= 24; i++)
    {
        TELL endl;
    }
}

void feltolt_eleje(char tomb[SOR_MAX][OSZL_MAX], int sor, int oszl)
{
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < sor; i++)
    {
        for (int j = 0; j < oszl; j++)
        {
            seed = random(1, 50);
            char akt = random('a', 'c');

            if (akt == 'a')
            {
                a++;
                if (a >= 3)
                {
                    seed = random(1000, 2000);
                    akt = random('b', 'c');
                    a--;
                    if (akt == 'b')
                        b++;
                    else if (akt == 'c')
                        c++;
                }
                tomb[i][j] = akt;
            }
            else if (akt == 'b')
            {
                b++;
                if (b >= 3)
                {
                    seed = random(3000, 4000);
                    akt = random('a', 'c');
                    b--;
                    if (akt == 'a')
                        a++;
                    else if (akt == 'c')
                        c++;
                    else if (akt == 'b')
                        akt = 'c';
                }
                tomb[i][j] = akt;
            }
            else if (akt == 'c')
            {
                c++;
                if (c >= 3)
                {
                    seed = random(4000, 5000);
                    akt = random('a', 'b');
                    c--;
                    if (akt == 'a')
                        a++;
                    else if (akt == 'b')
                        b++;
                }
                tomb[i][j] = akt;
            }
        }
    }
}

void feltolt_hatulja(char tomb[SOR_MAX][OSZL_MAX], int sor, int oszl)
{
    for (int i = 0; i < sor; i++)
    {
        for (int j = 0; j < oszl; j++)
        {
            tomb[i][j] = '*';
        }
    }
}

void kiir(char tomb[SOR_MAX][OSZL_MAX], int sor, int oszl)
{
    TELL "\n♤ ";
    for (int i = 1; i <= oszl; i++)
    {
        TELL i;
    }
    TELL endl;
    for (int i = 1; i <= oszl; i++)
    {
        TELL "──";
    }
    TELL endl;

    int x = 1;
    for (int i = 0; i < sor; i++)
    {
        TELL x << '|';
        for (int j = 0; j < oszl; j++)
        {
            TELL tomb[i][j];
        }
        x++;
        TELL endl;
    }
}

int main(int argc, char *argv[])
{
    int ok = 0, db = 0, sor_db = 0, oszl_db = 0, szumma = 0;
    TELL "Memoriajatek\n"
        << endl;
    do
    {
        TELL "Adja meg a sorok számát: ";
        sor_db = szamBeker(1, 7);
        TELL "Adja meg az oszlopok számát: ";
        oszl_db = szamBeker(1, 7);
        szumma = oszl_db * sor_db;
        if (szumma % 2 != 0)
            TELL "Adjon meg páros szorzatot adó számokat!" << endl;
    } while (szumma % 2 != 0);

    char kartyak_eleje[SOR_MAX][OSZL_MAX];
    feltolt_eleje(kartyak_eleje, sor_db, oszl_db);
    iras(kartyak_eleje, sor_db, oszl_db);
    char kartyak_hatulja[SOR_MAX][OSZL_MAX];
    feltolt_hatulja(kartyak_hatulja, sor_db, oszl_db);

    /*
    TELL "DEBUG" << endl; // Teszt
    kiir(kartyak_eleje, sor_db, oszl_db);
    TELL "________________\n\n"
        << endl;*/

    kiir(kartyak_hatulja, sor_db, oszl_db);
    do
    {
        int sor = '\0', oszlop = '\0', elozosor = '\0', elozooszlop = '\0';
        char elozo = '\0', akt = '\0';

        TELL "\nMegforditando kartya sora: ";
        elozosor = szamBeker(1, 2) - 1;
        TELL "Oszlopa: ";
        elozooszlop = szamBeker(1, 3) - 1;
        db++;

        elozo = kartyak_eleje[elozosor][elozooszlop];
        kartyak_hatulja[elozosor][elozooszlop] = elozo;

        TELL "\nMegforditando kartya sora: ";
        sor = szamBeker(1, sor_db) - 1;
        TELL "Oszlopa: ";
        oszlop = szamBeker(1, oszl_db) - 1;
        db++;

        akt = kartyak_eleje[sor][oszlop];
        kartyak_hatulja[sor][oszlop] = akt;

        if (akt == elozo && akt != '\0' && elozo != '\0')
        {
            ok++;
            TELL "Egyformak, a kartyak igy maradnak." << endl;
            kiir(kartyak_hatulja, sor_db, oszl_db);
        }
        else
        {
            TELL "Nem egyeznek, visszaforditom a lapokat." << endl;
            kartyak_hatulja[elozosor][elozooszlop] = '*';
            kartyak_hatulja[sor][oszlop] = '*';
            if (*argv == "torol")
                torol();
        }
    } while (ok != 3);
    if (ok == 3)
    {
        TELL "Gratulalok, On nyert " << db << " forditasbol." << endl;
    }
    return 0;
}
