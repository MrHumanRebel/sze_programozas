#include <iostream>  // Alap header
#include <stdlib.h>  // ??
#include <cstdlib>   //Random generátor
#include <fstream>   //File kezelés
#include <sstream>   //String stream
#include <string>    //String kezelés
#include <ctime>     //Pontos idő
using namespace std; // Névtér
#define TELL cout << // Shorten
#define ASK cin >>   // Shorten
#define SOR_MAX 2
#define OSZL_MAX 3
int seed = 0;

// Random szám generátor
int random(int tol, int ig)
{
    srand(time(NULL) + seed);
    return (tol + rand() % (ig - tol + 1));
}

void feltolt_eleje(char tomb[SOR_MAX][OSZL_MAX])
{
    int a_db = 0, b_db = 0, c_db = 0;
    for (int i = 0; i < SOR_MAX; i++)
    {
        for (int j = 0; j < OSZL_MAX; j++)
        {
            seed = random(1, 1000);
            tomb[i][j] = random('a', 'c');

            if (tomb[i][j] == 'a')
                a_db++;
            else if (tomb[i][j] == 'b')
                b_db++;
            else if (tomb[i][j] == 'c')
                c_db++;

            // TELL "a: " << a_db << " b: " << b_db << " c: " << c_db << endl;

            if (a_db >= 3)
            {
                do
                {
                    seed = random(1000, 2000);
                    tomb[i][j] = random('b', 'c');
                } while (tomb[i][j] != 'a');

                a_db--;
                if (tomb[i][j] == 'b')
                    b_db++;
                else if (tomb[i][j] == 'c')
                    c_db++;
            }

            if (b_db >= 3)
            {
                do
                {
                    seed = random(3000, 4000);
                    tomb[i][j] = random('a', 'c');
                } while (tomb[i][j] != 'b');

                b_db--;
                if (tomb[i][j] == 'a')
                    a_db++;
                else if (tomb[i][j] == 'c')
                    c_db++;
            }

            if (c_db >= 3)
            {
                do
                {
                    seed = random(4000, 5000);
                    tomb[i][j] = random('a', 'b');
                } while (tomb[i][j] != 'c');

                c_db--;
                if (tomb[i][j] == 'a')
                    a_db++;
                else if (tomb[i][j] == 'b')
                    b_db++;
            }
            TELL tomb[i][j];
        }
        TELL endl;
    }
}

void feltolt_hatulja(char tomb[SOR_MAX][OSZL_MAX])
{
    for (int i = 0; i < SOR_MAX; i++)
    {
        for (int j = 0; j < OSZL_MAX; j++)
        {
            tomb[i][j] = '*';
            TELL tomb[i][j];
        }
        TELL endl;
    }
}

// Teszt
int main()
{
    char kartyak_eleje[SOR_MAX][OSZL_MAX];
    feltolt_eleje(kartyak_eleje);
    char kartyak_hatulja[SOR_MAX][OSZL_MAX];
    feltolt_hatulja(kartyak_hatulja);

    return 0;
}
