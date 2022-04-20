#include <iostream>
using namespace std;

void gyorsbubi(int tomb[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool cserelt = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (tomb[j] > tomb[j + 1])
            {
                swap(tomb[j], tomb[j + 1]);
                cserelt = true;
            }
        }
        if (cserelt == false)
            break;
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
    int tomb[] = {50, 1, -3, -30, 9, -7, 5};
    int meret = sizeof(tomb) / sizeof(tomb[0]);
    kiir(tomb, meret);
    gyorsbubi(tomb, meret);
    kiir(tomb, meret);
    return 0;
}