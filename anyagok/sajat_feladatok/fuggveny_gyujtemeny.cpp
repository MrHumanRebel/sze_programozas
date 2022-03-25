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
        TELL "Adja meg a számot!";
        ASK akt;
        if (akt >= MIN && akt <= MAX)
            szambe_ok = true;
        else
            TELL "Adjon meg " << MIN << "-től " << MAX << "-ig tartományba tartozó számot! ";
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
        TELL "Adja meg a karaktert!";
        ASK akt;
        // akt = tolower(akt);
        // akt = toupper(akt);
        if (akt >= KEZD && akt <= VEG)
            karbe_ok = true;
        else
            TELL "Adjon meg " << KEZD << "-től " << VEG << "-ig tartományba tartozó karaktert! ";
    } while (karbe_ok == false);
    return akt;
}

int main()
{
    // Szám bekerő függvény tesztelő
    int MAX = 10;
    int MIN = 1;
    int akt;
    szambeker(MIN, MAX);

    // Karakter bekerő függvény tesztelő
    char KEZD = 'A';
    char VEG = 'D';
    karbeker(KEZD, VEG);
    return 0;
}