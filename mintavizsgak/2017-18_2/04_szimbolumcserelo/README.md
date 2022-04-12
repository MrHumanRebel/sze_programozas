# Szimbólumcserelő

Készítsen programot, ami addig olvassa a felhasználó által megadott szavakat a bemenetről, amíg `[vege]` nem érkezik, addig pedig minden szóban megkeresi a `$` jelek közé írt, alábbi táblázatban szereplő helyőrzőket, amiket nekik megfelelő másik szóra cserél.

## Feladat

A helyőrzők maguk nem tartalmaznak sem `$` karaktert, sem fehér karaktereket. A helyőrzők mindig egy szón belül helyezkednek el, de a szó egyéb karaktereket is tartalmazhat, melyeket meg kell őrizni. Ha ismeretlen helyőrzőre bukkan, őrizze meg a beolvasott szót eredeti formájában!

Ha valamelyik szóban a `$$` karakterpárt találja meg, helyettesítse azokat a kimeneten egyetlen `$` jellel! A bemenet szavai közötti több fehér karaktert a kimeneten helyettesítheti egyetlen szóközzel.

Feltételezheti, hogy a felhasználó a leírtaknak megfelelően használja a programot.

| Helyőrző    | Helyettesítő szó |
| ----------- | ---------------- |
| `nev`       | Gizi             |
| `szin`      | piros            |
| `allat`     | kutya            |
| `jarmu`     | bicikli          |
| `telepules` | Karakoszorcsog   |

## Példa

```
Szimbolumcserelo program
Adja meg az uzenet szavait [vege] vegjelig!
Szia $nev$! Lattalak $telepules$ fele menet, amint hajtottad a $szin$ $jarmu$det, a $allat$ pedig kergetett. Sok $$-t adtam volna akkor es ott egy fenykepezogepert :) [vege]
Szia Gizi! Lattalak Karakoszorcsog fele menet, amint hajtottad a piros biciklidet, a kutya pedig kergetett. Sok $-t adtam volna akkor es ott egy fenykepezogepert :)
```

## Értékelés

Az alapfeladat megoldása **2 pont**. Plusz, illetve mínusz pont adandó a következőkért:

| Pont   | Megjegyzés                                                                                                                                                                                                                                                                                                                                                                                                                   |
| ------ | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| -1     | Ha a program fordítása során egyetlen, szabvány fejfájlok be nem kapcsolásából (`#include`) adódó, figyelmeztető üzenet is akad.                                                                                                                                                                                                                                                                                             |
| –1, –2 | Ha az alapprogram működése bármiben is eltér a feladatban megfogalmazottól.                                                                                                                                                                                                                                                                                                                                                  |
| +1     | Ha a program a helyettesítést nem a fordítási időben adott adatokkal végzi, hanem az első parancssori paraméterként megadott szöveges fájlból olvassa be! A fájl minden sora egymástól szóközzel elválasztott helyőrző - helyettesítő szó párokat tartalmaz. A fájl megnyitásának sikerességét ellenőrizni kell, de egyébként feltételezheti, hogy a fájl tartalma helyes. Mintaként használhatja a `szimbolumok.txt` fájlt. |
| +1     | Ha a helyőrző - helyettesítő szó párokat struktúrákban tárolja, melyekből láncolt listát alkot. A program működése közben nem léphet fel memória szivárgás.                                                                                                                                                                                                                                                                  |
| +1     | Ha a bemeneten `$` jelek között a `vel` helyőrzőt találja a program, akkor helyettesítse azt egy `[0, 9999]` közé eső, véletlenszerűen generált egész számmal!                                                                                                                                                                                                                                                                 |
