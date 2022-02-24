#include <iostream>
using namespace std;
#define DB 10
char jatek[DB][DB];
bool van_e_palya = false;
bool vege;
bool sor_ok, oszl_ok = false;
int sor, c_oszl, jatekos;
int db = 0;
char oszl;

int alap_palya()
{
    for (int i = 1; i <= DB; i++)
    {
        for (int j = 1; j <= DB; j++)
        {
            jatek[i][j] = '.';
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
        if (sor >= 48 && sor <= 57) // Számok
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
    cout << "  \tABCDEFGHIJ" << endl;
    for (int i = 1; i <= DB; i++)
    {
        if (i < DB)
            cout << '0' << i << "\t";
        else
            cout << i << "\t";
        for (int j = 1; j <= DB; j++)
        {
            cout << jatek[i][j];
        }
        cout << endl;
    }
    return 0;
}

int valaszt()
{
    if (jatekos == 1)
    {
        if (jatek[sor][c_oszl] != 'O')
            jatek[sor][c_oszl] = 'X';
        else
            cout << "Ez a hely már foglalt, Ön csalni akart, ezért ebből a körből kimarad!" << endl;
    }

    if (jatekos == 2)
    {
        if (jatek[sor][c_oszl] != 'X')
            jatek[sor][c_oszl] = 'O';
        else
            cout << "Ez a hely már foglalt, Ön csalni akart, ezért ebből a körből kimarad!" << endl;
    }
    return 0;
}

int nyert()
{
    for (int i = 1; i <= DB; i++)
    {

        for (int j = 1; j <= DB; j++)
        {
            jatekos = 0;
            if (jatek[i][j] == 'X')
                jatekos++;
            if (jatekos == 5)
                cout << "Az első játékos nyert!";

            jatekos = 0;
            if (jatek[i][j] == 'O')
                jatekos++;
            if (jatekos == 5)
                cout << "A második játékos nyert!";
        }
    }
    return 0;
}

int main()
{

    cout << "Amőba játék\n"
         << endl;

    // Ha még nincs nincs pálya generáljuk egyet
    if (van_e_palya == false)
        alap_palya();

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

        cout << "Második játékos lépése:" << endl;
        jatekos = 2;
        beker();
        valaszt();
        allas();
        nyert();

    } while (!vege);
    return 0;
}