#include <iostream>
using namespace std;

string szovegBeker()
{
  string szoveg;

  cout << "Szogyakorisagi statisztika. Adja meg a szoveget!" << endl;
  getline(cin, szoveg);

  return szoveg;
}

int main(int argc, char const *argv[])
{
  string szoveg = szovegBeker();
  cout << szoveg << endl;

  return 0;
}
