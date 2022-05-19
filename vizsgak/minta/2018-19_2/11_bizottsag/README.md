# Bizottság

Készítsen programot, ami az államvizsga bizottságok kérdező tanárainak összeállítását segíti!

## Feladat

Az egyszerűség kedvéért tegyük fel, hogy egy bizottság egymás után legfeljebb 10 hallgatót vizsgáztathat, minden bizottság ugyanazon a napon tevékenykedik, és legfeljebb 5 ilyen bizottság van. Minden bizottság ugyanakkor kezdi a munkáját, minden hallgatót egy tanár vizsgáztat és minden hallgató ugyanannyi időt tölt a vizsgázással.

Olvassa be egymás után az első bizottság legfeljebb 10 kérdező tanárának nevét, vagy kevesebbet, ha név helyett a vege szót adják meg! Olvassa be egymás után a további legfeljebb 4 bizottság kérdező tanárainak nevét is, vagy kevesebbet, ha rögtön az első név helyett a vege szót adják meg!

Amennyiben egy tanár ugyanabban az időben már vizsgáztat valakit egy másik bizottságban, más tanárt kell megadni helyette! A program kilépés előtt táblázatos formában jelezze ki, hogy ki hány hallgatót vizsgáztat! A táblázat legyen a hallgatók száma szerint csökkenően rendezve!

## Példa

```
Allamvizsga bizottsagok osszeallitasa
1. bizottsag 1. vizsgaztatoja: Kovacs Janos
1. bizottsag 2. vizsgaztatoja: Hatwagner Ferenc Miklos
1. bizottsag 3. vizsgaztatoja: Kovacs Katalin
1. bizottsag 4. vizsgaztatoja: Kovacs Janos
1. bizottsag 5. vizsgaztatoja: vege
2. bizottsag 1. vizsgaztatoja: Kovacs Janos
Mar vizsgaztat ugyanebben az idoben mashol!
2. bizottsag 1. vizsgaztatoja: Hatwagner Ferenc Miklos
2. bizottsag 2. vizsgaztatoja: Horvath Erno
2. bizottsag 3. vizsgaztatoja: Osz Oliver
2. bizottsag 4. vizsgaztatoja: Hollosi Janos
2. bizottsag 5. vizsgaztatoja: Osz Oliver
2. bizottsag 6. vizsgaztatoja: Osz Oliver
2. bizottsag 7. vizsgaztatoja: vege
3. bizottsag 1. vizsgaztatoja: vege

Tanar neve 					Vizsgaztatott hallgatok szama
Osz Oliver					3
Kovacs Janos				2
Hatwagner Ferenc Miklos 	2
Kovacs Katalin				1
Horvath Erno				1
Hollosi Janos				1
```

## Értékelés

Az alapfeladat megoldása 2 pont(=jegy). Plusz, illetve mínusz pont adandó a következőkért:
| Pont | Megjegyzés |
|------|------------|
| –1 | Ha a program fordítása során egyetlen, szabvány fejfájlok be nem kapcsolásából (`#include`) adódó, figyelmeztető üzenet is akad. |
| –1 | Ha a program memóriakezelése hibás. Pl. nincs felszabadítva a lefoglalt terület, vagy túlcímzés történik. |
| –1, –2 | Ha az alapprogram működése bármiben is eltér a feladatban megfogalmazottól. |
| +1 | Ha dinamikus memóriakezeléssel megoldja, hogy az egyidejűleg dolgozó bizottságok száma tetszőlegesen nagy lehessen! |
| +1 | Ha parancssori paraméterként megadható, hogy `Hatwagner Ferenc Miklos` hányadik hallgatót nem tudja vizsgáztatni egyik bizottságban sem egyéb elfoglaltságai miatt. |
| +1 | Ha a program kilépés előtt kiírja a `naphose.txt` fájlba, hogy ki vizsgáztatott legtöbbször! Amennyiben többen is ugyanannyiszor vizsgáztattak, válasszon a vizsgáztatók közül véletlenszerűen! |
