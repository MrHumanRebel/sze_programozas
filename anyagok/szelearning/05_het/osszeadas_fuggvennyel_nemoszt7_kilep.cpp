#include <iostream>
using namespace std;
static int a, b, sum;

int summa()
{
    sum = a + b;
    return sum;
}

int main()
{
    int osszeg;
    bool ok = true;
    do
    {
        cout << "Adja meg a számot amihez hozzá szeretne adni!" << endl;
        cin >> a;
        cout << "Adja meg a számot amit hozzá szeretne adni az előzőhöz!" << endl;
        cin >> b;
        osszeg = summa();
        cout << "A két szám összege: " << osszeg << endl;
        if (osszeg % 7 != 0)
        {
            ok = false;
        }

    } while (ok);
    return 0;
}
