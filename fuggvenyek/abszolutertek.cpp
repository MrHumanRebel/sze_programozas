#include <iostream>
using namespace std;

int abszolut(int szam)
{
    return szam < 0. ? -szam : szam;
}

int main()
{
    int szam;
    cout << "Szam:";
    cin >> szam;
    cout << "Abszoluterteke:" << abszolut(szam) << endl;
    return 0;
}