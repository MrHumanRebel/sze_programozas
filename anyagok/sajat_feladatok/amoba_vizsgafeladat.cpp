#include <iostream>
using namespace std;
string jatek[10];
bool van_e_palya = false;
bool vege = false;
bool sor_ok, oszl_ok = false;
int sor;
char oszl;

int alap_palya()
{
    // Alap állás eltárolása a 10 sorhoz
    cout << "  ABCDEFGHIJ" << endl;
    for (int i = 1; i <= 10; i++)
    {
        if (i <= 10)
        {
            jatek[i] = "..........";
        }
    }
    // Alap állás kíírása
    for (int i = 1; i <= 10; i++)
    {
        if (i < 10)
        {
            cout << "0" << i << jatek[i] << endl;
        }
        else
        {
            cout << i << jatek[i] << endl;
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
        if (sor >= 48 && sor <= 57)
            sor_ok = true;
        else
            cout << "Adjon meg 1-10 tartományba tartozó számot! ";

    } while (sor_ok == false);

    do
    {
        cout << "Oszlop: ";
        cin >> oszl;
        if (oszl >= 65 && oszl <= 90)
            oszl_ok = true;
        else
            cout << "Adjon meg A-J tartományba tartozó angol nagybetűt! ";

    } while (oszl_ok == false);
    return 0;
}

int main()
{

    cout << "Amőba játék\n"
         << endl;

    // Ha még nincs nincs pálya generáljuk egyet
    if (van_e_palya == false)
        alap_palya();

    cout << "Első játékos lépése:" << endl;
    beker();
    // Módosító fg

    cout << "Második játékos lépése:" << endl;
    beker();
    // Módosító fg

    do
    {

    } while (vege == true);
}