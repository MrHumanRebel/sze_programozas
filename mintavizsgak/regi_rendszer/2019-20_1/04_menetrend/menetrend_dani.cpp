#include <iostream>
#include <fstream>
#include <string>
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
};

string beolv()
{
    string input;
    getline(cin, input);
    return input;
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
                vonat[i].erk_ora = stoi(akt);
                tabHelye += 4;

                akt = aktSor.substr(tabHelye, 2);
                vonat[i].erk_perc = stoi(akt);
                tabHelye += 3;

                akt = aktSor.substr(tabHelye, 2);
                vonat[i].el_ora = stoi(akt);
                tabHelye += 3;

                akt = aktSor.substr(tabHelye, 2);
                vonat[i].el_perc = stoi(akt);
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
                        TELL er << endl;
                        return er;
                    }
            }
        }
    }
    if (er == "\0")
        TELL "Nincs találat!";
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
    string filename = "/home/szeke/uni/sze_programozas/mintavizsgak/2019-20_1/04_menetrend/vonat.txt", start, stop, er;
    // string filename = "/mnt/c/Users/szeke/uni/sze_programozas/mintavizsgak/2019-20_1/04_menetrend/vonat.txt",start, stop, er;
    int adat_db = olvas(vonat, filename);
    bool run = true;
    TELL "Vonat menetrend" << endl;
    do
    {
        do
        {
            TELL "Indulás: ";
            start = beolv();
            if (start == "vege")
                return 0;
            TELL "Érkezés: ";
            stop = beolv();
            if (stop == "vege")
                return 0;
            if (start == stop)
                TELL "Nem megfelelő adatok!" << endl;
        } while (start == stop);
        er = feldolgoz(vonat, start, stop, adat_db);
        iras(vonat, er);
    } while (run);

    return 0;
}