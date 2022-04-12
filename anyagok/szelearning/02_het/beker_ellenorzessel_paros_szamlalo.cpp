#include <iostream>
using namespace std;

int main()
{
  int szam, masikszam, db, paros;
  db = 0;
  paros = 0;
  bool beker;
  beker = true;
  cout << "Adjon meg egy számot" << endl;
  cin >> szam;
  do
  {
    cout << "Adjon meg egy számot" << endl;
    cin >> masikszam;
    db++;
    if (masikszam % 2 == 0)
      paros++;
    if (szam == masikszam)
    {
      beker = false;
      cout << "A két szám egyenlő!" << endl;
      cout << "Ennyi számot olvastunk be ameddig nem lett egyenlő a két szám: " << db << endl;
      cout << "Ennyi db páros számot olvastunk be ameddig nem lett egyenlő a két szám: " << paros << endl;
    }
    else
      cout << "A két szám nem egyenlő!" << endl;
  } while (beker == true);
  return 0;
}
