# Leltározó

Írjon programot, ami egy vendéglátóegység leltározását valósítja meg parancssoros szerkesztéssel!

## Feladat

Tárolja el a láncolt listában a leltári tételek adatait: tétel, mennyiség! (Nem fogadjuk el az STL tárolók használatát.)
A felhasználó egy parancssoros menüből tudjon funkciót választani a menüpont számának megadásával:

1. Kilépés
2. Tétel hozzáadása: Kérje be a tétel adatait!
3. Törlés: A sorszám alapján, kérje be a törlendő tétel sorszámát, és törölje ki a listából!
4. Tétel módosítása: A sorszám alapján kérje be a módosítandó tétel sorszámát, majd, hogy mennyire módosítaná a mennyiséget!

## Példa

```
Leltarozo
   A leltar ures.

   Valasszon menupontot:
   1: Kilepes     2: Hozzaadas
   3: Torles      4: Modositas
>> Muvelet: 2
>> Tetel: Sajt
>> Darab: 12

   1 - Sajt (12 db)

   Valasszon menupontot:
   1: Kilepes     2: Hozzaadas
   3: Torles      4: Modositas
>> Muvelet: 2
>> Tetel: Soproni
>> Darab: 256
[...]

   1 - Sajt (12 db)
   2 - Soproni (256 db)
   3 - Asvanyviz (1 db)
   Valasszon menupontot:
   1: Kilepes     2: Hozzaadas
   3: Torles      4: Modositas
>> Muvelet: 3
>> Melyik tetelt torli: 1
   1 - Soproni (256 db)
   2 - Asvanyviz (1 db)
   Valasszon menupontot:
   1: Kilepes     2: Hozzaadas
   3: Torles      4: Modositas
>> Muvelet: 4
>> Melyik tetelt modoitsam: 1
>> Mennyire: 512
   1 - Soproni (512 db)
   2 - Asvanyviz (1 db)
   1: Kilepes     2: Hozzaadas
   3: Torles      4: Modositas
>> Muvelet: 1
   Viszlat!
```

## Értékelés

Az alapfeladat megoldása 2 pont. Plusz, illetve mínusz pont adandó a következőkért:
| Pont | Megjegyzés |
|------|------------|
| -1 | Ha a program fordítása során egyetlen, szabvány fejfájlok be nem kapcsolásából (`#include`) adódó, figyelmeztető üzenet is akad. |
| -1 | Ha a programból történő kilépés előtt a lefoglalt memóriaterületeket nem szabadítja fel, az esetlegesen megnyitott fájl(oka)t nem zárja le. |
| -1, -2 | Ha az alapprogram működése bármiben is eltér a feladatban megfogalmazottól. |
| +1 | Kilépés előtt automatikusan írja ki a lista tartalmát egy `leltar.txt` nevű állományba, amit a következő programindításnál beolvas! A fájl tetszőleges formátumú lehet, pl. tárolható az tétel és a darabszám külön vagy akár azonos sorban is. |
| +1 | Ha a lista tételei ábécésorrendbe rendezve követik egymást. |
| +1 | Inputellenőrzésként csak olyan tételeket fogadjon el, ami az angol ábécé betűiből áll. Továbbá a menüpontokat is validálja (csak létező menüpontot lehessen választani) és a darabszámot (pozitivitás ellenőrzése) is! |
