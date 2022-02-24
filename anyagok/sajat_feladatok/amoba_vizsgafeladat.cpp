#include <iostream>
using namespace std;
#define DB 10
char jatek[DB][DB];
bool van_e_palya = false;
bool vege = false;
bool sor_ok, oszl_ok = false;
int sor, c_oszl;
int db = 0;
char oszl;

int alap_palya()
{
    // Alap állás eltárolása a DB sorhoz
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
    cout << "  ABCDEFGHIJ" << endl;
    for (int i = 1; i <= DB; i++)
    {
        if (i < DB)
            cout << '0' << i;
        else
            cout << i;
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
    jatek[sor][c_oszl] = 'X';
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
    do
    {
        cout << "Első játékos lépése:" << endl;
        beker();
        valaszt();
        allas();

        cout << "Második játékos lépése:" << endl;
        beker();
        valaszt();
        allas();

    } while (vege == true);
    return 0;
}