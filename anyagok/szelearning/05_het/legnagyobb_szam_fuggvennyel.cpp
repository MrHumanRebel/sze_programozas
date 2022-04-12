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
    int akt, ujmax, aktmax;
    int szamlalo = 0;
    cout << "Adjon meg egy számot! " << endl;
    cin >> akt;
    aktmax = akt;
    cout << "A jelenlegi számok maximuma: " << aktmax << endl;
    do
    {
        cout << "Adjon meg másik számot! " << endl;
        cin >> akt;

        a = aktmax;
        b = akt;
        ujmax = max();
        if (ujmax >= aktmax)
        {
            szamlalo++;
            aktmax = ujmax;
            cout << "A jelenlegi számok maximuma: " << aktmax << endl;
        }

    } while (szamlalo != 3);

    return 0;
}