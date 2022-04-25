#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
using namespace std;
#define TELL cout <<
#define ASK cin >>
#define MAX 512

struct oraperc
{
    string ora;
    string perc;
};

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

void feldolgoz(string vonat[], oraperc ido[], int sor_db, string start, string stop)
{
    for (int i = 0; i < sor_db; i++)
    {
        string akt = "\0";
        if (isdigit(vonat[i][0]))
        {
            for (size_t j = 0; j < vonat[i + 1].length(); j++)
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

void jaratido(string vonat[], oraperc ido[], int sor_db)
{
    int k = 0;
    for (int i = 0; i < sor_db; i++)
    {
        string akt = vonat[i];
        if (!isdigit(vonat[i][0]) && vonat[i][0] != '-')
        {
            int tabHelye = akt.find("	");
            TELL "Tab helye: " << tabHelye << endl;

            ido[k].ora = akt.substr(tabHelye, 2);
            tabHelye += 3;
            ido[k].perc = akt.substr(tabHelye, 2);
            k++;

            TELL "Beidő: " << ido[k].ora << ido[k].perc << endl;

            ido[k].ora = akt.substr(tabHelye, 2);
            tabHelye += 3;
            ido[k].perc = akt.substr(tabHelye, 2);
            k++;

            TELL "Kiidő: " << ido[k].ora << ido[k].perc << endl;
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
    oraperc ido[jarat_db * 2];
    string start, stop;
    do
    {
        TELL "Indulás: ";
        start = beolv();
        TELL "Érkezés: ";
        stop = beolv();
        if (start == stop)
            TELL "Nem megfelelő adatok!" << endl;
    } while (start == stop);
    feldolgoz(vonat, ido, sor_db, start, stop);
    jaratido(vonat, ido, sor_db);

    return 0;
}