# Jelszógenerátor

Írjon jelszókészítő programot! 

## Feladat

A jelszót véletlenszám generátorral állítsa elő, melybe csak az angol ábécé kis- és nagybetűi, valamint számjegyek kerülhetnek! Ügyeljen rá, hogy ugyanaz a karakter ne fordulhasson elő benne kétszer! A jelszó hosszát (ami legalább 5, legfeljebb 20 karakter lehet), valamint azt, hogy hány darabot állítson elő, kérje be a felhasználótól! 

Amikor elkészült egy-egy jelszóval, jelenítse meg azt a szabvány kimeneten, majd olvasson be egy másik jelszót a felhasználótól! Állapítsa meg, hogy a két jelszó egyforma hosszú-e, vagy valamelyik hosszabb a másiknál! Amennyiben a hosszuk egyforma, írjon ki egy olyan karakterláncot, ami `*` karaktert tartalmaz minden olyan pozíción, ahol a két jelszó karakterei eltérnek egymástól, egyébként az egyező karaktert jelenítse meg! 

## Példa

```
Jelszogeneralo program. 
Hany karakterbol alljon a jelszo? 5 
Hany darab jelszot generaljak? 2
A(z) 1. generalt jelszo: ER4T5
Adjon meg egy masik jelszot: WE45Z
A ket jelszo hossza megegyezik, megegyezo karakterek: **4**
A(z) 2. generalt jelszo: wZ5eR
```

## Értékelés

Az alapfeladat megoldása 2 pont. Plusz, illetve mínusz pont adandó a következőkért:
| Pont | Megjegyzés |
|------|------------|
| -1 | Ha a hibás lépéseket nem kezeli a program az előírtnak megfelelően. |
| -1 | Ha a program fordítása során egyetlen, szabvány fejfájlok be nem kapcsolásából (`#include`) adódó, figyelmeztető üzenet is akad. |
| -1, -2 | Ha az alapprogram működése bármiben is eltér a feladatban megfogalmazottól. |
| +1 | Ha a generált és a felhasználó által bevitt jelszavakban a kis- és nagybetűk között nem tesz különbséget! |
| +1 | Ha a generált jelszavakat minden generálás után elmenti a `generalt.txt` fájlba, aminek a végén elhelyez még egy statisztikát is a generált jelszavakban használt karakterek előfordulási gyakoriságáról, előfordulás száma szerint csökkenő sorrendben! |
| +1 | Egészítse ki a programot úgy, hogy bekér a felhasználótól legalább 3 szót, és csak az ezekben szereplő karakterek segítségével állít elő jelszavakat! Ha a szavakban szereplő különböző jelek száma kevesebb, mint a jelszavak hossza, kérjen további szavakat! |