#include <iostream>
using namespace std;

// !!! BETA VERSION !!!

int tomb_shift(int tomb[], int hossz, int lepes, int ureshely)
{
    bool toRight = lepes >= 0;
    int ujhossz = hossz + lepes;
    lepes = lepes % hossz;
    if (lepes == 0)
    {
        return 0;
    }
    else if (toRight)
    {
        for (int i = hossz - 1; i >= lepes; i--)
        {
            tomb[i] = tomb[i - lepes];
        }
        for (int i = 0; i < lepes; i++)
        {
            tomb[i] = ureshely;
        }
    }
    else
    {
        lepes *= -1;
        for (int i = 0; i < hossz - lepes; i++)
        {
            tomb[i] = tomb[i + lepes];
        }
        for (int i = hossz - lepes; i < hossz; i++)
        {
            tomb[i] = ureshely;
        }
    }
    return ujhossz;
}

void kiir(int tomb[], int aktDb)
{
    for (int i = 0; i < aktDb; i++)
    {
        cout << tomb[i] << endl;
    }
    cout << endl;
}

int main()
{
    int tomb[] = {1, -3, 9, -7, 5};
    int shift = 2;
    int tombhossz = sizeof(tomb) / sizeof(tomb[0]);
    kiir(tomb, tombhossz);
    tombhossz = tomb_shift(tomb, tombhossz, shift, 0);
    kiir(tomb, tombhossz);
    return 0;
}