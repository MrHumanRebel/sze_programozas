#include <iostream>
using namespace std;

int main()
{
    int db = 0;
    double akt = 0;
    cout << "Hány darab számot szeretne átlagolni?" << endl;
    cin >> db;
    double adatok[db];
    int szamlalo[db];
    for (int i = 1; i <= db; i++)
    {
        cout << "Adja meg az " << i << ". számot!" << endl;
        cin >> akt;
        adatok[i] = akt;
        szamlalo[i] = 0;
    }
    for (int j = 1; j <= db; j++)
    {
        for (int k = 1; k <= db; k++)
        {
            if (adatok[j] == adatok[k])
                szamlalo[j]++;
        }
        if (adatok[j - 1] != adatok[j])
            cout << "Ez a szám, \"" << adatok[j] << "\" ennyiszer szerepel a listában: " << szamlalo[j] << endl;
    }
}