#include <iostream>
using namespace std;

long long hatvany(int alap, int kitevo)
{
    long long eredmeny;
    if (kitevo == 0)
        return 1;
    if (kitevo == 1)
        return alap;
    eredmeny = hatvany(alap, kitevo / 2);
    eredmeny *= eredmeny;

    if (kitevo % 2 == 1)
        eredmeny *= alap;
    return eredmeny;
}

int main()
{
    int szam, kitevo;
    long long eredmeny;
    cout << "Szam: ";
    cin >> szam;
    cout << "Kitevo: ";
    cin >> kitevo;
    eredmeny = hatvany(szam, kitevo);
    cout << "Eredmény: " << eredmeny << endl;
    if (eredmeny == 0)
        cout << "Hataron kivul!" << endl;
    return 0;
}
