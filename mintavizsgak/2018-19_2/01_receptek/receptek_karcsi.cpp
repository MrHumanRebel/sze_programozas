#include <iostream>

using namespace std;

#define KEZDO_KISERO "Fozesi lehetosegeket analizalo program."

#define ALAP_KISERO "Milyen alapanyagok allnak rendelkezesre?"
#define SZUKSEGES_KISERO "Milyen alapanyagokra van szukseg?"
#define INPUT_KISERO "Befejezes #-tel."

#define ETEL_KISERO "Etel neve: "

#define KILEP "Kilepes."

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
  alapanyag *szukseges;
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

alapanyag *alapanyagBeker(alapanyag *horgony, bool szukseges)
{
  alapanyag *akt = NULL;

  string kisero = szukseges ? SZUKSEGES_KISERO : ALAP_KISERO;
  cout << kisero << ' ' << INPUT_KISERO << endl;

  string aktSor = "";
  while (getline(cin, aktSor) && aktSor.find(INPUT_VEGE) == -1)
  {
    akt = beszur(aktSor, akt);
    if (!horgony)
      horgony = akt;
  }

  return horgony;
}

etel etelBeker()
{
  cout << ETEL_KISERO;

  string etelNeve;
  getline(cin, etelNeve);

  if (etelNeve[0] == INPUT_VEGE)
    return {etelNeve, NULL};

  alapanyag *szukseges = NULL;
  szukseges = alapanyagBeker(szukseges, true);

  etel uj = {etelNeve, szukseges};

  return uj;
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
  rendelkezesreAll = alapanyagBeker(rendelkezesreAll, false);

  bool kilepes = false;
  do
  {
    etel akt = etelBeker();
    if (akt.nev[0] == INPUT_VEGE)
      // Nem túl szép, hisz a kilepes helyett így simán lehetne egy true is
      break;

    

  } while (!kilepes);

  cout << KILEP << endl;

  torolMind(rendelkezesreAll);

  return 0;
}
