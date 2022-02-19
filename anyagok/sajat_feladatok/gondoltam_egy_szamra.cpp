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
        cout << "Gondoltam egy számra...\tTalálja ki ezt a számot!" << endl;
        while (!ok)
        {
            cin >> beker;
            if (beker == szam)
            {
                cout << "Ön sikeresen kitalálta a számot amire gondoltam!" << endl;
                ok = true;
            }
            else if (beker > szam)
                cout << "Nem erre a számra gondoltam! Túl nagy szám! \nPróbálja újra! " << endl;
            else
                cout << "Nem erre a számra gondoltam! Túl kicsi szám!\nPróbálja újra! " << endl;
        }
        cout << "Szeretné folytatni a játékot?\n 1-es gomb => IGEN \n 2-es gomb => NEM" << endl;
        cin >> beker;
        if (beker == 1)
        {
            jatszik = true;
            ok = false;
        }
        else if (beker == 2)
        {
            cout << "Program vége..." << endl;
            jatszik = false;
        }
        else
            cout << "Nem valós menüpont!" << endl;
    } while (jatszik);
    return 0;
}