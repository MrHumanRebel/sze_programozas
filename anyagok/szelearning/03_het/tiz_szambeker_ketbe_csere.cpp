#include <iostream>
using namespace std;

int main()
{
    int db = 10;
    int x, y;
    double szamok[db];
    double akt;
    cout << "Adjon meg " << db << " számot!" << endl;
    for (int k = 1; k <= db; k++)
    {
        cout << "Adja meg az " << k << ". számot!" << endl;
        cin >> akt;
        szamok[k] = akt;
    }
    cout << "Adja meg a megcserélni kívánt elemek sorszámát!" << endl;
    cout << "Első elem sorszáma: " << endl;
    cin >> x;
    cout << "Második elem sorszáma: " << endl;
    cin >> y;
    cout << "\n " << endl;
    for (int i = 1; i <= db; i++)
    {
        if (i == x)
        {
            for (int j = 1; j <= db; j++)
            {
                if (j == y)
                {
                    akt = szamok[i];
                    szamok[i] = szamok[j];
                    szamok[j] = akt;
                }
            }
        }
        cout << "A megcserélt " << i << ". szám:"
             << szamok[i] << endl;
    }
    return 0;
}