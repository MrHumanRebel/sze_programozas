#include <iostream>

using namespace std;

void bubi(int tomb[], int db)
{
  for (int i = db - 1; i >= 1; i--)
  {
    for (int j = 0; j < i; j++)
    {
      if (tomb[j] > tomb[j + 1])
      {
        int csere = tomb[j];
        tomb[j] = tomb[j + 1];
        tomb[j + 1] = csere;
      }
    }
  }
}

void kiir(int tomb[], int db)
{
  for (int i = 0; i < db; i++)
  {
    cout << tomb[i] << endl;
  }

  cout << endl;
}

int main()
{
  int tomb[] = {1, -3, 9, -7, 5};
  int meret = sizeof(tomb) / sizeof(tomb[0]);

  kiir(tomb, meret);
  bubi(tomb, meret);
  kiir(tomb, meret);

  return 0;
}
