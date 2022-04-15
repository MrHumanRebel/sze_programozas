#include <iostream>
using namespace std;
#define MAX 10

int tomb_meret(int tomb[])
{
    int n = *(&tomb + 1) - tomb; // Not working ATM
    return n;
}

int main()
{
    int tomb[MAX]{10, 20, 30, 40, 50, 60};
    cout << tomb_meret(tomb);
    return 0;
}