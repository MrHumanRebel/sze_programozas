#include <iostream>
using namespace std;

int main() {
  int szam;
  cout<<"Adjon meg egy számot, amekkora négyzetet szeretne pritelni!!!"<<endl;
  cin>>szam;
  for(int i=1;i<=szam;i++){
    for (int j=1;j<=szam;j++){
      cout << "*";
    }
    cout<<"\n";
  }
  return 0;
}
