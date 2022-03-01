#include <iostream>
using namespace std;

#define MAX 12

struct kodPar
{
  char billentyu;
  char ertekek[6];
  int ertekDb;
};

char ertekKeres(char billentyu, int db, kodPar kodtabla[MAX])
{
  int i = 0;
  while (i < MAX && kodtabla[i].billentyu != billentyu)
  {
    i++;
  }

  int keresettIndex = db - 1;
  if (i < MAX && db < kodtabla[i].ertekDb)
  {
    return kodtabla[i].ertekek[keresettIndex];
  }

  // Hibás billentyű/billentyűlenyomások esetén 
  return NULL;
}

string dekodol(string kodoltSzoveg)
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

  string dekodoltSzoveg = "";
  bool nagybetus = true;

  char aktKar = kodoltSzoveg[0];
  int aktKarDb = 1;

  size_t i = 1;
  while (i <= kodoltSzoveg.length())
  {
    if (kodoltSzoveg[i] == aktKar && kodoltSzoveg[i] != ' ')
    {
      aktKarDb++;
    }
    else
    {

      char aktErtek = ertekKeres(aktKar, aktKarDb, kodtabla);
      switch (aktErtek)
      {
      case 'k':
      case 'n':
        nagybetus = aktErtek == 'n';
        break;

      default:
        dekodoltSzoveg += nagybetus ? aktErtek : tolower(aktErtek);
        break;
      };

      cout << aktKar << " (" << aktKarDb << " db) "
           << "-> " << aktErtek << endl;

      aktKar = kodoltSzoveg[i];
      aktKarDb = 1;
    }

    i++;
  }

  return dekodoltSzoveg;
}

int main(int argc, char const *argv[])
{
  string tesztSzoveg = "55*3355#29999#334#337777#99996665553#2#333881 1 1";
  string dekodoltSzoveg = dekodol(tesztSzoveg);

  cout << dekodoltSzoveg << endl;

  return 0;
}
