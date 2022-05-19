#include <iostream>
#include <fstream>
using namespace std;

#define IDOMERES_FAJLNEV "idomeres.txt"
#define FUTOK_FAJLNEV "futok_nevei.txt"
#define ELL_PONT_DB 6
#define ELL_PONT_BUNT 20 // Percben megadva

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
  ido eredmeny;
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

int idoAtvalt(ido aktIdo)
{
  int oraMp = aktIdo.ora * 3600;
  int percMp = aktIdo.perc * 60;

  return oraMp + percMp + aktIdo.masodperc;
}

ido mpAtvalt(int aktMp)
{
  int ora = aktMp / 3600;
  int perc = (aktMp % 3600) / 60;
  int masodperc = (aktMp % 3600) % 60;

  ido aktIdo = {ora, perc, masodperc};
  return aktIdo;
}

ido eredmenySzamol(reszeredmeny *futoHorgony)
{
  reszeredmeny *akt = futoHorgony;

  // Első (0.) teljesített állomás részideje
  int reszidoMin = idoAtvalt(futoHorgony->erkezesiIdo);

  // Utolsó teljesített állomás részideje
  int reszidoMax = idoAtvalt(futoHorgony->erkezesiIdo);

  // Teljesített állomások darabszáma (büntetés számításához)
  int allomasDb = 0;

  while (akt)
  {
    int reszidoAkt = idoAtvalt(akt->erkezesiIdo);
    if (reszidoMin > reszidoAkt)
      reszidoMin = reszidoAkt;

    if (reszidoMax < reszidoAkt)
      reszidoMax = reszidoAkt;

    allomasDb++;

    akt = akt->kov;
  }

  int teljesitesiIdo = reszidoMax - reszidoMin;
  teljesitesiIdo += (ELL_PONT_DB - allomasDb) * ELL_PONT_BUNT * 60;

  ido eredmeny = mpAtvalt(teljesitesiIdo);

  return eredmeny;
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
      ido eredmeny = eredmenySzamol(futoReHorgony);

      futok[aktFuto] = {rajtszam, nev, futoReHorgony, eredmeny};
      aktFuto++;
    }

    fajl.close();
  }
}

void futoRendez(futo futok[], int futokDb)
{
  // Buborékrendezés
  for (int i = 0; i < futokDb; i++)
  {
    for (int j = 1; j < futokDb - i; j++)
    {
      if (idoAtvalt(futok[j - 1].eredmeny) > idoAtvalt(futok[j].eredmeny))
      {
        futo csere = futok[j - 1];
        futok[j - 1] = futok[j];
        futok[j] = csere;
      }
    }
  }
}

string idoFormaz(int idoKomponens)
{
  return to_string(idoKomponens).length() == 1 ? '0' + to_string(idoKomponens) : to_string(idoKomponens);
}

void eredmenyKiir(futo futok[], int futokDb)
{
  for (int i = 0; i < futokDb; i++)
  {
    string aktEredmeny = idoFormaz(futok[i].eredmeny.ora) + ':' + idoFormaz(futok[i].eredmeny.perc) + ':' + idoFormaz(futok[i].eredmeny.masodperc);
    cout << futok[i].rajtszam << ' ' << aktEredmeny << endl;
  }
}

void reszeredmenyTorol(reszeredmeny *akt)
{
  reszeredmeny *kov;
  while (akt)
  {
    kov = akt->kov;
    delete akt;
    akt = kov;
  }
}

int main(int argc, char const *argv[])
{
  reszeredmeny *horgony = NULL;
  int futokDb;
  horgony = reszeredmenyBetolt(IDOMERES_FAJLNEV, horgony, futokDb);

  futo futok[futokDb];
  futoBetolt(FUTOK_FAJLNEV, futok, futokDb, horgony);
  futoRendez(futok, futokDb);
  eredmenyKiir(futok, futokDb);

  reszeredmenyTorol(horgony);

  return 0;
}
