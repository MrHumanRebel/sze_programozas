#include <iostream>
using namespace std;

void tomb_rotate(int tomb[], int hossz, int lepes)
{
    bool toRight = lepes >= 0;
    lepes = lepes % hossz;
    if (lepes == 0)
    {
        return;
    }
    else if (toRight)
    {
        for (int i = 0; i < lepes; i++)
        {
            int last = tomb[hossz - 1];
            for (int j = hossz - 2; j >= 0; j--)
            {
                tomb[j + 1] = tomb[j];
            }
            tomb[0] = last;
        }
    }
    else
    {
        lepes *= -1;
        for (int i = 0; i < lepes; i++)
        {
            int first = tomb[0];
            for (int j = 0; j < hossz - 1; j++)
            {
                tomb[j] = tomb[j + 1];
            }
            tomb[hossz - 1] = first;
        }
    }
    return;
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
    int lepes = 2;
    int tombhossz = sizeof(tomb) / sizeof(tomb[0]);
    kiir(tomb, tombhossz);
    tomb_rotate(tomb, tombhossz, lepes);
    kiir(tomb, tombhossz);
    lepes = -3;
    kiir(tomb, tombhossz);
    tomb_rotate(tomb, tombhossz, lepes);
    kiir(tomb, tombhossz);
    return 0;
}