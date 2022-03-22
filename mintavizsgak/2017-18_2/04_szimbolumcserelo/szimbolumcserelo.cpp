#include <iostream>
using namespace std;

#define MAX 10

struct helyorzo
{
  string kulcs;
  string ertek;
};

string szovegBekerese()
{
  cout << "Adja meg az uzenet szavait [vege] vegjelig!" << endl;

  string bemenet;
  getline(cin, bemenet);

  // TODO: Refaktor, mert így nem túl biztos
  char keresettKar = ' ';
  int i = bemenet.length() - 1;
  while (i >= 0 && bemenet[i] != keresettKar)
  {
    i--;
  }

  if (i < 0)
  {
    cout << "Hibás input" << endl;
  }

  bemenet = bemenet.substr(0, i);
  return bemenet;
}

int main(int argc, char const *argv[])
{
  helyorzo helyorzok[MAX] = {
      {"nev", "Gizi"},
      {"szin", "piros"},
      {"allat", "kutya"},
      {"jarmu", "bicikli"},
      {"telepules", "Karakoszorcsog"},
  };

  cout << "Szimbolumcserelo" << endl;

  string szoveg = szovegBekerese();

  return 0;
}
