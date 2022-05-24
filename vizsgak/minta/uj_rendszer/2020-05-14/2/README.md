Készítsen hozzafuz nevű függvényt, ami a paraméterül kapott gitárokból álló egyirányú láncoltlista végére egy új gitárt fűz hozzá.

A függvény bemenetként 4 paramétert vár: a gitárok listáját (a láncolt listában az első gitár címe) és az új gitár paramétereit (húrok száma, ár, hangszedő típusa).

A függvény visszatérési értéke a láncolt lista legyen (a lista első gitárjának a címe).

A lista egy elemének a szerkezetét a következő struktúra adja meg (ennek létrehozásáról nem kell gondoskodnia):

struct gitar {
  int hurok_szama;
  int ar;
  string hangszedo;
  gitar* kov;
};


gitar* hozzafuz(gitar* lista, int hurok_szama, int ar, string hangszedo) {}