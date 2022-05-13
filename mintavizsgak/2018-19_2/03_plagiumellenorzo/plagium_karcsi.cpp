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

  cout << "Ev: " << ev << " - " << ev2 << endl;
  if (ev2 < ev)
    return false;

  int honap = datumFeldarabol(datum, kotojelHelye);
  int honap2 = datumFeldarabol(datum2, kotojelHelye2);

  cout << "Honap: " << honap << " - " << honap2 << endl;
  if (ev == ev2 && honap > honap2)
    return false;

  int nap = datumFeldarabol(datum, kotojelHelye);
  int nap2 = datumFeldarabol(datum2, kotojelHelye2);

  cout << "Nap: " << nap << " - " << nap2 << endl;
  if (ev == ev2 && honap == honap2 && nap > nap2)
    return false;

  return true;
}

// TODO: Implementáld
string szerzoEllenoriz(string nev, string datum, mu *horgony)
{
  string eredmeny;

  while (horgony)
  {
    

    horgony = horgony->kov;
  }

  return eredmeny;
}

int main(int argc, char const *argv[])
{
  cout << KEZDO << endl;
  mu *publikaciok = NULL;
  publikaciok = muFeltolt(publikaciok);

  muKiir(publikaciok);
  muTorolMind(publikaciok);

  return 0;
}
