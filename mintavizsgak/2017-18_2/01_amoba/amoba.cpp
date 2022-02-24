#include <iostream>
using namespace std;

#define MAX 20


struct meret
{
  int sor;
  int oszlop;
};

int meretBekerese(string tipus)
{
  bool helytelenMeret = false;
  int meret;

  do
  {
    if (helytelenMeret)
    {
      cout << "Nem megfelelő méret, a pálya " << tipus << " a [7, 20] intervallumba kell esni." << endl;
    }

    cout << "Kérem adja meg a pálya " << tipus << " a számát: ";
    cin >> meret;

    helytelenMeret = true;
  } while (meret < 7 || meret > 20);

  return meret;
}

meret init()
{
  meret palyaMeret;
  palyaMeret.sor = meretBekerese("sorainak");
  palyaMeret.oszlop = meretBekerese("oszlopainak");

  system("clear");
  return palyaMeret;
}

void jatek(meret palyaMeret)
{
  cout << "Amoba jatek" << endl;
}

void palyaFelallitas(meret palyaMeret)
{
  // TODO: Implementáld
}

void lepes()
{
  // TODO: Implementáld
}

void ellenoriz()
{
  // TODO: Implementáld
}

void palyaMegjelenit()
{
  // TODO: Implementáld
}

int main(int argc, char const *argv[])
{
  meret palyaMeret = init();
  jatek(palyaMeret);

  return 0;
}
