#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#define TELL cout <<
#define ASK cin >>
#define SOR_MAX 10
#define OSZLOP_MAX 10

void iras()
{
    ofstream allaski;
    string irashely;
    string akt;
    irashely = "/home/szeke/uni/sze_programozas/anyagok/vizsgafeladatok_dani/amoba.txt";
    allaski.open(irashely);
    for (int i = 0; i <= SOR; i++)
    {
        for (int j = 0; j <= OSZL; j++)
        {
            akt = tabla[i][j];
            if (j == 10)
                allaski << "\n";
            allaski << akt;
        }
    }
    allaski.close();
}