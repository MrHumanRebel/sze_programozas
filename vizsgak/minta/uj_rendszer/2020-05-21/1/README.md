Készítsen struktúrát munkák ütemezésének számontartására.

 A munka struktúra 2 stringet (munkát elvégző neve, munka azonosító) és két intet (munka kezdete, és munka hossza tartalmazzon).
 
  A kódból kiderül, de a tagok neve legyen: elvegzo; azonosito; kezdes és hossz.

Valósítsa meg a struktúradekalarációt és 2 rövid függvényt:

struct munka - a deklaráció
bool utkozes(struct munka m1, struct munka m2) - a munkák ütközésének figyelésére
void kiiratas(struct munka m) - kiíratás elvégző azonosító kezdés:befejezés formátumban, a munkát elvégző neve szerint rendezve


Segítség
A legegyszerűbb logika a munkák ütközésére: ha az egyik munka befejezése nagyobb a másik munka kezdeténél ÉS a a másik munka befejezése nagyobb az egyik munka kezdeténél, akkor ütközik.

For example:

Test	Result
struct munka munkak[DB] = {{"Cecil", "a5", 10 , 5}, {"Dani", "a4", 8 , 3}, {"Ede", "a3", 10 , 5}, {"Benedek", "a2", 10 , 5}, {"Albert", "a1", 10 , 5}};  
int i;
rendez(munkak, DB);
for(i = 0; i < DB; i++) 
    kiiratas(munkak[i]);
Albert a1 10 10:5
Benedek a2 10 10:5
Cecil a5 10 10:5
Dani a4 8 8:3
Ede a3 10 10:5


#define DB 5

struct munka{
  string elvegzo;
  string azonosito;
  int kezdes;
  int hossz;
};

bool utkozes(struct munka m1, struct munka  m2){
  return false;
}

void kiiratas(struct munka m){

}

void rendez(struct munka m[], int n) {
    
}
