#include <iostream>
using namespace std;

int main()
{
    int szam, beker, x = 0;
    bool ok = false;
    cout << "Adja meg a számtartományt!" << endl;
    cin >> x;
    szam = rand() % x + 1;
    cout << "Gondoltam egy számra...\t Találja ki ezt a számot!" << endl;
    while (!ok)
    {
        cin >> beker;
        if (beker == szam)
        {
            cout << "Ön sikeresen kitalálta a számot amire gondoltam!\n Program vége... " << endl;
            ok = true;
        }
        else
            cout << "Nem erre a számra gondoltam!\n Próbálja újra! " << endl;
    }
    return 0;
}