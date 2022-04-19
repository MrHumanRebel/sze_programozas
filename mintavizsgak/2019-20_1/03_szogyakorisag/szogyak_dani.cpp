#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;
#define TELL cout <<
#define ASK cin >>
#define MAXHOSSZ 256
#define MAXKIIR 10

// a aa aaa a aa aaa a aa aaa a aa aaa b bb bbb b bb bbb b bb bbb c cc ccc c cc ccc d dd ddd [vege]
// a aa aaa a aa aaa a aa aaa a aa aaa b bb bbb b bb bbb b
// Előzőnél több karakternél => [terminate called after throwing an instance of 'std::bad_alloc' what():  std::bad_alloc]

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

void szamol(string input)
{
  // Struktúratömb nullázása
  elemek elem[MAXHOSSZ];
  for (int i = 0; i < MAXHOSSZ; i++)
  {
    elem[i].akt = "\0";
    elem[i].db = 0;
  }

  // Adatfeldolgozás
  int vegeHelye = input.find("[vege]");
  input = input.substr(0, vegeHelye - 1);
  cout << input << endl;

  size_t i = 0;
  int k = 0;
  while (i < input.length())
  {
    if (input[i] != ' ')
    {
      elem[k].akt += input[i];

      i++;
    }
    else
    {
      elem[k].db++;

      k++;
      i++;
    }
  }

  // Növekvő bubi rendezés
  for (int v = k - 1; v >= 1; v--)
  {
    for (int e = 0; e < v; e++)
    {
      if (elem[e].db > elem[e + 1].db)
      {
        int csere = elem[e].db;
        elem[e].db = elem[e + 1].db;
        elem[e + 1].db = csere;
        string szocsere = elem[e].akt;
        elem[e].akt = elem[e + 1].akt;
        elem[e + 1].akt = szocsere;
      }
    }
  }

  // Struktúratömb nullázása
  elemek gyakori[MAXKIIR];
  for (int x = 0; x < MAXKIIR; x++)
  {
    gyakori[x].akt = "\0";
    gyakori[x].db = 0;
  }

  int j = 0;
  for (int i = 0; i <= j; i++)
  {
    if (elem[i].akt == elem[i + 1].akt)
    {
      gyakori[j].akt = elem[i].akt;
      gyakori[j].db++;
      TELL gyakori[j].akt;
      TELL gyakori[j].db;
    }
    else
    {
      j++;
    }
  }

  TELL endl;
}

int main()
{
  TELL "Szogyakorisagi statisztika. ";

  // Adatbekérés
  string input = beolv();
  szamol(input);

  return 0;
}