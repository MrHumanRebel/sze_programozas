# Telefon

Készítsen programot telefonálási költségek kiszámítására!

## Feladat

Az egyszerűség kedvéért tegyük fel, hogy minden beszélgetés ugyanazon a napon belül zajlik. Kérje be a felhasználótól a beszélgetések kezdetének és végének időpontját `ÓÓ:PP:MM` formátumban! Az adatbevitel végét a - karakterlánc jelzi, és nem kell **10**-nél több beszélgetés adatainak tárolására felkészülni. A beszélgetések időben nem fedhetik át egymást, és a beszélgetés kezdetének korábbi időpontnak kell lennie, mint a beszélgetés végének. Ha bármelyik szabályt megsérti a felhasználó, hibajelzést követően új időintervallumot kell bekérni, a rossz adatokat pedig figyelmen kívül kell hagyni.

Végül táblázatos formában kijelzendő a beszélgetések kezdete és vége a beszélgetések megkezdésének növekvő sorrendjében, az egyes beszélgetések hossza megkezdett percekben mérve, az egyes beszélgetések ára 20 Ft-os percdíjat feltételezve, majd a táblázat alatt feltüntetendő a végösszeg is.

## Példa

```
Telefonalasi koltsegek szamitasa
Adja meg a beszelgetesek idointervallumait! Befejezes ures sorral.

Besz. kezdete: 13:50:21
Besz. vege: 13:05:43
A beszelgetes kezdetenek korabbinak kell lennie a vegenel!
Besz. kezdete: 13:05:21
Besz. vege: 13:50:43
Besz. kezdete: 13:50:20
Besz. vege: 13:50:57
A beszelgetesek idoben nem fedhetik at egymast!
Besz. kezdete: 07:52:31
Besz. vege: 07:53:31
Besz. kezdete: -

Besz. kezdete Besz. vege Hossz (P) Ar (Ft)
07:52:31      07:53:31   1         20
13:05:21      13:50:43   46        920
Vegosszeg: 940Ft
```

## Értékelés

Az alapfeladat megoldása 2 pont. Plusz, illetve mínusz pont adandó a következőkért:
| Pont | Megjegyzés |
|------|------------|
| –1 | Ha a program fordítása során egyetlen, szabvány fejfájlok be nem kapcsolásából (`#include`) adódó, figyelmeztető üzenet is akad. |
| –1, –2 | Ha az alapprogram működése bármiben is eltér a feladatban megfogalmazottól. |
| +1 | Ha a beszélgetések adatait dinamikus adatszerkezettel tárolja, és nincs korlátozva a napi beszélgetések száma. Ne felejtse el felszabadítani a lefoglalt memóriát! |
| +1 | Ha a beszélgetés kezdetének időpontja helyett a `veletlen` szót adják meg, akkor generáljon véletlenszerűen egy olyan beszélgetést, ami az alapfeladatban rögzített kritériumoknak eleget tesz! Jelezze is ki ennek kezdési és befejezési időpontját! (Feltételezheti, hogy ilyen beszélgetés létesítése lehetséges.) |
| +1 | Ha parancssori paraméterként megadható a percdíj! |
