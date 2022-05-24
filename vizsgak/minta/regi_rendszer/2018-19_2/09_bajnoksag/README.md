# Bajnokság

Készítsen programot, amivel egy bajnokság alakulását lehet követni!

## Feladat

A bajnokságban 8 csapat van, a csapatnevekben nincs szóköz, és kezdetben minden csapatnak 0 pontja van. A program induláskor és a `refresh` parancs megadásakor jelenítse meg a bajnokság állását egy táblázatban, melynek 4 oszlopa tabulátorral legyen elválasztva:

1. Helyezés
2. Változás az előző megjelenítés óta
3. Pontszám
4. Csapatnév

A táblázat pontszám szerint növekvő, azon belül csapatnév szerinti ábécé-sorrendben legyen! A 2. oszlopban `+i` jelenjen meg, ha `i` helyezéssel előbbre került a csapat, és `-i`, ha `i` hellyel hátrébb került. _Tipp: Az előző helyezés tárolásához adjon hozzá egy extra adattagot a csapat adatstruktúrájához!_

A `refresh` mellett a másik parancs az `exit`, ennek hatására kilép a program. Ha ezektől eltérő sztringet ad meg a felhasználó, akkor azt csapatnévként értelmezze a program, kérje be a szerzett pontokat és adja hozzá a megfelelő nevű csapat pontszámához.

## Példa

```
Poz Mod Pt  Csapatnev
1   0   0   Arsenal
2   0   0   Burnley
3   0   0   Chelsea
4   0   0   Everton
5   0   0   Fulham
6   0   0   Liverpool
7   0   0   ManCity
8   0   0   ManUtd
>> Arsenal
Pontszam?
>> 1
>> Tottenham
Nincs ilyen csapat, adjon meg ujat!
>> Fulham
Pontszam?
>> 1
>> Chelsea
Pontszam?
>> 3
>> Liverpool
Pontszam?
>> 3
>> ManCity
Pontszam?
>> 3
>> refresh
Poz Mod Pt  Csapatnev
1   +2  3   Chelsea
2   +4  3   Liverpool
3   +4  3   ManCity
4   -3  1   Arsenal
5   0   1   Fulham
6   -5  0   Burnley
7   -3  0   Everton
8   0   0   ManUtd
>> exit
```

## Értékelés

Az alapfeladat megoldása 2 pont(=jegy). Plusz, illetve mínusz pont adandó a következőkért:
| Pont | Megjegyzés |
|------|------------|
| –1 | Ha a program fordítása során egyetlen, szabvány fejfájlok be nem kapcsolásából (`#include`) adódó, figyelmeztető üzenet is akad. |
| –1 | Ha a program memóriakezelése hibás. Pl. nincs felszabadítva a lefoglalt terület, vagy túlcímzés történik. |
| –1, –2 | Ha az alapprogram működése bármiben is eltér a feladatban megfogalmazottól. |
| +1 | Ha a csapatok számát és neveit a felhasználó adhatja meg a program indulásakor.
| +1 | Ha a program ismeretlen csapatnév esetén egy új csapatot ad hozzá az adott névvel. Az új csapatok megjelenítésénél a 2. oszlopban az szerepeljen, hogy uj.
| +1 | Ha a program kilépéskor kiírja a bajnokság végső állását (a táblázatot a 2. oszlop nélkül) a `league.txt` fájlba.
