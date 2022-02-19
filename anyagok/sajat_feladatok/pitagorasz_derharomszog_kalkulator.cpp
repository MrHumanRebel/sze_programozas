#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    int menu;
    int db = 1;
    double a, b, c, x, y, max = 0;
    double rad, alfa, beta, gamma, id = 0;
    bool beker, menuker = true;
    cout << "Saját vagy randomizált adatokkal szeretné használni a háromszög kalkulátort?\n"
         << "___________________________________________________________________________________\n\n"
         << "Randomizáláshoz nyomja meg az 1-es gombot!\n"
         << "Adatmegadáshoz nyomja meg a 2-es gombot!" << endl;
    while (menuker)
    {
        cin >> menu;
        if (menu >= 1 && menu < 3)
            menuker = false;
        else
            cout << "Nem valós menüpont!\n";
    }

    if (menu == 1)
    {
        do
        {
            a = rand() % 160 + 1;
            max = a;
            b = rand() % 120 + 1;
            if (b > max)
                max = b;
            if (a > 0 and b > 0)
            {
                c = sqrt((a * a) + (b * b));
                if (c > max)
                    max = c;
                if (c < (a + b) && a < (b + c) && b < (a + c))
                    beker = false;
                else
                {
                    db++;
                    beker = true;
                }
            }
        } while (beker == true);
        cout << "A randomizátor " << db << "-szer futott le mire megszerkeszthető derékszögű háromszög állt elő!\n"
             << endl;
    }

    if (menu == 2)
    {
        cout << "Adja meg a derékszögű háromszög két oldalát!\n"
             << "_________________________________\n"
             << endl;
        do
        {
            cout << "Adja meg a derékszögű háromszög egyik oldalát!" << endl;
            cin >> a;
            max = a;
            cout << "Adja meg a derékszögű háromszög másik oldalát!" << endl;
            cin >> b;
            if (b > max)
                max = b;
            if (a > 0 and b > 0)
            {
                c = sqrt((a * a) + (b * b));
                if (c > max)
                    max = c;
                if (c < (a + b) && a < (b + c) && b < (a + c))
                    beker = false;
                else
                {
                    cout << "Ez a háromszög nem derékszögű, adjon meg új adatokat!" << endl;
                    db++;
                    beker = true;
                }
            }
        } while (beker == true);
        cout << "Az adatok az " << db << ". alkalommal tették lehetővé derékszögű háromszög megszerkesztését!\n"
             << endl;
    }

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

    cout << "Ez a derékszögű háromszög megszerkeszthető!\n"
         << endl;

    cout << "A háromszög \"a\" oldalának hossza: " << a << "\n"
         << "A háromszög \"b\" oldalának hossza: " << b << "\n"
         << "A háromszög \"c\" oldalának hossza: " << c << "\n"
         << "A háromszög leghosszabb oldalának hossza: " << max << "\n"
         << endl;

    // Koszinusz tétellel leghosszabb oldalhoz tartozó szög kiszámítása
    id = ((x * x) + (y * y) - (max * max)) / (2 * x * y);
    gamma = acos(id);

    // Szinusz tétel
    id = (x / max) * sin(gamma);
    alfa = (asin(id));

    // Szinusz tétel
    id = y / max * sin(gamma);
    beta = (asin(id));

    // Radián átváltás fokba
    rad = 57.2957795131; // 180.0 / 3.141592653589793238463
    alfa = alfa * rad;
    beta = beta * rad;
    gamma = gamma * rad;

    cout << "Az \"A\" csúcshoz tartózó szöge: " << alfa << "\n A \"B\" csúcshoz tartózó szöge: " << beta << "\n A \"C\" csúcshoz tartózó szöge: " << gamma << "\n"
         << "A három szög összege ellenőrzésképpen: " << alfa + beta + gamma << "\n"
         << endl;

    return 0;
}