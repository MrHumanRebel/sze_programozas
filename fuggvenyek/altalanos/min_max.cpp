#include <iostream>
using namespace std;

int min(int input[], int meret)
{
    int akt = input[0];
    for (int i = 0; i < meret; i++)
    {
        if (input[i] < akt)
        {
            akt = input[i];
        }
    }
    cout << "Minimum: " << akt << endl;
    return akt;
}

int max(int input[], int meret)
{
    int akt = input[0];
    for (int i = 0; i < meret; i++)
    {
        if (input[i] > akt)
        {
            akt = input[i];
        }
    }
    cout << "Maximum: " << akt << endl;
    return akt;
}

int main()
{
    int tomb[] = {50, 1, -3, -30, 9, -7, 5};
    int meret = sizeof(tomb) / sizeof(tomb[0]);
    min(tomb, meret);
    max(tomb, meret);
    return 0;
}
