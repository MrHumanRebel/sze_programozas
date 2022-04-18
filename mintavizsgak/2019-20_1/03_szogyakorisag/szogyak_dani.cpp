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
// a aa aaa a aa aaa a aa aaa a aa aaa b bb bbb b bb bbb b
// Előzőnél több karakternél => [terminate called after throwing an instance of 'std::bad_alloc' what():  std::bad_alloc]

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
    // Struktúratömb nullázása
    elemek elem[MAXHOSSZ];
    for (int x = 0; x <= MAXHOSSZ; x++)
    {
        elem[x].akt = "\0";
        elem[x].db = 0;
    }
    // Adatbekérés
    string input = beolv();
    // Adatfeldolgozás
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

    // Növekvő bubi rendezés
    for (int v = k - 1; v >= 1; v--)
    {
        for (int e = 0; e < v; e++)
        {
            if (elem[e].db > elem[e + 1].db)
            {
                int csere = elem[e].db;
                elem[e].db = elem[e + 1].db;
                elem[e + 1].db = csere;
                string szocsere = elem[e].akt;
                elem[e].akt = elem[e + 1].akt;
                elem[e + 1].akt = szocsere;
            }
        }
    }

    // Struktúratömb nullázása
    elemek gyakori[MAXKIIR];
    for (int x = 0; x <= MAXKIIR; x++)
    {
        gyakori[x].akt = "\0";
        gyakori[x].db = 0;
    }

    int j = 0;
    for (int i = 0; i <= k; i++)
    {
        if (elem[i].akt == elem[i + 1].akt)
        {
            gyakori[j].akt = elem[i].akt;
            gyakori[j].db++;
            TELL gyakori[j].akt;
            TELL gyakori[j].db;
        }
        else
        {
            j++;
        }
    }
}

int main()
{
    TELL "Szogyakorisagi statisztika. ";
    szamol();

    return 0;
}