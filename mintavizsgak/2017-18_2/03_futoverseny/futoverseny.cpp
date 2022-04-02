#include <iostream>
using namespace std;

struct ido
{
  int ora;
  int perc;
  int masodperc;
};

struct reszeredmeny
{
  int rajtszam;
  int ellenorzoPont;
  ido erkezesiIdo;
  reszeredmeny *kov;
};

struct futo
{
  int rajtszam;
  string nev;
  reszeredmeny *kezdo;
};

int main(int argc, char const *argv[])
{
  cout << "Futoverseny" << endl;
  return 0;
}
