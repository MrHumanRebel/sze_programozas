#include <iostream>
#include <fstream>
using namespace std;

#define IDOMERES_FAJLNEV "idomeres.txt"
#define FUTOK_FAJLNEV "futok_nevei.txt"

struct ido
{
  int ora;
  int perc;
  int masodperc;
};

struct reszeredmeny
{
  int rajtszam;
  int ellenorzoPont;
  ido erkezesiIdo;
  reszeredmeny *kov;
};

struct futo
{
  int rajtszam;
  string nev;
  reszeredmeny *kezdo;
};

string sorFeldarabol(string &sor, int &szokozHelye)
{
  if (szokozHelye > 0)
    sor = sor.substr(szokozHelye + 1);

  szokozHelye = sor.find(' ');
  string aktElem = sor.substr(0, szokozHelye);

  return aktElem;
}

void reszeredmenyBeszur(int rajtszam, int ellenorzoPont, ido erkezesiIdo, reszeredmeny *elozo)
{

}

reszeredmeny *reszeredmenyBetolt(string fajlnev, reszeredmeny *horgony, int &futokDb)
{
  ifstream fajl(fajlnev);
  if (fajl.is_open())
  {
    string aktSor;
    reszeredmeny *aktReszeredmeny = NULL;

    // A futók száma az idomeres.txt fájlban tároljuk
    getline(fajl, aktSor);
    futokDb = stoi(aktSor);

    while (getline(fajl, aktSor))
    {
      int szokozHelye = -1;
      int rajtszam = stoi(sorFeldarabol(aktSor, szokozHelye));

      int ellenorzoPont = stoi(sorFeldarabol(aktSor, szokozHelye));

      int ora = stoi(sorFeldarabol(aktSor, szokozHelye));
      int perc = stoi(sorFeldarabol(aktSor, szokozHelye));
      int masodperc = stoi(sorFeldarabol(aktSor, szokozHelye));

      ido erkezesiIdo = {ora, perc, masodperc};
    }

    fajl.close();
  }

  return horgony;
}

void reszeredmenyTorol(reszeredmeny *kezdo)
{
}

int main(int argc, char const *argv[])
{
  cout << "Futoverseny" << endl;

  reszeredmeny *kezdo = NULL;
  int futokDb;
  kezdo = reszeredmenyBetolt(IDOMERES_FAJLNEV, kezdo, futokDb);

  return 0;
}
