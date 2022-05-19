# Rajzolóprogram

Készítsen egyszerű rajzolóprogramot!

## Feladat

A vászon legyen egy `10x10` karakter méretű terület a képernyőn, ami kezdetben háttérszínű mezőkből áll. Jelöljön minden ilyen mezőt egy `.` karakter! A ceruza hegye kezdetben a bal felső sarokban található, `0,0` koordinátájú (oszlop, sor; a koordináták lefelé és jobbra egyesével nőnek) mező felett lebeg. Ha a ceruza fel van emelve (így nem tud rajzolni), akkor jelenítse meg a helyét a vásznon egy `F` betűvel, leengedett esetben pedig egy `L`-lel! A vászonra rajzolni különféle parancsok megadásával tud.

A ceruzát felemelni a `FELEMEL`, leengedni a `LEENGED` paranccsal lehet. A leengedés helyét a ceruza rögtön írásszínűre színezi, amit jelöljön `X`-szel a vásznon! A ceruzát mozgatni a `BALRA`, `JOBBRA`, `FEL`, `LE` parancsokkal lehet. Minden ilyen parancs után egy pozitív egész számot is meg kell adni, ami a kiválasztott irány menti elmozdulás mértékét adja meg. Ha a ceruza le van engedve, akkor elmozdulás közben vonalat húz a vásznon. Ügyeljen rá, hogy a ceruza mindenképp a vásznon maradjon! Minden változás után meg kell jeleníteni a vászon aktuális állapotát. A programból kilépni a `VEGE` parancs megadásával lehet.

Amennyiben a programot pontosan egy parancssori paraméter megadásával indították, írja ki az adott nevű szöveges fájlba a vászon tartalmát!

## Példa

Bemutatjuk a vászon állapotát a `JOBBRA 4 LEENGED LE 20 FELEMEL BALRA 20 FEL 5 LEENGED JOBBRA 10` parancsok kiadása után.

```
....X.....
....X.....
....X.....
....X.....
XXXXXXXXXL
....X.....
....X.....
....X.....
....X.....
....X.....
```

## Értékelés

Az alapfeladat megoldása **2 pont**. Plusz, illetve mínusz pont adandó a következőkért:

| Pont | Megjegyzés |
|----------|----------------------------------------------------------------------------------------------------------------------------------|
| -1 | Ha a program fordítása során egyetlen, szabvány fejfájlok be nem kapcsolásából (`#include`) adódó, figyelmeztető üzenet is akad. |
| –1, –2 | Ha az alapprogram működése bármiben is eltér a feladatban megfogalmazottól. |
| +1 | Ha a program a `KITOLT` parancs hatására elvégzi annak a zárt alakzatnak a kitöltését, aminek a belsejében a ceruza áll. A kitöltés hatására a ceruza nem mozdul el a helyéről. Kitöltés közben egy mezőt akkor lehet írásszínűre változtatni, ha háttérszínű, és ebben az esetben minden háttérszínű szomszédjára is el kell végezni a kitöltést. |
| +1 | Ha a program a `TOROL` parancs hatására háttérszínű, a `NEGYZET` hatására írásszínű téglalapokat hoz létre a vásznon, de közben a ceruza állapota nem változik meg. Ezeket a parancsokat mindig **4 nemnegatív egész** követi, szóközökkel elválasztva: a téglalap bal felső sarkának oszlopa, sora, a téglalap szélessége, magassága. |
| +1 | Ha a vászon futás közben átméretezhető a `MERETEZ` paranccsal, melyet az új szélesség és magasság követ. A méreteknek benne kell lenniük az `[5, 20]` intervallumban, különben az egész átméretezést hagyja figyelmen kívül. A bal felső sarok koordinátája továbbra is `0,0` marad, csak a rajzterület szélessége és magassága változhat futásidőben a parancs hatására. Ha a vászon valamelyik irányban nő, ott mindig háttérszínű mezők jelennek meg, a levágott területek információtartalma pedig elvész. |
