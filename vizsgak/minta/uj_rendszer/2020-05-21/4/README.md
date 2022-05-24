Írjon egy string szokozkiszed(const string &s) és egy void betubolszam(string &s) függvényt. 

A szokozkiszed az átadott stringből szedje ki a szóközöket, majd ezt a stringet adja vissza.

A betubolszam a paraméter stringben található kisbetűkből állítson elő számokat, mégpedig úgy, hogy 'a'-ból, '1', 'b'-ből '2', stb. legyen. Ezt a standard kimentre írja ki.


For example:

Test	Result
string teszt1 = "a b c d e f"; cout << teszt1 << "\n"; 
cout << szokozkiszed(teszt1) << "\n";
betubolszam(teszt1);
    
a b c d e f
abcdef
1 2 3 4 5 6


#include <string>

string szokozkiszed(string &s){
    return "return";
}

void betubolszam(string &s){

}
