/*Írjon egy programot, amely 2 db felhasználói függvényt használ. Az egyik az int feltolt(char s_tb[]),
amely feltölt egy karakter tömböt (1. paraméter) ékezet nélküli szöveggel az ENTER billentyû leütéséig, vagy maximum 50
db karakterig. Bekérési információk és hibaüzenetek kiírása nem kell! A tömb hosszát szimbolikus állandóval állítsa be. A
függvény visszatérési értéke a feltöltött tömb hossza legyen. A másik függvény a void torol(char s_tb[], int h), pedig a
feltöltött tömb (1. paraméter) minden második elemét törölje, majd az így módosított tömb tartalmát írja is ki. A torol
függvény 2. paramétere a feltolt függvény visszatérési értéke.
*/
#include <iostream>


using namespace std;
#define N 50

int feltolt(char s_tb[]) {
	char aktChar;
	int array_LEN;
	bool ok = true;

	for (int i = 0; i < N; i++)
	{
		s_tb[i] = '\0';
	}

	int i = 0;
	do
	{
		cin.get(s_tb[i]);
		i++;

	} while (s_tb[i - 1] != '\n' && i < N); //i-1 mivel az i-t már növeltük


	return array_LEN = strlen(s_tb);
}


void torol(char s_tb[], int h) {
	string seged;
	int j = 0;
	for (int i = 0; i < h - 1; i++)
	{
		if (i % 2 == 0) {
			seged += s_tb[i];
		}
	}
//	cout << seged;
//	cout << endl;
//	cout << "********\n";
	for (int i = 0; i < seged.length(); i++)
	{
		s_tb[i] = seged[i];
		cout << s_tb[i];
	}

}


int main()
{
	char s_tb[N];
	int szam = feltolt(s_tb);
	torol(s_tb, szam);
	//cout << szam;
	return 0;
}