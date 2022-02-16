#include <iostream>
using namespace std;

int main() {
int N, fakt = 0;
int akt = 1;
bool beker;
beker = true;
cout << "Adjon meg egy számot!"<< endl;
while(beker){
  cin >> N;
  if(N>1){
    beker = false;
  }
  else  
  cout << "Adjon meg egy normális számot!"<< endl;
}
for (int i=1; i<=N; i++){
  akt = akt*i;
  if (akt % 3 == 0)
    cout << "Fizz"<<endl;
  if (akt % 5 == 0)
    cout << "Buzz"<<endl;
  if (akt % 3 == 0 && akt % 5 == 0)
    cout << "FizzBuzz"<<endl;
}
return 0;
}
