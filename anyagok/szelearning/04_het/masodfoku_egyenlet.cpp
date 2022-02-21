#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a, b, c, d, x1, x2 = 0;
    bool beker = true;
    do
    {
        cout << "Adja meg az \"a\" együtthatót!" << endl;
        cin >> a;
        cout << "Adja meg az \"b\" együtthatót!" << endl;
        cin >> b;
        cout << "Adja meg az \"c\" együtthatót!" << endl;
        cin >> c;
        if (a == 0)
        {
            cout << "Hiba!\nAz egyenlet nem másodfokú! (0-ás osztó!)";
            return 0;
        }
        else if ((b == 0) && (c == 0))
        {
            cout << "x1: 0";
            return 0;
        }
        else
        {
            d = (b * b) - (4 * a * c);
            if (d > 0)
            {
                cout << "Az egyenletnek vannak valós gyökei!" << endl;
                beker = false;
                x1 = ((b * -1) + (sqrt(d))) / (2 * a);
                x2 = ((b * -1) - (sqrt(d))) / (2 * a);
                cout << "x1 = " << x1 << endl;
                cout << "x2 = " << x2 << endl;
            }
            else if (d == 0)
            {
                cout << "Az egyenletnek van valós gyöke!" << endl;
                beker = false;
                x1 = ((b * -1) + (sqrt(d))) / (2 * a);
                cout << "x1 = " << x1 << endl;
            }
            else
            {
                cout << "Az egyenletnek nincs/nincsenek valós gyöke/gyökei, adjon meg új adatokat!" << endl;
            }
        }
    } while (beker == true);

    return 0;
}