#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cctype>
#include <fstream>

#define NEPTUNHOSSZ 6

using namespace std;

struct hallgato {
	string nev;
	string neptun;
	int zh1;
	int zh2;
	int pzh1;
	int pzh2;
};

bool neptunell(string n) {
	if (n.length() != NEPTUNHOSSZ) return false;
	for (int i = 0; i < NEPTUNHOSSZ; i++) {
		if (not isalnum(n[i])) return false;
	}
	return true;
}

int beolvas(hallgato t[], int max) {
	int i;
	string vez[] = { "Kiss", "Nagy", "Kovacs", "Toth", "Takacs" };
	string ker[] = { "Andrea", "Bela", "Csaba", "Daniella", "Elemer" };
	int ve = sizeof(vez) / sizeof(vez[0]);
	int ke = sizeof(ker) / sizeof(ker[0]);
  bool kilep = false;
	cout << "Adja meg a hallgatok adatait - vegjelig!\n";
	for (i=0; not kilep and i<max; i++) {
    cout << "Hallgato neve: ";
    getline(cin, t[i].nev);
    kilep = t[i].nev=="-";
    if(not kilep) {
      if(t[i].nev == "gen") {
        t[i].nev = vez[rand() % ve] + " " + ker[rand()%ke];
        for (int j = 0; j < NEPTUNHOSSZ; j++) {
          int kod = rand() % 36;
          if (kod < 26) {
            t[i].neptun += char('A' + kod);
          }	else {
            t[i].neptun += char('0' + kod - 26);
          }
        }
        t[i].zh1 = rand() % 8;
        t[i].zh2 = rand() % 8;
        t[i].pzh1 = rand() % 8;
        t[i].pzh2 = rand() % 8;
      }	else {
        do {
          cout << "Neptun kodja: ";
          cin >> t[i].neptun;
        } while(not neptunell(t[i].neptun));
        cout << "1. ZH pontszam: "; cin >> t[i].zh1;
        cout << "1. javito ZH pontszam: "; cin >> t[i].pzh1;
        cout << "2. ZH pontszam: "; cin >> t[i].zh2;
        cout << "2. javito ZH pontszam: "; cin >> t[i].pzh2;
        cin.ignore(); // Pufferbol torli a kov. karaktert, ami a beleragadt: \n
      }
    }
	}
	return i-1;
}

inline int max(int a, int b) {
	return a > b ? a : b;
}

void listazas(ostream& of, hallgato t[], int db) {
	of << "Nev\t\tNeptun\t1.ZH\t1. jav.\t2.ZH\t2. jav.\tAlairas\tMegajanlott\n";
	for(int i = 0; i < db; i++) {
		of << t[i].nev << "\t" << t[i].neptun << '\t' 
       << t[i].zh1 << '\t' << t[i].pzh1 << '\t' 
       << t[i].zh2 << '\t' << t[i].pzh2 << '\t';
		int osszeg = max(t[i].zh1, t[i].pzh1) + max(t[i].zh2, t[i].pzh2);
		if(osszeg >= 7)
			of << "Igen";
		else
			of << "Nem";
		of << '\t';
		switch(osszeg) {
      case 13: case 14: of << 5; break;
      case 11: case 12: of << 4; break;
      default: of << '-'; break;
		}
		of << endl;
	}
}

void buborek(hallgato t[], int n) {
	for(int i = n - 1; i >= 1; i--) {
		for(int k = 0; k < i; k++) {
			if(t[k].nev > t[k + 1].nev) {
				hallgato csere = t[k];
				t[k] = t[k + 1];
				t[k + 1] = csere;
			}
		}
	}
}

#define MAX 25
int main(int argc, char* argv[]) {
	hallgato ht[MAX];
	int db;
	bool fajlba = argc==2;
	srand((unsigned)time(NULL));
	cout << "Adminisztracios program\n";
	db = beolvas(ht, MAX);
	buborek(ht, db);
  cout << "Eredmenyek:\n";
  listazas(cout, ht, db);
	if(fajlba) {
		ofstream f(argv[1]);
		if(f.is_open()) {
			listazas(f, ht, db);
			f.close();
		}
	}
	return 0;
}
