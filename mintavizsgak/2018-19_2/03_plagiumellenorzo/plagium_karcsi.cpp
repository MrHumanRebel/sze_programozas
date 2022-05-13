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

int main(int argc, char const *argv[])
{
  cout << KEZDO << endl;
  mu *publikaciok = NULL;
  publikaciok = muFeltolt(publikaciok);

  muKiir(publikaciok);
  muTorolMind(publikaciok);

  return 0;
}
