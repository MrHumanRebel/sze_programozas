#include <iostream>
using namespace std;

int main()
{
  int szam, masikszam;
  bool beker;
  beker = true;
  cout << "Adjon meg egy számot" << endl;
  cin >> szam;
  do
  {
    cout << "Adjon meg egy számot" << endl;
    cin >> masikszam;
    if (szam == masikszam)
    {
      beker = false;
      cout << "A két szám egyenlő!" << endl;
    }
    else
      cout << "A két szám nem egyenlő!" << endl;
  } while (beker == true);
  return 0;
}
