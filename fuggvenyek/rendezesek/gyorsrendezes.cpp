#include <iostream>
using namespace std;

void cserel(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int particional(int tomb[], int min, int max)
{
    int pivot = tomb[max];
    int i = (min - 1);

    for (int j = min; j <= max - 1; j++)
    {
        if (tomb[j] < pivot)
        {
            i++;
            cserel(&tomb[i], &tomb[j]);
        }
    }
    cserel(&tomb[i + 1], &tomb[max]);
    return (i + 1);
}

void gyorsrendez(int arr[], int min, int max)
{
    if (min < max)
    {
        int n = particional(arr, min, max);
        gyorsrendez(arr, min, n - 1);
        gyorsrendez(arr, n + 1, max);
    }
}

void kiir(int tomb[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << tomb[i] << " ";
    cout << endl;
}

int main()
{
    int tomb[] = {1, -3, 9, -7, 5};
    int n = sizeof(tomb) / sizeof(tomb[0]);
    cout << "Rendezetlen: " << endl;
    kiir(tomb, n);
    gyorsrendez(tomb, 0, n - 1);
    cout << "Rendezett: " << endl;
    kiir(tomb, n);
    return 0;
}