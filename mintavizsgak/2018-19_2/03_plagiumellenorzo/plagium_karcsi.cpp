#include <iostream>

using namespace std;

#define KEZDO "Egyszeru plagiumellenorzo szoftver; kilepes ures sor megadasaval."

struct mu
{
  string tudosNeve;
  string datum;
  string tartalom;

  mu *kov;
};

mu *beszur(string tudosNeve, string datum, string tartalom, mu *elozo)
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

int main(int argc, char const *argv[])
{
  cout << KEZDO << endl;
  return 0;
}
