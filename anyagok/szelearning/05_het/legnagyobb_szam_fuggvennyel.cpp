#include <iostream>
using namespace std;
static int a, b, maximum;

int max()
{
    maximum = a;
    if (b > maximum)
        maximum = b;
    return maximum;
}

int main()
{
    int akt, szamlalo, elmax, aktmax;
    cin >> akt;
    aktmax = akt;
    do
    {
        cin >> akt;
        a = elmax;
        b = akt;
        aktmax = max();
        if (aktmax > elmax)
        {
            szamlalo++;
            aktmax = elmax;
        }

    } while (szamlalo == 3);

    return 0;
}