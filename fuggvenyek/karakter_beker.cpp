#include <iostream>
using namespace std;

// Karakter bekerő függvény
int karBeker(char kezd, char veg)
{
  char karakter;

  bool hibasKarakter = false;
  do
  {
    if (hibasKarakter)
      cout << "Hibás karakter, adjon meg egy " << kezd << "-től " << veg << "-ig tartományba tartozó karaktert!" << endl;

    cout << "Adjon meg egy karaktert: ";
    cin >> karakter;

    hibasKarakter = karakter < kezd || karakter > veg;
  } while (hibasKarakter);

  return karakter;
}

// Teszt
int main()
{
  char kezd = 'A';
  char veg = 'D';
  char bekertKar = karBeker(kezd, veg);

  cout << "Az Ön által megadott karakter: " << bekertKar << endl;

  return 0;
}