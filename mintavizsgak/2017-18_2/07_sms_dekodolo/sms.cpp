#include <iostream>
#include <fstream>
using namespace std;

#define HIBAS_KAR '>'

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

char ertekKeres(char billentyu, int db)
{
  kodPar kodtabla[] = {
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
  int kodtablaHossz = sizeof(kodtabla) / sizeof(kodtabla[0]);

  int i = 0;
  while (i < kodtablaHossz && kodtabla[i].billentyu != billentyu)
  {
    i++;
  }

  int keresettIndex = db - 1;
  if (i < kodtablaHossz && db < kodtabla[i].ertekDb)
  {
    return kodtabla[i].ertekek[keresettIndex];
  }

  // Hibás billentyű/billentyűlenyomások esetén
  return HIBAS_KAR;
}

string ertekHozzafuz(char kar, int karDb, string szoveg, bool &nagybetus)
{
  char aktErtek = ertekKeres(kar, karDb);
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

string dekodol(string kodoltSzoveg)
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
      dekodoltSzoveg = aktKar == ' ' ? csoportEllenoriz(dekodoltSzoveg) : ertekHozzafuz(aktKar, aktKarDb, dekodoltSzoveg, nagybetus);

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

void mentes(string uzenet, string fajlnev)
{
  ofstream fajl(fajlnev);

  fajl << uzenet.c_str() << endl;
  fajl.close();
}

int main(int argc, char const *argv[])
{
  string inputFajlnev = argv[1];
  string input = betolt(inputFajlnev);
  cout << "Input: " << input << endl;

  string dekodoltSzoveg = dekodol(input);
  cout << "Output: " << dekodoltSzoveg << endl;

  string outputFajlnev = argv[2];
  mentes(dekodoltSzoveg, outputFajlnev);

  return 0;
}
