/***************************************************************************************/
// 8/5 Mátrixok kezelése dinamikusan

#include <iostream>

#define SR 4
#define OP 20

using namespace std;

string *feltolt(const char (*a_b)[OP])
{
    string *szk = new string[SR];
    for (int i = 0; i < SR; i++)
    {
        szk[i] = a_b[i];
    }
    return szk;
}

string *kiir(const string *szk, string *m, bool mit)
{
    int j;
    char t;
    string io /*, df="12345"*/;
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
            // m[i]=df; // ??????
            m[i][0] = szk[i][0];
            m[i][1] = '.';
            m[i][2] = ' ';
            t = '!';
            for (j = 0; t != ' '; j++)
            {
                t = szk[i][j];
            }
            m[i][3] = szk[i][j];
            m[i][4] = '.'; /*m[i][5]='\0';*/
        }
    }
    return m;
}

int main()
{
    char adat_b[SR][OP] = {
        {"Clarke, Arthur C."},
        {"Tolkien, John R. R."},
        {"Asimov, Isaac"},
        {"King, Stephen"}};
    string *mgm = new string[SR];
    string *szerzok;
    szerzok = feltolt(adat_b);
    for (int i = 0; i < SR; i++)
    {
        cout << "\n A(z) " << i + 1 << ". elem címe: "
             << &szerzok[i] << endl;
        cout << " A(z) " << i + 1 << ". elem tartalma: "
             << szerzok[i] << endl;
    }
    cout << "\n A mátrix címe: " << szerzok
         << "\n A mátrix 1. eleme: " << (*szerzok) << endl;
    mgm = kiir(szerzok, mgm, 1);
    cout << endl;
    kiir(mgm, mgm, 0);
    cout << endl;
    delete[] mgm;
    delete[] szerzok;
    return 0;
}
