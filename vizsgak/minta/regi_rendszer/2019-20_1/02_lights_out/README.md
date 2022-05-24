# Lights out

Készítse el a Lights out nevű absztrakt táblás játék C++ nyelvű implementációját!

## Feladat

A játékot általában 5x5-ös méretű táblán játsszák, melynek mezői vagy világosak (jelölje ezt a karakteres képernyőn `*`), vagy sötétek (jelölje ezt `.` karakter). A játék kezdetén a mezők 36%-a (azaz jelen esetben 9 mező) világos, véletlenszerű elrendezésben. A játékos feladata az összes mező elsötétítése a lehető legkevesebb mező kiválasztásával. Az átkapcsoláshoz meg kell nevezni egy cellát, azonban ennek átkapcsolásával egyidejűleg a felette, alatta, tőle balra és jobbra lévő mezők állapota is az ellenkezőjére vált (amennyiben a kiválasztott mező nem a tábla szélére esik, és így ezek a szomszédos mezők léteznek).

Generálja véletlenszerűen a kezdőállapotot, majd kérje be a játékos által választott mező sor- és oszlopát, módosítsa a fényeket a játékszabálynak megfelelően mindaddig, míg az összes fény ki nem alszik! Minden átkapcsolás után jelezze ki a tábla állapotát! Jelezze ki az átkapcsolások számát!

## Példa

```
Lights out
 12345
1.....
2.*.*.
3**.**
4.*..*
5..*..
Mezo sora: 3
Oszlopa: 4
 12345
1.....
2.*...
3***..
4.*.**
5..*..
Mezo sora: 3
Oszlopa: 2
 12345
1.....
2.....
3.....
4...**
5..*..
Mezo sora: 5
Oszlopa: 4
 12345
1.....
2.....
3.....
4....*
5...**
Mezo sora: 5
Oszlopa: 5
 12345
1.....
2.....
3.....
4.....
5.....
Gratulalaok, az osszes lampat lekapcsolta 4 atkapcsolassal!
```

## Értékelés

Az alapfeladat megoldása 2 pont(=jegy). Plusz, illetve mínusz pont adandó a következőkért:
| Pont | Megjegyzés |
|------|------------|
| –1 | Ha a program fordítása során egyetlen, szabvány fejfájlok be nem kapcsolásából (`#include`) adódó, figyelmeztető üzenet is akad. |
| –1 | Ha a program memóriakezelése hibás. Pl. nincs felszabadítva a lefoglalt terület, vagy túlcímzés történik. |
| –1, –2 | Ha az alapprogram működése bármiben is eltér a feladatban megfogalmazottól. |
| +1 | A forrásszöveget készítse el úgy, hogy a `NYOMKOVETES` szimbolikus állandó definiáltsága esetén a fenti mintában látható kezdőállapottal indul a játék, ennek hiányában pedig véletlenszerűen generált kezdőállapottal! |
| +1 | Ha két parancssori paraméterrel megadható a tábla sorainak és oszlopainak száma, de bármilyen adatot is szolgáltasson a felhasználó, a méret nem lehet 3x3-nál kisebb. |
| +1 | Ha a `sor` megadásakor `-1`-et megadva a program kimenti a tábla állapotát a `tabla.txt` fájlba, majd kilép. A programot újraindítva a mentett állapotból folytatható a játék. |
