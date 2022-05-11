#include <iostream>

using namespace std;

#define KEZDO_KISERO "Fozesi lehetosegeket analizalo program."

#define ALAPANYAG_KISERO "Milyen alapanyagok allnak rendelkezesre?"
#define ETEL_KISERO "Milyen alapanyagokra van szukseg?"
#define INPUT_KISERO "Befejezes #-tel."

#define INPUT_VEGE '#'

struct alapanyag
{
  string nev;
  alapanyag *elozo;
  alapanyag *kov;
};

struct etel
{
  string nev;
  alapanyag *alapanyagok;
};

alapanyag *beszur(string nev, alapanyag *horgony)
{
  if (!horgony)
  {
    alapanyag *uj = new alapanyag;
    uj->nev = nev;
    uj->elozo = uj->kov = NULL;

    return uj;
  }

  if (nev.compare(horgony->nev) > 0)
  {
    horgony->kov = beszur(nev, horgony->kov);
  }
  else
  {
    horgony->elozo = beszur(nev, horgony->elozo);
  }

  return horgony;
}

alapanyag *alapanyagBeker(alapanyag *horgony)
{
  alapanyag *akt = NULL;

  cout << ALAPANYAG_KISERO << ' ' << INPUT_KISERO << endl;

  string aktSor = "";
  while (getline(cin, aktSor) && aktSor.find(INPUT_VEGE) == -1)
  {
    akt = beszur(aktSor, akt);
    if (!horgony)
      horgony = akt;
  }

  return horgony;
}

void kiirRendezett(alapanyag *horgony)
{
  if (!horgony)
  {
    return;
  }

  kiirRendezett(horgony->elozo);
  cout << horgony->nev << endl;
  kiirRendezett(horgony->kov);
}

void torolMind(alapanyag *horgony)
{

  while (horgony)
  {
    alapanyag *kovSzimb = horgony->kov;
    delete horgony;
    horgony = kovSzimb;
  }
}

int main(int argc, char const *argv[])
{
  cout << KEZDO_KISERO << endl;

  alapanyag *rendelkezesreAll = NULL;
  rendelkezesreAll = alapanyagBeker(rendelkezesreAll);

  kiirRendezett(rendelkezesreAll);
  torolMind(rendelkezesreAll);

  return 0;
}
