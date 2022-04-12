// Headers
#include <iostream>
using namespace std;
#define TELL cout <<
#define ASK cin >>

// Szám bekerő függvény
int szamBeker(int MIN, int MAX)
{
    bool szambe_ok = false;
    int akt;
    do
    {
        TELL "Adja meg a számot!" << endl;
        ASK akt;
        if (akt >= MIN && akt <= MAX)
            szambe_ok = true;
        else
            TELL "Adjon meg " << MIN << "-től " << MAX << "-ig tartományba tartozó számot!" << endl;
    } while (szambe_ok == false);
    return akt;
}
int main()
{
    // Szám bekerő függvény tesztelő
    int MAX = 10;
    int MIN = 1;
    int szam_akt = szamBeker(MIN, MAX);
    TELL szam_akt << endl;
    return 0;
}