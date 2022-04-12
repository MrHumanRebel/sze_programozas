// Headers
#include <iostream>
using namespace std;

#define TELL cout <<
#define ASK cin >>

// Szám bekerő függvény
int szamBeker(int min, int max)
{
  int szam;

  bool szamHibas = false;
  do
  {
    if (szamHibas)
      TELL "Nem megfelelő szám (tartomány: " << min << "-től " << max << "-ig)" << endl;

    TELL "Adjon meg egy számot: ";
    ASK szam;

    szamHibas = szam < min || szam > max;
  } while (szamHibas);

  return szam;
}

// Teszt
int main()
{
  int min = 1;
  int max = 10;

  int aktSzam = szamBeker(min, max);
  TELL "Az Ön által megadott szám: " << aktSzam << endl;

  return 0;
}