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
    int a = 0, b = 0, c = 0, x = 0;
    for (int i = 0; i < SOR_MAX; i++)
    {
        for (int j = 0; j < OSZL_MAX; j++)
        {
            seed = random(1, 1000);
            tomb[i][j] = random('a', 'c');

            if (tomb[i][j] == 'a')
                a++;
            else if (tomb[i][j] == 'b')
                b++;
            else if (tomb[i][j] == 'c')
                c++;

            // TELL "a: " << a_db << " b: " << b_db << " c: " << c_db << endl;

            if (a >= 3)
            {
                do
                {
                    seed = random(1000, 2000);
                    tomb[i][j] = random('b', 'c');
                    x++;
                    if (x > 100)
                    {
                        continue;
                    }
                } while (tomb[i][j] != 'a');

                if (x > 100)
                {
                    continue;
                }
                a--;
                if (tomb[i][j] == 'b')
                    b++;
                else if (tomb[i][j] == 'c')
                    c++;
            }

            x = 0;

            if (b >= 3)
            {
                do
                {
                    seed = random(3000, 4000);
                    tomb[i][j] = random('a', 'c');
                    if (x > 100)
                    {
                        continue;
                    }
                } while (tomb[i][j] != 'b');

                if (x > 100)
                {
                    continue;
                }
                b--;
                if (tomb[i][j] == 'a')
                    a++;
                else if (tomb[i][j] == 'c')
                    c++;
            }

            x = 0;

            if (c >= 3)
            {
                do
                {
                    seed = random(4000, 5000);
                    tomb[i][j] = random('a', 'b');
                    if (x > 100)
                    {
                        continue;
                    }
                } while (tomb[i][j] != 'c');

                if (x > 100)
                {
                    continue;
                }
                c--;
                if (tomb[i][j] == 'a')
                    a++;
                else if (tomb[i][j] == 'b')
                    b++;
            }
            x = 0;
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
    TELL "  123"
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

void beker()
{
    TELL "\nMegforditando kartya sora: ";
    szamBeker(1, 2);
    TELL "Oszlopa: ";
    szamBeker(1, 3);
}

void fordit(int ok)
{
}

int main()
{
    TELL "Memoriajatek\n"
        << endl;
    char kartyak_eleje[SOR_MAX][OSZL_MAX];
    feltolt_eleje(kartyak_eleje);
    char kartyak_hatulja[SOR_MAX][OSZL_MAX];
    feltolt_hatulja(kartyak_hatulja);
    int ok = 0;
    kiir(kartyak_eleje);
    beker();

    return 0;
}
