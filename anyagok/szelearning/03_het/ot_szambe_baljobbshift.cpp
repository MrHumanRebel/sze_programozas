#include <iostream>
using namespace std;
#define DB 5

int main()
{
    double szamok[DB];
    double id;
    int akt;
    cout << "Adjon meg " << DB << " db számot!" << endl;
    for (int i = 1; i <= DB; i++)
    {
        cout << "Adja meg az " << i << ". számot!" << endl;
        cin >> akt;
        szamok[i] = akt;
    }

    do
    {
        cout << "Adja meg az mennyivel szeretne shiftelni!" << endl;
        cin >> akt;
        if (akt < 0) // shift balra
        {
            for (int i = 0; i >= akt; i--)
            {
                for (int j = 1; j <= DB; j++)
                {
                    id = szamok[j + 1];
                    szamok[j + 1] = szamok[j];
                    szamok[j] = id;
                }
            }
        }
        else // shift jobbra
        {
            for (int i = 0; i <= akt; i++)
            {
                for (int j = 2; j <= DB; j++)
                {
                    id = szamok[j];
                    szamok[j] = szamok[j - 1];
                    szamok[j - 1] = id;
                }
            }
        }

        for (int j = 1; j <= DB; j++)
        {
            cout << szamok[j] << "\t";
        }
        cout << endl;
    } while (akt != 0);

    return 0;
}