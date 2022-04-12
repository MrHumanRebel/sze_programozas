#include <iostream>
using namespace std;

#define MAX 5

void tombToUpper(string tomb[], int aktDb)
{
  for (int i = 0; i < aktDb; i++)
  {
    string akt = tomb[i];
    int db = tomb[i].length();

    tomb[i] = "\0";
    for (int j = 0; j < db; j++)
    {
      tomb[i] += toupper(akt[j]);
    }
  }
}

void kiir(string tomb[], int aktDb)
{
  for (int i = 0; i < aktDb; i++)
  {
    cout << tomb[i] << endl;
  }

  cout << endl;
}

int main()
{
  string tomb[MAX] = {"abc", "bcd", "cad", "dec", "eda"};
  kiir(tomb, MAX);

  tombToUpper(tomb, MAX);
  kiir(tomb, MAX);

  return 0;
}