# Osztály

**⚠️ Láncolt listás feladat! ⚠️**

Írjon C++ programot az alábbi feladatokra! A program indulásakor jelezze ki, hogy mit csinál! Az input adatok bekérését és az eredmények közlését lássa el tájékoztató szövegekkel!

## Feladat

Írjon programot, amely egy középiskolai osztály adatait kezeli láncolt lista adatszerkezetben. A listaelemek alkossanak tornasort, ennek mintájaként a következő típusdefiníció szolgáljon:

### Struktúra

```cpp
struct nevLista {
  string keresztNev;
  int magassag;
  struct nevLista kov;
};
```

Töltse fel a láncolt listát egy `nevLista *listaFeltolt()` prototípusú függvénnyel, ami a lenti táblázat értékeit tölti rendre a listába. Olvasson be `kilep`-ig újabb rekordokat (név + magasság), majd szúrja be ezeket a magasság szerint rendezve egy `nevLista *listaRendezveBeszur(nevLista *elso, string keresztNev, int magassag)` prototípusú függvény segítségével a listába. Minden sikeres rekordbeolvasás után, valamint a program indulásakor listázza az első négy tanuló adatait. Minimális inputellenőrzésképp csak a keresztnevet kell ellenőrizni, ez legyen minimum **4** karakter.

A nem megfelelő input adat helyett mindenképpen és azonnal kérjen újat a program, hibajelzéssel! Ezen kívül alapfeladatként más inputellenőrzésre nem kell készülnie.

| `string keresztNev` | `int magassag` |
| ------------------- | -------------- |
| Cecil               | 198            |
| Bertalan            | 195            |
| Antal               | 180            |
| Domonkos            | 172            |

## Értékelés

Az alapfeladat megoldása 2 pont. Plusz, illetve mínusz pont adandó a következőkért (a teljesített pluszpont bekarikázandó):

| Pont   | Megjegyzés                                                                                                                                                                                                                                          |
| ------ | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| -1     | Ha a program fordítása során egyetlen, szabvány fejfájlok be nem kapcsolásából (`#include`) adódó, figyelmeztető üzenet is akad.                                                                                                                    |
| -1     | Ha a programból történő kilépés előtt a lefoglalt memóriaterületeket nem szabadítja fel, az esetlegesen megnyitott fájl(oka)t nem zárja le.                                                                                                         |
| -1, -2 | Ha az alapprogram működése bármiben is eltér a feladatban megfogalmazottól.                                                                                                                                                                         |
| +1     | A minimális inputellenőrzést egészítse ki azzal, hogy a név csak angol ABC-beli betűket tartalmazzon, nagybetűvel kezdődjön, és utána kisbetűk következzenek. A magasságnál a helyes input **120** és **210** cm közötti zárt intervallumon legyen. |
| +1     | Amennyiben újra megadunk egy nevet, írja felül a diák magasságát, amit jelezzen is külön, `Felulirtuk a magassagot` szöveggel!                                                                                                                      |
| +1     | Kilépés előtt mentse a listát egy `osztaly.txt` nevű fájlba! Amennyiben ez a fájl programinduláskor létezik, akkor ebből töltse be a nevLista `*listaFeltolt()` függvény a rekordokat.                                                              |
