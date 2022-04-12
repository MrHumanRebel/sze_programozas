#include <iostream>
#include <fstream>
using namespace std;

#define MAX 256

int olvas(string tomb[], string fajlnev)
{
  int i = 0;

  // Deklarássál együtt megpróbálja meg is nyitni
  ifstream fajl(fajlnev);
  string aktSor;

  if (fajl.is_open())
  {
    while (getline(fajl, aktSor))
    {
      tomb[i] = aktSor;
      i++;
    }
  }
  else
  {
    cout << "A fájl nem létezik!" << endl;
  }

  return i;
}

int main()
{
  string tomb[MAX];
  int tombDb = olvas(tomb, "/home/szeke/uni/sze_programozas/mintavizsgak/2017-18_2/12_akasztofa/megyek.txt");
  for (int i = 0; i < tombDb; i++)
  {
    cout << tomb[i] << endl;
  }

  return 0;
}