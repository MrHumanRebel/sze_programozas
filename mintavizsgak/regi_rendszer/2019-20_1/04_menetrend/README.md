# Menetrend

## Feladat

A `vonat.txt` fájl vasúti járatok menetrendjét tartalmazza. Az egyes járatok adatai a járat nevével kezdődnek, majd a rá következő szövegsorokban, egymástól tabulátorral elválasztva érkeznek a megállóhely neve, az oda megérkezés, és az onnan elindulás időpontjai. Az utolsó megálló után új sorban a `---` karaktersorozat áll elválasztóként. A járat indulási megállójánál az érkezés idejét, a végállomásnál a tovább indulás idejét nem lehet értelmezni, így ott 99:99 szerepel. A fájl végét az utolsó sorban álló vege jelzi.

Kérjen be a felhasználótól indulási- és célállomást, majd jelezze ki, hogy mikor és melyik járat indul az indulási állomásról, és az mikor érkezik meg a célállomásra (ilyenből lehet több is, vagy egy sem)! Ismételje mindezt addig, amíg a felhasználó nem jelzi kilépési szándékát az indulási megálló helyett megadott vege szóval! (Átszállási lehetőségekkel nem kell foglalkozni, csak közvetlen járatokkal.)

## Példa

```
Vonat menetrend
Indulas: Gyor
Erkezes: Budapest-Deli
4945_szemelyvonat 12:40 --> 14:39
Indulas: Budapest-Deli
Erkezes: Gyor
4910_szemelyvonat 04:30 --> 06:23
Indulas: vege
```

## Értékelés

Az alapfeladat megoldása 2 pont(=jegy). Plusz illetve mínusz pont adandó a következőkért:
| Pont | Megjegyzés |
|------|------------|
| –1 | Ha a program fordítása során egyetlen, szabvány fejfájlok be nem kapcsolásából (`#include`) adódó, figyelmeztető üzenet is akad. |
| –1 | Ha a program memóriakezelése hibás. Pl. nincs felszabadítva a lefoglalt terület, vagy túlcímzés történik. |
| –1, –2 | Ha az alapprogram működése bármiben is eltér a feladatban megfogalmazottól. |
| +1 | Ha a felhasználó az aktuális időt is megadhatja `óó:pp` formában, és a program ezután csak azokat a járatokat listázza, amikkel aznap még lehet utazni. |
| +1 | Ha egy-egy keresés eredményét a felhasználó kérésére ki tudja menteni a program a `menetrend.txt` fájlba is. |
| +1 | Ha egy megálló nevét parancssori paraméterként megadva a program kilistázza, hogy melyik járat mikor érkezik oda, ez a járat eredetileg honnan és mikor indult, valamint hová és mikor érkezik, majd végül kilép. |
