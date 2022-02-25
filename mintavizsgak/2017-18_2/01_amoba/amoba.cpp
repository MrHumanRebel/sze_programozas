#include <iostream>
using namespace std;

#define MAX 20
#define TAL 5 // A győzelemhez szükséges mezők száma
#define J1 'X'
#define J2 'O'

struct meret
{
  int sor;
  int oszlop;
};

struct mezo
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

int mezoBeker(char jatekos, int meret, string tipus)
{
  int mezo;

  string jatekosNeve = jatekos == J1 ? "Elso" : "Masodik";
  bool helytelenMezo = false;
  do
  {
    if (helytelenMezo)
    {
      cout << "Nem megfelelő " << tipus << "szám" << endl;
    }

    cout << jatekosNeve << " jatekos lepese, " << tipus << ": ";
    string ertek;
    cin >> ertek;

    mezo = tipus == "sor" ? stoi(ertek) - 1 : ertek[0] - 'A';
    helytelenMezo = mezo < 0 || mezo > meret;
  } while (helytelenMezo);

  return mezo;
}

void lepes(char jatekos, char palya[MAX][MAX], meret palyaMeret)
{
  mezo m;

  bool helytelenLepes = false;
  do
  {
    if (helytelenLepes)
    {
      cout << "Ez a mező már foglalt." << endl;
    }

    m.sor = mezoBeker(jatekos, palyaMeret.sor, "sor");
    m.oszlop = mezoBeker(jatekos, palyaMeret.oszlop, "oszlop");

    helytelenLepes = palya[m.sor][m.oszlop] != '.';
  } while (helytelenLepes);

  palya[m.sor][m.oszlop] = jatekos;
}

bool ellenoriz(char jatekos, char palya[MAX][MAX], meret palyaMeret)
{
  // Horizontális
  for (int i = 0; i < palyaMeret.sor; i++)
  {
    int talalat = 0;

    int kezdOszlop = 0;
    int vegOszlop = kezdOszlop + TAL - 1;
    while (vegOszlop < palyaMeret.oszlop && talalat < TAL)
    {
      talalat = 0;

      for (int j = kezdOszlop; j <= vegOszlop; j++)
      {
        if (palya[i][j] == jatekos)
        {
          talalat++;
        }
      }

      kezdOszlop++;
      vegOszlop++;
    }

    if (talalat == TAL)
    {
      return true;
    }
  }

  return false;
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

  char aktJatekos = J2;
  bool gyozelem = false;
  do
  {
    aktJatekos = aktJatekos == J1 ? J2 : J1;

    palyaMegjelenit(palya, palyaMeret);
    lepes(aktJatekos, palya, palyaMeret);
    gyozelem = ellenoriz(aktJatekos, palya, palyaMeret);

    if (!gyozelem)
    {
      system("clear");
    }

  } while (!gyozelem);

  if (gyozelem)
  {
    string gyoztesNeve = aktJatekos == J1 ? "elso" : "masodik";
    cout << "A(z) " << gyoztesNeve << " jatekos gyozott.";
  }
}

int main(int argc, char const *argv[])
{
  meret palyaMeret = init();
  jatek(palyaMeret);

  return 0;
}
