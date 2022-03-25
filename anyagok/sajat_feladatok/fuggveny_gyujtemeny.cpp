// Headers
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <fstream>
using namespace std;
#define TELL cout <<
#define ASK cin >>
#define SOR_MAX 10
#define OSZLOP_MAX 10

// Szám bekerő függvény
int szamBeker(int MIN, int MAX)
{
  bool szambe_ok = false;
  int akt;
  do
  {
    TELL "Adja meg a számot!" << endl;
    ASK akt;
    if (akt >= MIN && akt <= MAX)
      szambe_ok = true;
    else
      TELL "Adjon meg " << MIN << "-től " << MAX << "-ig tartományba tartozó számot!" << endl;
  } while (szambe_ok == false);
  return akt;
}

// Karakter bekerő függvény
int karBeker(char KEZD, char VEG)
{
  bool karbe_ok = false;
  char akt;
  do
  {
    TELL "Adja meg a karaktert!" << endl;
    ASK akt;
    // akt = tolower(akt);
    // akt = toupper(akt);
    if (akt >= KEZD && akt <= VEG)
      karbe_ok = true;
    else
      TELL "Adjon meg " << KEZD << "-től " << VEG << "-ig tartományba tartozó karaktert!" << endl;
  } while (karbe_ok == false);
  return akt;
}

// Pálya generáló függvény
// BETA VERSION
void palyaGen(char tabla[SOR_MAX][OSZLOP_MAX], int sor, int oszlop)
{

  for (int i = 0; i < sor; i++)
  {
    for (int j = 0; j < oszlop; j++)
    {
      tabla[i][j] = '.';
    }
  }
}

void palyaBeolvas(char palya[SOR_MAX][OSZLOP_MAX], int &sor, int &oszlop, string fajlnev)
{
  // TODO: Implementáld
  ifstream mentettPalya(fajlnev);

  string aktSor;

  // A fájl első két sora a pálya sorainak és az oszlopainak száma
  getline(mentettPalya, aktSor);
  sor = stoi(aktSor);

  getline(mentettPalya, aktSor);
  stoi(aktSor);

  for (int i = 0; i < sor; i++)
  {
    getline(mentettPalya, aktSor);

    for (int j = 0; j < oszlop; j++)
    {
      palya[i][j] = aktSor[j];
    }
  }

  mentettPalya.close();
}

// Alap karakter olvasó függvény
// BETA VERSION

int main()
{
  // Szám bekerő függvény tesztelő
  int MAX = 10;
  int MIN = 1;
  int szam_akt = szamBeker(MIN, MAX);
  TELL szam_akt << endl;

  // Karakter bekerő függvény tesztelő
  char KEZD = 'A';
  char VEG = 'D';
  char kar_akt = karBeker(KEZD, VEG);
  TELL kar_akt << endl;

  // Pálya generáló függvény tesztelő
  int sor = 10;
  int oszlop = 10;
  char tabla[SOR_MAX][OSZLOP_MAX];
  palyaGen(tabla, sor, oszlop);

  // Alap karakter olvasó függvény tesztelő
  string fajlnev = "/home/szeke/uni/sze_programozas/anyagok/sajat_feladatok/amoba.txt";
  palyaBeolvas(tabla, sor, oszlop, fajlnev);

  return 0;
}