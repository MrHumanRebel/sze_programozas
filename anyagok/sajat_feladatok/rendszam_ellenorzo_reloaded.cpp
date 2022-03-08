#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string rszam;
    bool ok = false;
    do
    {
        cout << "Adjon meg egy magyar rendszámot!" << endl;
        getline(cin, rszam); // cin.getline(INPUT),MAXIMUM MÉRET)
        int vizsgal = 0;

        // elválasztásokkal
        if (rszam.length() == 7)
        {
            for (int i = 0; i <= 2; i++)
            {
                rszam[i] = toupper(rszam[i]);
                if (rszam[i] >= 'A' && rszam[i] <= 'Z')
                    vizsgal++;
            }

            for (int j = 4; j <= 6; j++)
            {
                if (rszam[j] >= '0' && rszam[j] <= '9')
                    vizsgal++;
            }

            if (rszam[3] == '-')
            {
                vizsgal++;
            }

            if (rszam[3] == ' ')
            {
                vizsgal++;
            }

            if (vizsgal == 7)
            {
                rszam[3] = '-';
                ok = true;
                cout << "A megadott rendszám helyes!\n"
                     << "A rendszám hivatalos formátumban: " << rszam << endl;
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
                rszam[i] = toupper(rszam[i]);
                if (rszam[i] >= 'A' && rszam[i] <= 'Z')
                    vizsgal++;
            }

            for (int j = 3; j <= 5; j++)
            {
                if (rszam[j] >= '0' && rszam[j] <= '9')
                    vizsgal++;
            }

            if (vizsgal == 6)
            {
                for (long unsigned int i = 5; i >= 3; i--)
                {
                    rszam[i + 1] = rszam[i];
                }
                rszam[3] = '-';
                ok = true;
                cout << "A megadott rendszám helyes!\n"
                     << "A rendszám hivatalos formátumban: " << rszam << rszam[6] << endl;
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