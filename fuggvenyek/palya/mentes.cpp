#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

#define SOR_MAX 5
#define OSZLOP_MAX 5
#define FAJLNEV "palya_iras_teszt.txt"


void feltolt(char tabla[SOR_MAX][OSZLOP_MAX])
{
  for (int i = 0; i < SOR_MAX; i++)
  {
    for (int j = 0; j < OSZLOP_MAX; j++)
    {
      // Minden cella az ABC egyik random betűje (demonstrációs célzattal csak)
      tabla[i][j] = 'A' + (rand() % 26);
    }
  }
}

void ment(char tabla[SOR_MAX][OSZLOP_MAX])
{
  ofstream mentes(FAJLNEV);

  // A pálya méretének mentése, a betöltés megkönnyítésért
  mentes << SOR_MAX << endl;
  mentes << OSZLOP_MAX << endl;

  for (int i = 0; i < SOR_MAX; i++)
  {
    for (int j = 0; j < OSZLOP_MAX; j++)
    {
      mentes << tabla[i][j];
    }
    mentes << endl;
  }

  mentes.close();
}

int main()
{
  char tabla[SOR_MAX][OSZLOP_MAX];

  feltolt(tabla);
  ment(tabla);

  return 0;
}