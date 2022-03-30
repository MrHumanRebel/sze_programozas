# Akasztófa

Készítse el az akasztófa játék egy speciális változatát!

## Feladat

A kitalálandó, legalább 5 karakter hosszú szavakat fordítási időben tárolja el, legalább 5 darabot, melyek közül minden indításkor véletlenszerűen kiválaszt egyet. Segítségképpen jelezze ki a feladvány témakörét a szabvány kimenetre! 

Kezdetben a kitalálandó szó minden betűjének helyén egy csillagot jelenítsen meg, majd olvassa be egymás után a játékos tippjeit! A játékosnak maximum 5 lehetősége van eltalálni a szót! Ha a tipp tartalmazott olyan betűt, ami a feladványban is szerepel, akkor minden tipp után jelenítse is meg ezeket az eltalált betűket a megfelelő helyeken! 

Kis és nagy betűk között ne tegyen különbséget!

## Példa

```
Szokitalalalo jatek! Talald ki milyen orszagra gondoltam! 

Segitseg:
*****
Ird be a(z) 1. tipped!
Geza

Nem talalt! A kovetkezo helyen van jo betu:
*a*a*
Ird be a(z) 2. tipped!
Japan

Gratulalunk! Nyertel!

```

## Értékelés

Az alapfeladat megoldása 2 pont. Plusz, illetve mínusz pont adandó a következőkért:
| Pont | Megjegyzés |
|------|------------|
| -1 | Ha a program fordítása során egyetlen, szabvány fejfájlok be nem kapcsolásából (`#include`) adódó, figyelmeztető üzenet is akad. |
| -1, -2 | Ha az alapprogram működése bármiben is eltér a feladatban megfogalmazottól. |
| +1 | Ha lehetőség van csalni a játékban! Ha `/cheat` parancssori paraméterrel indítják a programot, akkor az első tippet megelőzően 2 helyen megjeleníti a helyes betűt! Utána minden tippnél ad egy plusz helyes belűt! |
| +1 | Egészítse ki azzal a játékot azzal, hogy a program minden lépés után automatikusan elmenti a játék állását a `hangman.txt` fájlba. Mentendő a játékosok eddigi tippjei, a témakör és a kitalálandó szó! |
| +1 | Amennyiben a kitalálandó szavakat be lehet tölteni egy `szavak.txt` fájlból! A fájl minden sora azonos szerkezetű: az első szó a témakör megnevezése, amelybe a második szóként megadott kitalálandó szó kerül. Ezeket fehér karakterek választják el egymástól. |