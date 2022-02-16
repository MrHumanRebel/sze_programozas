#include <iostream>
using namespace std;

int main() {
  int szam, masikszam = 0;
  cout << "Adjon meg egy számot!" << endl;
  cin >> szam;
  cout << "Adjon meg egy másik számot!" << endl;
  cin >> masikszam;
  if (szam > masikszam)
    cout << "A számok különbsége: " << szam-masikszam << endl;
  if (szam > 10 && masikszam > 10)
    cout << "A számok szorzata: " << szam*masikszam << endl;  
    return 0;
}
