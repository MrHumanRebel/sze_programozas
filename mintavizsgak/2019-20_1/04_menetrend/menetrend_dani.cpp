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

int olvas(adatok vonat[], string jaratok[], string fajlnev)
{
    int i = 0, k = 0;

    ifstream fajl(fajlnev);
    string aktSor;

    if (fajl.is_open())
    {
        while (getline(fajl, aktSor))
        {
            if (!isdigit(aktSor[0]) && aktSor[0] != '-')
            {
                int tabHelye = aktSor.find("\t");

                vonat[i].hely = aktSor.substr(0, tabHelye);

                string akt = aktSor.substr(tabHelye + 1, 2);
                if (akt[0] == '0')
                    akt[0] = akt[1];
                vonat[i].erk_ora = toint(akt);
                tabHelye += 4;

                akt = aktSor.substr(tabHelye, 2);
                if (akt[0] == '0')
                    akt[0] = akt[1];
                vonat[i].erk_perc = toint(akt);
                tabHelye += 3;

                akt = aktSor.substr(tabHelye, 2);
                if (akt[0] == '0')
                    akt[0] = akt[1];
                vonat[i].el_ora = toint(akt);
                tabHelye += 3;

                akt = aktSor.substr(tabHelye, 2);
                if (akt[0] == '0')
                    akt[0] = akt[1];
                vonat[i].el_perc = toint(akt);
                i++;
            }
            else
            {
                jaratok[k] = aktSor;
                k++;
            }
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
    string jaratok[MAX];
    int sor_db = olvas(vonat, jaratok, "/mnt/c/Users/szeke/uni/sze_programozas/mintavizsgak/2019-20_1/04_menetrend/vonat.txt");
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