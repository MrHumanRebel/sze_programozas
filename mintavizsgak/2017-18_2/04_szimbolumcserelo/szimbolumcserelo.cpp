#include <iostream>
using namespace std;

#define MAX 10
#define KERESETT_KAR '$'
#define INPUT_VEGE "[vege]"

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

  int vegeHely = bemenet.find(INPUT_VEGE);
  bemenet = vegeHely != -1 ? bemenet.substr(0, vegeHely) : "";

  return bemenet;
}

string helyorzoCsere(string szo, szimbolum szimbolumok[MAX])
{
  // Első releváns karakter megkeresése
  int i = szo.find(KERESETT_KAR);

  // Utolsó releváns karakter megkeresése
  int j = szo.find_last_of(KERESETT_KAR);

  // "$$" kezelése
  if (j - i == 1)
    return szo.substr(1);

  int helyorzoKezdet = i + 1;
  int helyorzoVeg = i > 0 ? (j - 1) - i : j - 1;
  string aktHelyorzo = szo.substr(helyorzoKezdet, helyorzoVeg);

  int k = 0;
  int szimbolumokSzama = sizeof(szimbolumok[0]) / sizeof(szimbolumok);

  while (k < szimbolumokSzama && szimbolumok[k].helyorzo != aktHelyorzo)
  {
    k++;
  }

  // Ismeretlen helyőrző esetén
  if (k >= szimbolumokSzama)
    return szo;

  string keresettErtek = szimbolumok[k].ertek;
  string csereltSzo = szo.replace(i, j + 1, keresettErtek);

  return csereltSzo;
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
      szoveg += vanHelyorzo ? helyorzoCsere(aktSzo, szimbolumok) + ' ' : aktSzo + ' ';

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
