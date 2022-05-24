# SMS dekódoló

Készítsen SMS dekódoló programot C/C++ nyelven!

## Feladat

A dekódolási eljárást valósítsa meg egy **függvénnyel**. A függvény egy forrássztringet kap paraméterként, és a dekódolt tartalmat adja vissza. A forrásszövegben az SMS szövege billentyűlenyomás szerint van kódolva.

Az egyes billentyűkhöz a következő karakterek tartoznak:

| Szám | Karakterek          |
| ---- | ------------------- |
| 1    | ./,/-/?/!/1         |
| 2    | A/B/C/2             |
| 3    | D/E/F/3             |
| 4    | G/H/I/4             |
| 5    | J/K/L/5             |
| 6    | M/N/O/6             |
| 7    | P/Q/R/S/7           |
| 8    | T/U/V/8             |
| 9    | W/X/Y/Z/9           |
| \*   | kisbetű/NAGYBETŰ/\* |
| 0    | +/0                 |
| #    | szóköz/#            |

A forrásszövegben a billentyűérték annyiszor ismétlődik, ahányadik a hozzá tartozó listában a küldeni kívánt karakter. Pl. az `1` jelentése `.` (pont), az `1111` jelentése `?` (kérdőjel). Az egyes dekódolandó karakterek szorosan egymást követik, kivéve, ha azonos csoportból származnak, ebben az esetben szóköz választja el őket egymástól. A szöveg karakterei alapértelmezés szerint nagybetűk. Írja ki a képernyőre a dekódolt szöveget. 

Ha a forrás jelei a 10 számjegyen, a csillagon, kettőskereszten és szóközön kívül bármi mást is tartalmaznának, vagy túl sok karakter alkotna egy-egy csoportot, akkor azt **hagyja figyelmen kívül**.

## Példa

```
Input: 55*3355#29999#334#337777#99996665553#2#333881 1 1
Output: Kek az eg es zold a fu…
```

## Értékelés

Az alapfeladat megoldása **2 pont**. Plusz, illetve mínusz pont adandó a következőkért:

| Pont | Megjegyzés |
|----------|----------------------------------------------------------------------------------------------------------------------------------|
| -1 | Ha a hibás eseteket nem kezeli a program az előírtnak megfelelően. |
| -1 | Ha a program fordítása során egyetlen, szabvány fejfájlok be nem kapcsolásából (`#include`) adódó, figyelmeztető üzenet is akad. |
| –1 | Ha az alapprogram működése bármiben is eltér a feladatban megfogalmazottól. |
| +1 | Ha a program egy hallgató által készített `KOD.TXT` fájlból olvassa be az input kódot és egy `SZOVEG.TXT`-be menti a dekódolt szöveget. |
| +1 | Ha az előző pontban említett ki- és bemeneti fájlokat parancssori paraméterként fogadja a program, és nem előre rögzített fájlneveket használ. |
| +1 | Készítsen egy olyan függvényt, amely az alapfeladatban meghatározott függvény ellentettjét végzi, azaz egy tetszőleges szöveget kódol SMS kóddá. |
