#include <iostream>
using namespace std;

int main() {
  cout << "Adjon meg egy számot!" << endl;
  int N, osszeg = 0;
  bool beker;
  beker = true;
  while (beker){
    cin >> N;
    if (N>1)
      beker = false;
    else
    cout << "Adjon meg egy normális számot!" << endl;
  }
  for (int i=1; i<=N ;i++){
    osszeg=osszeg+i;
  }  
  cout << "A számok összege N-ig: " << osszeg << endl;
  return 0;
}
