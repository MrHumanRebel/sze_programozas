#include <iostream>
using namespace std;

struct kodPar
{
  char billentyu;
  char ertekek[6];
  int ertekDb;
};

string dekodol(string kodoltSzoveg)
{
  kodPar kodtabla[] = {
      {'1', {'.', ',', '-', '?', '!', '1'}, 6},
      {'2', {'A', 'B', 'C', '2'}, 4},
      {'3', {'D', 'E', 'F', '3'}, 4},
      {'4', {'G', 'H', 'I', '4'}, 4},
      {'5', {'J', 'K', 'L', '5'}, 4},
      {'6', {'M', 'N', 'O', '6'}, 4},
      {'7', {'P', 'Q', 'R', 'S', '7'}, 5},
      {'8', {'T', 'U', 'V', '8'}, 4},
      {'9', {'W', 'X', 'Y', 'Z', '9'}, 5},
      {'*', {'k', 'n', '*'}, 3}, // k == kisbetű, n == nagybetű
      {'0', {'+', '0'}, 2},
      {'#', {' ', '#'}, 2},
  };

  string dekodoltSzoveg = "";

  return dekodoltSzoveg;
}

int main(int argc, char const *argv[])
{
  string tesztSzoveg = "55*3355#29999#334#337777#99996665553#2#333881 1 1";
  dekodol(tesztSzoveg);

  return 0;
}
