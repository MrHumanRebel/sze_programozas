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
// a aa aaa a aa a!!aa a aa aaa. A a.a aaa b bb bbb b bb bbb? b b????b bbb c. Cc c!cc c cc ccc d dd ddd [vege]

struct elem
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

void gyorsbubi(elem tomb[], int n)
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

int keres(elem gyakori[], string akt, int elemszam)
{
  int i;
  for (i = 0; i < elemszam; i++)
  {
    if (akt == gyakori[i].akt)
      return i;
  }
  return -1;
}

int szamol(elem gyakori[], string input)
{
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
      akt = "\0";
      i++;
    }
  }
  return elemszam;
}

void kiir(elem gyakori[], int elemszam)
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
    if (gyakori[kiirdb].db != 0)
      TELL "\t" << gyakori[kiirdb].akt << "\t" << gyakori[kiirdb].db << "\t" << szazalekok[kiirdb] << endl;
    kiirdb++;
  }
}

int betuszamlal(string input)
{
  int n = 0;
  for (size_t i = 0; i < input.length(); i++)
  {
    if (isalpha(input[i]) && input[i] != ' ')
      n++;
  }
  return n;
}

int szoszamlal(string input)
{
  int n = 0;
  for (size_t i = 0; i < input.length(); i++)
  {
    if (input[i] == ' ' && input[i + 1] != ' ')
      n++;
  }
  return n + 1;
}

int bekszamlal(string input)
{
  int n = 1;
  for (size_t i = 0; i < input.length(); i++)
  {
    if (input[i] == '\n')
      n++;
  }
  return n;
}

int mondatszamlal(string input)
{
  int n = 0;
  for (size_t i = 1; i < input.length(); i++)
  {
    if (input[i] == '.' && input[i + 1] == ' ' && input[i - 1] != ' ' && !islower(input[i + 2]))
      n++;
    else if (input[i] == '!' && input[i + 1] == ' ' && input[i - 1] != ' ' && !islower(input[i + 2]))
      n++;
    else if (input[i] == '?' && input[i + 1] == ' ' && input[i - 1] != ' ' && !islower(input[i + 2]))
      n++;
    else if (i == input.length() - 1)
      n++;
  }
  return n;
}

int main()
{
  // Struktúratömb nullázása
  elem gyakori[MAXHOSSZ];
  for (int i = 0; i < MAXHOSSZ; i++)
  {
    gyakori[i].akt = "\0";
    gyakori[i].db = 0;
  }

  TELL "Szogyakorisagi statisztika. ";
  string input = beolv();
  int elemszam = szamol(gyakori, input);
  gyorsbubi(gyakori, elemszam);
  kiir(gyakori, elemszam);
  int betudb = betuszamlal(input);
  int szodb = szoszamlal(input);
  int bekdb = bekszamlal(input);
  int mondatdb = mondatszamlal(input);
  TELL "\nBetűk száma: " << betudb << "\nSzavak száma: " << szodb << "\nBekezdések száma: " << bekdb << "\nMondatok száma: " << mondatdb << endl;

  return 0;
}