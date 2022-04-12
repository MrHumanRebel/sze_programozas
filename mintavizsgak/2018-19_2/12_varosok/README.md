# Városok

## Feladat

Szeretnénk meglátogatni 5 várost úgy, hogy végül visszaérkezzünk a kiindulási városba (kb. utazó ügynök probléma). A városokat egyszerűen csak sorszámaikkal jelöljük, 1-től 5-ig. A városok közötti távolságokat az alábbi táblázat adja meg:

| Városok távolsága (km) | 1   | 2   | 3   | 4   | 5   |
| ---------------------- | --- | --- | --- | --- | --- |
| 1                      | 0   | 101 | 140 | 66  | 82  |
| 2                      | 101 | 0   | 54  | 166 | 115 |
| 3                      | 140 | 54  | 0   | 205 | 119 |
| 4                      | 66  | 166 | 205 | 0   | 94  |
| 5                      | 82  | 115 | 119 | 94  | 0   |

Olvassa be egymás után az öt város sorszámát! Jelenítse meg az egymást követő város-párok közötti távolságokat (figyelembe véve, hogy végül vissza kell térni a kiindulási városba), és a teljes körutazás hosszát! Ismételje mindezt addig, amíg a felhasználó -1-et nem ad meg a körút első városának indexe helyett!

## Példa

```
Korutazasok hosszanak szamitasa
Adja meg a varosok sorrendjet!
1. varos: 3
2. varos: 1
3. varos: 4
4. varos: 5
5. varos: 2
Tavolsagok:
3 – 1: 140 km
1 – 4: 66 km
4 – 5: 94 km
5 – 2: 115 km
2 – 3: 54 km
Osszesen: 469 km
Adja meg a varosok sorrendjet!
1.	varos: -1
Viszlat!
```

## Értékelés

Az alapfeladat megoldása 2 pont(=jegy). Plusz, illetve mínusz pont adandó a következőkért:
| Pont | Megjegyzés |
|------|------------|
| –1 | Ha a program fordítása során egyetlen, szabvány fejfájlok be nem kapcsolásából (`#include`) adódó, figyelmeztető üzenet is akad. |
| –1 | Ha a program memóriakezelése hibás. Pl. nincs felszabadítva a lefoglalt terület, vagy túlcímzés történik. |
| –1, –2 | Ha az alapprogram működése bármiben is eltér a feladatban megfogalmazottól. |
| +1 | Ha kilépés előtt előállítja az összes lehetséges körutazást, majd az `utazas.txt` fájlba írja ezekről a következőket: 1) városok sorrendje, 2) város-párok közötti távolságok, 3) a teljes kör hossza. Az utolsó sorban tüntesse fel külön a(z egyik) legrövidebb kör városainak sorrendjét, és az utazás hosszát! |
| +1 | Ha a `tavolsagok.txt` fájlból tölti be a program a városok közötti távolságokat. A városok számát a fájl első sora rögzíti. Minden további sor tabulátorral elválasztva a következő adatokat tartalmazza: 1) első város száma, 2) második város száma, 3) a köztük lévő távolság km-ben. |
| +1 | Valósítson meg minimális input ellenőrzést, ami annyiból áll, hogy a városok számának megadásakor nem fogadja el azokat, amik korábban már megadásra kerültek (`Ez a varos mar szerepelt, adjon meg ujat!`), illetve nem létező városokhoz tartoznak (`Ilyen varos nem letezik, adjon meg ujat!`). |
