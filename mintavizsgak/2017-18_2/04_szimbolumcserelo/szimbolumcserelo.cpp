#include <iostream>
using namespace std;

#define MAX 10
#define KERESETT_KAR '$'

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

string helyorzoCsere(string szo, szimbolum szimbolumok[MAX])
{
  // Első releváns karakter megkeresése
  size_t i = 0;
  while (i < szo.length() && szo[i] != KERESETT_KAR)
  {
    i++;
  }

  if (i >= szo.length())
    return szo;

  // Utolsó releváns karakter megkeresése
  size_t j = szo.length() - 1;
  while (j > i && szo[j] != KERESETT_KAR)
  {
    j--;
  }

  if (j <= i)
    return szo;

  int helyorzoKezdet = i + 1;
  int helyorzoVeg = i > 0 ? (j - 1) - i : j - 1;

  string aktHelyorzo = szo.substr(helyorzoKezdet, helyorzoVeg);

  int k = 0;
  int szimbolumokSzama = sizeof(szimbolumok[0]) / sizeof(szimbolumok);
  while (k < szimbolumokSzama && szimbolumok[k].helyorzo != aktHelyorzo)
  {
    k++;
  }

  if (k >= szimbolumokSzama)
    return szo;

  string keresettErtek = szimbolumok[k].ertek;
  string toldalek = i > 0 ? szo.substr(0, helyorzoKezdet - 1) : szo.substr(j + 1);
  string keresettCsere = i > 0 ? toldalek + keresettErtek : keresettErtek + toldalek;

  return keresettCsere;
}

string csere(string bemenet, szimbolum szimbolumok[MAX])
{
  string szoveg;

  string aktSzo;
  bool vanHelyorzo = false;
  for (size_t i = 0; i < bemenet.length(); i++)
  {
    // TODO: Utolsó rész (":)") hozzáadása
    if (bemenet[i] == ' ')
    {
      bool csereSzukseges = vanHelyorzo;
      szoveg += csereSzukseges ? helyorzoCsere(aktSzo, szimbolumok) + ' ' : aktSzo + ' ';

      vanHelyorzo = false;
      aktSzo = "";
    }
    else
    {
      vanHelyorzo = vanHelyorzo || bemenet[i] == KERESETT_KAR;
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
