#include <iostream>
using namespace std;

#define MAX 20
#define J1 'X'
#define J2 'O'

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
  int meret;

  bool helytelenMeret = false;
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
  bool helytelenKoordinata = false;
  do
  {
    if (helytelenKoordinata)
    {
      cout << "Nem megfelelő " << tipus << "szám" << endl;
    }

    cout << "Kérem adjon meg egy " << tipus << rag << ": ";
    string ertek;
    cin >> ertek;

    koordinata = tipus == "sor" ? stoi(ertek) - 1 : ertek[0] - 'A';
    helytelenKoordinata = koordinata < 0 || koordinata > meret;
  } while (helytelenKoordinata);

  return koordinata;
}

void lepes(char jatekos, char palya[MAX][MAX], meret palyaMeret)
{
  koordinata k;

  bool helytelenLepes = false;
  do
  {
    if (helytelenLepes)
    {
      cout << "Ez a mező már foglalt." << endl;
    }

    k.sor = koordinataBeker(palyaMeret.sor, "sor");
    k.oszlop = koordinataBeker(palyaMeret.oszlop, "oszlop");

    helytelenLepes = palya[k.sor][k.oszlop] != '.';
  } while (helytelenLepes);

  palya[k.sor][k.oszlop] = jatekos;
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
    string aktSorszam = to_string(i + 1);
    aktSorszam = aktSorszam.length() == 1 ? "0" + aktSorszam : aktSorszam;
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
  do
  {
    for (int i = 0; i < 2; i++)
    {
      char jelenlegiJatekos = i == 0 ? J1 : J2;

      palyaMegjelenit(palya, palyaMeret);
      lepes(jelenlegiJatekos, palya, palyaMeret);
      system("clear");
    }

  } while (true);
}

int main(int argc, char const *argv[])
{
  meret palyaMeret = init();
  jatek(palyaMeret);

  return 0;
}
