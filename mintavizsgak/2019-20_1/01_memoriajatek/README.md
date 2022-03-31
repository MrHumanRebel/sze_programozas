# Memóriajáték

## Feladat

Az egyszerű memóriajátékot a következőképpen kell játszani: az asztalon kezdetben három oszlopban és két sorban elhelyeznek lefordítva egy-egy kártyát. Minden kártya hátulján egy `*` látható. Az előlapjukon az abc első három betűjének valamelyike található, bár ez kezdetben nem látszik. Minden egyes betű pontosan két kártya előlapjára kerül rá. A játékos megfordít egy kártyát, majd ezután még egyet. Ha a felfordított kártyákon ugyanaz a betű szerepelt, akkor többé nem is kell visszafordítani azokat. Ellenben, ha eltérő betűk szerepelnek a kártyák első oldalán, akkor mindkét kártyát vissza kell fordítani. A játékos célja, hogy minél kevesebb kártyafordítással megtaláljon minden betűpárt.

Készítse el a játék egyszerű számítógépes megvalósítását! A sorokat és oszlopokat számozza be! A felhasználó ezek megadásával fordíthat meg egy-egy kártyát. Minden futtatásnál véletlenszerűen kell meghatározni a kártyák helyét. Minden egyes fordítás után rajzolja ki újra az összes kártyát! A játék végén írja ki, hány fordításra volt szüksége a játékosnak!

## Példa

```
Memoriajatek
 123
1***
2***
Megforditando kartya sora: 1
Oszlopa: 1
 123
1a**
2***
Megforditando kartya sora: 1
Oszlopa: 2
 123
1ac*
2***
Nem egyeznek, visszaforditom a lapokat.
 123
1***
2***
Megforditando kartya sora: 1
Oszlopa: 3
 123
1**c
2***
Megforditando kartya sora: 1
Oszlopa: 2
 123
1*cc
2***
Egyformak, a kartyak igy maradnak.
Megforditando kartya sora:
…
 123
1acc
2bba
Egyformak, a kartyak igy maradnak.
Gratulalok, On nyert 8 forditasbol.
```

## Értékelés

Az alapfeladat megoldása 2 pont(=jegy). Plusz, illetve mínusz pont adandó a következőkért:
| Pont | Megjegyzés |
|------|------------|
| –1 | Ha a program fordítása során egyetlen, szabvány fejfájlok be nem kapcsolásából (`#include`) adódó, figyelmeztető üzenet is akad. |
| –1 | Ha a program memóriakezelése hibás. Pl. nincs felszabadítva a lefoglalt terület, vagy túlcímzés történik. |
| –1, –2 | Ha az alapprogram működése bármiben is eltér a feladatban megfogalmazottól. |
| +1 | Ha a program indításakor a `torles` szót adják meg parancssori paraméterként, akkor a kártyák visszafordítását követően 25 üres sort is megjelenít, ezzel „letörölve” a képernyőt, hogy a felhasználó ne tudjon a képernyőről puskázni. |
| +1 | Ha a program induláskor bekéri a kártyasorok és -oszlopok számát. Ezeknek az `[1, 7]` intervallumba kell esniük, de a kártyák számának párosnak kell lennie. Ha bármelyik kritérium nem teljesül, kérje be ismét az adatokat! |
| +1 | Ha a program indítását követően a `memoria.txt` fájlba írja, hogy melyik kártya hová van elrejtve. |
