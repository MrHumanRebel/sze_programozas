#include <iostream>
#include <climits> // INT_MAX, INT_MIN
#include <cmath>
using namespace std;
#define TOMBMAX 10

unsigned int beker(int be_tb[])
{
	int pozszorzat = 0;
	int negszorzat = 0;
	int aktszam;
	int i = 0;
	bool ok = false;
	do
	{
		ok = false;
		if (i < 5) // Első 5 elem
		{
			do
			{
				cin >> aktszam;
				if (aktszam > 0)
					ok = true;

			} while (ok == false);
			be_tb[i] = aktszam;
			if (pozszorzat == 0)
				pozszorzat = be_tb[i];
			else
			{
				pozszorzat *= be_tb[i];
			}
		}
		else // Maradék 5
		{
			do
			{
				cin >> aktszam;
				if (aktszam < 0)
					ok = true;

			} while (ok == false);
			be_tb[i] = aktszam;
			if (negszorzat == 0)
				negszorzat = be_tb[i];
			else
			{
				negszorzat *= be_tb[i];
			}
		}
		i++;
	} while (i < 10);
	negszorzat = abs(negszorzat);
	pozszorzat = abs(pozszorzat);
	if (negszorzat < pozszorzat)
		return negszorzat;
	else
		return pozszorzat;
}

void kiir(unsigned int sr)
{
	cout << "A kisebb szorzat: " << sr;
}

int main()
{
	int tomb[TOMBMAX];
	unsigned int szorzat = beker(tomb);
	kiir(szorzat);

	return 0;
}