#include <iostream>
using namespace std;

string uzenet;
string kod;
char kodtabla[11][5];

string decode()
{
    int szamlalo = 0;
    int akt;
    int x = 0;
    while (x <= kod.length())
    {
        if (kod[x] == '1')
            akt = 0;
        else if (kod[x] == '2')
            akt = 1;
        else if (kod[x] == '3')
            akt = 2;
        else if (kod[x] == '4')
            akt = 3;
        else if (kod[x] == '5')
            akt = 4;
        else if (kod[x] == '6')
            akt = 5;
        else if (kod[x] == '7')
            akt = 6;
        else if (kod[x] == '8')
            akt = 7;
        else if (kod[x] == '9')
            akt = 8;
        else if (kod[x] == '*')
            akt = 9;
        else if (kod[x] == '0')
            akt = 10;
        else
            akt = 11;

        if (kod[x] == kod[x + 1])
        {
            szamlalo++;
            x++;
        }
        else
        {
            cout << kodtabla[akt][szamlalo];
            szamlalo = 0;
            x++;
        }
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
    kodtabla[9][0] = '*'; // Nagybetű
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

    return 0;
}