#include <iostream>
using namespace std;

void bubi(int tomb[], int db)
{
    for (int v = db - 1; v >= 1; v--)
    {
        for (int e = 0, csere; e < v; e++)
        {
            if (tomb[e] > tomb[e + 1])
            {
                csere = tomb[e];
                tomb[e] = tomb[e + 1];
                tomb[e + 1] = csere;
            }
        }
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
    int meret = sizeof(tomb) / sizeof(tomb[0]);
    kiir(tomb, meret);
    bubi(tomb, meret);
    kiir(tomb, meret);
    return 0;
}
