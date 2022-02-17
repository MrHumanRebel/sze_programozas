#include <iostream>
using namespace std;

int main()
{
  int szam;
  cout << "Adja meg a lépcső magasságát!" << endl;
  cin >> szam;
  for (int i = 1; i <= szam; i++)
  {
    cout << "*";
    if (i > 1)
    {
      for (int j = 1; j <= i - 1; j++)
      {
        cout << "*";
      }
    }
    cout << "\n";
  }
  return 0;
}