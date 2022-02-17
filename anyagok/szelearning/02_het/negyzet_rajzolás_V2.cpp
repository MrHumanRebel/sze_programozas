#include <iostream>
using namespace std;

int main() {
  int szam;
  cout<<"Adjon meg egy számot, amekkora négyzetet szeretne pritelni!!!"<<endl;
  cin>>szam;
  for(int i=1;i<=szam;i++)
    cout<<"*";
  for(int i=1;i<=szam-2;i++)
    cout<<"*"<<"\t*szam"<<"*";
  for(int i=1;i<=szam;i++)
    cout<<"*";
  return 0;
}
