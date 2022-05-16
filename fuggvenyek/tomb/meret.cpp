#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define MAX 10

int main()
{
    int tomb[]{10, 20, 30, 40, 50, 60};
    int n = *(&tomb + 1) - tomb;
    int n2 = sizeof(tomb) / sizeof(tomb[0]);
    cout << n << endl;
    cout << n2 << endl;
    return 0;
}