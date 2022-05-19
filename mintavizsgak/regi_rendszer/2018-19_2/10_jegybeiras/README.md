# Jegybeírás

Készítsen programot, ami a felhasználótól származó adatok és egy táblázat felhasználásával meghatározza, hogy az egyes oktatók mely kurzusok jegyei közül hányat felejtették el határidőre rögzíteni a Neptunban!

## Feladat

A táblázat tartalmazza, hogy melyik oktató milyen kódú tárgynak mely kurzusait oktatja, és fordítási időben (forráskódba gépelve) adott az alábbiak szerint:

| Tárgykód     | Kurzus | Oktató              |
| ------------ | ------ | ------------------- |
| GKNB_INTM021 | 1      | Hatwagner F. Miklos |
| GKNB_INTM021 | 2      | Horvath Erno        |
| GKNB_INTM022 | 1      | Kovacs Katalin      |
| GKNB_INTM041 | 1      | Hatwagner F. Miklos |
| GKNB_INTM041 | 2      | Fogarasi Gergo      |

A felhasználó egymás után megadja a tárgy kódját és kurzusát, amelyből elmaradt a jegybeírás, valamint az érintett hallgatók számát. Az adatbevitel végét a tárgykód helyett megadott vege szó jelzi. Nem kell 25-nél több tárgykód-kurzus-darabszám hármas megadására felkészülni. Ezután a programnak egy olyan listát kell készítenie, mely oktatónként kilistázza, milyen tárgy mely kurzusánál hány jegyet kellett volna összesen beírnia a kollégának.

## Példa

```
Jegybeiras elmaradasanak ellenorzese
Targykod: GKNB_INTM021
Kurzus: 1
Darabszam: 5
Targykod: GKNB_INTM021
Kurzus: 1
Darabszam: 10
Targykod: GKNB_INTM022
Kurzus: 1
Darabszam: 3
Targykod: GKNB_INTM041
Kurzus: 1
Darabszam: 10
Targykod: GKNB_INTM063
Kurzus: 3
Darabszam: 1
Ismeretlen targykod vagy kurzus!
Targykod: vege
Hatwagner F. Miklos elmaradt jegybeirasai
Targykod 			Kurzus	Darabszam
GKNB_INTM021 	1		15
GKNB_INTM041 	1		10
Kovacs Katalin elmaradt jegybeirasai
Targykod 			Kurzus	Darabszam
GKNB_INTM022 	1		3
```

## Értékelés

Az alapfeladat megoldása 2 pont(=jegy). Plusz, illetve mínusz pont adandó a következőkért:
| Pont | Megjegyzés |
|------|------------|
| –1 | Ha a program fordítása során egyetlen, szabvány fejfájlok be nem kapcsolásából (`#include`) adódó, figyelmeztető üzenet is akad. |
| –1 | Ha a program memóriakezelése hibás. Pl. nincs felszabadítva a lefoglalt terület, vagy túlcímzés történik. |
| –1, –2 | Ha az alapprogram működése bármiben is eltér a feladatban megfogalmazottól. |
| +1 | Ha a táblázatnak dinamikus tömbben foglal helyet, amiben bináris kereséssel találja meg az oktatót. |
| +1 | Ha ismeretlen tárgykód és/vagy kurzus megadása esetén megkérdezi az oktató nevét, és beilleszti azt a táblázatba, később pedig már ezt felhasználva dolgozik. |
| +1 | Ha a programból történő kilépés előtt a tetszőleges szerkezetű tablazat.txt fájlba menti a táblázat tartalmát, valamint a program indulásakor, ha van ilyen fájl, akkor ennek tartalmát tölti be. |
