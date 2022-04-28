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

struct adat
{
    string jarat;
    string hely;
    int erk_ora;
    int erk_perc;
    int el_ora;
    int el_perc;
    int megallo_db;
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
    ifstream fajl(fajlnev);
    string aktSor;
    int i = 0;
    int adat_db = 0;

    if (fajl.is_open())
    {
        string aktjaratszam = "\0";
        while (getline(fajl, aktSor) && aktSor != "vege")
        {
            if (!isdigit(aktSor[0]) && aktSor != "---" && aktSor != "vege")
            {
                vonat[i].jarat = aktjaratszam;

                int tabHelye = aktSor.find("\t");

                vonat[i].hely = aktSor.substr(0, tabHelye);

                string akt = aktSor.substr(tabHelye + 1, 2);
                vonat[i].erk_ora = toint(akt);
                tabHelye += 4;

                akt = aktSor.substr(tabHelye, 2);
                vonat[i].erk_perc = toint(akt);
                tabHelye += 3;

                akt = aktSor.substr(tabHelye, 2);
                vonat[i].el_ora = toint(akt);
                tabHelye += 3;

                akt = aktSor.substr(tabHelye, 2);
                vonat[i].el_perc = toint(akt);
                // TELL "Járat szám: " << vonat[i].jarat << "\nTelepülés: " << vonat[i].hely << "\nÉrkezési idő: " << vonat[i].erk_ora << ":" << vonat[i].erk_perc << "\tTávozási idő: " << vonat[i].el_ora << ":" << vonat[i].el_perc << endl;
                i++;
            }
            else if (aktSor != "---" && aktSor != "vege")
            {
                aktjaratszam = aktSor;
                i++;
            }
            adat_db++;
        }
    }
    else
    {
        TELL "A fájl nem létezik!" << endl;
    }
    return adat_db;
}

string feldolgoz(adat vonat[], string start, string stop, int db)
{
    string er = "\0";
    for (int i = 0; i < db; i++)
    {
        if (start == vonat[i].hely)
        {
            for (int j = i; j < db; j++)
            {
                if (stop == vonat[j].hely)
                    if (vonat[i].jarat == vonat[j].jarat)
                    {
                        er = vonat[i].jarat + " " + to_string(vonat[i].el_ora) + ":" + to_string(vonat[i].el_perc) + " --> " + to_string(vonat[j].erk_ora) + ":" + to_string(vonat[j].erk_perc) + "\n";
                        TELL vonat[i].jarat << " " << vonat[i].el_ora << ":" << vonat[i].el_perc << " --> " << vonat[j].erk_ora << ":" << vonat[j].erk_perc << endl;
                        return er;
                    }
            }
        }
    }
    return er;
}

void iras(adat vonat[], string ki)
{
    ofstream allaski;
    string irashely;
    string akt = "\0";
    irashely = "/home/szeke/uni/sze_programozas/mintavizsgak/2019-20_1/04_menetrend/menetrend.txt";
    allaski.open(irashely);

    allaski << ki;

    allaski.close();
}

int main()
{
    adat vonat[MAX];
    string filename = "/home/szeke/uni/sze_programozas/mintavizsgak/2019-20_1/04_menetrend/vonat.txt";
    // string filename = "/mnt/c/Users/szeke/uni/sze_programozas/mintavizsgak/2019-20_1/04_menetrend/vonat.txt";
    int adat_db = olvas(vonat, filename);

    string start, stop, er;
    TELL "Vonat menetrend" << endl;
    do
    {
        TELL "Indulás: ";
        start = beolv();
        TELL "Érkezés: ";
        stop = beolv();
        if (start == stop)
            TELL "Nem megfelelő adatok!" << endl;
    } while (start == stop);
    er = feldolgoz(vonat, start, stop, adat_db);
    iras(vonat, er);
    return 0;
}