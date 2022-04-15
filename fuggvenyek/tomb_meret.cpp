#include <iostream>
using namespace std;
#define MAX 10
int seed = 0;

int tomb_meret(char tomb[])
{
    int n = sizeof(tomb) / sizeof(tomb[0]);
    return n;
}

int random(int tol, int ig)
{
    srand(time(NULL) + seed);
    return (tol + rand() % (ig - tol + 1));
}

int main()
{
    char tabla[MAX];
    for (int i = 0; i <= MAX; i++)
    {
        seed = random(1, 50);
        tabla[i] = random('A', 'Z');
    }
    cout << tomb_meret(tabla);
    return 0;
}