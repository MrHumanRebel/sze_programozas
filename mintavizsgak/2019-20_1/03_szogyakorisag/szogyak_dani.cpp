#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;
#define TELL cout <<
#define ASK cin >>
#define MAXHOSSZ 20
#define MAXKIIR 10

// a aa aaa a aa aaa a aa aaa a aa aaa b bb bbb b bb bbb b bb bbb c cc ccc c cc ccc d dd ddd [vege]

struct elemek
{
    string akt;
    int db;
};

string beolv()
{
    cout << "Adja meg a szöveget \"[vege]\" végjelig!" << endl;
    string input;
    getline(cin, input);
    return input;
}

void szamol()
{
    elemek elem[MAXHOSSZ];
    for (int i = 0; i <= MAXHOSSZ; i++)
    {
        elem[i].akt = "\0";
        elem[i].db = 0;
    }
    string input = beolv();
    long unsigned int i = 0;
    int k = 0;
    while (i < input.length())
    {
        if (input[i] != ' ')
        {
            elem[k].akt += input[i];
            elem[k].db++;
            i++;
        }
        else if (input[i + 1] == '[' && input[i + 2] == 'v' && input[i + 3] == 'e' && input[i + 4] == 'g' && input[i + 5] == 'e' && input[i + 6] == ']')
        {
            return;
        }
        else
        {
            k++;
            i++;
        }
    }
    for (long unsigned int j = 0; j < i; j++)
    {
        TELL elem[j].akt;
        if (elem[j].db != 0)
            TELL elem[j].db;
    }
}

int main()
{
    TELL "Szogyakorisagi statisztika. ";
    szamol();

    return 0;
}