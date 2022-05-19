# Busz

Készítsen programot, amely kiszámítja, hogy egy bizonyos hosszúságú utazás mennyibe kerülne autóbusszal!

## Feladat

A Volánbusz aktuális tarifáit a `tarifa.csv` fájl tartalmazza, mely egyszerű szövegfájl. Az első sora fejléc, minden további sorban az első két egész szám egy távolság-intervallumot ad meg, mely alulról nyitott, felülről zárt. A harmadik oszlop a teljes árú menetjegy bruttó árát tartalmazza. Pl. egy 42, vagy egy 45 km-es utazás ára egyformán 840 Ft. Az oszlopokat **tabulátorok** választják el egymástól. Töltse be a fájl tartalmát a memóriába, majd olvasson be távolságokat (egészek km-ben megadva)!

Ezt követően jelenítse meg az utazás árát! A programból nulla, vagy negatív távolság megadásával lehessen kilépni! Használjon bináris keresést a tarifa meghatározásához!

## Példa

```
Autobusz menetdij szamitasa. Kilepes negativ tavolsag megadasaval.
Tavolsag (km): 50
Teljesaru jegy bruttó ara: 930Ft
Tavolsag (km): -1
Kilepes.
```

## Értékelés

Az alapfeladat megoldása 2 pont. Plusz, illetve mínusz pont adandó a következőkért:
| Pont | Megjegyzés |
|------|------------|
| –1 | Ha a program fordítása során egyetlen, szabvány fejfájlok be nem kapcsolásából (`#include`) adódó, figyelmeztető üzenet is akad. |
| –1, –2 | Ha az alapprogram működése bármiben is eltér a feladatban megfogalmazottól. |
| +1 | Ha parancssori paraméterként egy `[0, 100]` intervallumba eső számot adnak meg, akkor a teljes árú díj helyett ekkora kedvezménnyel rendelkező jegyárat kell mutatnia! Pl. a 90% kedvezmény egy 100 km-es úton 186 Ft-os jegyárat jelent. |
| +1 | Ha az adatokat dinamikus tömb segítségével tárolja a memóriában! Kezdetben a tömb legyen alkalmas 4 sornyi adat tárolására. Ha a tömb mérete futás közben kevésnek bizonyulna, mindig növelje a tömb elemszámát a duplájára! |
| +1 | Ha a program bekéri induláskor az ÁFA kulcsot is százalékban, egészként (pl. 27), és ennek felhasználásával a bruttó árból meghatározza, majd kijelzi a nettó árat is! |
