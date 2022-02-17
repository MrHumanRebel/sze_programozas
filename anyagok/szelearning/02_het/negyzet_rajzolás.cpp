#include <iostream>
using namespace std;

int main() {
  int szam;
  cout<<"Adjon meg egy számot, amekkora négyzetet szeretne pritelni!!!"<<endl;
  cin>>szam;
  for(int i=1;szam;i++){
    for (int j=1;szam;j++){
      cout << "*";
    }
    cout<<"\n";
  }
  return 0;
}
