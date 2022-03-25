// Headers
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <fstream>
using namespace std;
#define TELL cout <<
#define ASK cin >>

// Szám bekerő függvény
int szambeker(int MIN, int MAX)
{
    bool szambe_ok = false;
    int akt;
    do
    {
        TELL "Adja meg a számot!" << endl;
        ASK akt;
        if (akt >= MIN && akt <= MAX)
            szambe_ok = true;
        else
            TELL "Adjon meg " << MIN << "-től " << MAX << "-ig tartományba tartozó számot!" << endl;
    } while (szambe_ok == false);
    return akt;
}

// Karakter bekerő függvény
int karbeker(char KEZD, char VEG)
{
    bool karbe_ok = false;
    char akt;
    do
    {
        TELL "Adja meg a karaktert!" << endl;
        ASK akt;
        // akt = tolower(akt);
        // akt = toupper(akt);
        if (akt >= KEZD && akt <= VEG)
            karbe_ok = true;
        else
            TELL "Adjon meg " << KEZD << "-től " << VEG << "-ig tartományba tartozó karaktert!" << endl;
    } while (karbe_ok == false);
    return akt;
}

// Pálya generáló függvény
// BETA VERSION
char palya_gen(int SORMAX, int OSZLMAX, char tabla[][], bool van_palya)
{

    for (int i = 0; i < SORMAX; i++)
    {
        for (int j = 0; j < OSZLMAX; j++)
        {
            tabla[i][j] = '.';
        }
    }
    van_palya = true;
    return tabla[][];
}

// Alap karakter olvasó függvény
// BETA VERSION
char olvasas(int SORMAX, int OSZLMAX, string olvashely, char tabla[][], bool van_palya)
{
    string olvashely;
    ifstream olvas;
    int tovabb = 0;
    char akt;
    olvas.open(olvashely);
    if (!olvas.is_open())
    {
        TELL "Nincs mentett állás, vagy a fájl nem elérhető!\n"
            << endl;
        van_palya = false;
    }
    else
    {
        van_palya = true;
        for (int i = 0; i <= SORMAX; i++)
        {
            for (int j = 0; j <= OSZLMAX; j++)
            {
                olvas >> akt;
                tabla[i][j] = akt;
            }
        }
    }
    olvas.close();
}

int main()
{
    // Szám bekerő függvény tesztelő
    int MAX = 10;
    int MIN = 1;
    int szam_akt = szambeker(MIN, MAX);
    TELL szam_akt << endl;

    // Karakter bekerő függvény tesztelő
    char KEZD = 'A';
    char VEG = 'D';
    char kar_akt = karbeker(KEZD, VEG);
    TELL kar_akt << endl;

    // Pálya generáló függvény tesztelő
    int SORMAX = 10;
    int OSZLMAX = 10;
    bool van_palya = false;
    char tabla[SORMAX][OSZLMAX] = palya_gen(SORMAX, OSZLMAX, tabla[][], van_palya);

    // Alap karakter olvasó függvény tesztelő
    string olvashely = "/home/szeke/uni/sze_programozas/anyagok/sajat_feladatok/amoba.txt";
    char tabla[SORMAX][OSZLMAX] = olvasas(SORMAX, OSZLMAX, olvashely, tabla[][], van_palya);

    return 0;
}