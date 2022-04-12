#include <iostream>
using namespace std;

int main()
{
    double akt, a, b, c, d, e, f, g, h, x, y;
    double atl;
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    f = 0;
    g = 0;
    h = 0;
    x = 0;
    y = 0;

    for (int i = 1; i <= 10; i++)
    {
        cout << "Adjon meg egy számot!" << endl;
        cin >> akt;
        if (a == 0)
        {
            a = akt;
        }
        else if (b == 0)
        {
            b = akt;
        }
        else if (c == 0)
        {
            c = akt;
        }
        else if (d == 0)
        {
            d = akt;
        }

        else if (e == 0)
        {
            e = akt;
        }

        else if (f == 0)
        {
            f = akt;
        }

        else if (g == 0)
        {
            g = akt;
        }

        else if (h == 0)
        {
            h = akt;
        }

        else if (x == 0)
        {
            x = akt;
        }

        else
        {
            y = akt;
        }
    }
    atl = ((a + b + c + d + e + f + g + h + x + y) / 10);
    cout << "A tíz szám átlaga: " << atl << endl;
    return 0;
}