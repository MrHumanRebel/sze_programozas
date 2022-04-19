#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;
#define TELL cout <<
#define ASK cin >>
#define MAXHOSSZ 64
#define MAXKIIR 10

// a aa aaa a aa aaa a aa aaa a aa aaa b bb bbb b bb bbb b bb bbb c cc ccc c cc ccc d dd ddd [vege]
// a aa aaa a aa aaa a aa aaa a aa aaa b bb bbb b bb bbb b

struct elemek
{
  string akt;
  int db;
};

string beolv()
{
  cout << "Adja meg a szöveget \"[vege]\" végjelig!" << endl;
  string input;
  getline(cin, input);
  return input;
}

int keres(elemek gyakori[], string akt, int elemszam)
{
  for (int i = 0; i <= elemszam; i++)
  {
    if (akt == gyakori[i].akt)
      return i; // Már van ilyen elem
    else if (akt == "\0")
      return -1; // Üres
    else
      return -2; // Még nincs ilyen elem
  }
}

void szamol(string input)
{
  // Struktúratömb nullázása
  elemek gyakori[MAXHOSSZ];
  for (int i = 0; i < MAXHOSSZ; i++)
  {
    gyakori[i].akt = "\0";
    gyakori[i].db = 0;
  }

  // Adatfeldolgozás
  int vegeHelye = input.find("[vege]");
  input = input.substr(0, vegeHelye - 1);

  size_t i = 0;
  int k = 0;
  string akt = "\0";
  int elemszam = 0;
  while (i < input.length())
  {
    if (input[i] != ' ') // Ha nem space
    {
      akt += input[i];
      i++;
    }
    else // Ha space
    {
      int talalt = keres(gyakori, akt, elemszam); // Van már ilyen karakter?
      TELL "Aktuális karakter:" << akt << "FG Értéke: " << talalt << endl;

      if (talalt == -2)
      {
        gyakori[k].akt = akt;
        gyakori[k].db = 1;
        elemszam++;
      }
      else
      {
        gyakori[talalt].db += 1;
      }

      akt = "\0";
      i++;
      k++;
    }
  }

  // DEBUG
  for (int i = 0; i < elemszam; i++)
  {
    TELL gyakori[i].akt;
    TELL gyakori[i].db;
  }
}

int main()
{
  TELL "Szogyakorisagi statisztika. ";

  // Adatbekérés
  string input = beolv();
  szamol(input);

  return 0;
}