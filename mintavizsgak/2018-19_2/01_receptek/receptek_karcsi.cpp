#include <iostream>

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

alapanyag *keres(string nev, alapanyag *horgony)
{
  if (horgony == NULL || horgony->nev == nev)
    return horgony;

  if (nev.compare(horgony->nev) > 0)
    return keres(nev, horgony->kov);

  return keres(nev, horgony->elozo);
}

alapanyag *hianyzik(alapanyag *hianyzo, alapanyag *elerheto, alapanyag *szukseges)
{
  alapanyag *aktHianyzo = NULL;
  alapanyag *aktSzuks = szukseges;

  while (aktSzuks)
  {
    string nev = aktSzuks->nev;
    alapanyag *talalat = keres(nev, elerheto);

    if (!talalat)
    {
      aktHianyzo = beszur(nev, aktHianyzo);
      if (!hianyzo)
        hianyzo = aktHianyzo;
    }

    aktSzuks = aktSzuks->kov;
  }

  return hianyzo;
}

void kiirRendezett(alapanyag *horgony)
{
  if (!horgony)
    return;

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

  /* A rendelkezésünkre álló alapanyagok bekérése
     és eltárolása egy bináris keresőfában (ABC-sorrendben rendezett) */
  alapanyag *elerheto = NULL;
  elerheto = alapanyagBeker(elerheto, false);

  bool kilepes = false;
  do
  {
    etel akt = etelBeker();

    /* '#' esetén nem szükséges tovább folytatnunk az adatok feldolgozását,
       így "elegánsan" kilépünk a ciklusból */
    if (akt.nev[0] == INPUT_VEGE)
      break;

    /* A keres() függvény segítségével összeszedjük a hiányzó alapanyagokat
       Üres láncolt lista esetén tudjuk, hogy elkészíthető,
       hiszen semmi se hiányzik */
    alapanyag *hianyzo = NULL;
    hianyzo = hianyzik(hianyzo, elerheto, akt.szukseges);

    string eredmeny = hianyzo ? NEM_KESZITHETO_EL : ELKESZITHETO;
    cout << "A(z) " << akt.nev << ' ' << eredmeny << endl;
    if (hianyzo)
      kiirRendezett(hianyzo);

    // A biztonság kedvéért likvidáljuk a memóriából az aktuális és a hiányzó alapanyagokat
    torolMind(akt.szukseges);
    torolMind(hianyzo);
  } while (!kilepes);

  cout << KILEP << endl;

  torolMind(elerheto);

  return 0;
}
