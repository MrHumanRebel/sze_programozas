#include <iostream>
#include <string>
#include <time.h>

using namespace std;
#define say cout<<
#define ask cin>>

string helyorzo[] = { "nev","szin","allat","jarmu","telepules","vel" };
string helyettesito[] = { "Gizi","piros","kutya","bicikli","Karakoszorcsog" };

int randomSzam() {
	srand(time(NULL)+0);
	return (0 + rand() % (9999-0));

}

int main()
{
	//egyszeri végigmenés, közben az új szöveg létrehozása 
	say "Szimbolum cserelo program.\n";
	string szoveg;
	string newSzoveg;
	getline(cin, szoveg);
	string csere = "";
	string hasonlitas;
	int vege = szoveg.find("[vege]");
	int kezdojel;
	int vegjel;
	for (int i = 0; i < vege; i++)
	{
		if (szoveg[i] != '$') {
			newSzoveg += szoveg[i];
		}
		if (szoveg[i] == '$') {
			if (szoveg[i + 1] == '$') {
				szoveg[i + 1] = '\0';
				newSzoveg += '$';

			}
			else
			{
				i++; //azért kell hogy a $ jelet amin i áll ne rakja bele hanem csak az azt követõt
				while (szoveg[i] != '$')
				{
					csere += szoveg[i];
					i++;
				}

				if (csere == helyorzo[5]) {
					newSzoveg += to_string(randomSzam());
				}
				else
				{
					bool bennevan = false; // $kecske$ esetén lesz kecske, a for-on kívül van, különben szóismétlés lépne fel stb.
					for (int j = 0; j < 5; j++)
					{

						if (csere == helyorzo[j]) {
							bennevan = true;
							newSzoveg += helyettesito[j];
						}

					}
					if (!bennevan) {
						newSzoveg += csere;
					}
				}

				csere.clear(); // ha nem lenne akkor Gizi utáni helyettesitok helyere "" kerülne.

			}
		}
	}
	say newSzoveg;
}