#include <iostream>
using namespace std;

int main()
{
  int szam;
  cout << "Adjon meg egy számot, amekkora négyzetet szeretne pritelni!!!" << endl;
  cin >> szam;
  // felső sor print
  for (int i = 1; i <= szam; i++)
  {
    cout << "*";
    cout << "\t";
  }

  // sor ugrás
  cout << "\n\n\n";

  int keresztAtlo = szam - 2;
  // közepe print
  for (int i = 1; i <= szam - 2; i++)
  {
    cout << "*";
    for (int j = 1; j <= szam - 1; j++)
    {
      cout << "\t";

      // egyik átló
      if (j == i)
      {
        cout << "*";
      }
      else if (j == keresztAtlo) // másik átló
      {
        cout << "*";
      }
    }

    keresztAtlo--;

    cout << "*";
    cout << "\n\n\n";
  }

  // alsó sor print
  for (int i = 1; i <= szam; i++)
  {
    cout << "*";
    cout << "\t";
  }

  return 0;
}
