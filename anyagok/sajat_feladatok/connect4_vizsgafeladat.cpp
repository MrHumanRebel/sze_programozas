#include <iostream>
using namespace std;
#define SOR 6
#define OSZL 7
char tabla[SOR][OSZL];
bool van_e_palya = false;
bool oszl_ok = false;
char be;
int oszlszam;

int alappalya()
{
    for (int i = 0; i <= SOR; i++)
    {
        for (int j = 0; j <= OSZL; j++)
        {
            tabla[i][j] = '.';
        }
    }
    van_e_palya = true;
    return 0;
}

int beker()
{
    int db = 0;
    do
    {
        cout << "Oszlop: ";
        cin >> be;
        if (be >= 65 && be <= 90) // Betűk
            oszl_ok = true;
        else
            cout << "Adjon meg A-J tartományba tartozó angol nagybetűt! ";

    } while (oszl_ok == false);
    db = 0;
    for (int i = 65; i <= 90; i++)
    {
        if (be == i)
        {
            oszlszam = (be - (be - 1)) + db;
            cout << "Az oszlop sorszáma:\t" << oszlszam << endl;
        }
        else
            db = db + 1;
    }
}

int allas()
{
    cout << "  \t";
    for (int i = 65; i < (65 + OSZL); i++) // 65 => "A" betű ASCII
    {
        cout << char(i);
    }
    cout << endl;

    for (int i = 0; i < SOR; i++)
    {
        if (i <= SOR - 1)
            cout << '0' << i + 1 << "\t";
        else
            cout << i + 1 << "\t";
        for (int j = 0; j < OSZL; j++)
        {
            cout << tabla[i][j];
        }
        cout << endl;
    }

    return 0;
}

int main()
{
    if (van_e_palya == false)
        alappalya();
    cout << "Első játékos lépése:" << endl;
    beker();
    allas();
    cout << "Második játékos lépése:" << endl;
    beker();
    allas();
    return 0;
}