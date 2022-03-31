# Tördelés

## Feladat

Készítsen programot, ami a `[vege]` szó megadásáig folyamatosan olvas be fehér karakterekkel elválasztott szavakat! Miután ez megtörtént, tördelje be a szavakat egy 20 karakter széles helyre, balra igazítottan!

A tördelés során a szavak közé akkor is egy szóközt tegyen, ha eredetileg nem ez a karakter választotta el a szavakat, vagy egynél több is állt közöttük! Ha egy szó önmagában is hosszabb 20 karakternél, akkor tördelje azt szét legfeljebb 20 karakteres darabokra, és azokat helyezze el a sorokban! A szélességet (20 karakter) lehessen szimbolikus állandóval változtatni! Jelenítsen meg fejlécet a mintán látható módon, hogy a tördelés helyessége ellenőrizhető legyen!

## Példa

```
Szoveg tordelese
Ez itt egy nagyon hosszu szoveg, amit balra igazitva be kell tordelni a rendelkezesre allo, 20 karakter szeles helyre. [vege]
*12345678901234567890*
*Ez itt egy nagyon   *
*hosszu szoveg, amit *
*balra igazitva be   *
*kell tordelni a     *
*rendelkezesre allo, *
*20 karakter szeles  *
*helyre.             *
*12345678901234567890*
```

## Értékelés

Az alapfeladat megoldása 2 pont(=jegy). Plusz, illetve mínusz pont adandó a következőkért:
| Pont | Megjegyzés |
|------|------------|
| –1 | Ha a program fordítása során egyetlen, szabvány fejfájlok be nem kapcsolásából (`#include`) adódó, figyelmeztető üzenet is akad. |
| –1 | Ha a program memóriakezelése hibás. Pl. nincs felszabadítva a lefoglalt terület, vagy túlcímzés történik. |
| –1, –2 | Ha az alapprogram működése bármiben is eltér a feladatban megfogalmazottól. |
| +1 | Ha a program a parancssorban megadott egész értéknek megfelelő szélességre tudja tördelni a szöveget. |
| +1 | Ha a program megkérdezi, hogy a szöveget balra, középre vagy jobbra igazítva kívánjuk-e tördelni, és ennek megfelelően is végzi el a munkát. |
| +1 | Ha a bevitt szöveget sorkizártan is meg tudja jeleníteni (a szavakat elválasztó szóközök darabszámai közötti különbség nem lehet több egynél). |
