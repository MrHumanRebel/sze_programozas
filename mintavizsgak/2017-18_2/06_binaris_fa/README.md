# Bináris fa

Készítsen egy olyan C/C++ programot, amely a szabványos bemenetről érkező szöveget dolgozza fel! 

## Feladat
A program a következőképpen dolgozza fel a szöveget: a szöveget szavakra bontja, és a szavakat bináris fában tárolja. A bináris fa csúcsai a szükséges mutatók mellett a beolvasott szavakat tárolják, mindegyiket pontosan egyszer. A fa **maximum** 15 karakteres szavakat tárolhat. A fehér karakterekkel elválasztott szavak karakterei közül csak az angol ABC betűit őrizze meg, a többit törölje ki! Ha egy szó még így is hosszabb 15 karakternél, akkor minden további karaktert **hagyjon figyelmen kívül**! Miután beolvasta a szöveget, írja ki a szavakat a képernyőre ABC sorrendben, feltüntetve a szavak hosszát is!

## Értékelés
Az alapfeladat megoldása **2 pont**. Plusz, illetve mínusz pont adandó a következőkért:

| Pont | Megjegyzés |
|----------|----------------------------------------------------------------------------------------------------------------------------------|
| -1 | Ha a program fordítása során egyetlen, szabvány fejfájlok be nem kapcsolásából (`#include`) adódó, figyelmeztető üzenet is akad. |
| –1, –2 | Ha az alapprogram működése bármiben is eltér a feladatban megfogalmazottól. |
| +1 | Ha a parancssori paraméterként kapott nevű fájlba is kiírja a képernyőn megjelenő adatokat. |
| +1 | Egészítse ki azzal a programot, hogy a szavakon túl, azok előfordulásának számát is tárolja és kijelzi. |
| +1 | Ha kiegészíti a programot úgy, hogy a bináris fában tárolt szavakat megjelöli csillaggal, ha visszafelé olvasva is ugyanazt kapjuk (pl. erre, arra, soros, rotor). |