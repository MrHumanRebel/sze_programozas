#include <iostream>
using namespace std;

int main() {
  cout << "Adjon meg egy számot!" << endl;
  int N = 0;
  bool beker;
  beker = true;
  while (beker){
    cin >> N;
    if (N>1)
      beker = false;
    else
    cout << "Adjon meg egy normális számot!" << endl;
  }
  cout << "Az összes szám N-ig: " << endl;
  for (int i=1; i<=N ;i++){
    cout << i << endl;
  }  
  return 0;
}
