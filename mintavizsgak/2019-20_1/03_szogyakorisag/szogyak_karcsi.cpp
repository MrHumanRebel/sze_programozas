#include <iostream>
using namespace std;

#define INPUT_VEG "[vege]"

string szovegBeker()
{
  string szoveg;

  cout << "Szogyakorisagi statisztika. Adja meg a szoveget!" << endl;
  getline(cin, szoveg);

  int zarasHelye = szoveg.find(INPUT_VEG);
  szoveg = szoveg.substr(0, zarasHelye - 1);

  return szoveg;
}

int main(int argc, char const *argv[])
{
  string szoveg = szovegBeker();

  return 0;
}
