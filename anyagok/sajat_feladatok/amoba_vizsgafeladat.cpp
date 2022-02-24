#include <iostream>
#include <stdlib.h>
using namespace std;
#define DB 10
char tabla[DB][DB];
bool van_e_palya = false;
bool vege;
bool sor_ok, oszl_ok = false;
int sor, c_oszl, jatekos;
int db = 0;
char oszl;

int alap_palya()
{
    for (int i = 0; i < DB; i++)
    {
        for (int j = 0; j < DB; j++)
        {
            tabla[i][j] = '.';
        }
    }
    van_e_palya = true;
    return 0;
}

int beker()
{
    do
    {
        cout << "Sor: ";
        cin >> sor;
        if (sor >= 1 && sor <= 10) // Számok
            sor_ok = true;
        else
            cout << "Adjon meg 1-" << DB << " tartományba tartozó számot! ";

    } while (sor_ok == false);

    do
    {
        cout << "Oszlop: ";
        cin >> oszl;
        if (oszl >= 65 && oszl <= 90) // Betűk
            oszl_ok = true;
        else
            cout << "Adjon meg A-J tartományba tartozó angol nagybetűt! ";

    } while (oszl_ok == false);

    db = 0;
    for (int i = 65; i <= 90; i++)
    {
        if (oszl == i)
        {
            c_oszl = (oszl - (oszl - 1)) + db;
            cout << "Az oszlop sorszáma:\t" << c_oszl << endl;
        }
        else
            db = db + 1;
    }

    return 0;
}

int allas()
{
    system("clear"); // Console clear
    // cout << "  \tABCDEFGHIJ" << endl;
    cout << "  \t";
    for (int i = 65; i < (65 + DB); i++) // 65 => "A" betű ASCII
    {
        cout << char(i);
    }
    cout << endl;

    for (int i = 0; i < DB; i++)
    {
        if (i < DB - 1)
            cout << '0' << i + 1 << "\t";
        else
            cout << i + 1 << "\t";
        for (int j = 0; j < DB; j++)
        {
            cout << tabla[i][j];
        }
        cout << endl;
    }

    return 0;
}

int valaszt()
{
    if (jatekos == 1)
    {
        if (tabla[sor - 1][c_oszl - 1] != 'O')
            tabla[sor - 1][c_oszl - 1] = 'X';
        else
            cout << "Ez a hely már foglalt, Ön csalni akart, ezért ebből a körből kimarad!" << endl;
    }

    if (jatekos == 2)
    {
        if (tabla[sor - 1][c_oszl - 1] != 'X')
            tabla[sor - 1][c_oszl - 1] = 'O';
        else
            cout << "Ez a hely már foglalt, Ön csalni akart, ezért ebből a körből kimarad!" << endl;
    }
    return 0;
}

int nyert()
{
    jatekos = 0;
    for (int i = 0; i < DB; i++)
    {
        for (int j = 0; j < DB; j++)
        {
            if (tabla[i][j] == 'X')
                jatekos++;
            if (jatekos == 5)
                vege = true;
        }
    }
    if (jatekos == 5)
        cout << "Az első játékos nyert!";
    jatekos = 0;

    for (int i = 0; i < DB; i++)
    {
        for (int j = 0; j < DB; j++)
        {
            if (tabla[i][j] == 'O')
                jatekos++;
            if (jatekos == 5)
                vege = true;
        }
    }
    if (jatekos == 5)
        cout << "A második játékos nyert!";

    return 0;
}

int main()
{

    cout << "Amőba játék\n"
         << endl;

    // Ha még nincs nincs pálya generáljuk egyet
    if (van_e_palya == false)
        alap_palya();

    // Alap állás printelése
    allas();
    vege = false;
    do
    {
        cout << "Első játékos lépése:" << endl;
        jatekos = 1;
        beker();
        valaszt();
        allas();
        nyert();
        if (vege == true)
            return 0;

        cout << "Második játékos lépése:" << endl;
        jatekos = 2;
        beker();
        valaszt();
        allas();
        nyert();
        if (vege == true)
            return 0;

    } while (!vege);
    return 0;
}