#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;
#define TELL cout <<
#define ASK cin >>
#define SOR_MAX 2
#define OSZL_MAX 3
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

void feltolt_eleje(char tomb[SOR_MAX][OSZL_MAX])
{
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < SOR_MAX; i++)
    {
        for (int j = 0; j < OSZL_MAX; j++)
        {
            seed = random(1, 50);
            tomb[i][j] = random('a', 'c');

            if (tomb[i][j] == 'a')
            {
                a++;
                if (a >= 3)
                {
                    do
                    {
                        seed = random(1000, 2000);
                        tomb[i][j] = random('b', 'c');
                    } while (tomb[i][j] != 'a');

                    a--;
                    if (tomb[i][j] == 'b')
                        b++;
                    else if (tomb[i][j] == 'c')
                        c++;
                }
            }
            else if (tomb[i][j] == 'b')
            {
                b++;
                if (b >= 3)
                {
                    do
                    {
                        seed = random(3000, 4000);
                        tomb[i][j] = random('a', 'c');
                    } while (tomb[i][j] != 'b');

                    b--;
                    if (tomb[i][j] == 'a')
                        a++;
                    else if (tomb[i][j] == 'c')
                        c++;
                }
            }
            else if (tomb[i][j] == 'c')
            {
                c++;
                if (c >= 3)
                {
                    do
                    {
                        seed = random(4000, 5000);
                        tomb[i][j] = random('a', 'b');
                    } while (tomb[i][j] != 'c');

                    c--;
                    if (tomb[i][j] == 'a')
                        a++;
                    else if (tomb[i][j] == 'b')
                        b++;
                }
            }

            // TELL "a: " << a_db << " b: " << b_db << " c: " << c_db << endl;
        }
    }
}

void feltolt_hatulja(char tomb[SOR_MAX][OSZL_MAX])
{
    for (int i = 0; i < SOR_MAX; i++)
    {
        for (int j = 0; j < OSZL_MAX; j++)
        {
            tomb[i][j] = '*';
        }
    }
}

void kiir(char tomb[SOR_MAX][OSZL_MAX])
{
    TELL "♤ 123"
        << "\n─────" << endl;
    int x = 1;
    for (int i = 0; i < SOR_MAX; i++)
    {
        TELL x << '|';
        for (int j = 0; j < OSZL_MAX; j++)
        {
            TELL tomb[i][j];
        }
        x++;
        TELL endl;
    }
}

int main()
{
    TELL "Memoriajatek\n"
        << endl;
    // Inicializáció
    int ok = 0, db = 0;
    char kartyak_eleje[SOR_MAX][OSZL_MAX];
    feltolt_eleje(kartyak_eleje);
    char kartyak_hatulja[SOR_MAX][OSZL_MAX];
    feltolt_hatulja(kartyak_hatulja);

    TELL "DEBUG" << endl;
    kiir(kartyak_eleje);
    TELL "________________" << endl;

    kiir(kartyak_hatulja);
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
        sor = szamBeker(1, 2) - 1;
        TELL "Oszlopa: ";
        oszlop = szamBeker(1, 3) - 1;
        db++;

        akt = kartyak_eleje[sor][oszlop];
        kartyak_hatulja[sor][oszlop] = akt;

        if (akt == elozo && akt != '\0' && elozo != '\0')
        {
            ok++;
            TELL "Egyformak, a kartyak igy maradnak." << endl;
            kiir(kartyak_hatulja);
        }
        else
        {
            TELL "Nem egyeznek, visszaforditom a lapokat." << endl;
            kartyak_hatulja[elozosor][elozooszlop] = '*';
            kartyak_hatulja[sor][oszlop] = '*';
        }
    } while (ok != 3);
    if (ok == 3)
    {
        TELL "Gratulalok, On nyert " << db << " forditasbol." << endl;
    }
    return 0;
}
