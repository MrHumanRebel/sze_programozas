//alappálya beolvas pipa
//jatek vege - inkább bool játék addig megy amíg a poz != jobb felsõ sarok
//lépés beolvasások külön f,l,j,b - ezeknek legyen belsõ bool értékei, hogy jók-e. térjenek  vissza bool értékkel ELSÕNEK MEGNÉZI, HOGY FEL ESETÉN PL. X+i JÓ-E HA NEM LE SE FUT
// összegzett lépés beolvasó, ami beolvassa hány f,l van azokat meghívja, eredményeket összegez i-t ad vissza
// összegzett lépés beolvasó, ami beolvassa hány j,b van azokat meghívja, eredményeket összegez j-t ad vissza
// hogy melyik függvényt hívja meg az a bemenet hosszától függjön
//léptetõ fgv. kap két értéket, i és j majd, ezekkel lép a kellõ helyre
// pozíció törlõ fgv.
//random lépés fgv. random érték 1,2,3,4 majd switch-case meghívja 1 esetén f 2... ha nincs jó lépés nem lép
// felhasználó állítsa be a pályát, nem lesz mert ez jó neki :3333
//
// MÓDOSÍTOTT TERV:
// jatek vege - pipa
// pálya beolvas - pipa
// pálya betölt - pipa
// lépés ellenõrzés - pipa
// lépés feldolgozó x értékekre x értékét adja vissza - pipa
// lépésfeldolgozó y értékekre y értékét adja vissza - pipa
// lépést elvégzõ fgv. O akt. helyét törli, új helyére berakja - pipa : Ez eddig 3-as megoldás
// random lépés - megnézi, hogy körülötte hol van hely, ha van vmelyikre odalép - PIPAAAAAAAAAAAAAAA - 4-es megoldás
// játékos maga állítja be a pályát 

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char matrix[5][5]{ };



struct jatekosPoz
{
	int x = 4; //alapon 4 
	int y = 0; //alapon 0
};
jatekosPoz jatekos;
void palyaBetolt() {
	ifstream beolv;
	beolv.open("palya.txt");
	if (beolv.is_open())
	{
		string sor;
		for (int i = 0; i < 5; i++)
		{
			getline(beolv, sor);
			for (int j = 0; j < 5; j++)
			{
				matrix[i][j] = sor[j];
			}
		}

	}
	else
	{
		cout << "Valami nem jó.";
	}
}

string palyaModositEll() {

	bool ok = false;
	string sz;  // jó példa: vt232 
	do
	{
		cout << "Adja meg a kivant modositas helyes kodjat. Minta: vt232\n";
		cin >> sz;
		int vTav = 0;
		int fTav = 0;
		if ((sz[2] >= '0' && sz[2] <= '4') && (sz[3] >= '0' && sz[3] <= '4')) {
			//vízszintes:
			vTav = 4 - (sz[2] - '0');
			//cout << vTav;
			//cout << endl;
			//vfüggõleges:
			fTav = 4 - (sz[3] - '0');
			//cout << fTav;
			//cout << endl;
		}

		//2 if egy v és egy f esetére v esetén jobb o.-i táv míg f esetén az alsó vonalig való hossz használatos
		if (sz[0] == 'v') {

			if ((sz[1] == 'r' || sz[1] == 't') && (sz[2] >= '0' && sz[2] <= '4') && (sz[3] >= '0' && sz[3] <= '4') && (sz[4] >= '1' && sz[4] <= '0' + vTav)) { // && (sz[2] == '7') && ('0' < sz[3] <= '5') && ('0' < sz[4] <= '5')
				ok = true;
			}
		}
		else if (sz[0] == 'f')
		{
			//char(fTav)
			if ((sz[1] == 'r' || sz[1] == 't') && (sz[2] >= '0' && sz[2] <= '4') && (sz[3] >= '0' && sz[3] <= '4') && (sz[4] >= '1' && sz[4] <= '0' + fTav)) { // && (sz[2] == '7') && ('0' < sz[3] <= '5') && ('0' < sz[4] <= '5')
				ok = true;
			}

		}
		if (sz.length() != 5) // azért itt ellenõrizzük mert ha az if-else elõtt tennénk, nem érne semmit, mert már akkor is false az érték és amikor belép a vizsgálásba, azt is nézi ami nincs...
			ok = false;

	} while (!ok);

	return sz;
}

void palyaSzerkeszto(string kod) { // Ez, a palyaModositEll() és palyaAllas() addig ismétlõdjön amig kesz parancsot nem kap
	// vt232
	char kitoltes = kod[1] == 'r' ? 'X' : '.';
	int xPos = kod[2] - '0';
	int yPos = kod[3] - '0';
	int meddig = kod[4] - '0';

	if (kod[0] == 'v') {

		for (int i = 0; i < meddig; i++)
		{
			matrix[xPos][yPos+i] = kitoltes;
		}

	}
	else if (kod[0] == 'f') {

		for (int i = 0; i < meddig; i++)
		{
			matrix[xPos + i][yPos] = kitoltes;
		}

	}
}

void palyaAllas() {
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << matrix[i][j];
		}
		cout << endl;
	}
}

string merreLep() {
	string irany; //do whileba....
	//jatekosPoz jatekos;
	cout << "Merre lep? ";
	cout << "Labirintus jatek, jusson el a jobb felso sarokba. Navigalas:\n Fel: f, Le: l, Balra: b, Jobbra: j, Random lepes: r,\n Kombinalt lepesek lehetnek pl.: fljbjj\n";
	cin >> irany;
	int kezdetiX = jatekos.x;
	int kezdetiY = jatekos.y;
	int lepesDb = irany.length();

	int i = 0;
	while (i < lepesDb)
	{
		//ide még egy if r-re, ha r, akkor csinál egy random számot 1-4 között, amit megfeleltet egy betûnek, azt hozzáfûzi az irányhoz, újra lefuttatja az egészet, de csak az irany[1]-re
		if (lepesDb == 1 && irany[i] == 'r') {
			string valasztek = "";
			if (matrix[(jatekos.x) - 1][jatekos.y] == '.') //sima if-ek hisz az össz. lehetõséget meg kell vizsgálni
				valasztek += 'f';
			if (matrix[jatekos.x + 1][jatekos.y] == '.')
				valasztek += 'l';
			if ((matrix[jatekos.x][jatekos.y + 1] == '.') && (jatekos.y + 1 > 0))
				valasztek += 'j';
			if ((matrix[jatekos.x][jatekos.y - 1] == '.') && (jatekos.y - 1 < 4))
				valasztek += 'b';
			//	char valasztek[] = "fljb"; // változtatni, hogy mibõl választhat
			char randomChar = valasztek[rand() % valasztek.length()]; //lazán faszán mükszik :3
		//	cout << randomChar;
			irany += randomChar;
			lepesDb = irany.length();
			i++;
		}
		else if (irany[i] == 'f') {
			if (matrix[(jatekos.x) - 1][jatekos.y] == '.') {
				jatekos.x -= 1;
				i++;
			}
			else {
				jatekos.x = kezdetiX;
				jatekos.y = kezdetiY;
				i = 0;
				cin >> irany;
				//eredeti re visszaállítani x-et y-t, ha nem jó, hiszen az érték torzulhatott, i-t 0-ra, hisz már egy másikat számolt, és újra bekéri, mert szar amit kapott
				lepesDb = irany.length(); //hogy kurvára ne essen végtelen ciklusba :3
			}
		}
		else if (irany[i] == 'l')
		{
			if (matrix[jatekos.x + 1][jatekos.y] == '.') {
				jatekos.x += 1;
				i++;
			}
			else {
				jatekos.x = kezdetiX;
				jatekos.y = kezdetiY;
				i = 0;
				cin >> irany;
				lepesDb = irany.length();
			}
		}
		else if (irany[i] == 'j')
		{
			if ((matrix[jatekos.x][jatekos.y + 1] == '.') && (jatekos.y + 1 > 0 && jatekos.y + 1 <= 4)) { //&& (jatekos.y+1 > 0 && jatekos.y + 1 <= 4) eznélkül ugrálgatna a sorok közt (j oldalról)
				jatekos.y += 1;
				i++;
			}
			else {
				jatekos.x = kezdetiX;
				jatekos.y = kezdetiY;
				i = 0;
				cin >> irany;
				lepesDb = irany.length();
			}
		}
		else if (irany[i] == 'b')
		{
			if ((matrix[jatekos.x][jatekos.y - 1] == '.') && (jatekos.y - 1 < 4 && jatekos.y - 1 >= 0)) {  // (jatekos.y - 1 != 4)
				jatekos.y -= 1;																				//(matrix[jatekos.x][jatekos.y - 1] != matrix[jatekos.x][jatekos.y - 1])
				i++;
			}
			else {
				jatekos.x = kezdetiX;
				jatekos.y = kezdetiY;
				i = 0;
				cin >> irany;
				lepesDb = irany.length();
			}
		}
		else
		{
			jatekos.x = kezdetiX;
			jatekos.y = kezdetiY;
			i = 0;
			cin >> irany;
			lepesDb = irany.length();
		}
	}

	return irany;

}

int xErtekek(string irany) {
	int xErtek = jatekos.x;
	for (int i = 0; i < irany.length(); i++)
	{
		if (irany[i] = 'f')
			xErtek -= 1;
		if (irany[i] = 'l')
			xErtek += 1;

	}
	return xErtek;
}

int yErtekek(string irany) {
	int yErtek = jatekos.y;
	for (int i = 0; i < irany.length(); i++)
	{
		if (irany[i] = 'b')
			yErtek -= 1;
		if (irany[i] = 'j')
			yErtek += 1;

	}
	return yErtek;
}


void pozCsere(int x, int y) {

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++) {
			if (matrix[i][j] == 'O')
				matrix[i][j] = '.';
		}
	}

	matrix[x][y] = 'O';

}

int main()
{
	//Akar-e szerkeszteni?
	bool jatekVege = false;
	palyaBetolt();
	//	cout << "Labirintus jatek, jusson el a jobb felso sarokba. Navigalas:\n Fel: f, Le: l, Balra: b, Jobbra: j, Random lepes: r,\n Kombinalt lepesek lehetnek pl.: fljbjj\n";
	palyaAllas();
	char kíván = false;
	cout << "Kivnja-e szerkeszteni a palyat?\nHa igen, nyomja meg az 'i' billentyutt, minden mas billentyu esetben\na szerkesztes nem megy vegbe es automatikusan az alap jatek indul el.\n";
	cin >> kíván;
	if (kíván == 'i') {
			bool szerkVege = true;
		do
		{
			cout << "Hasznalat: v a vizszintes, f a fuggoleges vonalhoz. Majd r a rajzolashoz, t a torleshez.\nKovetkezo ket szam a kezdopont x es y koordinatai.\nAz utolso karakter a vonal hosszat hatarozza meg.";
			string kod = palyaModositEll();
			palyaSzerkeszto(kod);
			palyaAllas();
			cout << "A modositas a \"kesz\" parancsig megy\nIrjon be barmi mast a folytatashoz.\nFIGYELEM: Ha most kilep kesobb nem tud valtoztatni!\n";
			string kesz;
			cin >> kesz;
			if (kesz == "kesz")
				szerkVege = false;
		} while (szerkVege);

	}
	do
	{
		string lep = merreLep();
		int x = xErtekek(lep);
		int y = yErtekek(lep);
		system("CLS"); //törli a konzolt
		pozCsere(x, y);
	//	cout << "Labirintus jatek, jusson el a jobb felso sarokba. Navigalas:\n Fel: f, Le: l, Balra: b, Jobbra: j, Random lepes: r,\n Kombinalt lepesek lehetnek pl.: fljbjj\n";
		palyaAllas();
		if (matrix[0][4] == 'O') {
			jatekVege = true;
			cout << "Jatek vege.";
		}
	} while (!jatekVege);

	//cout << lep;
}
