#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int db = 1;
    double a, b, c, id, x1, x2 = 0;
    bool beker = true;
    do
    {
        cout << "Adja meg az a együtthatót!" << endl;
        cin >> a;
        cout << "Adja meg az b együtthatót!" << endl;
        cin >> b;
        cout << "Adja meg az c együtthatót!" << endl;
        cin >> c;
        if (a != 0 and b != 0 and c != 0)
        {
            id = (b * b) - (4 * a * c);
            if (id > 0)
            {
                cout << "Az egyenletnek vannak valós gyökei!" << endl;
                beker = false;
                x1 = ((b * -1) + (sqrt(id))) / (2 * a);
                x2 = ((b * -1) - (sqrt(id))) / (2 * a);
                cout << "x1 = " << x1 << endl;
                cout << "x2 = " << x2 << endl;
            }
            else if (id == 0)
            {
                cout << "Az egyenletnek van valós gyöke!" << endl;
                beker = false;
                x1 = ((b * -1) + (sqrt(id))) / (2 * a);
                cout << "x1 = " << x1 << endl;
            }
            else
            {
                cout << "Az egyenletnek nincs/nincsenek valós gyöke/gyökei, adjon meg új adatokat!" << endl;
                db++;
            }
        }
    } while (beker == true);

    return 0;
}