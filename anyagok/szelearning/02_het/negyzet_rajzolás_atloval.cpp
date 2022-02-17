#include <iostream>
using namespace std;

int main() {
  int szam;
  cout<<"Adjon meg egy számot, amekkora négyzetet szeretne pritelni!!!"<<endl;
  cin>>szam;
  //felső sor print
  for(int i=1;i<=szam;i++){
    cout<<"*";
    cout<<"\t";
  }

  //sor ugrás
  cout<<"\n\n\n";

  //közepe print
  for(int i=1;i<=szam-2;i++){
    cout<<"*";
    for(int j=1;j<=szam-1;j++){
      cout<<"\t";

      //egyik átló
      
      if (i==j){
        cout<<"*";
      }

      //másik átló BETA

      /*for(int k=szam;k>=1;k--){
        if (k==j){
        cout<<"*";
        }
      }
      */
    }
    cout<<"*";
    cout<<"\n\n\n";
  }

  //alsó sor print

  for(int i=1;i<=szam;i++){
    cout<<"*";
    cout<<"\t";
  }
  return 0;
}
