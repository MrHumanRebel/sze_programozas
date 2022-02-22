#include <iostream>
using namespace std;
static int a, b;
#define DB 7

int kisnagyobb()
{
    if (a > b)
        return 1;
    if (b < a)
        return -1;
    else
        return 0;
}

int main()
{
    int szamok[DB];
    int akt;
    cout << "Adjon meg " << DB << " db számot!" << endl;
    for (int i = 1; i <= DB; i++)
    {
        cout << "Adja meg az " << i << ". számot!" << endl;
        cin >> akt;
        szamok[i] = akt;
    }
    for (int i = 1; i < DB; i++)
    {
        a = szamok[i];
        b = szamok[i + 1];
        if (kisnagyobb() == 1)

            cout << "\nAz alábbi elempárokra igaz, hogy az első nagyobb a másodiknál!\n"
                 << szamok[i] << "\t" << szamok[i + 1] << endl;
    }

    return 0;
}