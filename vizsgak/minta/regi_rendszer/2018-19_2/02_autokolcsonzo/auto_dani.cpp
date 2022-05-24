#include <iostream>
#include <fstream>
using namespace std;

#define TELL cout <<
#define ASK cin >>
#define MAX 32

struct adat
{
    string marka;
    int nehezseg;
    int penz;
};

int olvas(adat tomb[], string fajlnev)
{
    int i = 0;
    ifstream fajl(fajlnev);
    string aktSor;

    if (fajl.is_open())
    {
        while (getline(fajl, aktSor))
        {
            int spacehelye = aktSor.find(' ');
            tomb[i].marka = aktSor.substr(0, spacehelye);
            spacehelye++;
            tomb[i].nehezseg = stoi(aktSor.substr(spacehelye, 2));
            spacehelye += 2;
            int akthossz = aktSor.length() - spacehelye;
            tomb[i].penz = stoi(aktSor.substr(spacehelye, akthossz));
            // TELL tomb[i].marka << "\t" << tomb[i].nehezseg << "\t" << tomb[i].penz << endl;
            i++;
        }
    }
    else
        TELL "A fájl nem létezik!" << endl;

    return i;
}

void ellenoriz(int kocsidb, adat felhasznalo, string aktSor, adat kocsik[])
{
    int spacehelye = aktSor.find(' ');
    felhasznalo.marka = aktSor.substr(0, spacehelye);
    spacehelye++;
    felhasznalo.nehezseg = stoi(aktSor.substr(spacehelye, 2));
    spacehelye += 2;
    int akthossz = aktSor.length() - spacehelye;
    felhasznalo.penz = stoi(aktSor.substr(spacehelye, akthossz));

    // TELL "\nFelhasználó adatai: " << felhasznalo.marka << "\t" << felhasznalo.nehezseg << "\t" << felhasznalo.penz << endl;

    bool viheti = false;
    bool szint = false;
    bool penz = false;

    for (int i = 0; i < kocsidb; i++)
    {

        if (kocsik[i].marka == felhasznalo.marka && kocsik[i].nehezseg <= felhasznalo.nehezseg && kocsik[i].penz <= felhasznalo.penz)
            viheti = true;
        else if (kocsik[i].marka == felhasznalo.marka && kocsik[i].nehezseg >= felhasznalo.nehezseg && kocsik[i].penz <= felhasznalo.penz)
            szint = true;
        else if (kocsik[i].marka == felhasznalo.marka && kocsik[i].nehezseg <= felhasznalo.nehezseg && kocsik[i].penz >= felhasznalo.penz)
            penz = true;
        else if (kocsik[i].marka == felhasznalo.marka && kocsik[i].nehezseg >= felhasznalo.nehezseg && kocsik[i].penz >= felhasznalo.penz)
        {
            penz = true;
            szint = true;
        }

        if (i == kocsidb - 1)
        {
            if (viheti == true)
            {
                TELL "Vigye az autot!" << endl;
                return;
            }
            else if (szint == true && penz == true)
            {
                TELL "Nem eleg ugyes sofor. Nincs eleg penze. Nem szolgaljuk ki." << endl;
                return;
            }
            else if (szint == true)
            {
                TELL "Nem eleg ugyes sofor. Nem szolgaljuk ki." << endl;
                return;
            }
            else if (penz == true)
            {
                TELL "Nincs eleg penze. Nem szolgaljuk ki." << endl;
                return;
            }
            else
                TELL "Nincs ilyen autonk. Nem szolgaljuk ki." << endl;
        }
    }
}

string beolv()
{
    string input;
    getline(cin, input);
    return input;
}

int main()
{
    TELL "Autokolcsonzo program; kilepes # megadasaval." << endl;
    adat kocsik[MAX];
    adat felhasznalo;
    string akt;
    int kocsidb = olvas(kocsik, "/home/szeke/uni/sze_programozas/mintavizsgak/2018-19_2/02_autokolcsonzo/input.txt");
    do
    {
        akt = beolv();
        if (akt == "#")
            return 0;
        ellenoriz(kocsidb, felhasznalo, akt, kocsik);
    } while (akt != "#");

    return 0;
}