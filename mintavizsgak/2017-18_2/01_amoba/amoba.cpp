#include <iostream>
using namespace std;

#define MAX 20
#define LMAX 100

struct meret
{
  int sor;
  int oszlop;
};

struct koordinata
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

    helytelenMeret = meret < 7 || meret > 20;
  } while (helytelenMeret);

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

int koordinataBeker(int meret, string tipus)
{
  int koordinata;

  string rag = tipus == "sor" ? "t" : "ot";
  bool hibas = false;
  do
  {
    if (hibas)
    {
      cout << "Nem megfelelő " << tipus << "szám" << endl;
    }

    cout << "Kérem adjon meg egy " << tipus << rag << ": ";
    string ertek;
    cin >> ertek;

    koordinata = tipus == "sor" ? stoi(ertek) - 1 : ertek[0] - 'A';
    hibas = true;
  } while (koordinata < 0 || koordinata > meret);

  return koordinata;
}

bool helyesLepes(koordinata k, koordinata lepesek[LMAX], int lepesekDb)
{
  int i = 0;
  while (k.sor != lepesek[i].sor && k.oszlop != lepesek[i].oszlop && i < lepesekDb)
  {
    i++;
  }

  return i >= lepesekDb;
}

void lepes(char palya[MAX][MAX], koordinata lepesek[LMAX], meret palyaMeret, int lepesekDb)
{
  koordinata k;

  bool hibas = false;
  do
  {
    if (hibas)
    {
      cout << "Nem megfelelő lépés." << endl;
    }

    k.sor = koordinataBeker(palyaMeret.sor, "sor");
    k.oszlop = koordinataBeker(palyaMeret.oszlop, "oszlop");

    hibas = true;
    if (hibas)
    {
      cout << "Nem megfelelő lépés." << endl;
    }
  } while (!helyesLepes(k, lepesek, lepesekDb));

  lepesek[lepesekDb] = k;
  lepesekDb++;

  palya[k.sor][k.oszlop] = 'X';

  // system("clear");
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

void jatek(meret palyaMeret, int lepesekDb)
{
  cout << "Amoba jatek" << endl;

  char palya[MAX][MAX];
  koordinata lepesek[LMAX];

  palyaFelallit(palya, palyaMeret);

  do
  {
    palyaMegjelenit(palya, palyaMeret);
    lepes(palya, lepesek, palyaMeret, lepesekDb);
    system("clear");
  } while (true);
}

int main(int argc, char const *argv[])
{
  meret palyaMeret = init();
  int lepesekDb = 0;
  jatek(palyaMeret, lepesekDb);

  return 0;
}
