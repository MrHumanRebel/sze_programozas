/*
feladat: Írjon egy programot, amely 2 db felhasználói függvényt használ. Az egyik az int beker(int be_tb[], int *min, int
*max), amely 10 db elõjeles egész számot kér be úgy, hogy azokat egy tömbbe tárolja le.A tömb hosszát szimbolikus
állandóval állítsa be. A tárolás csak akkor jöjjön létre, ha az alábbi feltételek teljesülnek. A tömb 0. indexén csak a nulla
érték, a páratlan indexein csak páratlan értékek és a páros indexein csak páros számok szerepelhetnek! Ha az adott érték
nem teljesíti a rá vonatkozó feltételt, akkor új számot kell bekérni. Bekérési információk és hibaüzenetek kiírása nem kell!
A feltételek teljesülése esetén a beker függvény határozza meg és tárolja el a legkisebb páratlan, illetve a legnagyobb
páros számokat. Ezen értékek a függvény 2. és 3. paraméterei, amíg az 1. paraméter a tároló tömb. A függvény
visszatérési értéke a 10 db szám összege legyen. A mási függvény a void kiir(int szum, int min, int max), pedig írja ki a
beker függvény visszatérési értékét illetve a 2. és 3. paraméterek értékeit a példában látott szövegezéssel.
*/

#include <iostream>

using namespace std;
#define N 10


int beker(int be_tb[], int* min, int* max) {
	int szam;
	int sum = 0;
	bool megfelel = false;
	
	int i = 0;
	while (i<10)
	{
		megfelel = false;
		if (i == 0) {
			do
			{
				cin >> szam;
				if (szam == 0)
				{
					be_tb[i] = 0;
					megfelel = true;
				}
			} while (megfelel == false);
		}
		else if (i%2 != 0) {
			do
			{
				cin >> szam;
				if (szam % 2 != 0)
				{
					be_tb[i] = szam;
					sum += szam;
					if (szam < *min) {
						*min = szam;
					}
					megfelel = true;
				}
			} while (megfelel == false);
		}
		else if (i%2 == 0) {
			do
			{
				cin >> szam;
				if (szam % 2 == 0)
				{
					be_tb[i] = szam;
					sum += szam;
					if (szam > *max) {
						*max = szam;
					}
					megfelel = true;
				}
			} while (megfelel == false);
		}
		i++;
	}

	return sum;
}

void kiir(int sum, int min, int max) {
	cout << "Szum: " << sum;
	cout << "Paratlan: " << min;
	cout << "Paros: " << max;
}

int main()
{
	int be_tb[N];
	int paratlanMin = INT_MAX;
	int parosMax = INT_MIN;

	int szum = beker(be_tb, &paratlanMin, &parosMax);
	kiir(szum, paratlanMin, parosMax);

	return 0;

}

