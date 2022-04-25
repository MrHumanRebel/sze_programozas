// 8/3 Mátrixok

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
        cout << "\n A(z)" << io << "mátrix " << i + 1 << ". eleme: " << szk[i];
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
            m[i][4] = '.'; // m[i][5]='\0';
        }                  // if
    }                      // külső for
}

int main()
{
    char mgm[SR][OP];
    char szerzok[SR][OP] = {
        {"Clarke, Arthur C."},
        {"Tolkien, John R. R."},
        {"Asimov, Isaac"},
        {"King, Stephen"}};
    cout << "\n A mátrix címe: " << szerzok
         << "\n A mátrix 1. eleme: "
         << szerzok[0] << endl; // szerzok[0]
    kiir(szerzok, mgm, 1);
    cout << endl;
    kiir(mgm, mgm, 0);
    cout << endl;
    return 0;
}