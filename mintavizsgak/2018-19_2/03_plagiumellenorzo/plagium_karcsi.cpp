#include <iostream>

using namespace std;

#define KEZDO "Egyszeru plagiumellenorzo szoftver; kilepes ures sor megadasaval."
#define TUDOS "Tudos neve: "
#define TART "Mu: "
#define DATUM "Datum: "

struct mu
{
  string tudosNeve;
  string tartalom;
  string datum;

  mu *kov;
};

mu *muBeszur(string tudosNeve, string datum, string tartalom, mu *elozo)
{
  mu *uj = new mu;

  if (uj)
  {
    uj->tudosNeve = tudosNeve;
    uj->datum = datum;
    uj->tartalom = tartalom;

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
    cout << TUDOS
         << horgony->tudosNeve << endl;
    cout << TART
         << horgony->tartalom << endl;
    cout << DATUM
         << horgony->datum << endl;

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

int main(int argc, char const *argv[])
{
  cout << KEZDO << endl;
  mu *publikaciok = NULL;

  muKiir(publikaciok);
  muTorolMind(publikaciok);

  return 0;
}
