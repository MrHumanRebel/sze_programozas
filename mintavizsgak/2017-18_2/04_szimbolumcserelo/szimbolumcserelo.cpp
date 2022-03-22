#include <iostream>
using namespace std;

#define MAX 10

struct szimbolum
{
  string helyorzo;
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

string szimbolumKeres(string szo, szimbolum szimbolum[MAX])
{
  char keresettKar = '$';
  cout << szo << endl;

  // Első releváns karakter megkeresése
  size_t i = 0;
  while (i < szo.length() && szo[i] != keresettKar)
  {
    i++;
  }

  if (i >= szo.length())
    return szo;

  // Utolsó releváns karakter megkeresése
  size_t j = 0;
  while (j > i && szo[j] != keresettKar)
  {
    j--;
  }

  if (j <= i)
    return szo;

  string aktHelyorzo = szo.substr(i, j);
  cout << aktHelyorzo << endl;
}

string csere(string bemenet, szimbolum szimbolumok[MAX])
{
  string szoveg;

  string aktSzo;
  bool vanHelyorzo = false;
  for (size_t i = 0; i < bemenet.length(); i++)
  {
    if (bemenet[i] == ' ')
    {
      // TODO: Metódus cserére
      szoveg += vanHelyorzo && aktSzo[1] != '$' ? szimbolumKeres(aktSzo, szimbolumok) + ' ' : aktSzo + ' ';

      vanHelyorzo = false;
      aktSzo = "";
    }
    else
    {
      vanHelyorzo = vanHelyorzo || bemenet[i] == '$';
      aktSzo += bemenet[i];
    }
  }

  return szoveg;
}

int main(int argc, char const *argv[])
{
  szimbolum szimbolumok[MAX] = {
      {"nev", "Gizi"},
      {"szin", "piros"},
      {"allat", "kutya"},
      {"jarmu", "bicikli"},
      {"telepules", "Karakoszorcsog"},
  };

  cout << "Szimbolumcserelo" << endl;

  string bemenet = szovegBekerese();
  string szoveg = csere(bemenet, szimbolumok);

  cout << szoveg << endl;

  return 0;
}
