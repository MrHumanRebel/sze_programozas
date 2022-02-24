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
    kodtabla[1][0] = 'A';
    kodtabla[1][1] = 'B';
    kodtabla[1][2] = 'C';
    kodtabla[1][3] = '2';
    // 3
    kodtabla[2][0] = 'D';
    kodtabla[2][1] = 'E';
    kodtabla[2][2] = 'F';
    kodtabla[2][3] = '3';
    // 4
    kodtabla[3][0] = 'G';
    kodtabla[3][1] = 'H';
    kodtabla[3][2] = 'I';
    kodtabla[3][3] = '4';
    // 5
    kodtabla[4][0] = 'J';
    kodtabla[4][1] = 'K';
    kodtabla[4][2] = 'L';
    kodtabla[4][3] = '5';
    // 6
    kodtabla[5][0] = 'M';
    kodtabla[5][1] = 'N';
    kodtabla[5][2] = 'O';
    kodtabla[5][3] = '6';
    // 7
    kodtabla[6][0] = 'P';
    kodtabla[6][1] = 'Q';
    kodtabla[6][2] = 'R';
    kodtabla[6][3] = 'S';
    kodtabla[6][4] = '7';
    // 8
    kodtabla[7][0] = 'T';
    kodtabla[7][1] = 'U';
    kodtabla[7][2] = 'V';
    kodtabla[7][3] = '8';
    // 9
    kodtabla[8][0] = 'W';
    kodtabla[8][1] = 'X';
    kodtabla[8][2] = 'Y';
    kodtabla[8][3] = 'Z';
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