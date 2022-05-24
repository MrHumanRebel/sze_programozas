Készítsen szures nevű függvényt, ami gitárokat tartalmazó egyirányú láncolt listát vár paraméterül.

A függvény készítsen egy új listát, amelyre a 6 húros, "single coil" típusú hangszedővel, valamint a 8 húros, "humbucker" hangszedővel rendelkező gitárok kerülnek fel.
 
A szűrt listára a hangszerek olyan sorrendben kerüljenek, amilyen sorrendben egymás követik az eredeti listában.
  
A függvény visszatérési értéke a szűrt lista legyen (a lista első gitárjának a címe). Ha nincs ilyen gitár, akkor NULL értékkel térjen vissza.

A lista egy elemének a szerkezetét a következő struktúra adja meg (ennek létrehozásáról nem kell gondoskodnia):

struct gitar {
  int hurok_szama;
  int ar;
  string hangszedo;
  gitar* kov;
};


gitar* szures(gitar* lista) {}