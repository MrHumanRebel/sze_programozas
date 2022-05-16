#include <iostream>
using namespace std;

int keres(int tomb[], int db, int elem)
{
    int i;
    for (i = 0; i < db; i++)
    {
        if (tomb[i] == elem)
            return i;
    }
    return -1;
}

int main()
{

    int tomb[] = {2, 3, 4, 10, 40};
    int x = 10;
    int n = sizeof(tomb) / sizeof(tomb[0]);
    int eredmeny = keres(tomb, n, x);
    (eredmeny == -1)
        ? cout << "Nem található!"
        : cout << "Ezen az indexen található: " << eredmeny;
    return 0;
}