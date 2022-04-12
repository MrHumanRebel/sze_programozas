#include <iostream>
using namespace std;

#define MIN 5
#define MAX 50

// Random szám generátor
int random(int tol, int ig)
{
  return (tol + rand() % (ig - tol + 1));
}

// Teszt
int main()
{
  int szam = random(MIN, MAX);
  cout << szam;

  return 0;
}