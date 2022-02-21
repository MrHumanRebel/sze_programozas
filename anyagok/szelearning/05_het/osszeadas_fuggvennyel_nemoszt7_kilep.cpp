#include <iostream>
using namespace std;

int main()
{
    int elsoszam, masikszam, osszeg;
    bool ok = true;
    do
    {
        cout << "Adja meg a számot amihez hozzá szeretne adni!" << endl;
        cin >> elsoszam;
        cout << "Adja meg a számot amit hozzá szeretne adni az előzőhöz!" << endl;
        cin >> masikszam;
        // itt lesz a függvény hívás majd
        if (osszeg % 7 != 0)
        {
            ok = false;
        }

    } while (ok);
    return 0;
}