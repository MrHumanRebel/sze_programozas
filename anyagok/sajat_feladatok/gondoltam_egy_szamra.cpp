#include <iostream>
using namespace std;
#define TELL cout <<
#define ASK cin >>

int main()
{
    int szam, beker, x = 0;
    bool ok = false;
    bool jatszik = true;
    do
    {
        TELL "Adja meg a számtartományt!" << endl;
        ASK x;
        szam = rand() % x + 1;
        TELL "Gondoltam egy számra...\tTalálja ki ezt a számot!" << endl;
        while (!ok)
        {
            ASK beker;
            if (beker == szam)
            {
                TELL "Ön sikeresen kitalálta a számot amire gondoltam!" << endl;
                ok = true;
            }
            else if (beker > szam)
                TELL "Nem erre a számra gondoltam! Túl nagy szám! \nPróbálja újra! " << endl;
            else
                TELL "Nem erre a számra gondoltam! Túl kicsi szám!\nPróbálja újra! " << endl;
        }
        TELL "Szeretné folytatni a játékot?\n 1-es gomb => IGEN \n 2-es gomb => NEM" << endl;
        ASK beker;
        if (beker == 1)
        {
            jatszik = true;
            ok = false;
        }
        else if (beker == 2)
        {
            TELL "Program vége..." << endl;
            jatszik = false;
        }
        else
            TELL "Nem valós menüpont!" << endl;
    } while (jatszik);
    return 0;
}