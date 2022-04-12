#include <iostream>
using namespace std;

int main()
{
    int db = 0;
    double akt, atl = 0;
    cout << "Hány darab számot szeretne átlagolni?" << endl;
    cin >> db;
    double adatok[db];
    for (int i = 1; i <= db; i++)
    {
        cout << "Adja meg az " << i << ". számot!" << endl;
        cin >> akt;
        adatok[i] = akt;
        atl = atl + akt;
    }
    atl = atl / db;
    cout << "Az adatok átlaga: " << atl << "\n"
         << endl;
    for (int j = 1; j <= db; j++)
    {
        if (adatok[j] < atl)
            cout << "Az alábbi adat átlagon aluli: "
                 << adatok[j] << "\t\t"
                 << "Az adat megadási sorszáma: " << j << endl;
    }
    return 0;
}