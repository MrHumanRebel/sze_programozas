#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

#define N 10
#define MIN_T 2000
#define MAX_T 8000

string sorKiszed(string &sor, int &szokozHelye)
{
  if (szokozHelye > 0)
    sor = sor.substr(szokozHelye + 1);

  szokozHelye = sor.find(' ');
  string aktElem = sor.substr(0, szokozHelye);

  return aktElem;
}

double teruletSzamol(int oldal1, int oldal2, int szog)
{
  return (oldal1 * oldal2 * sin(szog)) / 2;
}

void haromszogFeltolt(int oldalak1[], int oldalak2[], int szogek[], double teruletek[], string sor, int aktIndex)
{
  int szokozHelye = -1;

  oldalak1[aktIndex] = stoi(sorKiszed(sor, szokozHelye));
  oldalak2[aktIndex] = stoi(sorKiszed(sor, szokozHelye));
  szogek[aktIndex] = stoi(sorKiszed(sor, szokozHelye));

  teruletek[aktIndex] = teruletSzamol(oldalak1[aktIndex], oldalak2[aktIndex], szogek[aktIndex]);
}

double area(string fbe)
{
  ifstream fajl(fbe);
  if (fajl.is_open())
  {
    int oldalak1[N];
    int oldalak2[N];
    int szogek[N];
    double teruletek[N];

    string aktSor;
    int i = 0;
    while (getline(fajl, aktSor))
    {
      haromszogFeltolt(oldalak1, oldalak2, szogek, teruletek, aktSor, i);

      i++;
    }

    double atlag = 0.0;
    for (int i = 0; i < N; i++)
    {
      if (teruletek[i] >= MIN_T && teruletek[i] <= MAX_T)
      {
        cout << teruletek[i] << " [nm]" << endl;
      }

      atlag += teruletek[i];
    }
    atlag /= N;

    return atlag;
  }
  else
  {
    cout << "Sikertelen file-nyitás" << endl;
  }

  return -1;
}

int main()
{
  double avg = area("Tri.txt");
  cout << avg;

  return 0;
}
