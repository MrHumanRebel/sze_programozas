#include <iostream>
#include <fstream>

using namespace std;

struct triathlete
{
  string lic;
  int swim;
  int cycle;
  int run;
  int depo;
  int sum;
};

void buborek(triathlete** tb, int hossz){
    string cs;
    for(int i = hossz - 1; i >= 1; i-- ){
        for(int j = 0, csere; j < i; j++){            // létrhoz egy int cserét is
            if(tb[j]->sum > tb[j+1]->sum){
                csere = tb[j]->sum;
                tb[j]->sum = tb[j+1]->sum;
                tb[j+1]->sum = csere;

                cs = tb[j]->lic;
                tb[j]->lic = tb[j+1]->lic;
                tb[j+1]->lic = cs;
            }
        }
    }
}

string tri_result(string fbe){
    ifstream f(fbe);                          // ezzel olvassuk be a fájlt
    string uzenet = "N/A!";
    if (f.is_open()) {                        // csak akkor, ha nyitva van
        int versenyzokSzama;
        f >> versenyzokSzama;                 // beolvassuk az első sort

        triathlete** tri = new triathlete*[versenyzokSzama];       // soronként beolvassuk a fájlt
        for(int i = 0; i < versenyzokSzama; i++){
            tri[i] = new triathlete();                             // létrehozunk egy új atlétát
            f >> tri[i]->lic
              >> tri[i]->swim 
              >> tri[i]->cycle 
              >> tri[i]->run 
              >> tri[i]->depo;
            
            tri[i]->sum = tri[i]->swim +
                          tri[i]->cycle +
                          tri[i]->run +
                          tri[i]->depo;
        }
        f.close();  // bezárjuk, ne maradjon nyitva
        buborek(tri, versenyzokSzama);

        cout << (tri[0]->lic) << " => " 
             << (tri[0]->sum)/ORA << ":"
             << (tri[0]->sum)%ORA/PRC << ":"
             << (tri[0]->sum)%ORA%PRC 
             << " [h:m:s]" << endl;

         uzenet = tri[versenyzokSzama-1]->lic;   

        delete [] tri; tri = 0;
    }
    else cout << "Sikertelen file nyitás." << endl;
    return uzenet;
}
