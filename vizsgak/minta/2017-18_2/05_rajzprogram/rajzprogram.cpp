#include <iostream>
using namespace std;

#define M_MIN 5
#define M_MAX 20
#define MEZO_HATTER '.'
#define MEZO_IRAS 'X'

struct meret
{
  int sor;
  int oszlop;
};

void tablaFeltolt(char tabla[M_MAX][M_MAX], meret tablaMeret)
{
  for (int i = 0; i < tablaMeret.sor; i++)
  {
    for (int j = 0; j < tablaMeret.oszlop; j++)
    {
      tabla[i][j] = MEZO_HATTER;
    }
  }
}

void tablaMegjelenit(char tabla[M_MAX][M_MAX], meret tablaMeret)
{
  for (int i = 0; i < tablaMeret.sor; i++)
  {
    for (int j = 0; j < tablaMeret.oszlop; j++)
    {
      cout << tabla[i][j];
    }
    cout << endl;
  }
}

int main(int argc, char const *argv[])
{
  // A tábla kezdőmérete
  meret tablaMeret = {10, 10};
  char rajztabla[M_MAX][M_MAX];

  tablaFeltolt(rajztabla, tablaMeret);
  tablaMegjelenit(rajztabla, tablaMeret);

  return 0;
}
