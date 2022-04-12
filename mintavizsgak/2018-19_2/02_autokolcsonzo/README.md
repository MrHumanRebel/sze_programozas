# Autókölcsönző

Írjon programot, ami egy autókölcsönzőben eldönti, hogy az adott ügyfél kiszolgálható-e az igényei alapján, továbbá, ha nem, akkor indokolja, hogy miért nem.

## Feladat

A rendelkezésre álló autók nevét és kölcsönzési feltételeit a mellékelt input.txt fájl tartalmazza. Az első oszlopban az autó neve áll (egyetlen szó, egyedi azonosító), ezt követi a minimálisan szükséges vezetői ügyesség (nemnegatív egész), végül a minimálisan szükséges pénzösszeg következik. Az oszlopokat szóközök választják el egymástól.

A program a fejlécének megjelenítését követően olvassa be a kölcsönözni kívánt autó nevét, a sofőr ügyességét, valamint a rendelkezésre álló pénzét! Ezután döntse el, hogy az ügyfél kiszolgálható-e. Ha igen, akkor írja ki a program a `Vigye az autot!` üzenetet. Ellenkező esetben indokolja, miért nem, és a megfelelő szöveget írja a képernyőre! Pl. `Nincs ilyen autonk.`, `Nincs eleg penze.`, `Nem eleg ugyes sofor.` Ezután még írja ki azt is, hogy `Nem szolgaljuk ki.`. Ha több oka is van az elutasításnak, írja ki az összes okot.

A programból kilépni az autó neve helyett megadott kettőskereszt karakterrel lehet.

## Példa

```
Autokolcsonzo program; kilepes # megadasaval.
Peugeot 52 5000
Nincs ilyen autonk. Nem szolgaljuk ki.
Trabant 14 100555
Nem eleg ugyes sofor. Nem szolgaljuk ki.
Opel 50 55000
Nincs eleg penze. Nem szolgaljuk ki.
Opel 40 50111
Nem eleg ugyes sofor. Nincs eleg penze. Nem szolgaljuk ki.
Opel 48 58000
Vigye az autot!
VW 42 500888
Vigye az autot!
Mercedes 99 430222
Nincs ilyen autonk. Nem szolgaljuk ki.
#
Kilepes.
```

## Értékelés

Az alapfeladat megoldása 2 pont. Plusz, illetve mínusz pont adandó a következőkért:
| Pont | Megjegyzés |
|------|------------|
| –1 | Ha a program fordítása során egyetlen, szabvány fejfájlok be nem kapcsolásából (`#include`) adódó, figyelmeztető üzenet is akad. |
| –1, –2 | Ha az alapprogram működése bármiben is eltér a feladatban megfogalmazottól. |
| –1 | Ha az `input.txt` fájlt minden egyes ügyfél esetén újra és újra beolvassa. |
| +1 | Ha az autó keresésénél bináris keresést alkalmaz. A tömböt foglalja le dinamikusan! |
| –1 | Ha a dinamikusan lefoglalt memóriaterületeket kilépés előtt nem szabadítja fel a program. |
| +1 | Ha a valamelyik ügyfél által igényelt, de eddig nem létező autó adatait bekéri, a memóriában eltárolja, és a legközelebbi kölcsönzési kísérletnél már ennek figyelembevételével dönt! A fájl tartalmát nem kell módosítani. |
| +1 | Ha az elutasításkor kiírandó több mondatot összefűzi egyetlen mondattá (az elején nagy kezdőbetű, a többi betű mind kicsi, a végén pont, a tagmondatok között vessző). |
