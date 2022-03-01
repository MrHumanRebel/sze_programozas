#include <iostream>
using namespace std;

// 55*3355#29999#334#337777#99996665553#2#333881 1 1

string uzenet = "";
string kod;
char kodtabla[11][5];

void decode()
{
    int szamlalo = 0;
    int akt;
    for (long unsigned int i = 0; i <= kod.length(); i++)
    {
        switch (kod[i])
        {
        case ('1'):
            akt = 0;
            break;
        case ('2'):
            akt = 1;
            break;
        case ('3'):
            akt = 2;
            break;
        case ('4'):
            akt = 3;
            break;
        case ('5'):
            akt = 4;
            break;
        case ('6'):
            akt = 5;
            break;
        case ('7'):
            akt = 6;
            break;
        case ('8'):
            akt = 7;
            break;
        case ('9'):
            akt = 8;
            break;
        case ('*'):
            akt = 9;
            break;
        case ('0'):
            akt = 10;
            break;
        case ('#'):
            akt = 11;
            break;
        }

        if (kod[i] == kod[i + 1])
        {
            szamlalo++;
        }
        else
        {
            // cout << kodtabla[akt][szamlalo];
            uzenet = uzenet + kodtabla[akt][szamlalo];
            szamlalo = 0;
        }
    }
    if ((kod[0] != kod[1] && kod[1] == '*') or (kod[0] == kod[1] && kod[2] == '*') or (kod[0] == kod[1] == kod[2] && kod[3] == '*'))
    {
        akt = uzenet[0];
        akt = akt - 32;
        uzenet[0] = char(akt);
    }
}
void kodtablazat()
{
    string aktstring;
    for (int i = 0; i <= 11; i++)
    {
        if (i == 0)
            aktstring = ".,-?!1";
        if (i == 1)
            aktstring = "abc2";
        if (i == 2)
            aktstring = "def3";
        if (i == 3)
            aktstring = "ghi4";
        if (i == 4)
            aktstring = "jkl5";
        if (i == 5)
            aktstring = "mno6";
        if (i == 6)
            aktstring = "pqrs7";
        if (i == 7)
            aktstring = "tuv8";
        if (i == 8)
            aktstring = "wxyz9";
        if (i == 9)
            aktstring = "\0";
        if (i == 10)
            aktstring = "+0";
        if (i == 11)
            aktstring = " #";
        for (int j = 0; j <= aktstring.length(); j++)
        {
            kodtabla[i][j] = aktstring[j];
        }
    }

    decode();
}

int main()
{
    cout << "Adja meg a dekódolandó kódsorozatot!" << endl;
    cin >> kod;
    kodtablazat();
    cout << uzenet;

    return 0;
}
