#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
#define SOR_MAX 5
#define OSZLOP_MAX 5
int seed = 0;

void iras(char tabla[SOR_MAX][OSZLOP_MAX])
{
    ofstream allaski;
    string irashely;
    string akt;
    irashely = "/mnt/c/Users/szeke/uni/sze_programozas/fuggvenyek/palya_iras_teszt.txt";
    allaski.open(irashely);
    for (int i = 0; i <= SOR_MAX; i++)
    {
        for (int j = 0; j <= OSZLOP_MAX; j++)
        {
            akt = tabla[i][j];
            if (j == OSZLOP_MAX)
                allaski << "\n";
            allaski << akt;
        }
    }
    allaski.close();
}

int random(int tol, int ig)
{
    srand(time(NULL) + seed);
    return (tol + rand() % (ig - tol + 1));
}

int main()
{
    char tabla[SOR_MAX][OSZLOP_MAX];
    for (int i = 0; i <= SOR_MAX; i++)
    {
        for (int j = 0; j <= OSZLOP_MAX; j++)
        {
            seed = random(1, 50);
            tabla[i][j] = random('A', 'Z');
        }
    }
    iras(tabla);
    return 0;
}