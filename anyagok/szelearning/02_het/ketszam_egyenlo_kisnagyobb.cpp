#include <iostream>
using namespace std;

int main() {
  int szam, masikszam;
  cout << "Adjon meg egy számot!"<<endl;
  cin >> szam;
  cout << "Adjon meg egy másik számot!"<<endl;
  cin >> masikszam;
  if (szam > masikszam)
    cout <<"Az első szám a nagyobb"<<endl;
  else if (szam==masikszam)
    cout <<"A két szám egyenlő!"<<endl;
  else
    cout <<"A második szám a nagyobb"<<endl;
  return 0;
}
