#include <iostream>
using namespace std;

int main()
{
    double akt, atl = 0;
    int db = 0;
    cout << "Hány darab számot szeretne átlagolni?" << endl;
    cin >> db;
    for (int i = 1; i <= db; i++)
    {
        cout << "Adja meg az " << i << ". számot!" << endl;
        cin >> akt;
        atl = atl + akt;
    }
    atl = atl / db;
    cout << "Az adatok átlaga: " << atl << endl;
    return 0;
}