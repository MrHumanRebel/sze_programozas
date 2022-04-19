#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;
#define TELL cout <<
#define ASK cin >>
#define MAXHOSSZ 96
#define MAXKIIR 10
#define MAXSZELES 20
#define VEGEJEL "[vege]"

// a aa aaa a aa aaa a aa aaa a aa aaa b bb bbb b bb bbb b bb bbb c cc ccc c cc ccc d dd ddd [vege]
// a aa a b b b b b b b b bb bbb

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

void gyorsbubi(elemek tomb[], int n)
{
  bool cserelt;
  for (int i = 0; i < n - 1; i++)
  {
    cserelt = false;
    for (int j = 0; j < n - i - 1; j++)
    {
      if (tomb[j].db < tomb[j + 1].db)
      {
        swap(tomb[j], tomb[j + 1]);
        cserelt = true;
      }
    }
    if (cserelt == false)
      break;
  }
}

int keres(elemek gyakori[], string akt, int elemszam)
{
  int i;
  for (i = 0; i < elemszam; i++)
  {
    if (akt == gyakori[i].akt)
      return i;
  }
  return -1;
}

int szamol(elemek gyakori[], string input)
{
  // Adatfeldolgozás
  int vegeHelye = input.find(VEGEJEL);
  input = input.substr(0, vegeHelye - 1);

  size_t i = 0;
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

      if (talalt == -1)
      {
        gyakori[elemszam].akt = akt;
        gyakori[elemszam].db = 1;
        elemszam++;
      }
      else
      {
        gyakori[talalt].db += 1;
      }
      // TELL "Aktuális karakter:" << akt << "\tFG Értéke: " << talalt << "\t Akt elemszám: " << elemszam << endl;

      akt = "\0";
      i++;
    }
  }
  return elemszam;
}

void kiir(elemek gyakori[], int elemszam)
{
  double szazalekok[elemszam];
  int osszdb = 0, kiirdb = 0;
  for (int i = 0; i < elemszam; i++)
    osszdb += gyakori[i].db;
  for (int i = 0; i < elemszam; i++)
    szazalekok[i] = (double)gyakori[i].db / (double)osszdb * 100;

  while (kiirdb < MAXKIIR)
  {
    int egycsillag = MAXSZELES / szazalekok[0];
    int n = szazalekok[kiirdb] * egycsillag;
    for (int i = 0; i < n; i++)
    {
      TELL '*';
    }
    TELL "\t" << gyakori[kiirdb].akt << "\t" << gyakori[kiirdb].db << "\t" << szazalekok[kiirdb] << endl;
    kiirdb++;
  }

  /*// DEBUG
  TELL "\n"
      << endl;
  for (int i = 0; i < elemszam; i++)
  {
    TELL gyakori[i].akt;
    if (gyakori[i].db != 0)
      TELL gyakori[i].db;
    TELL "  ";
  }*/
}

int main()
{
  // Struktúratömb nullázása
  elemek gyakori[MAXHOSSZ];
  for (int i = 0; i < MAXHOSSZ; i++)
  {
    gyakori[i].akt = "\0";
    gyakori[i].db = 0;
  }

  TELL "Szogyakorisagi statisztika. ";

  // Adatbekérés
  string input = beolv();
  int elemszam = szamol(gyakori, input);
  gyorsbubi(gyakori, elemszam);
  kiir(gyakori, elemszam);

  return 0;
}