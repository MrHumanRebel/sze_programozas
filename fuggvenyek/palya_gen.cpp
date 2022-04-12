// Headers
#include <iostream>
using namespace std;
#define TELL cout <<
#define ASK cin >>
#define SOR_MAX 10
#define OSZLOP_MAX 10

// Pálya generáló függvény
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

int main()
{
  // Pálya generáló függvény tesztelő
  int sor = 10;
  int oszlop = 10;
  char tabla[SOR_MAX][OSZLOP_MAX];
  palyaGen(tabla, sor, oszlop);
  return 0;
}