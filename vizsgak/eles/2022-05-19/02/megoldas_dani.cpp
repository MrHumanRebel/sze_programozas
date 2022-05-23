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
    int j = 1;
    // Megtartandó elemek eltárolása
    for (int i = 2; i < h; i += 2)
    {
        ujtomb[j] = s_tb[i];
        j++;
    }
    // Régi tömb kiűrítése
    for (int i = 0; i < MAX; i++)
    {
        s_tb[i] = '\0';
    }
    //Új elemsor eltárolása
    int ujmeret = h / 2;
    for (int i = 0; i < ujmeret - 1; i++)
    {
        s_tb[i] = ujtomb[i];
        cout << s_tb[i];
    }
}

int main()
{
    char tomb[MAX];
    int tombhossz = feltolt(tomb);
    torol(tomb, tombhossz);
    return 0;
}