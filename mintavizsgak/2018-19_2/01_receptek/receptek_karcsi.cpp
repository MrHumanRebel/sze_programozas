#include <iostream>
#include <fstream>

using namespace std;

#define KEZDO_KISERO "Fozesi lehetosegeket analizalo program."

#define ALAP_KISERO "Milyen alapanyagok allnak rendelkezesre?"
#define SZUKSEGES_KISERO "Milyen alapanyagokra van szukseg?"
#define INPUT_KISERO "Befejezes #-tel."

#define ETEL_KISERO "Etel neve: "
#define ELKESZITHETO "elkeszitheto."
#define NEM_KESZITHETO_EL "nem keszitheto el, a kovetkezo alapanyagok hianyoznak: "

#define KILEP "Kilepes."

#define INPUT_VEGE '#'
#define FAJLNEV "alapanyagok_karcsi.txt"

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

void alapanyagMent(alapanyag *horgony, string fajlnev)
{
  ofstream fajl(fajlnev);

  alapanyag *akt = horgony;
  while (akt)
  {
    fajl << akt->nev << endl;
    akt = akt->kov;
  }
}

void kiirEsMentRendezett(alapanyag *horgony, ostream &kimenet)
{
  if (!horgony)
    return;

  kiirEsMentRendezett(horgony->elozo, kimenet);
  kimenet << horgony->nev << endl;
  kiirEsMentRendezett(horgony->kov, kimenet);
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

alapanyag *alapanyagBeker(alapanyag *horgony, bool szukseges, string fajlnev = "")
{
  alapanyag *akt = NULL;

  ifstream fajl(fajlnev);
  istream &bemenet = !szukseges && fajl.is_open() ? fajl : cin;

  string aktSor;

  if (!fajl.is_open())
  {
    string kisero = szukseges ? SZUKSEGES_KISERO : ALAP_KISERO;
    cout << kisero << ' ' << INPUT_KISERO << endl;
  }

  while (getline(bemenet, aktSor) && aktSor[0] != INPUT_VEGE)
  {
    akt = beszur(aktSor, akt);
    if (!horgony)
      horgony = akt;
  }

  if (!fajl.is_open())
  {
    ofstream mentes(fajlnev);
    kiirEsMentRendezett(horgony, mentes);
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

alapanyag *keres(string nev, alapanyag *horgony)
{
  if (horgony == NULL || horgony->nev == nev)
    return horgony;

  if (nev.compare(horgony->nev) > 0)
    return keres(nev, horgony->kov);

  return keres(nev, horgony->elozo);
}

// Pszichológiai horror, nem működik
alapanyag *hianyzik(alapanyag *hianyzo, alapanyag *elerheto, alapanyag *szukseges)
{
  alapanyag *aktHianyzo = NULL;
  alapanyag *aktSzuks = szukseges;

  return hianyzo;
}

bool etelKezel(alapanyag *elerheto)
{
  etel akt = etelBeker();

  if (akt.nev[0] == INPUT_VEGE)
    return true;

  /* A keres() függvény segítségével összeszedjük a hiányzó alapanyagokat
   Üres láncolt lista esetén tudjuk, hogy elkészíthető,
   hiszen semmi se hiányzik */
  alapanyag *hianyzo = NULL;
  hianyzo = hianyzik(hianyzo, elerheto, akt.szukseges);

  string eredmeny = hianyzo ? NEM_KESZITHETO_EL : ELKESZITHETO;
  cout << "A(z) " << akt.nev << ' ' << eredmeny << endl;
  if (hianyzo)
    kiirEsMentRendezett(hianyzo, cout);

  // A biztonság kedvéért likvidáljuk a memóriából az aktuális és a hiányzó alapanyagokat
  torolMind(akt.szukseges);
  torolMind(hianyzo);

  return false;
}

int main(int argc, char const *argv[])
{
  cout << KEZDO_KISERO << endl;

  /* A rendelkezésünkre álló alapanyagok bekérése
     és eltárolása egy bináris keresőfában (ABC-sorrendben rendezett) */
  alapanyag *elerheto = NULL;
  elerheto = alapanyagBeker(elerheto, false, FAJLNEV);

  bool kilep = false;
  do
  {
    kilep = etelKezel(elerheto);
  } while (!kilep);

  cout << KILEP << endl;

  torolMind(elerheto);

  return 0;
}
