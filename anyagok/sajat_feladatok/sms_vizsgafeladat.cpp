#include <iostream>
using namespace std;

// 55*3355#29999#334#337777#99996665553#2#333881 1 1

string uzenet = "";
string kod;
char kodtabla[11][5];

string decode()
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
    return "";
}
string kodtablazat()
{

    // 1
    kodtabla[0][0] = '.';
    kodtabla[0][1] = ',';
    kodtabla[0][2] = '-';
    kodtabla[0][3] = '?';
    kodtabla[0][4] = '!';
    kodtabla[0][5] = '1';
    // 2
    kodtabla[1][0] = 'a';
    kodtabla[1][1] = 'b';
    kodtabla[1][2] = 'c';
    kodtabla[1][3] = '2';
    // 3
    kodtabla[2][0] = 'd';
    kodtabla[2][1] = 'e';
    kodtabla[2][2] = 'f';
    kodtabla[2][3] = '3';
    // 4
    kodtabla[3][0] = 'g';
    kodtabla[3][1] = 'h';
    kodtabla[3][2] = 'i';
    kodtabla[3][3] = '4';
    // 5
    kodtabla[4][0] = 'j';
    kodtabla[4][1] = 'k';
    kodtabla[4][2] = 'l';
    kodtabla[4][3] = '5';
    // 6
    kodtabla[5][0] = 'm';
    kodtabla[5][1] = 'n';
    kodtabla[5][2] = 'o';
    kodtabla[5][3] = '6';
    // 7
    kodtabla[6][0] = 'p';
    kodtabla[6][1] = 'q';
    kodtabla[6][2] = 'r';
    kodtabla[6][3] = 's';
    kodtabla[6][4] = '7';
    // 8
    kodtabla[7][0] = 't';
    kodtabla[7][1] = 'u';
    kodtabla[7][2] = 'v';
    kodtabla[7][3] = '8';
    // 9
    kodtabla[8][0] = 'w';
    kodtabla[8][1] = 'x';
    kodtabla[8][2] = 'y';
    kodtabla[8][3] = 'z';
    kodtabla[8][4] = '9';
    // 10
    kodtabla[9][0] = 0; // Nagybetű
    // 11
    kodtabla[10][0] = '+';
    kodtabla[10][1] = '0';
    // 12
    kodtabla[11][0] = ' ';
    kodtabla[11][1] = '#';

    decode();

    return "";
}

int main()
{
    cout << "Adja meg a dekódolandó kódsorozatot!" << endl;
    cin >> kod;
    kodtablazat();
    cout << uzenet;

    return 0;
}
