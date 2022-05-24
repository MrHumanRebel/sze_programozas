Készítsen szures nevű függvényt, ami paraméterül vár egy gitárokat tartalmazó egyirányú láncolt listát.

 A függvény visszatérési értéke egy 1 elemű lista, ami a legolcsóbb 12 húros gitárt tartalmazza.
 
  Ha több gitár is van a listán, ami a legolcsóbbnak minősül, akkor a bemeneti lista sorrendjében az első találatot kell figyelembe venni.
  
   Ha nincs ilyen gitár, akkor NULL értékkel térjen vissza.

A lista egy elemének a szerkezetét a következő struktúra adja meg (ennek létrehozásáról nem kell gondoskodnia):

struct gitar {
  int hurok_szama;
  int ar;
  string hangszedo;
  gitar* kov;
};


gitar* szures(gitar* lista) {}