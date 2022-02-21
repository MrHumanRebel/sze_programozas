#include <iostream>
using namespace std;

int main()
{
    int db = 0;
    double akt = 0;
    cout << "Hány darab számot szeretne tárolni?" << endl;
    cin >> db;
    double adatok[db];
    int szamlalo[db];
    int hasonlit[db];
    for (int i = 1; i <= db; i++)
    {
        cout << "Adja meg az " << i << ". számot!" << endl;
        cin >> akt;
        adatok[i] = akt;
        szamlalo[i] = 0;
        hasonlit[i] = 0;
    }
    for (int j = 1; j <= db; j++)
    {
        cout << "Adja meg az ellenőrizni kívánt " << j << ". számot!" << endl;
        cin >> akt;
        for (int k = 1; k <= db; k++)
        {
            if (akt == adatok[k])
                hasonlit[j]++;
        }
        if (adatok[j - 1] != adatok[j] && hasonlit[j] != 0)
            cout << "Ez a szám, \"" << akt << "\" ennyiszer szerepel az eredeti listában: " << hasonlit[j] << endl;
        else
            cout << "Ez a szám nem szerepel a listában!\n"
                 << endl;
    }

    cout << "\n\nTömb statisztika:"
         << endl;

    for (int j = 1; j <= db; j++)
    {
        for (int k = 1; k <= db; k++)
        {
            if (adatok[j] == adatok[k])
                szamlalo[j]++;
        }
        if (adatok[j - 1] != adatok[j])
            cout << "Ez a szám, \"" << adatok[j] << "\" ennyiszer szerepel az eredeti listában: " << szamlalo[j] << endl;
    }
}