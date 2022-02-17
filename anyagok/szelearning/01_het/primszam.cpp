#include <iostream>
using namespace std;

int main()
{
  int szam = 0;
  cout << "Adjon meg egy számot!" << endl;
  cin >> szam;
  if (szam % 1 == 0 && szam / szam == 1 && szam % 5 != 0 && szam % 3 != 0 && szam % 10 != 0)
    cout << "A megadott szám prímszám!" << endl;
  return 0;
}
