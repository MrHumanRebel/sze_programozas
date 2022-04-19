#include <iostream>
using namespace std;

#define INPUT_VEG "[vege]"

struct szo
{
  string szoveg;
  int db;
  szo *kov;
};

string szovegBeker()
{
  string szoveg;

  cout << "Szogyakorisagi statisztika. Adja meg a szoveget!" << endl;
  getline(cin, szoveg);

  int zarasHelye = szoveg.find(INPUT_VEG);
  szoveg = szoveg.substr(0, zarasHelye - 1);

  return szoveg;
}

szo *szoFeltolt(szo *horgony, string szoveg)
{
  size_t i = 0;

  cout << szoveg << endl;

  while (i <= szoveg.length())
  {
    int szokozHelye = szoveg.find(' ');
    //cout << szokozHelye << endl;
    string aktSzo = szoveg.substr(i, szokozHelye - 1);

    // cout << aktSzo << " (" << i << ", " << szoveg.length() << ")" << endl;

    szoveg = szoveg.substr(szokozHelye + 1);
    i = szokozHelye + 1;
  }

  return horgony;
}

int main(int argc, char const *argv[])
{
  string szoveg = szovegBeker();

  szo *kezdo = NULL;
  kezdo = szoFeltolt(kezdo, szoveg);

  return 0;
}
