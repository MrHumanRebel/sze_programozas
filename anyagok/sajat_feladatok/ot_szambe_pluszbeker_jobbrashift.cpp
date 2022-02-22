#include <iostream>
using namespace std;
#define db 5

int main()
{
    double szamok[db * db];
    int pluszdb = db;
    double akt;
    cout << "Adjon meg " << db << " db számot!" << endl;
    for (int k = 1; k <= db; k++)
    {
        cout << "Adja meg az " << k << ". számot!" << endl;
        cin >> akt;
        szamok[k] = akt;
    }
    do
    {
        cout << "\nAdja meg a számot amit be szeretne illeszteni!" << endl;
        cin >> akt;
        // if (akt >= 0)
        //{
        pluszdb++;
        for (int i = pluszdb; i > 1; i--)
        {
            szamok[i + 1] = szamok[i];
        }
        szamok[0] = akt;
        //}

        /*else // BETA VERSION NOT WORKING
        {
            pluszdb++;
            for (int i = pluszdb; i > 1; i--)
            {
                szamok[i - 1] = szamok[i];
            }
            szamok[db] = akt;
        }
        */

        //ÚJ ADATOK KIÍRÁSA
        for (int j = 0; j <= pluszdb; j++)
        {
            cout << szamok[j] << "\t";
        }
    } while (akt != 0);

    return 0;
}