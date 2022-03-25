#include <iostream>
#include <fstream>
using namespace std;

#define MAX 10
#define SZIMB_DELIM '$'
#define INPUT_VEGE "[vege]"
#define VEL_MAX 9999 // VEL_MAX, mert a RAND_MAX már foglalt

struct szimbolum
{
  string helyorzo;
  string ertek;
  szimbolum *kov;
};

szimbolum *szimbolumBeszur(string helyorzo, string ertek, szimbolum *elozoSzimb)
{
  szimbolum *ujSzimb = new szimbolum;

  ujSzimb->helyorzo = helyorzo;
  ujSzimb->ertek = ertek;

  if (elozoSzimb)
  {
    ujSzimb->kov = elozoSzimb->kov;
    elozoSzimb->kov = ujSzimb;
  }
  else
  {
    ujSzimb->kov = NULL;
  }

  return ujSzimb;
}

szimbolum *szimbolumBetolt(szimbolum *horgony, string fajlnev)
{
  ifstream fajl(fajlnev);
  if (fajl.is_open())
  {
    string aktSor;
    szimbolum *aktSzimb = NULL;
    while (getline(fajl, aktSor))
    {
      /* Windowsos új sor karakter ellenőrzése (WSL alatt probléma)

         A bemeneti fájl (szimbolumok.txt) CRLF sorvégi karakterekkel ("\r\n") rendelkezik,
         míg Linux alatt csak LF ('\n')
      */
      if (aktSor[aktSor.length() - 1] == '\r')
        aktSor.replace(aktSor.length() - 1, 1, "");

      int szokozHelye = aktSor.find(' ');
      string helyorzo = aktSor.substr(0, szokozHelye);
      string ertek = aktSor.substr(szokozHelye + 1);

      aktSzimb = szimbolumBeszur(helyorzo, ertek, aktSzimb);
      if (!horgony)
        horgony = aktSzimb;
    }
  }
  fajl.close();

  return horgony;
}

void szimbolumTorol(szimbolum *aktSzimb)
{
  szimbolum *kovSzimb;
  while (aktSzimb)
  {
    kovSzimb = aktSzimb->kov;
    delete aktSzimb;
    aktSzimb = kovSzimb;
  }
}

string szovegBeker()
{
  cout << "Adja meg az uzenet szavait [vege] vegjelig!" << endl;

  string bemenet;
  getline(cin, bemenet);

  int vegeHely = bemenet.find(INPUT_VEGE);
  bemenet = vegeHely != -1 ? bemenet.substr(0, vegeHely) : "";

  return bemenet;
}

string helyorzoCsere(string szo, szimbolum *horgony)
{
  // Első releváns karakter megkeresése
  int i = szo.find(SZIMB_DELIM);

  // Utolsó releváns karakter megkeresése
  int j = szo.find_last_of(SZIMB_DELIM);

  // "$$" kezelése
  if (j - i == 1)
    return szo.substr(1);

  int helyorzoKezdet = i + 1;
  int helyorzoVeg = i > 0 ? (j - 1) - i : j - 1;
  string aktHelyorzo = szo.substr(helyorzoKezdet, helyorzoVeg);

  if (aktHelyorzo == "vel")
  {
    // Az srand() meghívásával mindig más seedet kapunk, így minden futásnál eltérő értéket kapunk
    srand((unsigned)time(NULL));

    int randErtek = rand() % VEL_MAX + 1;
    string csereltSzo = szo.replace(i, j + 1, to_string(randErtek));

    return csereltSzo;
  }

  szimbolum *aktSzimb = horgony;
  while (aktSzimb && aktSzimb->helyorzo != aktHelyorzo)
  {
    aktSzimb = aktSzimb->kov;
  }

  // Ismeretlen helyőrző esetén
  if (!aktSzimb)
    return szo;

  string keresettErtek = string(aktSzimb->ertek);
  string csereltSzo = szo.replace(i, j + 1, keresettErtek);

  return csereltSzo;
}

string szovegCsere(string bemenet, szimbolum *kezdo)
{
  string szoveg;

  string aktSzo;
  bool vanHelyorzo = false;
  for (size_t i = 0; i < bemenet.length(); i++)
  {
    if (bemenet[i] == ' ')
    {
      szoveg += vanHelyorzo ? helyorzoCsere(aktSzo, kezdo) + ' ' : aktSzo + ' ';

      vanHelyorzo = false;
      aktSzo = "";
    }
    else
    {
      vanHelyorzo = vanHelyorzo || bemenet[i] == SZIMB_DELIM;
      aktSzo += bemenet[i];
    }
  }

  return szoveg;
}

int main(int argc, char const *argv[])
{
  cout << "Szimbolumcserelo" << endl;

  szimbolum *horgony = NULL;
  horgony = szimbolumBetolt(horgony, "szimbolumok.txt");

  string bemenet = szovegBeker();
  string szoveg = szovegCsere(bemenet, horgony);
  cout << szoveg << endl;

  szimbolumTorol(horgony);

  return 0;
}
