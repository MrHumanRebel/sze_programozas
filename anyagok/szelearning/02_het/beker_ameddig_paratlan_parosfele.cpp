#include <iostream>
using namespace std;

int main()
{
  int szam;
  bool beker;
  beker = true;
  do
  {
    cout << "Adjon meg egy számot" << endl;
    cin >> szam;
    if (szam % 2 == 0)
      cout << szam / 2 << endl;
    else
      beker = false;
  } while (beker == true);
  return 0;
}
