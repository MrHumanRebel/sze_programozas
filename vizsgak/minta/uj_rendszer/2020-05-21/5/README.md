Adott az alábbi mátrixot leíró struktúra:


struct matrix {
  int sorok; // A matrix sorainak száma

  int oszlopok; // A matrix oszlopainak száma

  double** m; // Matrix mutatótömbös alakban megadva; 'sorok' darab 'double*' mutató, ami 'oszlop' elemű 'double' tömböt címez.

};


Készítse el a matrix* szorzas(const matrix& m, const double d) függvényt, melynek első paramétere egy mátrix adatait megadó struktúra, második paraméter pedig egy konstans szám. 


A függvény térjen vissza egy dinamikusan foglalt területen lévő mátrix címével, mely a mátrix konstans paraméterrel történő szorzását tartalmazza!

Szintaktikai hiba esetén a fordító által jelzett sor számából vonjon ki 20-at, hogy megkapja a szerkesztőben olvasható sorszámot!


For example:

Test	Result
matrix m1 = general(3, 2, 0);
matrix* m2 = szorzas(m1, 10.0);
kiir(m1); cout << "\n";
if(m2) kiir(*m2);
else cout << "Nem ertelmezheto.";
felszabadit(m1); 
if(m2) {
  felszabadit(*m2); delete m2;
}

    
0 1
2 3
4 5

0 10
20 30
40 50


matrix* szorzas(const matrix& m, const double d) {
  matrix* mtx = new matrix;
  return mtx;
}