#include <iostream>
using namespace std;

int main() {
  int szam, masikszam, szorzat, extra, osszeg = 0;
  cout << "Adjon meg egy számot!" << endl;
  cin >> szam;
  cout << "Adjon meg egy másik számot!" << endl;
  cin >> masikszam;
  osszeg = szam+masikszam;
  szorzat = szam*masikszam;
  extra = szorzat-osszeg;
  cout << "A számok összege: " << osszeg << endl;
  cout << "A sszámok szorzata: " << szorzat << endl;
  cout << "A számok szorzatának és összegének különbsége: " << extra << endl;
  return 0;
}
