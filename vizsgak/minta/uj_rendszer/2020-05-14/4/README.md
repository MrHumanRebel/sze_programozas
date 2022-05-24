Készítsen szures nevű függvényt, ami paraméterül vár egy gitárokat tartalmazó egyirányú láncolt listát.

 A függvény készítsen egy új listát a drága gitárokról. Egy gitárt akkor nevezünk drágának, ha az ára magasabb, mint a listán szereplő gitárok árának az átlaga.
 
  A szűrt lista legyen a függvény visszatérési értéke (a lista első gitárjának a címe).
  
   Ha nincs ilyen gitár, akkor NULL értékkel térjen vissza.

A lista egy elemének a szerkezetét a következő struktúra adja meg (ennek létrehozásáról nem kell gondoskodnia):

struct gitar {
  int hurok_szama;
  int ar;
  string hangszedo;
  gitar* kov;
};


gitar* szures(gitar* lista) {}