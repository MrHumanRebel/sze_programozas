// 8/4 Mátrixok kezelése mutatókkal.
//  Ez, a mutatóra mutató mutató, avagy a mutató tömb.

#include <iostream>

#define SR 4
#define OP 20

using namespace std;

void kiir(const char szk[][OP], char m[][OP], bool mit)
{
    int j;
    char t;
    string io;
    if (mit)
        io = " alap ";
    else
        io = " monogram ";
    for (int i = 0; i < SR; i++)
    {
        cout << "\n A(z)" << io << "mátrix " << i + 1 << ". eleme: "
             << szk[i];
        if (mit)
        {
            m[i][0] = szk[i][0];
            m[i][1] = '.';
            m[i][2] = ' ';
            t = '!';
            for (j = 0; t != ' '; j++)
            {
                t = szk[i][j];
            }
            m[i][3] = szk[i][j];
            m[i][4] = '.';
            m[i][5] = '\0';
        }
    }
}

int main()
{
    char mgm[SR][OP];
    char szerzok[SR][OP] = {
        {"Clarke, Arthur C."},
        {"Tolkien, John R. R."},
        {"Asimov, Isaac"},
        {"King, Stephen"}};
    char *p[SR];
    for (int i = 0; i < SR; i++)
    {
        cout << "\n A(z) " << i + 1 << ". elem címe: "
             << &szerzok[i] << endl;
        p[i] = szerzok[i];
        cout << " A(z) " << i + 1 << ". elem mutatott címe: "
             << /*(void*)*/ p[i] << endl;
    }
    cout << "\n A mátrix címe: " << szerzok
         << "\n A mátrix 1. eleme: " << (*szerzok) << endl;
    kiir(szerzok, mgm, 1);
    cout << endl;
    kiir(mgm, mgm, 0);
    cout << endl;
    return 0;
}
/***********************/
/* A (void*) elsődlegesen arra használatos, hogy mutatókat adjunk át olyan
    függvényeknek/objektumoknak, amelyek nem feltételeznek semmit
    az objektumok típusáról, valamint arra, hogy a függvények/objektumok
    nem típusos objektumokat adjanak vissza.
    Ahhoz, hogy ilyen objektumokat használjunk, explicit típuskonverziót kell
    alkalmaznunk.
    Azok a függvények/objektumok, amelyek (void*) típusú mutatókat használnak,
    jellemzően a rendszer legalsó szintjén helyezkednek el,
    ahol az igazi hardver-erőforrásokat kezelik. */