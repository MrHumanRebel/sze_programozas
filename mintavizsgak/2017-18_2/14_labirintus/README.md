# Labirintus

Készítsen egyszerű labirintus játékot, melyben a játékosnak az akadályokat kerülgetve el kell jutnia a célig! 

## Feladat

A labirintus 5x5 méretű, melyet a `palya.txt` fájl tartalmaz. Ebben az akadályokat `X` betű jelöli, a `.`–tal jelzett helyekre léphet a játékos. A játékos a **bal alsó** sarokból indul, és a játéknak akkor van vége, ha eljutott a **jobb felsőbe**.

Töltse be a pályát, majd jelölje be rajta a játékos helyzetét egy `O` betűvel! Ezután olvassa be a játékos lépését, ami az `f`, `l`, `j` és `b` betűk egyike lehet (minden egyéb jelet hagyjon figyelmen kívül). A betűk az elmozdulás irányát adják meg (fel, le, jobbra, balra). Az akadályokra rá-, illetve a pályáról lelépni értelemszerűen nem lehet, az erre irányuló felhasználói kéréseket hagyja figyelmen kívül! 

Minden lépés megtétele után rajzolja ki újra az egész pályát a képernyőre!

## Példa

```
Labirintus
...X.
.X.X.
.X...
.X..X
O...X
Merre lep? F
...X.
.X.X.
.X...
OX..X
....X

```

## Értékelés

Az alapfeladat megoldása 2 pont. Plusz, illetve mínusz pont adandó a következőkért:
| Pont | Megjegyzés |
|------|------------|
| -1 | Ha a hibás lépéseket nem kezeli a program az előírtnak megfelelően. |
| -1 | Ha a program fordítása során egyetlen, szabvány fejfájlok be nem kapcsolásából (`#include`) adódó, figyelmeztető üzenet is akad. |
| -1, -2 | Ha az alapprogram működése bármiben is eltér a feladatban megfogalmazottól. |
| +1 | Ha a felhasználó több betűből álló mozgásparancsokat is kiadhat, pl. `ffjb`, melyeket egymás után végrehajt a program (amennyiben ennek részletei önmagukban értelmesek), majd csak a végeredményként adódó helyen jeleníti meg a játékost a pályán (tehát közbenső állapotokat nem rajzol). |
| +1 | Ha az `r` betűt is elfogadja mozgásparancsnak, melynek hatására a másik négy irány közül a program véletlenszerűen választ egyet. Arra azonban ügyelnie kell, hogy ha ez egyáltalán lehetséges, akkor mozduljon is el a játékos a pályán, azaz a mozgásparancs végrehajtható legyen (pl. ne menjen falnak). |
| +1 | Ha a betöltött pályát felhasználás előtt a felhasználó át is szerkesztheti. (ld. példa) |

### Szerkesztési funkció

`I M S O H`

Ahol `I` az irány, ami lehet `v`, azaz vízszintes, vagy `f`, azaz függőleges. `M` a módot adja meg, ami lehet `r`, mint rajzolás és `t`, mint törlés. Az `S` a pálya sorának, az `O` a pálya oszlopának indexe (a bal felső sarok a 0, 0 koordinátájú hely). A `H` a hosszt adja meg. 

Pl. ha a pálya kezdeti állapota ez:
```
...X.
.X.X.
.X...
.X..X
....X
```

Akkor a `v r 0 0 3` hatására a pályára új akadályt rajzolunk, és az most így fest:
```
XXXX.
.X.X.
.X...
.X..X
....X
```
	
Minden rajzolási parancs kiadása után rajzolja ki a teljes pályát! A pályaszerkesztést befejezni a `kesz` parancs kiadásával lehet.