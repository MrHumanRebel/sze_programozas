#include <iostream>

using namespace std;

#define KEZDO "Egyszeru plagiumellenorzo szoftver; kilepes ures sor megadasaval."
#define TUDOS "Tudos neve: "
#define TART "Mu: "
#define DATUM "Datum: "

#define URES "--- Ures sort adtak meg, beolvasas vege. ---"

struct mu
{
  string tudosNeve;
  string tartalom;
  string datum;

  mu *kov;
};

mu *muBeszur(string tudosNeve, string tartalom, string datum, mu *elozo)
{
  mu *uj = new mu;

  if (uj)
  {
    uj->tudosNeve = tudosNeve;
    uj->tartalom = tartalom;
    uj->datum = datum;

    if (elozo)
    {
      uj->kov = elozo->kov;
      elozo->kov = uj;
    }
    else
    {
      uj->kov = NULL;
    }
  }

  return uj;
}

void muKiir(mu *horgony)
{
  while (horgony)
  {
    cout << horgony->tudosNeve << " (" << horgony->datum << ")" << endl;
    cout << TART
         << horgony->tartalom << endl;
    cout << endl;

    horgony = horgony->kov;
  }
}

void muTorolMind(mu *horgony)
{
  while (horgony)
  {
    mu *kov = horgony->kov;
    delete horgony;
    horgony = kov;
  }
}

string adatBeker(string kisero, bool &kilep)
{
  string adat;

  cout << kisero;
  getline(cin, adat);

  if (adat.empty())
  {
    cout << URES << endl;
    kilep = true;
  }

  return adat;
}

mu *muFeltolt(mu *horgony)
{
  mu *akt = NULL;

  bool kilep = false;
  do
  {
    string tudosNeve = adatBeker(TUDOS, kilep);
    string tartalom = kilep ? "" : adatBeker(TART, kilep);
    string datum = kilep ? "" : adatBeker(DATUM, kilep);

    if (!kilep)
    {
      akt = muBeszur(tudosNeve, tartalom, datum, akt);
      if (!horgony)
        horgony = akt;
    }
  } while (!kilep);

  return horgony;
}

int datumFeldarabol(string &datum, int &kotojelHelye)
{
  if (kotojelHelye > 0)
    datum = datum.substr(kotojelHelye + 1);

  kotojelHelye = datum.find("-");
  int aktElem = stoi(datum.substr(0, kotojelHelye));

  return aktElem;
}

bool korabbiMu(string datum, string datum2)
{
  int kotojelHelye = -1;
  int kotojelHelye2 = -1;

  int ev = datumFeldarabol(datum, kotojelHelye);
  int ev2 = datumFeldarabol(datum2, kotojelHelye2);

  if (ev2 < ev)
    return false;

  int honap = datumFeldarabol(datum, kotojelHelye);
  int honap2 = datumFeldarabol(datum2, kotojelHelye2);

  if (ev == ev2 && honap > honap2)
    return false;

  int nap = datumFeldarabol(datum, kotojelHelye);
  int nap2 = datumFeldarabol(datum2, kotojelHelye2);

  if (ev == ev2 && honap == honap2 && nap > nap2)
    return false;

  return true;
}

int mennyireEgyezik(string tartalom, string tartalom2, double minSzazalek)
{
  int egyezikDb = 0;

  int karDb = tartalom < tartalom2 ? tartalom.length() : tartalom2.length();
  for (int i = 0; i < karDb; i++)
  {
    if (tartalom[i] == tartalom2[i])
      egyezikDb++;
  }

  if (minSzazalek > 0)
  {
    double szazalekPlagizalt = (egyezikDb * 1.0 / tartalom.length()) * 100;
    egyezikDb = szazalekPlagizalt < minSzazalek ? 0 : egyezikDb;
  }

  return egyezikDb;
}

string szerzoEllenoriz(string nev, string tartalom, string datum, mu *horgony, double minSzazalek)
{
  string eredmeny = "";

  while (horgony)
  {
    if (nev != horgony->tudosNeve && korabbiMu(horgony->datum, datum))
    {
      int egyezikDb = mennyireEgyezik(tartalom, horgony->tartalom, minSzazalek);
      if (egyezikDb > 0)
      {
        eredmeny = eredmeny == "" ? "csalt (lopott tole: " : eredmeny;
        eredmeny += horgony->tudosNeve + ", ";
      }
    }

    horgony = horgony->kov;
  }

  if (eredmeny == "")
  {
    eredmeny = "becsuletes, nem csalt";
  }
  else
  {
    eredmeny = eredmeny.substr(0, eredmeny.length() - 2);
    eredmeny += ")";
  }

  return eredmeny;
}

int main(int argc, char const *argv[])
{
  cout << KEZDO << endl;
  mu *publikaciok = NULL;
  publikaciok = muFeltolt(publikaciok);

  double szazalekMegengedett = argc == 2 ? stod(argv[1]) : 0;
  mu *aktPubl = publikaciok;
  while (aktPubl)
  {
    string eredmeny = szerzoEllenoriz(aktPubl->tudosNeve, aktPubl->tartalom, aktPubl->datum, publikaciok, szazalekMegengedett);

    cout << aktPubl->tudosNeve << " - " << eredmeny << endl;
    aktPubl = aktPubl->kov;
  }

  muTorolMind(publikaciok);

  return 0;
}
