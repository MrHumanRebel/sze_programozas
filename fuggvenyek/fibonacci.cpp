#include <iostream>
using namespace std;

long long fibonacci(int n)
{
    if (n < 2)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int szam;
    long long eredmeny;
    cout << "Szam: ";
    cin >> szam;
    eredmeny = fibonacci(szam);
    cout << "Eredmény: " << eredmeny << endl;
    return 0;
}