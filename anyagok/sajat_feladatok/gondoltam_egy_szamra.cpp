#include <iostream>
using namespace std;

int main()
{
    int szam, beker, x = 0;
    bool ok = false;
    bool jatszik = true;
    do
    {
        cout << "Adja meg a számtartományt!" << endl;
        cin >> x;
        szam = rand() % x + 1;
        cout << "Gondoltam egy számra...\t Találja ki ezt a számot!" << endl;
        while (!ok)
        {
            cin >> beker;
            if (beker == szam)
            {
                cout << "Ön sikeresen kitalálta a számot amire gondoltam!" << endl;
                ok = true;
            }
            else
                cout << "Nem erre a számra gondoltam!\n Próbálja újra! " << endl;
        }
        cout << "Szeretné folytatni a játékot?\n 1-es gomb => IGEN \n 2-es gomb => NEM" << endl;
        cin >> beker;
        if (beker == 1)
            jatszik = true;
        else if (beker == 2)
            jatszik = false;
        else
            cout << "Nem valós menüpont!" << endl;
    } while (jatszik);
    return 0;
}