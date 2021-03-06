# 1. feladat

## Leírás

Írjon egy programot, amely 2 db felhasználói függvényt használ.

Az egyik az `int beker(int be_tb[], int *min, int *max)`, amely 10 db előjeles egész számot kér be úgy, hogy azokat egy tömbbe tárolja le. A tömb hosszát szimbolikus állandóval állítsa be.

A tárolás csak akkor jöjjön létre, ha az alábbi feltételek teljesülnek:
- A tömb 0. indexén csak a nulla érték, 
- a páratlan indexein csak páratlan értékek,
- és a páros indexein csak páros számok szerepelhetnek!

Ha az adott érték nem teljesíti a rá vonatkozó feltételt, akkor új számot kell bekérni. Bekérési információk és hibaüzenetek kiírása nem kell!

A feltételek teljesülése esetén a `beker` függvény határozza meg és tárolja el a legkisebb páratlan, illetve a legnagyobb páros számokat. Ezen értékek a függvény 2. és 3. paraméterei, amíg az 1. paraméter a tároló tömb. 

A függvény visszatérési értéke a 10 db szám összege legyen.

A másik függvény a `void kiir(int szum, int min, int max)`,
pedig írja ki a beker függvény visszatérési értékét illetve a 2. és 3. paraméterek értékeit a példában látott szövegezéssel.

## Példa
| Input | Result |
|-------|--------|
| `0 1 2 3 4 5 6 7 8 9` | `Szum: 45`<br>`Prtln min: 1`<br>`Prs max: 8` |
| `2 0 -1 -2 2 3 3 4 5 6 7 8 9` | `Szum: 39`<br>`Prtln min: -1`<br>`Prs max: 8` |