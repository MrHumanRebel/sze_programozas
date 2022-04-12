#include <iostream>
using namespace std;
#define TELL cout <<
#define ASK cin >>

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

int main()
{
  // Karakter bekerő függvény tesztelő
  char KEZD = 'A';
  char VEG = 'D';
  char kar_akt = karBeker(KEZD, VEG);
  TELL kar_akt << endl;
  return 0;
}