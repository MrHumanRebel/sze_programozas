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

void palyaFelallit(char palya[MAX][MAX], meret palyaMeret)
{
  for (int i = 0; i < palyaMeret.sor; i++)
  {
    for (int j = 0; j < palyaMeret.oszlop; j++)
    {
      palya[i][j] = '.';
    }
  }
}

void lepes()
{
  // TODO: Implementáld
}

void ellenoriz()
{
  // TODO: Implementáld
}

void palyaMegjelenit(char palya[MAX][MAX], meret palyaMeret)
{
  // Fejléc (oszlopok)
  cout << "  ";
  char aktKar = 'A';
  for (int i = 0; i < palyaMeret.sor; i++)
  {
    cout << aktKar;
    aktKar++;
  }
  cout << endl;

  for (int i = 0; i < palyaMeret.sor; i++)
  {
    // 1 -> 01, 10 -> 10
    string aktSorszam = to_string(i + 1).length() == 1 ? "0" + to_string(i + 1) : to_string(i + 1);
    cout << aktSorszam;

    for (int j = 0; j < palyaMeret.oszlop; j++)
    {
      cout << palya[i][j];
    }

    cout << "\n";
  }
}

void jatek(meret palyaMeret)
{
  cout << "Amoba jatek" << endl;

  char palya[MAX][MAX];
  palyaFelallit(palya, palyaMeret);
  palyaMegjelenit(palya, palyaMeret);
}

int main(int argc, char const *argv[])
{
  meret palyaMeret = init();
  jatek(palyaMeret);

  return 0;
}
