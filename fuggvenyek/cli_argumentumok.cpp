#include <iostream>

using namespace std;

#define DEFAULT_ARG "--teknős"

/* Instrukciók:
   Csak a terminalból futtatva tudjuk megadni a CLI argumentumokat, így először kézzel kell lebuildelnünk:
   cd fuggvenyek
   g++ -Wall -fno-stack-protector -g cli_argumentumok.cpp -o cli_argumentumok
   
   Majd lefuttatnunk:
   ./cli_argumentumok --macska (ez esetben az argv tömb 1. indexű eleme a "--macska" string)
   ./cli_argumentumok (ez esetben az argc értéke 1, így a DEFAULT_ARG ("--teknős") lesz az eredmeny változó értéke)
*/

int main(int argc, char const *argv[])
{
  string eredmeny = argc == 2 ? argv[1] : DEFAULT_ARG;
  cout << "Az általad megadott CLI argumentum: " << eredmeny << endl;

  return 0;
}
