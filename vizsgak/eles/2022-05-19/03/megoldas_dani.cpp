#include <iostream>
#include <fstream>

using namespace std;
#define MAX 16

struct triathlete
{
    string lic;
    int swim;
    int cycle;
    int run;
    int depo;
    int sum;
};

struct versenyzo
{
    string lic;
    int hours;
    int minutes;
    int seconds;
};

string tri_result(triathlete tomb[], string fbe)
{
    int i = 0;
    ifstream fajl(fbe);
    string aktSor;
    int adatdb = 0;
    if (fajl.is_open())
    {
        while (getline(fajl, aktSor))
        {
            if (isdigit(aktSor[0]) == true)
            {
                adatdb = stoi(aktSor);
                // cout << adatdb << endl;
                i++;
            }
            else
            {
                int spacehelye = aktSor.find(' ');
                tomb[i].lic = aktSor.substr(0, spacehelye);
                spacehelye++;
                // cout << tomb[i].lic << "\t";

                tomb[i].swim = stoi(aktSor.substr(spacehelye, 4));
                spacehelye += 5;
                // cout << tomb[i].swim << "\t";

                tomb[i].cycle = stoi(aktSor.substr(spacehelye, 4));
                spacehelye += 5;
                // cout << tomb[i].cycle << "\t";

                tomb[i].run = stoi(aktSor.substr(spacehelye, 4));
                spacehelye += 5;
                // cout << tomb[i].run << "\t";

                tomb[i].depo = stoi(aktSor.substr(spacehelye, 3));
                // cout << tomb[i].depo << "\t";

                tomb[i].sum = tomb[i].swim + tomb[i].cycle + tomb[i].run + tomb[i].depo;
                // cout << tomb[i].sum << "\t";
                // cout << endl;

                i++;
            }
        }
    }
    else
    {
        cout << "Sikertelen file-nyitás!\nN/A!" << endl;
        return "\0";
    }
    versenyzo ujadatok[adatdb];
    for (int i = 1; i <= adatdb; i++)
    {
        int aktora = 0;
        int aktperc = 0;
        int aktmperc = tomb[i].sum;

        // Upper protections
        while (aktmperc >= 60)
        {
            aktmperc -= 60;
            aktperc += 1;
        }
        while (aktperc >= 60)
        {
            aktperc -= 60;
            aktora += 1;
        }

        // Lower protections
        while (aktmperc < 0)
        {
            aktmperc += 60;
            aktperc -= 1;
        }
        while (aktperc < 0)
        {
            aktperc += 60;
            aktora -= 1;
        }

        ujadatok[i].hours = aktora;
        ujadatok[i].minutes = aktperc;
        ujadatok[i].seconds = aktmperc;
        cout << tomb[i].lic << " => " << ujadatok[i].hours << ':' << ujadatok[i].minutes << ':' << ujadatok[i].seconds << " [h:m:s]" << endl;
    }
    return tomb[adatdb].lic;
}

int main()
{
    triathlete adatok[MAX];
    string filename = "/home/szeke/uni/sze_programozas/vizsgak/eles/2022-05-19/03/Chip.txt";
    tri_result(adatok, filename);
    return 0;
}