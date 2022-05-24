#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
#define MAX 10
#define KIIRMIN 2000
#define KIIRMAX 8000

double area(string fbe)
{
    int a_oldalak[MAX];
    int b_oldalak[MAX];
    int szogek[MAX];
    double teruletek[MAX];
    double osszterulet = 0;
    int i = 0;
    ifstream fajl(fbe);
    string aktSor;

    if (fajl.is_open())
    {
        while (getline(fajl, aktSor))
        {
            int spacehelye = aktSor.find(' ');
            if (spacehelye == 3)
            {
                a_oldalak[i] = stoi(aktSor.substr(0, spacehelye));
                spacehelye++;
                // cout << a_oldalak[i] << "\t";

                b_oldalak[i] = stoi(aktSor.substr(spacehelye, 3));
                spacehelye += 4;
                // cout << b_oldalak[i] << "\t";

                szogek[i] = stoi(aktSor.substr(spacehelye, 2));
                // cout << szogek[i] << "\t";

                teruletek[i] = (a_oldalak[i] * b_oldalak[i] * sin(szogek[i] * (M_PI / 180))) / 2; // RAD TO DEG * (M_PI / 180)
                // cout << teruletek[i] << "\t";
            }
            else
            {
                a_oldalak[i] = stoi(aktSor.substr(0, spacehelye));
                spacehelye++;
                // cout << a_oldalak[i] << "\t";

                b_oldalak[i] = stoi(aktSor.substr(spacehelye, 2));
                spacehelye += 3;
                // cout << b_oldalak[i] << "\t";

                szogek[i] = stoi(aktSor.substr(spacehelye, 2));
                // cout << szogek[i] << "\t";

                teruletek[i] = (a_oldalak[i] * b_oldalak[i] * sin(szogek[i] * (M_PI / 180))) / 2; // RAD TO DEG * (M_PI / 180)
                // cout << teruletek[i] << "\t";
            }

            if (teruletek[i] >= KIIRMIN && teruletek[i] <= KIIRMAX)
                cout << teruletek[i] << " [nm]" << endl;

            osszterulet += teruletek[i];
            i++;
            // cout << endl;
        }
    }
    else
    {
        cout << "Sikertelen file-nyitás!" << endl;
        return -1;
    }
    return (osszterulet / i);
}

int main()
{
    double atlag = area("/home/szeke/uni/sze_programozas/vizsgak/eles/2022-05-19/04/Tri.txt");
    cout << atlag << endl;
    return 0;
}