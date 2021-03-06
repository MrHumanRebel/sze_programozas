#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

#define TELL cout <<
#define ASK cin >>
#define SOR 10
#define OSZL 10

char tabla[SOR][OSZL];

bool sor_ok = false, oszl_ok = false, vege = false, van_e_palya = false;
int sor, c_oszl, jatekos, szamlalo;
int db = 0;
char oszl, aktjel;

void alap_palya()
{
    for (int i = 0; i < SOR; i++)
    {
        for (int j = 0; j < OSZL; j++)
        {
            tabla[i][j] = '.';
        }
    }
    van_e_palya = true;
}

void beker()
{
    do
    {
        TELL "Sor: ";
        ASK sor;
        if (sor >= 1 && sor <= 10)
            sor_ok = true;
        else
            TELL "Adjon meg 1-" << SOR << " tartományba tartozó számot! ";

    } while (sor_ok == false);

    do
    {
        TELL "Oszlop: ";
        ASK oszl;
        oszl = toupper(oszl);
        if ((oszl >= 'a' && oszl <= 'j') or (oszl >= 'A' && oszl <= 'J'))
            oszl_ok = true;
        else
            TELL "Adjon meg A-J tartományba tartozó betűt! ";

    } while (oszl_ok == false);

    if (oszl_ok == true)
    {
        db = 0;
        for (int i = 65; i <= 90; i++)
        {
            if (oszl == i)
            {
                c_oszl = (oszl - (oszl - 1)) + db;
                TELL "Az oszlop sorszáma: " << c_oszl << "\n"
                     << endl;
            }
            else
                db = db + 1;
        }
    }
}

void allas()
{
    TELL "  \t";
    for (int i = 'A'; i < ('A' + SOR); i++)
    {
        TELL char(i);
    }
    TELL endl;

    for (int i = 0; i < SOR; i++)
    {
        if (i < SOR - 1)
            TELL '0' << i + 1 << "\t";
        else
            TELL i + 1 << "\t";
        for (int j = 0; j < OSZL; j++)
        {
            TELL tabla[i][j];
        }
        TELL endl;
    }
}

void valaszt()
{
    if (jatekos == 1)
    {
        if (tabla[sor - 1][c_oszl - 1] != 'O')
            tabla[sor - 1][c_oszl - 1] = 'X';
        else
        {
            TELL "Ez a hely már foglalt, Ön csalni akart!" << endl;
            beker();
            valaszt();
        }
    }

    if (jatekos == 2)
    {
        if (tabla[sor - 1][c_oszl - 1] != 'X')
            tabla[sor - 1][c_oszl - 1] = 'O';
        else
        {
            TELL "Ez a hely már foglalt, Ön csalni akart!" << endl;
            beker();
            valaszt();
        }
    }
}

void ellenoriz()
{
    // Sima jobbra balra le fel
    for (int i = 0; i < SOR; i++)
    {
        for (int j = 0; j < OSZL; j++)
        {
            if (tabla[i][j] == aktjel &&
                tabla[i][j + 1] == aktjel &&
                tabla[i][j + 2] == aktjel &&
                tabla[i][j + 3] == aktjel &&
                tabla[i][j + 4] == aktjel)
            {
                vege = true;
                TELL "Vízszintes irányban ";
                return;
            }
            if (tabla[i][j] == aktjel &&
                tabla[i + 1][j] == aktjel &&
                tabla[i + 2][j] == aktjel &&
                tabla[i + 3][j] == aktjel &&
                tabla[i + 4][j] == aktjel)
            {
                vege = true;
                TELL "Függőleges irányban ";
                return;
            }
        }
    }

    // Balrol jobbra atló
    for (int i = 0; i < SOR - 4; i++)
    {
        for (int j = 0; j < OSZL - 4; j++) //"G" sornál álljon le
        {
            if (tabla[i][j] == aktjel)
            {
                szamlalo = 0;
                for (int k = 0; k < 5; k++)
                {
                    if (tabla[i + k][j + k] == aktjel)
                        szamlalo++;

                    if (szamlalo >= 5)
                    {
                        vege = true;
                        TELL "Balról jobbra atlóval ";
                        return;
                    }
                }
            }
        }
    }

    // Jobbról balra atló
    for (int i = SOR - 1; i >= 4; i--)
    {
        for (int j = 0; j < OSZL - 4; j++) //"G" sornál álljon le
        {
            if (tabla[i][j] == aktjel)
            {
                szamlalo = 0;
                for (int k = 0; k < 5; k++)
                {
                    if (tabla[i - k][j + k] == aktjel)
                        szamlalo++;

                    if (szamlalo >= 5)
                    {
                        vege = true;
                        TELL "Jobbról balra atlóval, ";
                        return;
                    }
                }
            }
        }
    }
}

void nyert()
{
    if (jatekos == 1)
    {
        aktjel = 'X';
        ellenoriz();
        if (szamlalo >= 5)
            TELL "az első játékos nyert!";
    }

    if (jatekos == 2)
    {
        aktjel = 'O';
        ellenoriz();
        if (szamlalo >= 5)
            TELL "a második játékos nyert!";
    }
}

void olvasas()
{
    string olvashely;
    ifstream olvas;
    int tovabb = 0;
    char akt;
    // olvashely = "/mnt/c/Users/szeke/uni/sze_programozas/anyagok/vizsgafeladatok_dani/amoba.txt";
    olvashely = "/home/szeke/uni/sze_programozas/anyagok/vizsgafeladatok_dani/amoba.txt";
    olvas.open(olvashely);
    if (!olvas.is_open())
    {
        TELL "Nincs mentett játékállás!\n"
             << endl;
        van_e_palya = false;
    }
    else
    {
        TELL "Van mentett játékállás!\n"
             << "Ha szeretné betölteni az előző játékállást, nyomja meg az \"1\"-es gombot!" << endl;
        ASK tovabb;
        if (tovabb == 1)
        {
            van_e_palya = true;
            for (int i = 0; i <= SOR; i++)
            {
                for (int j = 0; j <= OSZL; j++)
                {
                    olvas >> akt;
                    tabla[i][j] = akt;
                }
            }
        }
        olvas.close();
    }
}

void iras()
{
    ofstream allaski;
    string irashely;
    string akt;
    // irashely = "/mnt/c/Users/szeke/uni/sze_programozas/anyagok/vizsgafeladatok_dani/amoba.txt";
    irashely = "/home/szeke/uni/sze_programozas/anyagok/vizsgafeladatok_dani/amoba.txt";
    allaski.open(irashely);
    for (int i = 0; i <= SOR; i++)
    {
        for (int j = 0; j <= OSZL; j++)
        {
            akt = tabla[i][j];
            if (j == 10)
                allaski << "\n";
            allaski << akt;
        }
    }
    allaski.close();
    TELL "Játék állás sikeresen mentve!" << endl;
}

int main()
{

    TELL "Amőba játék\n"
         << endl;

    olvasas();
    if (van_e_palya == false)
        alap_palya();

    allas();
    vege = false;
    do
    {
        TELL "Első játékos lépése:" << endl;
        jatekos = 1;
        beker();
        valaszt();
        allas();
        nyert();
        if (vege == true)
            return 0;
        iras();

        TELL "Második játékos lépése:" << endl;
        jatekos = 2;
        beker();
        valaszt();
        allas();
        nyert();
        iras();

    } while (!vege);
    return 0;
}