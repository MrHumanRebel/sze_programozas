#include <iostream>
#include <cmath>
using namespace std;

int toint(string str)
{
    bool negativ = (str[0] == '-');
    int szam = 0;
    for (size_t i = negativ; i < str.length(); i++)
    {
        if ((int)(str[i]) - 48 >= 0 && (int)(str[i]) - 48 <= 9)
        {
            szam += (int)(((int)(str[i])) - (int)48) * pow(10, str.length() - i - (int)1);
        }
        else
        {
            szam = 0;
            break;
        }
    }
    szam -= (int)negativ * szam * 2;
    return szam;
}

int main()
{
    string szam = "1234567";
    string szam2 = "-7654321";
    cout << toint(szam) << endl;
    cout << toint(szam2) << endl;
    return 0;
}