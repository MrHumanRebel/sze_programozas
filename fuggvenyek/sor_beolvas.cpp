#include <iostream>
#include <fstream>
using namespace std;
#define TELL cout <<
#define ASK cin >>
#define MAX 256

int olvas(string tomb[], string olvashely)
{
    ifstream olvas;
    string akt;
    int i = 0;
    olvas.open(olvashely);
    if (!olvas.is_open())
    {
        TELL "A fájl nem létezik!" << endl;
    }
    else
    {
        while (getline(olvas, akt))
        {
            olvas >> akt;
            tomb[i] = akt;
            i++;
        }
    }
    return i;
}

int main()
{
    string tomb[MAX];
    int tomb_db = olvas(tomb, "/home/szeke/uni/sze_programozas/mintavizsgak/2017-18_2/12_akasztofa/megyek.txt");
    for (int i = 0; i < tomb_db; i++)
    {
        TELL tomb[i] << endl;
    }
    return 0;
}