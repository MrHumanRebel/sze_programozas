#include <iostream>
using namespace std;

// NOT WORKING
// BETA VERSION

void tomb_shift(int tomb[], int shift)
{
    int tombhossz = sizeof(tomb) / sizeof(tomb[0]);
    for (int i = tombhossz - 1; i >= shift; i--)
    {
        tomb[i] = tomb[i - shift];
    }
    for (int i = 0; i < shift; i++)
    {
        tomb[i] = 0;
    }
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
    tomb_shift(tomb, shift);
    kiir(tomb, tombhossz);
    return 0;
}