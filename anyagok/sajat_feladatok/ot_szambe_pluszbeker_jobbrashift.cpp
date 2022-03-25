#include <iostream>
using namespace std;
#define db 5
#define TELL cout <<
#define ASK cin >>

int main()
{
    double szamok[db * db];
    int pluszdb = db;
    double akt;
    TELL "Adjon meg " << db << " db számot!" << endl;
    for (int k = 1; k <= db; k++)
    {
        TELL "Adja meg az " << k << ". számot!" << endl;
        ASK akt;
        szamok[k] = akt;
    }
    do
    {
        TELL "\nAdja meg a számot amit be szeretne illeszteni!" << endl;
        ASK akt;
        // if (akt >= 0)
        //{
        pluszdb++;
        for (int i = pluszdb; i > 1; i--)
        {
            szamok[i + 1] = szamok[i];
        }
        szamok[0] = akt;
        //}

        /*else // BETA VERSION NOT WORKING
        {
            pluszdb++;
            for (int i = pluszdb; i > 1; i--)
            {
                szamok[i - 1] = szamok[i];
            }
            szamok[db] = akt;
        }
        */

        //ÚJ ADATOK KIÍRÁSA
        for (int j = 0; j <= pluszdb; j++)
        {
            TELL szamok[j] << "\t";
        }
    } while (akt != 0);

    return 0;
}