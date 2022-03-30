# Koktél

**⚠️ Láncolt listás feladat! ⚠️**

Írjon C++ programot az alábbi feladatokra! A program indulásakor jelezze ki, hogy mit csinál! Az input adatok bekérését és az eredmények közlését lássa el tájékoztató szövegekkel!

## Feladat

Írjon programot, amely koktél összetevőit kezeli láncolt lista adatszerkezetben. Az összetevők lehetnek az angol ábécé betűiből álló szavak (pl. `Tej`) vagy 2-9-ig számok, rögtön ezután pedig a szó (pl. `8Tej`). A szám jelentse azt, hogy hányszoros részét önti az összetevőnek a koktélba. Feltételezheti, hogy a felhasználó helyesen adja meg az adatokat.  Minden beolvasás után írja ki a koktél százalékos összetételét. A programból kilépni a `kesz` szó megadásával lehet.

## Példa

```
Kerem az osszetevot: Narancsle
  >> 100% Narancsle
Kerem az osszetevot: Vodka
  >> 50% Narancsle, 50% Vodka
Kerem az osszetevot: Narancsle
  >> 66.6% Narancsle, 33.3% Vodka 
Kerem az osszetevot: 2Jeg
  >> 40% Narancsle, 20% Vodka, 40% Jeg
Kerem az osszetevot: 3Vodka
  >> 25% Narancsle, 50% Vodka, 25% Jeg
```

## Értékelés 

Az alapfeladat megoldása 2 pont. Plusz, illetve mínusz pont adandó a következőkért:
| Pont | Megjegyzés |
|------|------------|
| -1 | Ha a program fordítása során egyetlen, szabvány fejfájlok be nem kapcsolásából (`#include`) adódó, figyelmeztető üzenet is akad. |
|-1 | Ha a programból történő kilépés előtt a lefoglalt memóriaterületeket nem szabadítja fel, az esetlegesen megnyitott fájl(oka)t nem zárja le. |
|-1, -2 |	Ha az alapprogram működése bármiben is eltér a feladatban megfogalmazottól. |
|+1 |	Olvassa be a kezdő listát egy koktel.txt nevű állományból. |
|+1 |	Minden sikeres rekordbeolvasás után, valamint a program indulásakor írja ki a legnagyobb százalékos és a legkisebb százalékos arányú összetevőt. Jelezze ki azt is, ha ezekből több van. |
|+1 |	Inputellenőrzésként csak olyan összetevőket fogadjon el, ami angol ábécé betűiből álló szó illetve opcionálisan 2-9-ig számok alkotnak. A szám csak a szó elején lehet. |

