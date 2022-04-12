#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define SOR_MAX 10
#define OSZLOP_MAX 10

void palyaBeolvas(char palya[SOR_MAX][OSZLOP_MAX], int sor, int oszlop, string fajlnev)
{
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

int main()
{
  // Alap karakter olvasó függvény tesztelő
  char tabla[SOR_MAX][OSZLOP_MAX];

  // TODO: Felülvizsgálni
  string fajlnev = "/home/szeke/uni/sze_programozas/anyagok/sajat_feladatok/amoba.txt";
  palyaBeolvas(tabla, SOR_MAX, OSZLOP_MAX, fajlnev);
  return 0;
}