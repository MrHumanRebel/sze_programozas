#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

#define TELL cout <<
#define ASK cin >>
#define MAX 20
#define VEGEJEL "[vege]"
// 12345678901234567890 Ez itt egy nagyon hosszu szoveg, amit balra igazitva be kell tordelni a rendelkezesre allo, 20 karakter szeles helyre. [vege]

string beolv()
{
    cout << "Adja meg a szöveget \"[vege]\" végjelig!" << endl;
    string input;
    getline(cin, input);
    return input;
}

void kiir(string szoveg)
{
    int db = szoveg.length();
    int aktdb = db;
    TELL "Szöveg hossza:" << aktdb << endl;
    int aktkar = 0;
    while (aktdb > 0)
    {
        TELL '*';
        for (int i = 0; i < MAX; i++)
        {
            if (aktkar >= db)
                TELL ' ';
            else
                TELL szoveg[aktkar];
            aktkar++;
            aktdb--;
        }
        TELL '*' << endl;
    }
}

int main()
{
    string szoveg = beolv();
    int vegeHelye = szoveg.find(VEGEJEL);
    szoveg = szoveg.substr(0, vegeHelye - 1);
    kiir(szoveg);
    return 0;
}