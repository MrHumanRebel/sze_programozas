#include <iostream>
using namespace std;
#define TELL cout <<
#define ASK cin >>
#define MAX 5

void toupper_tomb(string tomb[], int aktdb)
{
    for (int i = 0; i < aktdb; i++)
    {
        string akt = tomb[i];
        int db = tomb[i].length();
        tomb[i] = "\0";
        for (int j = 0; j < db; j++)
        {
            tomb[i] += toupper(akt[j]);
        }
    }
}

void kiir(string tomb[], int aktdb)
{
    for (int i = 0; i < aktdb; i++)
    {
        TELL tomb[i] << endl;
    }
    TELL endl;
}

int main()
{
    string tomb[MAX]{"abc", "bcd", "cad", "dec", "eda"};
    kiir(tomb, MAX);
    toupper_tomb(tomb, MAX);
    kiir(tomb, MAX);
    return 0;
}