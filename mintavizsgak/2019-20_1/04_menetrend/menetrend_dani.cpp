#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;
#define TELL cout <<
#define ASK cin >>
#define MAX 256

string beolv()
{
    string input;
    getline(cin, input);
    return input;
}

int olvas(string tomb[], string fajlnev)
{
    int i = 0;

    ifstream fajl(fajlnev);
    string aktSor;

    if (fajl.is_open())
    {
        while (getline(fajl, aktSor))
        {
            tomb[i] = aktSor;
            i++;
        }
    }
    else
    {
        TELL "A fájl nem létezik!" << endl;
    }

    return i;
}

void feldolgoz(string vonat[], int sor_db, string start, string stop)
{
    for (int i = 0; i < sor_db; i++)
    {
        string akt = "\0";
        if (isdigit(vonat[i][0]))
        {
            for (int j = 0; j < vonat[i + 1].length(); j++)
            {
                if (!isdigit(vonat[i + 1][j]) && vonat[i + 1][j] != ':' && vonat[i + 1][j] != ' ')
                    akt += vonat[i + 1][j];
            }
            TELL akt << endl;
            if (start == akt)
            {
            }
        }
    }
}

int jaratok(string vonat[], int sor_db)
{
    int db = 0;
    for (int i = 0; i < sor_db; i++)
    {
        if (isdigit(vonat[i][0]))
            db++;
    }
    return db;
}

int main()
{
    string vonat[MAX];
    int sor_db = olvas(vonat, "/mnt/c/Users/szeke/uni/sze_programozas/mintavizsgak/2019-20_1/04_menetrend/vonat.txt");
    int jarat_db = jaratok(vonat, sor_db);

    TELL "Indulás: ";
    string start = beolv();
    TELL "Érkezés: ";
    string stop = beolv();
    feldolgoz(vonat, sor_db, start, stop);

    return 0;
}