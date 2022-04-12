# Szálloda

Írjon programot, amely egy szálloda lakóinak adatait kezeli **láncolt lista** adatszerkezetben.

## Feladat

A listaelemek mintájaként a következő típusdefiníció szolgáljon:

```cpp
struct vendeg {
  string keresztNev;
  int emelet;
  int ajto;
  struct vendeg *kov;
};
```

Töltse fel a láncolt listát egy `vendeg *listaFeltolt()` prototípusú függvénnyel, ami a lenti táblázat értékeit tölti rendre a listába. Ezután olvasson be `Kilep`–ig újabb rekordokat (név + emelet + ajtó), majd szúrja be ezeket emelet azután pedig ajtó szerint rendezve egy `vendeg *listaRendezveBeszur(vendeg *elso, string keresztNev, int emelet, int ajto)` prototípusú függvény segítségével a listába. Minden sikeres rekordbeolvasás után, valamint a program indulásakor listázza a szálloda lakóit!

Minimális inputellenőrzésképp csak az emeletet és az ajtót kell ellenőrizni. Az emelet `1, 7` zárt intervallumba, míg a szoba `1, 20` zárt intervallumba essen! A nem megfelelő input adat helyett mindenképpen és azonnal kérjen újat a program, hibajelzéssel! Ezen kívül alapfeladatként más inputellenőrzésre nem kell készülnie.

### Táblázat

| `string keresztNev` | `int emelet` | `int ajto` |
| ------------------- | ------------ | ---------- |
| Ferenc              | 1            | 1          |
| Bertalan            | 2            | 1          |
| Anna                | 2            | 15         |
| Marika              | 7            | 16         |

## Értékelés

Az alapfeladat megoldása 2 pont. Plusz, illetve mínusz pont adandó a következőkért:
| Pont | Megjegyzés |
|------|------------|
| -1 | Ha a program fordítása során egyetlen, szabvány fejfájlok be nem kapcsolásából (`#include`) adódó, figyelmeztető üzenet is akad. |
| -1 | Ha a programból történő kilépés előtt a lefoglalt memóriaterületeket nem szabadítja fel, az esetlegesen megnyitott fájl(oka)t nem zárja le. |
| -1, -2 | Ha az alapprogram működése bármiben is eltér a feladatban megfogalmazottól. |
| +1 | Mentse a listát egy `hotel.csv` nevű fájlba! Amennyiben ez a fájl programinduláskor létezik, akkor ebből töltse be a `nevLista *listaFeltolt()` függvény a rekordokat. Az adatokat vesszővel, a rekordokat sortöréssel válassza el egymástól! |
| +1 | A minimális inputellenőrzést egészítse ki azzal, hogy a név csak betűket tartalmazzon, nagybetűvel kezdődjön, és utána kisbetűk következzenek. A név minimum 5 karakter hosszú legyen! |
| +1 | Amennyiben újra megadunk már létező szobaszámot, írja felül a nevet és jelezze is külön, "Uj lako" szöveggel! |
