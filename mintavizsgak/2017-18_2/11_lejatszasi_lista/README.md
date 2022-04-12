# Lejátszási lista

Készítsen programot, ami egy zenei lejátszási lista parancssoros szerkesztését teszi lehetővé!

## Feladat

Egy láncolt listában tárolja el a zeneszámok adatait: előadó, cím.

A felhasználó egy parancssoros menüből tudjon funkciót választani a menüpont számának megadásával:
1.	Kilépés
2.	Szám hozzáadása
	Kérje be a szám adatait, majd azt, hogy hányadik helyre (hányadik szám elé) szúrja be
3.	Szám törlése
	Kérje be a törlendő szám sorszámát, és törölje ki a listából

A program induláskor és minden művelet után jelenítse meg a lista tartalmát (1-től sorszámozva), és a menüpontokat.

## Példa

```
Lejatszasi lista szerkeszto
A lejatszasi lista ures.
Valasszon menupontot:
1 - Kilepes
2 - Hozzaadas
3 - Eltavolitas
2

Kerem az eloadot:
Metal Maiden
Kerem a szam cimet:
Integer of the beast
Hanyadik legyen a listaban?
1

A lejatszasi lista:
1. Metal Maiden - Integer of the beast
Valasszon menupontot:
1 - Kilepes
2 - Hozzaadas
3 - Eltavolitas
2
...

A lejatszasi lista:
1. Metal Maiden - Integer of the beast
2. Blue Day - American stupid
3. AVS - Viszlat tel
Valasszon menupontot:
1 - Kilepes
2 - Hozzaadas
3 - Eltavolitas
3

Hanyadik szamot szeretne torolni?
2
A lejatszasi lista:
1. Metal Maiden - Integer of the beast
2. AVS - Viszlat tel
Valasszon menupontot:
1 - Kilepes
2 - Hozzaadas
3 - Eltavolitas
1

Viszlat!
```

## Értékelés

Az alapfeladat megoldása 2 pont. Plusz, illetve mínusz pont adandó a következőkért:
| Pont | Megjegyzés |
|------|------------|
| –1 | Ha a program fordítása során egyetlen, szabvány fejfájlok be nem kapcsolásából (`#include`) adódó, figyelmeztető üzenet is akad. |
| –1, –2 | Ha az alapprogram működése bármiben is eltér a feladatban megfogalmazottól. |
| +1 | Készítsen egy **Rendezés** funkciót, ami ábécésorrendbe rendezi a számokat előadó, azon belül cím szerint. |
| +1 | A program kilépéskor mentse el a lejátszási listát egy fájlba, és induláskor onnan töltse be a kezdeti adatokat. A fájl tetszőleges formátumú lehet, pl. tárolható az előadó és a cím két külön sorban. |
| +1 | Készítsen egy **Áthelyez** funkciót, amivel egy szám tetszőleges helyre áthelyezhető a listában. |

### Példa az **Áthelyez** funkcióra

```
A lejatszasi lista:
1. Metal Maiden - Integer of the beast
2. Blue Day - American stupid
3. AVS - Viszlat tel
4. Ironica - Master of programs
Hanyadik szamot szeretne athelyezni?
3

Hanyadik szam ele?
1. Metal Maiden - Integer of the beast
2. Blue Day - American stupid
3. Ironica - Master of programs
4. (vegere)
1
```