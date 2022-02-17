#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a, b, c, x, y, max = 0;
    double rad, alfa, beta, gamma, id, id2 = 0;
    bool beker = true;
    cout << "Adja meg a háromszög oldalait!\n"
         << "_________________________________\n"
         << endl;
    do
    {
        cout << "Adja meg a háromszög első oldalát!" << endl;
        cin >> a;
        max = a;
        cout << "Adja meg a háromszög második oldalát!" << endl;
        cin >> b;
        if (b > a)
            max = b;
        cout << "Adja meg a háromszög harmadik oldalát!" << endl;
        cin >> c;
        if (c > a or c > b)
            max = c;
        if (a > 0 and b > 0 and c > 0)
        {
            if (c < (a + b) && a < (b + c) && b < (a + c))
            {
                cout << "Ez a háromszög megszerkeszthető!\n"
                     << "Már számoljuk is a jellemzőit...\n"
                     << endl;
                beker = false;
            }
            else
                cout << "Ez a háromszög nem szerkeszthető meg, adjon meg új adatokat!" << endl;
        }
    } while (beker == true);

    cout << "A háromszög leghosszabb oldalának hossza: " << max << "\n"
         << endl;

    if (c == max)
    {
        x = a;
        y = b;
    }
    if (b == max)
    {
        x = a;
        y = c;
    }
    if (a == max)
    {
        x = b;
        y = c;
    }

    // Koszinusz tétellel leghosszabb oldalhoz tartozó szög kiszámítása
    id = ((x * x) + (y * y) - (max * max)) / (2 * x * y);
    gamma = acos(id);

    id = (x / max) * sin(gamma);
    alfa = (asin(id));

    id = y / max;
    id2 = sin(gamma);
    beta = (asin(id * id2));

    // Radián átváltás fokba
    rad = (180.0 / 3.141592653589793238463);
    alfa = alfa * rad;
    beta = beta * rad;
    gamma = gamma * rad;

    cout << "Az A csúcshoz tartózó szög: " << alfa << "\t A B csúcshoz tartózó szög: " << beta << "\t A C csúcshoz tartózó szög: " << gamma << "\n"
         << "A három szög összege ellenőrzésképpen: " << alfa + beta + gamma << endl;

    return 0;
}