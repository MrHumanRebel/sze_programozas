#include <iostream>
#include <cmath>
using namespace std;

#define TELL cout <<
#define ASK cin >>

int main()
{
    int menu;
    int db = 1;
    double a, b, c, x, y, max = 0;
    double rad, alfa, beta, gamma, kerulet, terulet, bsugar, ksugar, batmero, katmero, m_a, m_b, m_c, id = 0;
    bool beker, menuker = true;

    TELL "Saját vagy randomizált adatokkal szeretné használni a háromszög kalkulátort?\n"
         << "___________________________________________________________________________________\n\n"
         << "Randomizáláshoz nyomja meg az 1-es gombot!\n"
         << "Adatmegadáshoz nyomja meg a 2-es gombot!" << endl;
    while (menuker)
    {
        ASK menu;
        if (menu >= 1 && menu < 3)
            menuker = false;
        else
            TELL "Nem valós menüpont!\n";
    }

    if (menu == 1)
    {
        do
        {
            a = rand() % 160 + 1;
            max = a;
            b = rand() % 140 + 1;
            if (b > max)
                max = b;
            c = rand() % 120 + 1;
            if (c > max)
                max = c;
            if (a > 0 and b > 0 and c > 0)
            {
                if (c < (a + b) && a < (b + c) && b < (a + c))
                {
                    TELL "A randomizált háromszög megszerkeszthető!\n"
                         << "Már számoljuk is a jellemzőit...\n"
                         << endl;
                    beker = false;
                }
                else
                {
                    db++;
                    beker = true;
                }
            }
        } while (beker == true);
        TELL "A randomizátor " << db << "-szer futott le mire megszerkeszthető adatok háromszög állt elő!\n"
             << endl;
    }

    if (menu == 2)
    {
        TELL "Adja meg a háromszög oldalait!\n"
             << "_________________________________\n"
             << endl;
        do
        {
            TELL "Adja meg a háromszög első oldalát!" << endl;
            ASK a;
            max = a;
            TELL "Adja meg a háromszög második oldalát!" << endl;
            ASK b;
            if (b > max)
                max = b;
            TELL "Adja meg a háromszög harmadik oldalát!" << endl;
            ASK c;
            if (c > max)
                max = c;
            if (a > 0 and b > 0 and c > 0)
            {
                if (c < (a + b) && a < (b + c) && b < (a + c))
                {
                    TELL "Ez a háromszög megszerkeszthető!\n"
                         << "Már számoljuk is a jellemzőit...\n"
                         << endl;
                    beker = false;
                }
                else
                {
                    TELL "Ez a háromszög nem szerkeszthető meg, adjon meg új adatokat!" << endl;
                    db++;
                    beker = true;
                }
            }
        } while (beker == true);
        TELL "Az adatok az " << db << ". alkalommal tették lehetővé háromszög megszerkesztését!\n"
             << endl;
    }

    TELL "A háromszög \"a\" oldalának hossza: " << a << "\n"
         << "A háromszög \"b\" oldalának hossza: " << b << "\n"
         << "A háromszög \"c\" oldalának hossza: " << c << "\n"
         << "A háromszög leghosszabb oldalának hossza: " << max << "\n"
         << endl;

    //Új adatok a leghosszabb oldal alapján a koszinusz tételhez
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

    TELL "Az \"A\" csúcshoz tartózó szöge: " << alfa << "\n A \"B\" csúcshoz tartózó szöge: " << beta << "\n A \"C\" csúcshoz tartózó szöge: " << gamma << "\n"
         << "A három szög összege ellenőrzésképpen: " << alfa + beta + gamma << "\n"
         << endl;

    // Kerület kiszámítása
    kerulet = a + b + c;
    TELL "A háromszög kerülete: " << kerulet << "\n"
         << endl;

    // Magasságvonalak kiszámítása
    m_a = abs(b * sin(gamma));
    m_b = abs(c * sin(alfa));
    m_c = abs(a * sin(beta));

    TELL "Az \"a\" oldalhoz tartózó magassága: " << m_a << "\n A \"b\" oldalhoz tartózó magassága: " << m_b << "\n A \"c\" oldalhoz tartózó magassága: " << m_c << "\n"
         << endl;

    // Terület kiszámítása
    terulet = (b * m_b) / 2;
    TELL "A háromszög területe: " << terulet << "\n"
         << endl;

    // Belső kör sugár és átmérő kiszámítása
    bsugar = (2 * terulet) / (a + b + c);
    batmero = bsugar * 2;
    TELL "A háromszöghöz tartozó belső kör sugara: " << bsugar << "\n"
         << "A háromszöghöz tartozó belső kör átmérője: " << batmero << "\n"
         << endl;

    // Külső kör sugár és átmérő kiszámítása
    ksugar = (a * b * c) / (4 * terulet);
    katmero = 2 * ksugar;
    TELL "A háromszöghöz tartozó külső kör sugara: " << ksugar << "\n"
         << "A háromszöghöz tartozó külső kör átmérője: " << katmero << "\n"
         << endl;

    return 0;
}