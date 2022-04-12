# Futóverseny

Készítsen programot, ami egy futóverseny időmérési adatai alapján kiszámolja és megjeleníti a végeredményt!

## Feladat

Minden futónak van egy egyedi rajtszáma. 5 ellenőrzési pont van, ahol rögzítik a futók beérkezési idejét, valamint a start, ahol az indulási időt rögzítik, ami a sok induló miatt nem mindenkinél azonos.

A mért adatokat egy fájlba egyesítik, amely soronként egy mérést tartalmaz: rajtszám (egész szám), ellenőrző pont sorszáma (a start 0, a cél 5), óra, perc, másodperc. Az idő mindig érvényes értékeket tartalmaz 24 órás formátumban, és feltételezhető, hogy egyetlen naptári nap alatt lezajlik a verseny.
A program olvassa be az időmérések adatait az `idomeres.txt` fájlból, és írja ki a versenyzők rajtszámát és időeredményét, utóbbi szerint csökkenő sorrendben. A fájl első sorában meg van adva a versenyzők száma.

Előfordulhat, hogy nem minden versenyző ér célba, ők a lista végén jelenjenek meg, az idejük helyett `DNF` szöveggel. Az is előfordulhat, hogy egy versenyző kihagy egy ellenőrzési pontot, ekkor diszkvalifikálják. Az ilyen versenyzők ne jelenjenek meg az eredménylistában.

_Megjegyzés: a valóságban az is előfordulhat, hogy rossz sorrendben érintik az ell. pontokat, de ezt ott helyben ellenőrzik, ezért a programban ezzel nem kell foglalkozni._

## Példa

```
idomeres.txt tartalma:
4
123 0 09 11 37
888 1 09 53 41
123 1 09 56 32
420 0 09 10 13
888 0 09 30 51
123 2 10 06 40
123 3 10 36 53
888 4 10 51 03
123 4 10 58 52
774 0 09 36 04
888 3 10 11 17
888 5 11 25 40
123 5 11 14 11
774 1 10 21 10
420 1 10 36 14
888 2 09 57 31
420 5 11 35 12
Kimenet:
888 1:54:49
123 2:02:34
774 DNF
```

## Értékelés

Az alapfeladat megoldása **2 pont**. Plusz, illetve mínusz pont adandó a következőkért:
| Pont | Megjegyzés |
|----------|----------------------------------------------------------------------------------------------------------------------------------|
| -1 | Ha a hibás lépéseket nem kezeli a program az előírtnak megfelelően. |
| -1 | Ha a program fordítása során egyetlen, szabvány fejfájlok be nem kapcsolásából (`#include`) adódó, figyelmeztető üzenet is akad. |
| –1, –2 | Ha az alapprogram működése bármiben is eltér a feladatban megfogalmazottól. |
| +1 | Módosítsa a programot úgy, hogy diszkvalifikálás helyett hiányzó ellenőrzőpontonként 20 perc időt adjon hozzá az eredményhez. |
| +1 | Egészítse ki a programot a versenyzők neveinek beolvasásával, ezek egy `futoknevei.txt` fájlban találhatók: soronként egy rajtszám és egy (akár szóközöket is tartalmazó) név. Az eredmény kiírásakor a név is jelenjen meg. |
| +1 | Amennyiben a programot a `reszletes` parancssori paraméterrel indítják, ne csak a teljes futott időt írja ki, hanem oszloponként minden ellenőrzőpontra a részidőt (az indulástól mérve). |
