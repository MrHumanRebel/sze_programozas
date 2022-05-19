# Sakk

Írjon programot, ami egy 8x8-as sakktáblán fogadja el a ló lépéseit.

## Feladat

Először a kezdő mezőt kérje be, két darab `0` és `7` zárt intervallumba eső számként (sor, oszlop), az input helyességét (intervallumba esés) ellenőrizze! Ezután folyamatosan kérje be a következő lépéseket, ugyanebben a formátumban. A helyes lépés 2 vertikális, 1 horizontális eltolást, illetve ennek fordítottját 1 vertikális, 2 horizontális eltolást jelent az eredeti helyhez képest. Az eltolás lehet pozitív vagy negatív így maximum 8 lépési lehetőség adott. A program `Kilep` sor megadásáig tartson, a lépések helyességéről adjon tájékoztatást, csak a helyes mezőre engedje továbblépni a bábut!

## Példa

### Program

```
Sakktabla program
Kerem a kezdo lepest: 3 3
 >> Helyes lepes, az uj hely: 3 3
Kerem a 2. lepest: 5 4
 >> Helyes lepes, az uj hely: 5 4
Kerem a 3. lepest: 7 7
 >> Hiba, marad a 5 4 helyen
Kerem ujra a 3. lepest: 7 5
 >> Helyes lepes, az uj hely: 7 5
Kerem a 4. lepest: Kilep
 >> Viszlat
```

### Sakktábla

|     |     |     |     |     |     |     |     |     |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
|     | 0   | 1   | 2   | 3   | 4   | 5   | 6   | 7   |
| 0   |     |     |     |     |     |     |     |     |
| 1   |     |     | A   |     | B   |     |     |     |
| 2   |     | H   |     |     |     | C   |     |     |
| 3   |     |     |     | X   |     |     |     |     |
| 4   |     | G   |     |     |     | D   |     |     |
| 5   |     |     | F   |     | E   |     |     |     |
| 6   |     |     |     |     |     |     |     |     |
| 7   |     |     |     |     |     |     |     |     |

## Értékelés

Az alapfeladat megoldása 2 pont. Plusz, illetve mínusz pont adandó a következőkért:
| Pont | Megjegyzés |
|------|------------|
| -1 | Ha a program fordítása során egyetlen, szabvány fejfájlok be nem kapcsolásából (`#include`) adódó, figyelmeztető üzenet is akad. |
| -1 | Ha a programból történő kilépés előtt a lefoglalt memóriaterületeket nem szabadítja fel, az esetlegesen megnyitott fájl(oka)t nem zárja le. |
| -1, -2 | Ha az alapprogram működése bármiben is eltér a feladatban megfogalmazottól. |
| +1 | Hibás lépés esetén írja ki a lehetséges lépéseket. _Megjegyzés: ez nem mindig 8 lehetőség!_ |
| +1 | Gyűjtse a helyes lépéseket láncolt listába és jelenítse meg őket a kilépés előtt! (Az STL gyűjtemények használatát nem fogadjuk el.) |
| +1 | Minden helyes lépés után jelezze a ki a sakktáblát, rajta a jelenlegi és az előző lépést. |
