#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a, b, c, max = 0;
    double alfa, beta, gamma, id, id2 = 0;
    bool beker = true;
    cout << "Adja meg a háromszög oldalait!\n\n"
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

    id = ((a * a) + (b * b) - (c * c)) / (2 * a * b);
    gamma = 100 * acos(id);

    id = a / c;

    cout << id;
    cout << "\n";

    id2 = sin(gamma);

    cout << id2;
    cout << "\n";

    alfa = 100 * sin(id * id2);

    cout << "Az A csúcshoz tartózó szög: " << alfa << "\t A B csúcshoz tartózó szög: " << gamma << endl;

    return 0;
}