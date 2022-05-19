#define DB 5

struct munka{
  string elvegzo;
  string azonosito;
  int kezdes;
  int hossz;
};

bool utkozes(struct munka m1, struct munka  m2){
  return (m1.kezdes + m1.hossz > m2.kezdes) and (m2.kezdes + m2.hossz > m1.kezdes);
}

void kiiratas(struct munka m){
  cout << m.elvegzo << " " <<  m.azonosito << " " << m.kezdes << " " << m.kezdes << ":" << m.hossz << "\n";
}

void rendez(struct munka m[], int n) {
  for(int i=n-1; i>=1; i--) {
    for(int k=0; k<i; k++) {
      if(m[k].elvegzo.compare(m[k+1].elvegzo) > 0) {
        struct munka csere = m[k];
        m[k] = m[k+1];
        m[k+1] = csere;
      }
    }
  }
}
int main(){
  struct munka munkak[DB] = {{"Cecil", "a5", 10 , 5}, {"Dani", "a4", 8 , 3}, {"Ede", "a3", 10 , 5}, {"Benedek", "a2", 10 , 5}, {"Albert", "a1", 10 , 5}};  
  int i;
  rendez(munkak, DB);
  for(i = 0; i < DB; i++) 
    kiiratas(munkak[i]);
  return 0;
}
