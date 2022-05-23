#include <iostream>
#include <cstring>

using namespace std;

#define MAX 50

int feltolt(char s_tb[])
{
    string sor;
    int sorhossz;
    bool ok = false;
    int i;
    do
    {
        getline(cin, sor);
        sorhossz = sor.length();
    } while (sorhossz > MAX);
    if (sorhossz <= MAX)
        ok = true;
    if (ok == true)
    {
        for (i = 0; i < sorhossz; i++)
        {
            s_tb[i] = sor[i];
        }
    }
    return i;
}

void torol(char s_tb[], int h)
{
    char ujtomb[MAX];
    ujtomb[0] = s_tb[0];
    cout << ujtomb[0];
    for (int i = 2; i < h; i += 2)
    {
        ujtomb[i] = s_tb[i];
        cout << ujtomb[i];
    }
}

int main()
{
    char tomb[MAX];
    int tombhossz = feltolt(tomb);
    torol(tomb, tombhossz);
    return 0;
}