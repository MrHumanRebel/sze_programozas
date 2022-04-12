# Tápanyagok

Készítsen programot, ami a napi étkezésekkel bevitt tápanyagokról készít statisztikát!

## Feladat

A program kérje be a felhasználótól az elfogyasztott ételek nevét és tömegét. A programban legyen eltárolva néhány étel tápanyag tartalma, azaz, hogy 100 g hány kcal energiát, illetve hány gramm fehérjét, szénhidrátot és zsírt tartalmaz. Ezen adatok az alábbi táblázatban találhatóak, a napi ajánlott bevitellel együtt:

| Név          | Energia (kcal/100g) | Fehérje (g/100g) | Szénhidrát (g/100g) | Zsír (g/100g) |
| ------------ | ------------------- | ---------------- | ------------------- | ------------- |
| Alma         | 30                  | 0                | 7                   | 0             |
| Burgonya     | 92                  | 2.5              | 20                  | 0.2           |
| Csirke       | 110                 | 25               | 0.5                 | 1             |
| Kenyér       | 250                 | 10               | 54                  | 1.4           |
| Sertés       | 300                 | 17               | 0.3                 | 24            |
| Tej          | 60                  | 3.4              | 5.3                 | 2.8           |
| Napi bevitel | 2000                | 90               | 270                 | 50            |

A program minden bevitt étkezés után jelenítse meg a bevitt tápanyagok összegét, és hogy hány százalékát teszik ki a napi ajánlott mennyiségnek. Az étel neve helyett `exit` beírásával tudjon kilépni a felhasználó.

## Példa

```
Adja meg az etel nevet!
Kenyer
Adja meg az adag tomeget grammban!
50
Bevitt tapanyagok:
Energia: 125 kcal (6.25%)
Feherje: 5 g (5.55556%)
Szenhidrat: 27 g (10%)
Zsir: 0.7 g (1.4%)
Adja meg az etel nevet!
Szalonna
Az etel nem talalhato!
Adja meg az etel nevet!
exit
```

## Értékelés

Az alapfeladat megoldása 2 pont(=jegy). Plusz, illetve mínusz pont adandó a következőkért:
| Pont | Megjegyzés |
|------|------------|
| –1 | Ha a program fordítása során egyetlen, szabvány fejfájlok be nem kapcsolásából (`#include`) adódó, figyelmeztető üzenet is akad. |
| –1 | Ha a program memóriakezelése hibás. Pl. nincs felszabadítva a lefoglalt terület, vagy túlcímzés történik. |
| –1, –2 | Ha az alapprogram működése bármiben is eltér a feladatban megfogalmazottól. |
| +1 | Módosítsa úgy a programot, hogy ha olyan nevű ételt ad meg a felhasználó, amit nem ismer a program, akkor kérje be a tápanyagok 100 grammonkénti mennyiségét, és tárolja el! Gondoskodjon róla, hogy tetszőleges számú étel adatait fel lehessen vinni! |
| +1 | A program induláskor a `tapanyagok.txt` fájlból olvassa be a tápanyag adatokat. A fájlban minden ételhez 2 sor tartozik, az 1. sor a név, ami szóközöket is tartalmazhat, a 2. sorban pedig szóközzel elválasztva szerepel a 4 tápanyag mennyiség. |
| +1 | Ha a hatékonyabb kereséshez bináris keresőfában tárolja az adatokat, az étel nevét kulcsként használva. |
