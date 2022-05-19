#include <iostream>
#include <climits> // INT_MAX, INT_MIN
using namespace std;
#define TOMBMAX 10

int beker(int be_tb[], int *min, int *max)
{
    int szum = 0;
    int aktszam;
    int i = 0;
    bool ok = false;
    do
    {
        ok = false;
        if (i == 0) // Nulla
        {
            do
            {
                cin >> aktszam;
                if (aktszam == 0)
                    ok = true;

            } while (ok == false);
            be_tb[i] = aktszam;
        }
        else if (i % 2 == 0) // Páros
        {
            do
            {
                cin >> aktszam;
                if (aktszam % 2 == 0)
                    ok = true;

            } while (ok == false);
            be_tb[i] = aktszam;
            szum += aktszam;
            if (aktszam > *max)
                *max = aktszam;
        }
        else if (i % 2 != 0) // Páratlan
        {
            do
            {
                cin >> aktszam;
                if (aktszam % 2 != 0)
                    ok = true;

            } while (ok == false);
            be_tb[i] = aktszam;
            szum += aktszam;
            if (aktszam < *min)
                *min = aktszam;
        }
        i++;
    } while (i < 10);
    return szum;
}

void kiir(int szum, int min, int max)
{
    cout << "Szum:" << szum << "\nPrtln min:" << min << "\nPrs max:" << max;
}

int main()
{
    int min = INT_MAX;
    int max INT_MIN;

    int tomb[TOMBMAX];
    int szum = beker(tomb, &min, &max);
    kiir(szum, min, max);

    return 0;
}