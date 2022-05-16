/* Rekurzív faktoriális függvény */
#include <iostream>
using namespace std;

int faktorialis(int n)
{
  if (n == 0)
    return 1;
  return n * faktorialis(n - 1);
}

int main(int argc, char const *argv[])
{
  int fakt = faktorialis(5);
  cout << fakt << endl;
  return 0;
}
