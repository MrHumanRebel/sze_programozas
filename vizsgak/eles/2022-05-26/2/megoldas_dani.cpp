#include <iostream>
#include <cstring>
#include <string>
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

void cserel(char s_tb[], int h)
{
	char *ujtomb = new char[MAX];
	if (h % 2 == 0) // Páros hossz
	{
		for (int i = 0; i < h; i += 2)
		{
			ujtomb[i] = s_tb[i + 1];
			ujtomb[i + 1] = s_tb[i];
		}
		// Régi tömb kiűrítése
		for (int i = 0; i < h; i++)
		{
			s_tb[i] = '\0';
		}
		//Új elemsor eltárolása
		for (int i = 0; i < h; i++)
		{
			s_tb[i] = ujtomb[i];
			cout << s_tb[i];
		}
	}
	else if (h % 2 != 0)
	{ // Páratlan hossz
		char utolsobetu = s_tb[h - 1];
		for (int i = 0; i < h - 1; i += 2)
		{
			ujtomb[i] = s_tb[i + 1];
			ujtomb[i + 1] = s_tb[i];
		}
		// Régi tömb kiűrítése
		for (int i = 0; i < h - 1; i++)
		{
			s_tb[i] = '\0';
		}
		//Új elemsor eltárolása
		for (int i = 0; i < h - 1; i++)
		{
			s_tb[i] = ujtomb[i];
			cout << s_tb[i];
		}
		s_tb[h] = utolsobetu;
		cout << s_tb[h];
	}

	delete[] ujtomb;
}

int main()
{
	char tomb[MAX];
	int tombhossz = feltolt(tomb);
	cserel(tomb, tombhossz);
	return 0;
}