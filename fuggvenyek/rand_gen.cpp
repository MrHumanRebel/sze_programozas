#include <iostream>
using namespace std;
#define TELL cout <<
#define ASK cin >>
#define MIN 5
#define MAX 50

// Random szám generátor
int random(int tol, int ig)
{
  return (tol + rand() % (ig - tol + 1));
}

int main()
{
  // Random szám generátor tesztelő
  int szam = random(MIN, MAX);
  TELL szam;
  return 0;
}