#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
#define TELL cout <<
#define ASK cin >>
#define MAX 128

struct megallo
{
    string hely;
    int erk_ora;
    int erk_perc;
    int el_ora;
    int el_perc;
};

struct adat
{
    string jarat;
    megallo megallok[MAX];
    int db;
};

string beolv()
{
    string input;
    getline(cin, input);
    return input;
}

int toint(string str)
{
    bool negativ = (str[0] == '-');
    int szam = 0;
    for (size_t i = negativ; i < str.length(); i++)
    {
        if ((int)(str[i]) - 48 >= 0 && (int)(str[i]) - 48 <= 9)
        {
            szam += (int)(((int)(str[i])) - (int)48) * pow(10, str.length() - i - (int)1);
        }
        else
        {
            szam = 0;
            break;
        }
    }
    szam -= (int)negativ * szam * 2;
    return szam;
}

int olvas(adat vonat[], string fajlnev)
{
    int i = 0, j = 0;

    ifstream fajl(fajlnev);
    string aktSor;

    if (fajl.is_open())
    {
        while (getline(fajl, aktSor) && aktSor != "vege")
        {
            if (!isdigit(aktSor[0]) && aktSor[0] != '-' && aktSor[0] != 'v')
            {
                int tabHelye = aktSor.find("\t");
                vonat[i].megallok[j].hely = aktSor.substr(0, tabHelye);

                string akt = aktSor.substr(tabHelye + 1, 2);
                vonat[i].megallok[j].erk_ora = toint(akt);
                tabHelye += 4;

                akt = aktSor.substr(tabHelye, 2);
                vonat[i].megallok[j].erk_perc = toint(akt);
                tabHelye += 3;

                akt = aktSor.substr(tabHelye, 2);
                vonat[i].megallok[j].el_ora = toint(akt);
                tabHelye += 3;

                akt = aktSor.substr(tabHelye, 2);
                vonat[i].megallok[j].el_perc = toint(akt);
                j++;
            }
            else if (aktSor[0] != '-' && aktSor[0] != 'v')
            {
                vonat[i].jarat = aktSor;
                i++;
                j = 0;
            }
            vonat[i].db = j;
        }
    }
    else
    {
        TELL "A fájl nem létezik!" << endl;
    }
    return i;
}

void kiir(adat tomb[], int db)
{
    for (int i = 0; i < db; i++)
    {
        TELL tomb[i].jarat << endl;
        for (int j = 0; j < tomb[i].db; j++)
        {
            TELL tomb[i].megallok[j].hely << endl;
        }
    }
}

void feldolgoz(adat vonat[], string start, string stop, int db)
{
    int startid, startjaratid, stopid, stopjaratid, i = 0;
    do
    {

        for (int j = 0; j < vonat[i].db; j++)
        {
            if (vonat[i].megallok[j].hely == start)
            {
                startid = j;
                startjaratid = i;
            }
            if (vonat[i].megallok[j].hely == stop)
            {
                stopid = j;
                stopjaratid = i;
            }
        }
        i++;

    } while (startjaratid != stopjaratid or i < db);
    TELL vonat[startjaratid].megallok[startid].erk_ora << ":" << vonat[startjaratid].megallok[startid].erk_perc << endl;
}

int main()
{
    adat vonat[MAX];
    int adat_db = olvas(vonat, "/mnt/c/Users/szeke/uni/sze_programozas/mintavizsgak/2019-20_1/04_menetrend/vonat.txt");
    TELL "Sorok száma: " << adat_db << endl;

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
    feldolgoz(vonat, start, stop, adat_db);
    // kiir(vonat, adat_db);
    return 0;
}