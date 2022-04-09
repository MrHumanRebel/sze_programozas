// Headers
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <string>
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

int random(int tol, int ig)
{
    return (tol + rand() % (ig - tol + 1));
}

void nagybeture(string tomb[], int aktdb)
{
    for (int i = 0; i < aktdb; i++)
    {
        string akt = tomb[i];
        int db = tomb[i].length();
        tomb[i] = "\0";
        for (int j = 0; j < db; j++)
        {
            tomb[i] += toupper(akt[j]);
        }
    }
}

void kitalal(string tomb[], int aktdb)
{
    int index = random(0, aktdb);
    string akt = tomb[index], tipp;
    int hossz = akt.length(), szamlalo = 1;
    TELL akt << endl;
    for (int i = 1; i < hossz; i++)
    {
        TELL '*';
    }
    do
    {
        TELL "\nAdja meg a(z) " << szamlalo << ". tippjét!" << endl;
        ASK tipp;
        string kiir = "\0";
        for (long unsigned int i = 0; i < akt.length(); i++)
        {
            for (long unsigned int j = 0; j < tipp.length(); j++)
            {
                tipp[j] = toupper(tipp[j]);
                if (akt[i] == tipp[j])
                {
                    kiir += akt[i];
                }
                else
                    kiir += '*';
            }
        }
        TELL kiir;

    } while (hossz == 0);
}

int main()
{
    TELL "Akasztófa játék\nA játék ékezetek nélkül játszandó!\n1-es gomb => Magyarország települései\n2-es gomb => Magyarország megyéi\n3-as gomb => A világ országai" << endl;
    int menu = szamBeker(1, 3);
    if (menu == 1)
    {
        system("clear");
        TELL "Téma:\nMagyarország települései\n_________________________" << endl;
        string telepulesek[3256];
        int telepules_db = telepules_olvas(telepulesek);
        nagybeture(telepulesek, telepules_db);
        kitalal(telepulesek, telepules_db);
    }
    else if (menu == 2)
    {
        system("clear");
        TELL "Téma:\nMagyarország megyéi\n_________________________" << endl;
        string megyek[20];
        int megye_db = megyek_olvas(megyek);
        nagybeture(megyek, megye_db);
        kitalal(megyek, megye_db);
    }
    else if (menu == 3)
    {
        system("clear");
        TELL "Téma:\nA világ országai\n_________________________" << endl; // Ötletek: Kutyafajták, lánynevek, fiunevek
        string orszagok[250];
        int orszag_db = orszagok_olvas(orszagok);
        nagybeture(orszagok, orszag_db);
        kitalal(orszagok, orszag_db);
    }

    return 0;
}