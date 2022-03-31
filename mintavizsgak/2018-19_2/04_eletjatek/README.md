# Conway Életjátéka

Készítsen programot, ami Conway Életjátékát demonstrálja!

## Feladat

Az Életjáték egy négyzetrácsos pályán zajlik, ennek a mérete legyen **20x40** (sor x oszlop). A mezőkön vagy van egy sejt vagy nincs.
A program induláskor jelenítse meg az alább látható kezdeti állapotot, majd kérjen be sor- és oszlopindex párokat. A megadott pozíciókban jelenjenek meg új sejtek! Addig ismételje a bekérést, amíg érvénytelen (pályán kívüli) pozíciót nem ad meg a felhasználó! Ekkor induljon el a szimuláció, és jelenítse meg a következő 30 iteráció állapotát, majd álljon le a program. (A pálya egyes állapotait írja ki egymás alá.)

Az iterációk között eltűnhetnek és megjelenhetnek új sejtek a következő szabályok alapján:

- Egy sejt megmarad, ha 2 vagy 3 sejt van a körülötte lévő 8 mezőn, különben eltűnik
- Egy üres mezőn új sejt jelenik meg, ha a körülötte lévő 8 mezőn pontosan 3 sejt van

A feltételek vizsgálatához az előző iteráció állapotát vegye figyelembe, ne az éppen módosult mezőket! Ebben segíthet egy segédpálya létrehozása.

A szélső mezők pályán kívüli szomszédai mindig üresnek számítanak. Segítheti a szomszédok ellenőrzését, ha minden irányban 1-gyel nagyobb pályát tárol, de a szélső mezőket nem jeleníti meg és nem is frissíti az állapotukat az iterációk között.

A program is jelenítse meg a pálya keretét, de a sor- és oszlopindexeket nem kell.

## Példa

```
Kezdeti állapot (X jelöli a sejteket):
  0123456789
  ----------------------------------------
0| X                                      |
1|                                        |
2| X                                      |
3|  XX                                    |
4| XX                                     |
5|                                        |
6|                                        |
7|                                        |
8|XXX                                     |
9|                                        |
 |                                        |
 |                                        |
 |                                        |
 |                                        |
 |                                        |
 |                                        |
 |                                        |
 |                                        |
 |                                        |
 |                                        |
  ----------------------------------------

Következő állapot:
  0123456789
  ----------------------------------------
0|                                        |
1|                                        |
2|  X                                     |
3|   X                                    |
4| XXX                                    |
5|                                        |
6|                                        |
7| X                                      |
8| X                                      |
9| X                                      |
 |                                        |
 |                                        |
 |                                        |
 |                                        |
 |                                        |
 |                                        |
 |                                        |
 |                                        |
 |                                        |
 |                                        |
  ----------------------------------------
```

## Értékelés

Az alapfeladat megoldása 2 pont(=jegy). Plusz, illetve mínusz pont adandó a következőkért:
| Pont | Megjegyzés |
|------|------------|
| –1 | Ha a program fordítása során egyetlen, szabvány fejfájlok be nem kapcsolásából (`#include`) adódó, figyelmeztető üzenet is akad. |
| –1 | Ha a program memóriakezelése hibás. Pl. nincs felszabadítva a lefoglalt terület, vagy túlcímzés történik. |
| –1, –2 | Ha az alapprogram működése bármiben is eltér a feladatban megfogalmazottól. |
| +1 | A program induláskor kérje be a pálya méretét, és ekkora pályát hozzon létre dinamikusan. A méretnek mindkét dimenzióban legalább 10-nek kell lennie, így a kezdeti állapot is rá fog férni.
| +1 | Az iterációk számát parancssori argumentumként lehessen megadni. |
| +1 | A fent megadott kezdőállapot helyett véletlenszerűen töltse fel a pályát sejtekkel, úgy, hogy minden sornak a negyede tartalmazzon sejtet (ha 4-gyel nem osztható a méret, akkor lefelé kerekítve). |
