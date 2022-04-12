#include <iostream>
using namespace std;

// Szám bekerő függvény
int szamBeker(int min, int max)
{
  int szam;

  bool szamHibas = false;
  do
  {
    if (szamHibas)
      cout << "Nem megfelelő szám (tartomány: " << min << "-től " << max << "-ig)" << endl;

    cout << "Adjon meg egy számot: ";
    cin >> szam;

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
  cout << "Az Ön által megadott szám: " << aktSzam << endl;

  return 0;
}