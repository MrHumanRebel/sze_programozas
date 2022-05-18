/*Készítsen diagonális mátrixot felhasználva egy vektor elemeit!
Definiálja az int** vec2diagMtx(const int* vector, int n) függvényt,
ami paraméterként megkapja az n elemű vector vektort,
melynek elemeit elhelyezi egy dinamikusan,
futásidőben lefoglalt kvadratikus mátrix főátlója mentén!
A mátrix összes többi elemének zérusnak kell lennie.*/

int** vec2diagMtx(const int* vector, int n) {
  int** mtx = new int*[n];
  for(int i=0; i<n; i++) {
    mtx[i] = new int[n];
    for(int j=0; j<n; j++) {
      mtx[i][j] = i==j?vector[i]:0;
    }
  }
  return mtx;
}
