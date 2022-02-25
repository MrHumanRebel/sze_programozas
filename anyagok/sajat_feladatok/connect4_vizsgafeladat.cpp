#include <iostream>
using namespace std;
#define SOR 6
#define OSZL 7
char tabla[SOR][OSZL];
bool van_e_palya = false;
bool oszl_ok = false;
char be;
int oszlszam, jatekos;
int jatekos_1_db = SOR;
int jatekos_2_db = SOR;

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

int valaszt()
{
    if (jatekos == 1)
    {
        for (int i = SOR; i <= jatekos_1_db; i++)
        {
            if (tabla[jatekos_2_db-1][oszlszam - 1] == '.')
            {
                tabla[jatekos_2_db-1][oszlszam - 1] = 'X';
                jatekos_1_db--;
            }
        }
    }
    if (jatekos == 2)
    {
        for (int i = SOR; i <= jatekos_2_db; i++)
        {
            if (tabla[jatekos_2_db-1][oszlszam - 1] == '.')
            {
                tabla[jatekos_2_db-1][oszlszam - 1] = 'O';
                jatekos_2_db--;
            }
        }
    }
}

int main()
{
    bool vege = false;
    if (van_e_palya == false)
        alappalya();
    allas();
    do
    {
        cout << "Első játékos lépése:" << endl;
        jatekos = 1;
        beker();
        valaszt();
        allas();
        cout << "Második játékos lépése:" << endl;
        jatekos = 2;
        beker();
        valaszt();
        allas();
    } while (!vege);
    return 0;
}