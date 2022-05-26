#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;
#define MAX1 10
#define MAX2 2


double** befogok(string fbe)
{
	int adatok[MAX1][MAX2]; //Elso adat atfogo másik hegyesszog
	double szogek[MAX1][MAX2]; //Elso adat hegyesszöggel szembeni befogó masodik hegyesszög melletti befogó
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
				adatok[i][0] = stoi(aktSor.substr(0, spacehelye));
				spacehelye++;
				// cout << a_oldalak[i] << "\t";

				adatok[i][1] = stoi(aktSor.substr(spacehelye, 3));
				spacehelye += 4;
				// cout << b_oldalak[i] << "\t";
				szogek[i][0] = adatok[i][1] * sin(adatok[i][2]*(M_PI / 180));
				szogek[i][1] = adatok[i][1] * cos(adatok[i][2] * (M_PI / 180));
				// cout << szogek[i] << "\t";


			}
			else
			{
				adatok[i][0] = stoi(aktSor.substr(0, spacehelye));
				spacehelye++;
				// cout << a_oldalak[i] << "\t";

				adatok[i][1] = stoi(aktSor.substr(spacehelye, 2));
				spacehelye += 3;
				// cout << b_oldalak[i] << "\t";
				szogek[i][0] = adatok[i][1] * sin(adatok[i][2] * (M_PI / 180));
				szogek[i][1] = adatok[i][1] * cos(adatok[i][2] * (M_PI / 180));
				// cout << szogek[i] << "\t";
			}
			i++;
			// cout << endl;
		}
	}
	else
	{
		cout << "Sikertelen file-nyitás!" << endl;
		return 0;
	}
	return 0;
}