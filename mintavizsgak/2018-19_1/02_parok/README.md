# Párok

## Feladat

Írjon programot, ami keresztneveket olvas be üres sorig! Amennyiben valamelyik keresztnevet első alkalommal adták meg, kérdezze meg, hogy ez női, vagy férfi név-e!
Hozzon létre férfi – nő párokat a nevek megadásának sorrendjében, amint lehetséges! A program kilépés előtt még jelezze ki, hogy kik maradtak pár nélkül. Feltételezheti, hogy egyszerre **20**-nál többen nem várakoznak párra, és a nevek száma nemenként nem haladja meg az **50**-et.

## Példa

```
Parokat adminisztralo program; kilepes ures sor megadasaval.
Nev: Gizi
Ez (f)erfi vagy (n)oi nev? n
Nev: Mari
Ez (f)erfi vagy (n)oi nev? n
Nev: Pisti
Ez (f)erfi vagy (n)oi nev? f
Uj par: Pisti – Gizi
Nev: Mari
Nev: Geza
Ez (f)erfi vagy (n)oi nev? f
Uj par: Geza – Mari
Nev:
Ures sor, kilepes.
Par nelkul maradt nok: Mari
```

## Értékelés

Az alapfeladat megoldása 2 pont. Plusz, illetve mínusz pont adandó a következőkért:
| Pont | Megjegyzés |
|------|------------|
| –1 | Ha a program fordítása során egyetlen, szabvány fejfájlok be nem kapcsolásából (`#include`) adódó, figyelmeztető üzenet is akad. |
| –1, –2 | Ha az alapprogram működése bármiben is eltér a feladatban megfogalmazottól. |
| +1 | Ha a neveket a nemek szerint egy-egy bináris fában tartja nyilván. |
| +1 | Ha a párra várakozó személyek neveit nemenként egy-egy láncolt listában tartja nyilván! |
| –1 | Ha a dinamikusan lefoglalt memóriaterületeket kilépés előtt nem szabadítja fel a program. |
| +1 | Ha a beolvasott név-nem adatokat a nemek.txt fájlba kimenti, majd a későbbi programindításkor betölti, ezzel csökkentve a felhasználó által megadandó adatok mennyiségét! A fájl szerkezete tetszőleges. |


