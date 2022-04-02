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

reszeredmeny *reszeredmenyBeszur(int rajtszam, int ellenorzoPont, ido erkezesiIdo, reszeredmeny *elozo)
{
  reszeredmeny *uj = new reszeredmeny;

  uj->rajtszam = rajtszam;
  uj->ellenorzoPont = ellenorzoPont;
  uj->erkezesiIdo = erkezesiIdo;

  if (elozo)
  {
    uj->kov = elozo->kov;
    elozo->kov = uj;
  }
  else
  {
    uj->kov = NULL;
  }

  return uj;
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

      aktReszeredmeny = reszeredmenyBeszur(rajtszam, ellenorzoPont, erkezesiIdo, aktReszeredmeny);
      if (!horgony)
        horgony = aktReszeredmeny;
    }

    fajl.close();
  }

  return horgony;
}

string idoKiir(int idoKomponens)
{
  return to_string(idoKomponens).length() == 1 ? '0' + to_string(idoKomponens) : to_string(idoKomponens);
}

void reszeredmenyKiir(reszeredmeny *horgony)
{
  reszeredmeny *akt = horgony;
  while (akt)
  {
    cout << "Rajtszám: " << akt->rajtszam << '\n'
         << "Ellenőrző pont: " << akt->ellenorzoPont << '\n'
         << "Érkezési idő: " << idoKiir(akt->erkezesiIdo.ora) << ':' << idoKiir(akt->erkezesiIdo.perc) << ':' << idoKiir(akt->erkezesiIdo.masodperc) << '\n'
         << endl;

    akt = akt->kov;
  }
}

void reszeredmenyTorol(reszeredmeny *akt)
{
  reszeredmeny *kovEr;
  while (akt)
  {
    kovEr = akt->kov;
    delete akt;
    akt = kovEr;
  }
}

int main(int argc, char const *argv[])
{
  cout << "Futoverseny" << endl;

  reszeredmeny *kezdo = NULL;
  int futokDb;
  kezdo = reszeredmenyBetolt(IDOMERES_FAJLNEV, kezdo, futokDb);

  reszeredmenyKiir(kezdo);
  reszeredmenyTorol(kezdo);

  return 0;
}
