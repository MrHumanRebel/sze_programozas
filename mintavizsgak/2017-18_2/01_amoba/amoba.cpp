#include <iostream>
using namespace std;

#define MAX 20
#define TAL 5           // A győzelemhez szükséges mezők száma
#define ELL_MOD TAL + 1 // ellenorzes() függvényben használt
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
      cout << "Nem megfelelo meret, a palya " << tipus << " a [7, 20] intervallumba kell esni." << endl;
    }

    cout << "Kerem adja meg a palya " << tipus << " a szamat: ";
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
      cout << "Nem megfelelo " << tipus << endl;
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
      cout << "Ez a mezo mar foglalt." << endl;
    }

    m.sor = mezoBeker(jatekos, palyaMeret.sor, "sor");
    m.oszlop = mezoBeker(jatekos, palyaMeret.oszlop, "oszlop");

    helytelenLepes = palya[m.sor][m.oszlop] != '.';
  } while (helytelenLepes);

  palya[m.sor][m.oszlop] = jatekos;
}

bool iranyEllenoriz(char tengely, char atlo, char jatekos, char palya[MAX][MAX], meret palyaMeret)
{
  int allTengely;  // Külső ciklus
  int valtTengely; // Belső ciklus

  if (tengely != '-')
  {
    allTengely = tengely == 'h' ? palyaMeret.sor : palyaMeret.oszlop;
    valtTengely = tengely == 'h' ? palyaMeret.oszlop - ELL_MOD : palyaMeret.sor - ELL_MOD;
  }
  else
  {
    allTengely = palyaMeret.sor - ELL_MOD;
    valtTengely = palyaMeret.oszlop - ELL_MOD;
  }

  for (int i = 0; i < allTengely; i++)
  {
    for (int j = 0; j < valtTengely; j++)
    {
      // Csak átló esetén
      int oszlop = atlo == 'k' ? (palyaMeret.oszlop - 1) - j : j;

      int talalat = 0;
      int aktEltolas = 0;
      while (aktEltolas < TAL && talalat < TAL)
      {
        int aktAll = atlo != '-' ? i + aktEltolas : i;
        int aktMellek = atlo == 'k' ? oszlop - aktEltolas : j + aktEltolas;

        char aktMezo = tengely == 'h' || atlo != '-' ? palya[aktAll][aktMellek] : palya[aktMellek][aktAll];

        if (aktMezo == jatekos)
        {
          talalat++;
        }

        aktEltolas++;
      }

      if (talalat == TAL)
      {
        return true;
      }
    }
  }

  return false;
}

bool ellenoriz(char jatekos, char palya[MAX][MAX], meret palyaMeret)
{

  bool tengelyGyozelem = iranyEllenoriz('h', '-', jatekos, palya, palyaMeret) || iranyEllenoriz('v', '-', jatekos, palya, palyaMeret);
  bool atlosGyozelem = iranyEllenoriz('-', 'n', jatekos, palya, palyaMeret) || iranyEllenoriz('-', 'k', jatekos, palya, palyaMeret);

  return tengelyGyozelem || atlosGyozelem;
}

void palyaMegjelenit(char palya[MAX][MAX], meret palyaMeret)
{
  cout << "Amoba jatek" << endl;

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
  char palya[MAX][MAX];
  palyaFelallit(palya, palyaMeret);

  char aktJatekos = J2;

  bool gyozelem = false;
  int elerhetoMezok = palyaMeret.sor * palyaMeret.oszlop;
  do
  {
    aktJatekos = aktJatekos == J1 ? J2 : J1;

    palyaMegjelenit(palya, palyaMeret);
    lepes(aktJatekos, palya, palyaMeret);
    gyozelem = ellenoriz(aktJatekos, palya, palyaMeret);

    elerhetoMezok--;
    if (!gyozelem && elerhetoMezok > 0)
    {
      system("clear");
    }

  } while (!gyozelem && elerhetoMezok > 0);

  if (gyozelem)
  {
    string gyoztesNeve = aktJatekos == J1 ? "elso" : "masodik";
    cout << "A(z) " << gyoztesNeve << " jatekos gyozott.";
  }
  else
  {
    cout << "Döntetlen.";
  }
}

int main(int argc, char const *argv[])
{
  meret palyaMeret = init();
  jatek(palyaMeret);

  return 0;
}
