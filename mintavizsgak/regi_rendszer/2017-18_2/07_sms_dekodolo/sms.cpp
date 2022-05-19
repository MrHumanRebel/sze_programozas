#include <iostream>
#include <fstream>
using namespace std;

#define BILL_N 12
#define HIBAS_KAR '>'
#define DEKOD_INPUT "55*3355#29999#334#337777#99996665553#2#333881 1 1"
#define KOD_INPUT "Kek az eg es zold a fu..."

struct kodPar
{
  char billentyu;
  char ertekek[6];
  int ertekDb;
};

string betolt(string fajlnev)
{
  ifstream fajl(fajlnev);

  string sor;
  getline(fajl, sor);
  fajl.close();

  return sor;
}

char ertekKeres(char billentyu, int db, kodPar kodtabla[BILL_N])
{
  int i = 0;
  while (i < BILL_N && kodtabla[i].billentyu != billentyu)
  {
    i++;
  }

  int keresettIndex = db - 1;
  if (i < BILL_N && db < kodtabla[i].ertekDb)
  {
    return kodtabla[i].ertekek[keresettIndex];
  }

  // Hibás billentyű/billentyűlenyomások esetén
  return HIBAS_KAR;
}

string ertekHozzafuz(char kar, int karDb, kodPar kodtabla[BILL_N], string szoveg, bool &nagybetus)
{
  char aktErtek = ertekKeres(kar, karDb, kodtabla);
  switch (aktErtek)
  {
  case 'k':
  case 'n':
    nagybetus = aktErtek == 'n';
    break;

  default:
    szoveg += nagybetus ? aktErtek : tolower(aktErtek);
    break;
  };

  return szoveg;
}

string csoportEllenoriz(string szoveg)
{
  bool helyes = szoveg.find(HIBAS_KAR) >= szoveg.length();

  return helyes ? szoveg : "";
}

string dekodol(string kodoltSzoveg, kodPar kodtabla[BILL_N])
{
  string dekodoltSzoveg = "";
  bool nagybetus = true;

  char aktKar = kodoltSzoveg[0];
  int aktKarDb = 1;

  size_t i = 1;
  while (i <= kodoltSzoveg.length())
  {
    if (aktKar != kodoltSzoveg[i])
    {
      dekodoltSzoveg = aktKar == ' ' ? csoportEllenoriz(dekodoltSzoveg) : ertekHozzafuz(aktKar, aktKarDb, kodtabla, dekodoltSzoveg, nagybetus);

      aktKar = kodoltSzoveg[i];
      aktKarDb = 1;
    }
    else
    {
      aktKarDb++;
    }

    i++;
  }

  return dekodoltSzoveg;
}

string billentyuKeres(char ertek, bool &nagybetus, bool ujCsoport, kodPar kodtabla[BILL_N])
{
  string eredmeny = ujCsoport ? " " : "";

  /* XOR, csak akkor váltunk, ha eltér egymástól a két érték

     A sima összehasonlítás nem működik,
     hisz nem 0/1-et vagy true/false értéket ad vissza,
     hanem egy konkrét int-et (0-t, ha nem nagybetűs)
  */
  if (nagybetus && isupper(ertek) == 0)
  {
    eredmeny = isupper(ertek) ? "**" : "*";
    nagybetus = !nagybetus;
  }

  char keresettBillentyu;
  int billentyuDb = 0;
  bool ertekMegvan = false;

  int i = 0;
  while (i < BILL_N && !ertekMegvan)
  {
    kodPar aktKodPar = kodtabla[i];

    int j = 0;
    while (j < aktKodPar.ertekDb && !ertekMegvan)
    {
      if (aktKodPar.ertekek[j] == toupper(ertek))
      {
        keresettBillentyu = kodtabla[i].billentyu;
        billentyuDb = j + 1;
        ertekMegvan = true;
      }

      j++;
    }

    i++;
  }

  eredmeny += ertekMegvan ? string(billentyuDb, keresettBillentyu) : string(1, HIBAS_KAR);
  return eredmeny;
}

string kodol(string szoveg, kodPar kodtabla[BILL_N])
{
  bool nagybetus = isupper(szoveg[0]);
  string kodoltSzoveg = nagybetus ? "" : "*";

  bool ujCsoport = false;
  for (size_t i = 0; i < szoveg.length(); i++)
  {
    ujCsoport = i > 0 ? szoveg[i - 1] == szoveg[i] : false;
    kodoltSzoveg += billentyuKeres(szoveg[i], nagybetus, ujCsoport, kodtabla);
  }

  return kodoltSzoveg;
}

void mentes(string uzenet, string fajlnev)
{
  ofstream fajl(fajlnev);

  fajl << uzenet.c_str() << endl;
  fajl.close();
}

int main(int argc, char const *argv[])
{
  kodPar kodtabla[BILL_N] = {
      {'1', {'.', ',', '-', '?', '!', '1'}, 6},
      {'2', {'A', 'B', 'C', '2'}, 4},
      {'3', {'D', 'E', 'F', '3'}, 4},
      {'4', {'G', 'H', 'I', '4'}, 4},
      {'5', {'J', 'K', 'L', '5'}, 4},
      {'6', {'M', 'N', 'O', '6'}, 4},
      {'7', {'P', 'Q', 'R', 'S', '7'}, 5},
      {'8', {'T', 'U', 'V', '8'}, 4},
      {'9', {'W', 'X', 'Y', 'Z', '9'}, 5},
      {'*', {'k', 'n', '*'}, 3}, // k == kisbetű, n == nagybetű
      {'0', {'+', '0'}, 2},
      {'#', {' ', '#'}, 2},
  };

  // Első argumentum az inputot tartalmazó szöveges fájl
  string input = argc == 3 ? betolt(argv[1]) : KOD_INPUT;
  cout << "Input: " << input << endl;

  string eredmeny = kodol(input, kodtabla);

  if (argc == 3)
  {
    string outputFajlnev = argv[2];
    mentes(eredmeny, outputFajlnev);
  }
  cout << "Output: " << eredmeny << endl;

  return 0;
}
