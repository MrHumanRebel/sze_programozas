#include <iostream>
using namespace std;

int main()
{
    double menu, szam, masikszam, hatvany, emel, hossz, novekmeny; //a double a hatványozás miatt kell, mivel kicsordul az int tartományából
    bool beker;
    beker = true;
    do
    {
        cout << "Válasszon menüpontot:\n"
             << "1-es gomb => Összeadás\n"
             << "2-es gomb => Szorzás\n"
             << "3-es gomb => Hatványozás\n"
             << "4-es gomb => Számtani sorozat\n"
             << endl;
        cin >> menu;
        if (menu >= 1 && menu < 5)
            beker = false;
        else
            cout << "Nem valós menüpont!\n\n"
                 << endl;
    } while (beker == true);

    if (menu == 1)
    {
        cout << "Adjon meg egy számot!" << endl;
        cin >> szam;
        cout << "Adjon meg egy másik számot!" << endl;
        cin >> masikszam;
        cout << "A két szám összege: " << szam + masikszam << endl;
    }
    else if (menu == 2)
    {
        cout << "Adjon meg egy számot!" << endl;
        cin >> szam;
        cout << "Adjon meg egy másik számot!" << endl;
        cin >> masikszam;
        cout << "A két szám szorzata: " << szam * masikszam << endl;
    }
    else if (menu == 3)
    {
        cout << "Adjon meg egy számot!" << endl;
        cin >> szam;
        cout << "Adja meg hányadik hatványra szeretné emelni!" << endl;
        cin >> emel;
        hatvany = szam;
        for (int i = 2; i <= emel; i++)
        {
            hatvany = hatvany * szam;
        }
        cout << "Az adott szám " << emel << "-edik hatványa: " << hatvany << endl;
    }
    else
    {
        cout << "Adja meg a kezdő számot!" << endl;
        cin >> szam;
        cout << "Adja meg a növekményt!" << endl;
        cin >> novekmeny;
        cout << "Adja meg a kívánt sorozat hosszát!" << endl;
        cin >> hossz;
        for (int i = 1; i <= hossz; i++)
        {
            cout << "A sorozat " << i << "-edik/adik eleme: " << szam << endl;
            szam = szam + novekmeny;
        }
    }

    return 0;
}