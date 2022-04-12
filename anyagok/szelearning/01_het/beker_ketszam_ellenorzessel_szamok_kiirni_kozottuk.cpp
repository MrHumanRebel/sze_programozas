#include <iostream>
using namespace std;

int main()
{
  cout << "Adjon meg egy számot!" << endl;
  int N, M = 0;
  bool beker, bekerketto;
  beker = true;
  bekerketto = true;
  while (beker)
  {
    cin >> N;
    if (N > 1)
      beker = false;
    else
      cout << "Adjon meg egy normális számot!" << endl;
  }
  cout << "Adjon meg egy másik számot, ami nagyobb mint az előző!" << endl;
  while (bekerketto)
  {
    cin >> M;
    if (M > 1 && M > N)
      bekerketto = false;
    else
      cout << "Adjon meg egy normális számot!" << endl;
  }
  cout << "A számok N és M között " << endl;
  for (int i = N; i <= M; i++)
  {
    cout << i << endl;
  }
  return 0;
}
