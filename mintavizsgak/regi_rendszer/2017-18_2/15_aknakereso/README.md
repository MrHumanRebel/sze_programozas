# Aknakereső

Készítsen egyszerű aknakereső játékot!

## Feladat

A játéktér mérete 5 sor x 8 oszlop, melyről a játékos kezdetben nem tudja, hol van elrejtve rajta a 8 darab bomba. A bombákat (`B`) a program mindig ugyanott rejtse el, az alábbi ábrának megfelelően:

|   | A | B | C | D | E | F | G | H |
|---|---|---|---|---|---|---|---|---|
| 1 |   |   |   | B |   |   |   |   |
| 2 |   |   |   | B |   | B |   |   |
| 3 |   |   | B |   |   |   |   | B |
| 4 |   |   |   |   |   |   | B |   |
| 5 |   |   |   | B |   |   |   | B |

A játék indulásakor minden mezőben egy `?` jelenjen meg, ami azt fejezi ki, hogy az adott mezőről még nem tudni semmi biztosat. Ezután kérje be a játékostól egy mező koordinátáját SO formában (pl. `1A`), és rajzolja újra a játékteret a következők szerint:
1. Ha az adott helyen bomba van, a játéknak vége. A játéktér aktuális megjelenítésének annyiban kell eltérnie az előzőtől, hogy minden mezőben, ahol bomba volt elrejtve, meg kell jeleníteni egy `B` betűt. A játéktér alatt jelenítse meg a `Jateknak vege, On vesztett.` üzenetet, majd álljon le a program!
2. Ha az adott mezőben nincs bomba, de közvetlen környezetében legalább egy van, akkor a környező helyeken lévő bombák összesített számát kell a mezőben megjeleníteni.
3. Ha az adott mezőben és közvetlen szomszédjaiban sincs bomba, akkor ebben a mezőben egy `-` jelnek kell megjelennie, és a programnak úgy kell viselkednie, mintha a mező minden szomszédjának koordinátáit is kiadta volna a játékos. Ha ezek között is akad olyan, melyen és közvetlen környezetében sincs bomba, akkor itt is ugyanígy kell eljárni, és így tovább (rekurzív működés).

Ha a játékos kiadta az összes olyan mező koordinátáját, melyeken nincs bomba elrejtve, a játék véget ér, és az `Ön nyert!` feliratot kell megjeleníteni! A korábban már kiadott mezőkoordinátákat hagyja figyelmen kívül! Feltételezheti, hogy a koordináták formailag helyesek.

## Példa

```
Aknakereso

 ABCDEFGH
1????????
2????????
3????????
4????????
5????????

Mezo: 1A

 ABCDEFGH
1--2?????
2-13?????
3-1??????
4-12?????
5--1?????

Mezo: 1D

 ABCDEFGH
1--2B????
2-13B?B??
3-1B????B
4-12???B?
5--1B???B

Jateknak vege, On vesztett.
```

## Értékelés

Az alapfeladat megoldása 2 pont. Plusz, illetve mínusz pont adandó a következőkért:
| Pont | Megjegyzés |
|------|------------|
| -1 | Ha a program fordítása során egyetlen, szabvány fejfájlok be nem kapcsolásából (`#include`) adódó, figyelmeztető üzenet is akad. |
| -1, -2 | Ha az alapprogram működése bármiben is eltér a feladatban megfogalmazottól. |
| +1 | Ha a program a bombákat képes véletlenszerűen elhelyezni a játéktéren. Az ellenőrizhetőség kedvéért valamilyen módon írja ki a játék kezdetén a bombák mezőit! |
| +1 | Ha a program képes az első parancssori paraméterében adott fájlt használva, az ilyen nevű fájlból pályát betölteni. Az első sor tartalmazza a sorok, a második az oszlopok számát. Ezután soronként `?`-et és `B`-t tartalmazó karakterek következnek. (ld. `akna.txt`) A sorokról feltételezheti, hogy számuk nem haladja meg a **9**-et, az oszlopok száma pedig a **20**-at. |
| +1 | Ha a gyanús mezőket meg lehet jelölni, illetve a jelölt mezők ismételt jelölésével a jelölést meg lehet szüntetni. Jelölni csak a még fel nem fedett mezőket lehet. A jelölés úgy történik, hogy a koordináta elé egy `J` betűt illesztünk, pl. `J1A`. A jelölt mezők helyén egy `J` betűnek kell látszania a játéktér megjelenítésekor. |