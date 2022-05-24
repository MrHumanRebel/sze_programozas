# Plágiumellenőrző

A feladat egyszerű plágium-ellenőrző program elkészítése.

## Feladat

A program a fejlécének megjelenítését követően olvassa be egy tudós nevét (szóközöket tartalmazhat), az általa készített „tudományos művet” (tetszőleges tartalmú szövegsor), végül a mű publikálásának dátumát `ÉÉÉÉ-HH-NN` formátumban! Ismételje a név-mű-dátum beolvasásokat üres sor megadásáig, majd állapítsa meg, mely tudósok követtek el plágiumot! Nem kell **25**-nél több adat-hármas tárolására felkészülni.

Egy tudományos műben plagizáltak, ha legalább egyszer előfordul olyan, hogy egy másik, korábban publikált mű azonos sorszámú karaktere megegyezik vele, pl. `abc` és `xxc` tudományos művekben egymástól loptak, hiszen a harmadik karakter mindkét esetben `c`.

## Példa

```
Egyszeru plagiumellenorzo szoftver; kilepes ures sor megadasaval.
Tudos neve: Kis-Nagyhazik Geza
Mu: aaabbbccc
Datum: 2001-02-08
Tudos neve: Nagysandorfa Otto
Mu: ppppppppppppppppppppppp
Datum: 2019-05-01
Tudos neve: Kisfalvai Katalin
Mu: aadzz
Datum: 1982-11-03
Tudos neve: Kalmanfalvai Bela
Mu: ccayyyyyyyyyyyyyyyy
Datum: 1998-07-23
--- Ures sort adtak meg, beolvasas vege. ---
Kis-Nagyhazik Geza – csalt (lopott tole: Kisfalvai Katalin, Kalmanfalvai Bela)
Nagysandorfa Otto – becsuletes, nem csalt
Kisfalvai Katalin – becsuletes, nem csalt
Kalmanfalvai Bela - becsuletes, nem csalt
```

## Értékelés

Az alapfeladat megoldása 2 pont. Plusz illetve mínusz pont adandó a következőkért:
| Pont | Megjegyzés |
|------|------------|
| –1 | Ha a program fordítása során egyetlen, szabvány fejfájlok be nem kapcsolásából (`#include`) adódó, figyelmeztető üzenet is akad. |
| –1, –2 | Ha az alapprogram működése bármiben is eltér a feladatban megfogalmazottól. |
| +1 | Ha a tudósokat és műveiket dinamikus adatszerkezetben tárolja el. (Az STL tárolók használatát nem fogadjuk el.) |
| –1 | Ha a dinamikusan lefoglalt memóriaterületeket kilépés előtt nem szabadítja fel a program. |
| +1 | Ha a program első parancssori paramétereként megadható, hogy hány százalék plágium felett lehet szemet hunyni, és az ilyen művek szerzőit is becsületesnek minősíti a program. |
| +1 | Ha a program nem fogadja el ugyanazt a nevet többször, valamint hibás név megadása esetén is ismételteti az adatbevitelt. Hibásnak tekintendő a név, ha a szavak kezdőbetűi nem nagybetűsek, a többi pedig nem kisbetű. Név csak az angol abc betűiből és szóközökből állhat. |
