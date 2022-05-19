# Szógyakoriság

Készítsen C++ programot, ami egy tetszőleges hosszúságú szöveget olvas be a szabvány bemenetről!

## Feladat

Az adatbevitel végét a `[vege]` szó megadása jelzi (ez utóbbi nem számít a szöveg részének). A szavakat tetszőleges számú fehér karakter választja el egymástól. A beolvasást követően készítsen sávdiagramot, ami legfeljebb **10**, a szövegben leggyakrabban előforduló szó előfordulási gyakoriságának megfelelő szélességű sávokat rajzol `*` karakterekből. A sávoknak egymás alatt kell elhelyezkednie, a szavak előfordulási gyakorisága szerinti csökkenő sorrendben. A legszélesebb sáv **20** karakterből álljon, a többi legyen arányosan rövidebb! Minden sáv mögött írja ki a szót, annak előfordulási darabszámát és előfordulásának százalékos arányát is!

## Példa

```
Szogyakorisagi statisztika. Adja meg a szoveget!
a aa aaa a aa aaa a aa aaa a aa aaa b bb bbb b bb bbb b bb bbb c cc ccc c cc ccc d dd ddd [vege]
******************** a 4 13.333333%
******************** aa 4 13.333333%
******************** aaa 4 13.333333%
***************      b 3 10.000000%
***************      bb 3 10.000000%
***************      bbb 3 10.000000%
**********           c 2 6.666667%
**********           cc 2 6.666667%
**********           ccc 2 6.666667%
*****                d 1 3.333333%
```

## Értékelés

Az alapfeladat megoldása 2 pont(=jegy). Plusz, illetve mínusz pont adandó a következőkért:
| Pont | Megjegyzés |
|------|------------|
| –1 | Ha a program fordítása során egyetlen, szabvány fejfájlok be nem kapcsolásából (`#include`) adódó, figyelmeztető üzenet is akad. |
| –1 | Ha a program memóriakezelése hibás. Pl. nincs felszabadítva a lefoglalt terület, vagy túlcímzés történik. |
| –1, –2 | Ha az alapprogram működése bármiben is eltér a feladatban megfogalmazottól. |
| +1 | Amennyiben a programnak parancssori paramétereket adnak meg, ezeket szöveges fájlok neveinek tekinti, és minden egyes fájl tartalmával kapcsolatban elvégzi a statisztikai számításokat, megjeleníti az eredményt! |
| +1 | Ha megjeleníti a szövegben előforduló összes betű számát (fehér karakterek nélkül), az összes szó és az összes bekezdés számát is! |
| +1 | Ha megjeleníti a mondatok számát is! Ha a szöveg tartalmaz akár csak egyetlen betűt is, a mondatok száma legalább 1. Egyébként a mondatokat szó végi írásjelek (`.!?`) választják el egymástól. A szó végi `.` nem számít a mondat végének, ha a következő szó első betűje kisbetű (rövidítések). Az utolsó mondat végén hiányozhat az írásjel. |
