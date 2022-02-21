#include <iostream>
using namespace std;

int main()
{
    string rszam;
    bool ok = false;
    do
    {
        cout << "Adjon meg egy magyar rendszámot!" << endl;
        cin >> rszam;
        int vizsgal = 0;

        // elválasztásokkal
        if (rszam.length() == 7)
        {
            for (int i = 0; i <= 2; i++)
            {
                if (rszam[i] >= 65 && rszam[i] <= 90)
                    vizsgal++;
            }

            for (int j = 4; j <= 6; j++)
            {
                if (rszam[j] >= 48 && rszam[j] <= 57)
                    vizsgal++;
            }

            if (rszam[3] == 45)
            {
                vizsgal++;
            }

            if (rszam[3] == 32)
            {
                vizsgal++;
            }

            if (vizsgal == 7)
            {
                ok = true;
                cout << "A megadott rendszám helyes!" << endl;
            }
            else
            {
                cout << "A megadott rendszám nem helyes!" << endl;
                vizsgal = 0;
                ok = false;
            }
        }

        // elválasztások nélkül
        if (rszam.length() == 6)
        {
            for (int i = 0; i <= 2; i++)
            {
                if (rszam[i] >= 65 && rszam[i] <= 90)
                    vizsgal++;
            }

            for (int j = 3; j <= 5; j++)
            {
                if (rszam[j] >= 48 && rszam[j] <= 57)
                    vizsgal++;
            }

            if (vizsgal == 6)
            {
                ok = true;
                cout << "A megadott rendszám helyes!" << endl;
            }
            else
            {
                cout << "A megadott rendszám nem helyes!" << endl;
                vizsgal = 0;
                ok = false;
            }
        }

    } while (ok == false);

    return 0;
}