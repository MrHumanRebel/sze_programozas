#include <iostream>
#include <fstream>
#include <climits>
#include <cstring>
#include <string>

using namespace std;
#define MAX 16

struct runner
{
	string lic;
	int run_1;
	int run_2;
	int run_3;
	int best;
};

string run_result(string fbe)
{

	int i = 0;
	int leggyorsabbid;
	int leggyorsabb = 0;
	string leggyorsabblic;

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
			runner *tomb = new runner[adatdb];
			if (isdigit(aktSor[0]) != true)
			{
				int spacehelye = aktSor.find(' ');
				tomb[i].lic = aktSor.substr(0, spacehelye);
				spacehelye++;
				// cout << tomb[i].lic << "\t";

				tomb[i].run_1 = stoi(aktSor.substr(spacehelye, 4));
				spacehelye += 5;
				// cout << tomb[i].swim << "\t";

				tomb[i].run_2 = stoi(aktSor.substr(spacehelye, 4));
				spacehelye += 5;
				// cout << tomb[i].cycle << "\t";

				tomb[i].run_3 = stoi(aktSor.substr(spacehelye, 4));
				spacehelye += 5;
				// cout << tomb[i].run << "\t";

				tomb[i].best = tomb[i].run_1;


				if (tomb[i].best < tomb[i].run_2)
				{
					tomb[i].best = tomb[i].run_2;
				}
				if (tomb[i].best < tomb[i].run_3)
				{
					tomb[i].best = tomb[i].run_3;
				}
				if (leggyorsabb == 0)
					leggyorsabb = tomb[i].best;
				else
				{
					if (tomb[i].best < leggyorsabb)
					{
						leggyorsabb = tomb[i].best;
						leggyorsabbid = i;
					}
				}

				// cout << tomb[i].sum << "\t";
				// cout << endl;

				i++;
				leggyorsabblic = tomb[leggyorsabbid].lic;
			}
		}
	}
	else
	{
		cout << "Sikertelen file-nyitás!" << endl;
		return "\0";
	}

	return leggyorsabblic;
}