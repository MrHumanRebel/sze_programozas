#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

#define SOR_MAX 5
#define OSZLOP_MAX 5
#define SEED 0
#define FAJLNEV "palya_iras_teszt.txt"

int random(int tol, int ig, int seed)
{
  srand(time(NULL) + seed);
  return (tol + rand() % (ig - tol + 1));
}

void feltolt(char tabla[SOR_MAX][OSZLOP_MAX], int seed)
{
  for (int i = 0; i < SOR_MAX; i++)
  {
    for (int j = 0; j < OSZLOP_MAX; j++)
    {
      seed = random(1, 50, seed);
      tabla[i][j] = random('A', 'Z', seed);
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
  int seed = 0;
  
  feltolt(tabla, seed);
  ment(tabla);

  return 0;
}