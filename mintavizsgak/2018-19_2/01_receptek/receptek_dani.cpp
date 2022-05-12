#include <iostream>

using namespace std;

#define TELL cout <<
#define ASK cin >>
#define MAX 32

int keres(string alapanyag[], string mikell[], int alapdb, int mikelldb)
{
    int i;
    int talalat = 0;
    for (i = 0; i < alapdb; i++)
    {
        for (int j = 0; j < mikelldb; j++)
        {
            if (alapanyag[i] == mikell[j])
                talalat++;
        }
    }
    return talalat;
}

string beolv()
{
    string input;
    getline(cin, input);
    return input;
}

int beker(string tomb[])
{
    int i = 0;
    string input;
    do
    {
        input = beolv();
        tomb[i] = input;
        i++;
    } while (input != "#");
    return i;
}

int main()
{
    string alapanyagok[MAX];
    string mikell[MAX];

    TELL "Milyen alapanyagok allnak rendelkezesre? Befejezes #-tel." << endl;
    int hanyvan = beker(alapanyagok) - 1;

    TELL "Etel neve: ";
    string aktetel = beolv();

    TELL "Milyen alapanyagokra van szukseg? Befejezes #-tel." << endl;
    int hanykell = beker(mikell) - 1;

    int talalat = keres(alapanyagok, mikell, hanyvan, hanykell);

    if (hanykell == talalat)
        TELL "A(z) " << aktetel << " elkeszitheto." << endl;
    else
        TELL "A(z) " << aktetel << " nem keszitheto el." << endl;

    return 0;
}