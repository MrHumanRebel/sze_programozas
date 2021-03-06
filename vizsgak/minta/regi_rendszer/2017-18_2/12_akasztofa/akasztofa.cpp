#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;
#define TELL cout <<
#define ASK cin >>

int olvas(string tomb[], string olvashely)
{
    ifstream olvas;
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
            tomb[i] = akt;
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

void toupper_tomb(string tomb[], int aktdb)
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
    for (int i = 0; i < hossz; i++)
    {
        TELL '*';
    }
    char kitalalni_char[akt.length()];
    for (size_t i = 0; i < akt.length(); i++)
    {
        kitalalni_char[i] = akt[i];
    }
    do
    {
        TELL "\nAdja meg a(z) " << szamlalo << ". tippjét!" << endl;
        ASK tipp;
        // Kitalálandó karakterek
        string kiir = "\0";
        for (size_t i = 0; i < akt.length(); i++)
        {
            for (size_t j = 0; j < tipp.length(); j++)
            {

                tipp[j] = toupper(tipp[j]);
                if (kitalalni_char[i] == tipp[j])
                {
                    kiir += kitalalni_char[i];
                    kitalalni_char[i] = '\0';
                    hossz--;
                }
                else if (j == tipp.length() - 1)
                {
                    kiir += '*';
                    i++;
                }
            }
        }
        szamlalo++;
        TELL kiir << endl;
        TELL "DEBUG Hossz:" << hossz << endl;

    } while (hossz > 0);
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
        int telepules_db = olvas(telepulesek, "/home/szeke/uni/sze_programozas/anyagok/vizsgafeladatok_dani/telepulesek.txt");
        toupper_tomb(telepulesek, telepules_db);
        kitalal(telepulesek, telepules_db);
    }
    else if (menu == 2)
    {
        system("clear");
        TELL "Téma:\nMagyarország megyéi\n_________________________" << endl;
        string megyek[20];
        int megye_db = olvas(megyek, "/home/szeke/uni/sze_programozas/anyagok/vizsgafeladatok_dani/megyek.txt");
        toupper_tomb(megyek, megye_db);
        kitalal(megyek, megye_db);
    }
    else if (menu == 3)
    {
        system("clear");
        TELL "Téma:\nA világ országai\n_________________________" << endl;
        string orszagok[250];
        int orszag_db = olvas(orszagok, "/home/szeke/uni/sze_programozas/anyagok/vizsgafeladatok_dani/orszagok.txt");
        toupper_tomb(orszagok, orszag_db);
        kitalal(orszagok, orszag_db);
    }
    return 0; // Ötletek: Kutyafajták, lánynevek, fiunevek
}