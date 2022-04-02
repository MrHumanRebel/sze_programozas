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
  reszeredmeny *kezdoRe;
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

reszeredmeny *reszeredmenyKeres(int keresettRajtszam, reszeredmeny *futoHorgony, reszeredmeny *horgony)
{
  reszeredmeny *aktFuto = NULL;

  reszeredmeny *akt = horgony;
  while (akt)
  {
    if (akt->rajtszam == keresettRajtszam)
    {
      aktFuto = reszeredmenyBeszur(akt->rajtszam, akt->ellenorzoPont, akt->erkezesiIdo, aktFuto);
      if (!futoHorgony)
        futoHorgony = aktFuto;
    }

    akt = akt->kov;
  }

  return futoHorgony;
}

void futoBetolt(string fajlnev, futo futok[], int futokDb, reszeredmeny *horgony)
{
  ifstream fajl(fajlnev);
  if (fajl.is_open())
  {
    string aktSor;
    int aktFuto = 0;
    while (getline(fajl, aktSor) && aktFuto < futokDb)
    {
      int szokozHelye = -1;

      int rajtszam = stoi(sorFeldarabol(aktSor, szokozHelye));
      string nev = sorFeldarabol(aktSor, szokozHelye);

      reszeredmeny *futoReHorgony = NULL;
      futoReHorgony = reszeredmenyKeres(rajtszam, futoReHorgony, horgony);

      futok[aktFuto] = {rajtszam, nev, futoReHorgony};
      aktFuto++;
    }

    fajl.close();
  }
}

string idoFormaz(int idoKomponens)
{
  return to_string(idoKomponens).length() == 1 ? '0' + to_string(idoKomponens) : to_string(idoKomponens);
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
  reszeredmeny *horgony = NULL;
  int futokDb;
  horgony = reszeredmenyBetolt(IDOMERES_FAJLNEV, horgony, futokDb);

  futo futok[futokDb];
  futoBetolt(FUTOK_FAJLNEV, futok, futokDb, horgony);

  reszeredmenyTorol(horgony);

  return 0;
}
