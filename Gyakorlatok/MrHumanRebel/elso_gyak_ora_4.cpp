// 1/3 => Alap-operátorok, változó, while ciklus
#include<iostream>

#define NK 2
#define AP 2
#define KT 10

using namespace std;

int main() {
    cout << "Összeg: " << NK + 2 << "\n" << "Különbség: " << NK - 2 << "\n" 
	        << "Szorzat: " << NK * 2 << endl;
	cout << "Hányados: " << NK / 2 << "\n" << "Maradék: " << NK % 2 << "\n" << endl;
	int f_k=1, k_e=1;
    while(f_k <= KT) {
	  cout << AP << "^" << f_k << ". hatványa: " << AP * k_e << endl;
	  f_k = f_k + 1;
	  k_e = AP * k_e;
	 }
return 0;
}