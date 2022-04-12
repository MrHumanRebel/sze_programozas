#include <iostream>
using namespace std;

int main()
{
  int N = 0;
  int fb_counter = 0;
  int b_counter = 0;
  int f_counter = 0;
  int akt = 1;
  bool beker;
  beker = true;
  cout << "Adjon meg egy számot!" << endl;
  while (beker)
  {
    cin >> N;
    if (N > 1)
    {
      beker = false;
    }
    else
      cout << "Adjon meg egy normális számot!" << endl;
  }
  for (int i = 1; i <= N; i++)
  {
    akt = akt * i;
    if (akt % 3 == 0)
    {
      cout << "Fizz" << endl;
      f_counter++;
    }
    if (akt % 5 == 0)
    {
      cout << "Buzz" << endl;
      b_counter++;
    }
    if (akt % 3 == 0 && akt % 5 == 0)
    {
      cout << "FizzBuzz" << endl;
      fb_counter++;
    }
  }
  cout << "Fizz " << f_counter << " alkalommal fordult elő." << endl;
  cout << "Buzz " << b_counter << " alkalommal fordult elő." << endl;
  cout << "FizzBuzz " << fb_counter << " alkalommal fordult elő." << endl;
  return 0;
}
