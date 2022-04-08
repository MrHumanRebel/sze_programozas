#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

#define TELL cout <<
#define ASK cin >>

int telepules_olvas(string telep[])
{
    ifstream olvas;
    string olvashely = "/mnt/c/Users/szeke/uni/sze_programozas/anyagok/vizsgafeladatok_dani/telepulesek.txt";
    string akt;
    int i = 0;
    olvas.open(olvashely);
    if (!olvas.is_open())
    {
        TELL "A fájl nem létezik!" << endl;
    }
    else
    {
        while (getline(olvas, akt))
        {
            olvas >> akt;
            telep[i] = akt;
            i++;
        }
    }
    return i;
}

int megyek_olvas(string megyek[])
{
    ifstream olvas;
    string olvashely = "/mnt/c/Users/szeke/uni/sze_programozas/anyagok/vizsgafeladatok_dani/megyek.txt";
    string akt;
    int i = 0;
    olvas.open(olvashely);
    if (!olvas.is_open())
    {
        TELL "A fájl nem létezik!" << endl;
    }
    else
    {
        while (getline(olvas, akt))
        {
            olvas >> akt;
            megyek[i] = akt;
            i++;
        }
    }
    return i;
}

int orszagok_olvas(string orszagok[])
{
    ifstream olvas;
    string olvashely = "/mnt/c/Users/szeke/uni/sze_programozas/anyagok/vizsgafeladatok_dani/orszagok.txt";
    string akt;
    int i = 0;
    olvas.open(olvashely);
    if (!olvas.is_open())
    {
        TELL "A fájl nem létezik!" << endl;
    }
    else
    {
        while (getline(olvas, akt))
        {
            olvas >> akt;
            orszagok[i] = akt;
            i++;
        }
    }
    return i;
}

int szamBeker(int MIN, int MAX)
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

int main()
{
    string telepulesek[3256];
    string megyek[20];
    string orszagok[250];
    int telepules_db = telepules_olvas(telepulesek);
    int megye_db = megyek_olvas(megyek);
    int orszag_db = orszagok_olvas(orszagok);
    int menu = szamBeker(1, 3);
    if (menu == 1)
    {
        TELL "Téma: Magyar települések..." << endl;
    }
    else if (menu == 2)
    {
        TELL "Téma: Magyar megyék..." << endl;
    }
    else
        TELL "Téma: A világ országai..." << endl;

    return 0;
}