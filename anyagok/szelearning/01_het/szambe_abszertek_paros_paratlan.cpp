#include <iostream>
using namespace std;

int main()
{
  int szam = 0;
  cout << "Adjon meg egy számot!" << endl;
  cin >> szam;
  cout << "A szám abszolút értéke: " << abs(szam) << endl;
  if (szam % 2 == 0)
    cout << "A megadott páros szám fele: " << szam / 2 << endl;
  else
    cout << "A megadott szám 2-vel való osztásának eredménye: " << szam / 2 << endl;
  return 0;
}
