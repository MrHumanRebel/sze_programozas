#include <iostream>
#include <climits> // INT_MAX, INT_MIN

using namespace std;

#define N 10

int szamBeker(int aktIndex)
{
  int aktSzam;

  bool helytelenErtek = false;
  do
  {
    cin >> aktSzam;

    helytelenErtek = (aktIndex == 0 && aktSzam != 0) || (aktIndex % 2 != abs(aktSzam % 2));
  } while (helytelenErtek);

  return aktSzam;
}

int minKeres(int tomb[])
{
  int min = INT_MAX;

  for (int i = 0; i < N; i++)
  {
    if (tomb[i] % 2 != 0 && min > tomb[i])
      min = tomb[i];
  }

  return min;
}

int maxKeres(int tomb[])
{
  int max = INT_MIN;

  for (int i = 0; i < N; i++)
  {
    if (tomb[i] % 2 == 0 && max < tomb[i])
      max = tomb[i];
  }

  return max;
}

int beker(int be_tb[], int *min, int *max)
{
  int szum = 0;

  for (int i = 0; i < N; i++)
  {
    be_tb[i] = szamBeker(i);
    szum += be_tb[i];
  }

  *min = minKeres(be_tb);
  *max = maxKeres(be_tb);

  return szum;
}

void kiir(int szum, int min, int max)
{
  cout << "Szum: " << szum << "\n";
  cout << "Prtln min: " << min << "\n";
  cout << "Prs max: " << max << endl;
}

int main()
{
  int be_tb[N];
  int paratlanMin = INT_MAX;
  int paratlanMax = INT_MIN;

  int szum = beker(be_tb, &paratlanMin, &paratlanMax);
  kiir(szum, paratlanMin, paratlanMax);

  return 0;
}
