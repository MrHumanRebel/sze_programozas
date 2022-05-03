#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

#define TELL cout <<
#define ASK cin >>
#define MAX 20
#define VEGEJEL "[vege]"
// Ez itt egy nagyon hosszu szoveg, amit balra igazitva be kell tordelni a rendelkezesre allo, 20 karakter szeles helyre. [vege]

string beolv()
{
    cout << "Adja meg a szöveget \"[vege]\" végjelig!" << endl;
    string input;
    getline(cin, input);
    return input;
}

void oszlopir()
{
    int ciklus = 0;
    TELL '*';
    while (ciklus != 2)
    {
        for (int i = 0; i <= MAX / 2 - 1; i++)
        {
            TELL i;
        }
        ciklus++;
    }
    TELL '*' << endl;
}

void kiir(string szoveg)
{
    int db = szoveg.length();
    string akt = "\0";
    int szamlalo = 0;
    string sorok[MAX];
    for (int i = 0; i < MAX; i++)
    {
        sorok[i] = "\0";
    }
    int j = 0;
    for (int i = 0; i < db; i++)
    {
        if (szoveg[i] != ' ')
        {
            akt += szoveg[i];
            szamlalo++;
            if (szamlalo >= MAX)
            {
                szamlalo = 0;
                j++;
            }
        }
        else
        {
            sorok[j] = sorok[j] + akt + ' ';
            szamlalo++;
            akt = "\0";
        }
    }

    oszlopir();
    for (int i = 0; i <= j; i++)
    {
        TELL '*' << sorok[i];
        if (sorok[i].length() < MAX)
            for (size_t k = 0; k < MAX - sorok[i].length(); k++)
            {
                TELL ' ';
            }
        TELL '*' << endl;
    }
    oszlopir();
}

int main()
{
    string szoveg = beolv();
    int vegeHelye = szoveg.find(VEGEJEL);
    szoveg = szoveg.substr(0, vegeHelye - 1);
    kiir(szoveg);
    return 0;
}