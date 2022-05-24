# Neptun

Készítsen tantárgyi adminisztrációt segítő programot!

## Feladat

Minden hallgatóról nyilván kell tartani egy struktúrában a nevét, neptun kódját, első és második ZH-jának pontszámát, valamint az első és a második javító ZH-n elért eredményét. A ZH-kon `[0, 7]` pontot lehet gyűjteni. Az eredeti és a neki megfelelő javító ZH közül a jobb eredmény számít. Ha valaki nem írja meg valamelyik ZH-t, azt jelöljük 0 pontosként! Aki legalább 7 pontot összegyűjt a két ZH-ból, az aláírást szerez, aki 11-12 pontot gyűjt, az 4-es, aki 13-14 pontot, az 5-ös megajánlott jegyet kap.

Az adatokat (név, neptun, 1. ZH, 1. ZH javítása, 2. ZH, 2. ZH javítása) egymás után kell megadni. Az adatbevitel végét a hallgató neve helyett megadott – karakter jelzi. Feltételezheti, hogy a felhasználó helyes adatokat ad meg, és nem kell **25**-nél több hallgató kezelésére felkészülni.

Végül jelezze ki táblázatosan a hallgatók adatait név szerint abc-sorrendbe rendezve, melyből kiderül, szereztek-e aláírást / megajánlott jegyet.

## Példa

```
Adminisztrácios program
Hallgato neve: Nagy Istvan
Neptun kodja: A1B2C3
1. ZH pontszam: 3
1. javito ZH pontszam: 2
2. ZH pontszam: 5
2. javito ZH pontszam: 0
Hallgato neve: Kiss Milan
Neptun kodja: ABCDEF
1. ZH pontszam: 7
1. javito ZH pontszam: 0
2. ZH pontszam: 5
2. javito ZH pontszam: 6
Hallgato neve: -
Eredmenyek:
Nev            Neptun 1.ZH 1.jav 2.ZH 2.jav Alairas Megajanlott
Kiss Milan     ABCDEF 7    0     5    6     igen    5
Nagy Istvan    A1B2C3 3    2     5    0     igen    -
```

## Értékelés

Az alapfeladat megoldása 2 pont. Plusz, illetve mínusz pont adandó a következőkért:
| Pont | Megjegyzés |
|------|------------|
| –1 | Ha a program fordítása során egyetlen, szabvány fejfájlok be nem kapcsolásából (`#include`) adódó, figyelmeztető üzenet is akad. |
| –1, –2 | Ha az alapprogram működése bármiben is eltér a feladatban megfogalmazottól. |
| +1 | Ha a név helyett a `gen` szót adják meg, akkor generálja véletlenszerűen a hallgató összes adatát! A név egy vezetéknévből és egy keresztnévből áll. A lehetséges vezetéknevek, melyek közül választhat a gép véletlenszerűen: `Kiss`, `Nagy`, `Kovacs`, `Toth`, `Takacs`. A keresztnevek listája: `Andrea`, `Bela`, `Csaba`, `Daniella`, `Elemer`. |
| +1 | Ellenőrizze a megadott Neptun kódokat! Ha a Neptun kód nem pontosan 6 karakterből álló, csak az angol abc kis- és nagybetűit, valamint számjegyeket tartalmazó karakterlánc, kérjen helyette újat! |
| +1 | Ha a program futtatásakor megadtak pontosan egy parancssori paramétert, akkor az eredménylistát a paraméterként adott nevű fájlba is mentse ki! |
