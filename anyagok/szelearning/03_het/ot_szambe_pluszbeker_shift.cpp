#include <iostream>
using namespace std;

int main()
{
    int db = 5;
    double szamok[db * db];
    int pluszdb = db;
    double akt, id;
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
        if (akt >= 0)
        {
            pluszdb++;
            for (int i = pluszdb; i >= 1; i--)
            {
                szamok[i + 1] = szamok[i];
            }
            szamok[1] = akt;
        }

        else // BETA VERSION
        {
            pluszdb++;
            for (int i = 1; i <= pluszdb; i++)
            {
                id = szamok[i - 1];
                szamok[i - 1] = szamok[i];
                szamok[i] = id;
            }
            szamok[1] = akt;
        }

        for (int j = 1; j <= pluszdb; j++)
        {
            cout << szamok[j] << "\t";
        }
    } while (akt != 0);

    return 0;
}