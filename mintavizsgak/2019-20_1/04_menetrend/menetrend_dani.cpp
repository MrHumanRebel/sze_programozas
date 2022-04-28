#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
using namespace std;
#define TELL cout <<
#define ASK cin >>
#define MAX 256

struct adatok
{
    string hely;
    int erk_ora;
    int erk_perc;
    int el_ora;
    int el_perc;
};

string beolv()
{
    string input;
    getline(cin, input);
    return input;
}

int olvas(adatok vonat[], string fajlnev)
{
    int i = 0;

    ifstream fajl(fajlnev);
    string aktSor;

    if (fajl.is_open())
    {
        while (getline(fajl, aktSor))
        {
            int tabHelye = aktSor.find("\t");

            string akthely = vonat[i].hely = aktSor.substr(0, tabHelye);

            vonat[i].erk_ora = stoi(aktSor.substr(tabHelye, 3));
            tabHelye += 4;
            vonat[i].erk_perc = stoi(aktSor.substr(tabHelye, 3));
            tabHelye += 2;

            vonat[i].el_ora = stoi(aktSor.substr(tabHelye, 3));
            tabHelye += 4;
            vonat[i].el_perc = stoi(aktSor.substr(tabHelye, 3));
            tabHelye += 2;
            i++;
        }
    }
    else
    {
        TELL "A fájl nem létezik!" << endl;
    }
    return i;
}

/*void feldolgoz(string vonat[], adatok ido[], int sor_db, string start, string stop)
{
    for (int i = 0; i < sor_db; i++)
    {
        string akt = "\0";
        if (!isdigit(vonat[i][0]) && vonat[i][0] != '-')
        {
            for (size_t j = 0; j < vonat[i].length(); j++)
            {
                if (!isdigit(vonat[i][j]) && vonat[i][j] != ':' && vonat[i][j] != ' ')
                    akt += vonat[i][j];
            }
            if (start == akt)
            {
                TELL akt << endl;
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
}*/

int main()
{
    adatok vonat[MAX];
    int sor_db = olvas(vonat, "/mnt/c/Users/szeke/uni/sze_programozas/mintavizsgak/2019-20_1/04_menetrend/vonat.txt");
    TELL "Sorok száma: " << sor_db << endl;

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

    return 0;
}