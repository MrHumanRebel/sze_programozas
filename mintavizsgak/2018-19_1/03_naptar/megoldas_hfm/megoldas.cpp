#include <iostream>
#include <cstdlib>
#include <fstream>
#include "datum2.h"

#define FAJLNEV "unnepnapok.txt"

using namespace std;

enum tipus { munka, szabadsag, hetvege, unnep };

void inicializal(string fajlnev, int ev, int* nyilvantartas, int napok) {
  for(int n=1; n<=napok; n++) {
    datum d = hoEsNap(ev, n);
    string hn = hetNapja(&d);
    if(hn=="szombat" or hn=="vasarnap") {
      nyilvantartas[n-1] = hetvege;
    } else {
      nyilvantartas[n-1] = munka;
    }
  }
  ifstream i(fajlnev);
  if(i.is_open()) {
    string sor;
    while(getline(i, sor), not i.eof()) {
      datum d;
      d.ev = ev;
      d.ho = atoi(sor.c_str());
      d.nap = atoi(sor.c_str()+3);
      nyilvantartas[evNapja(&d)-1] = unnep;
    }
    i.close();
  }
}

void megjelenit(int ev, int* nyilvantartas) {
  static char rajzKar[] = { '-', 's', 'h', 'u' };
  cout << "   ";
  for(int n=1; n<=31; n++) {
    if(int egesz=n/10) {
      cout << egesz;
    } else {
      cout << ' ';
    }
  }
  cout << "\n   ";
  for(int n=1; n<=31; n++) {
    cout << n%10;
  }
  for(int h=1; h<=12; h++) {
    cout << endl;
    if(h<10) cout << ' ';
    cout << h << ' ';
    for(int n=1; n<=napok(ev, h); n++) {
      datum d = { ev, h, n };
      cout << rajzKar[nyilvantartas[evNapja(&d)-1]];
    }
  }
  cout << endl;
}

int main(int argc, char* argv[]) {
  int ev = 2019;
  if(argc == 2) {
    ev = atoi(argv[1]);
  }
  int napok = 365 + (szoko(ev)?1:0);
  int nyilvantartas[napok];
  inicializal(FAJLNEV, ev, nyilvantartas, napok);
  cout << "Szabadsag nyilvantartas. Kilepes 40 nap szabadsag kiirasa utan.\n";
  datum kezdo, zaro;
  kezdo.ev = zaro.ev = ev;
  int szabOssz = 0;
  while(szabOssz != 40) {
    cout << "Kezdo honap: "; cin >> kezdo.ho;
    cout << "Kezdo nap: "; cin >> kezdo.nap;
    cout << "Zaro honap: "; cin >> zaro.ho;
    cout << "Zaro nap: "; cin >> zaro.nap;
    int k = evNapja(&kezdo);
    int z = evNapja(&zaro);
    for(int n=k; n<=z; n++) {
      if(nyilvantartas[n-1] == munka) {
        nyilvantartas[n-1] = szabadsag;
        szabOssz++;
      } else if(nyilvantartas[n-1] == szabadsag) {
        nyilvantartas[n-1] = munka;
        szabOssz--;
      }
    }
    megjelenit(ev, nyilvantartas);
  }
  cout << "Pontosan 40 nap szabadsag, kilepes.\n";
  return 0;
}
