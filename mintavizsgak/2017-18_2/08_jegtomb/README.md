# Jégtömb

## Feladat

Írjon programot, amely egy jégtömb olvadását írja le, `5x5`-ös mátrixban. A kettőskereszttel jelölt pontok (ld. alábbi ábra) jelölik a jégtömbbe tartozó pozíciókat. Először sorról-sorra olvassa be a jégtömb alakját! Soronként 2 számot kell megadni, ahol az első szám a soron belüli, összefüggően jeges terület kezdő indexét, a második pedig a végének indexét jelenti. A `00` jelentse az üres sort. Az inputot nem kell ellenőriznie. Ha a jégtömbre meleg levegőt fújunk, akkor a szélén olvadni kezd, és a keletkezett víz elfolyik.

_Az olvadás szabálya_: egy időegység alatt abban a mezőben levő jég olvad el (tűnik el a táblázatból), amelynek 4 lehetséges oldal-szomszédja (bal, jobb, fent, lent) közül csak 1 szomszédja van. A 2. időegységben csak az eredeti mátrix szerinti 2 szomszédú tűnik el, és így tovább. Jelezze ki 5 időegységig a beolvasott alakú jégtömb olvadását, eddigre a teljes jégtömbnek el kell tűnnie!

## Példa

**TODO**: Valamilyen formában kerüljön ide a táblázat

## Értékelés

Az alapfeladat megoldása **2 pont**. Plusz, illetve mínusz pont adandó a következőkért (a teljesített pluszpont bekarikázandó):

| Pont   | Megjegyzés                                                                                                                                                                                                                     |
| ------ | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| -1     | Ha a program fordítása során egyetlen, szabvány fejfájlok be nem kapcsolásából (`#include`) adódó, figyelmeztető üzenet is akad.                                                                                               |
| -1     | Ha a programból történő kilépés előtt a lefoglalt memóriaterületeket nem szabadítja fel, az esetlegesen megnyitott fájl(oka)t nem zárja le.                                                                                    |
| -1, -2 | Ha az alapprogram működése bármiben is eltér a feladatban megfogalmazottól.                                                                                                                                                    |
| +1     | `TXT` parancssori paraméterrel indítva a programot ne a bemenetről, hanem egy `jeg.txt` állományból olvassa be a mátrixot. Ebben a jégtömbbe tartozó pozíciókat `1`, a többit `0` jelöli. Validálja a `.txt` fájl helyességét! |
| +1     | Módosítsa úgy a programot, hogy az elején a felhasználó határozhassa meg a mátrix méretét! A szélesség és hosszúság a `[3, 9]` intervallumba kell, hogy essen.                                                                 |
| +1     | Inputellenőrzésként csak olyan bemenetet fogadjon el, ami csak számokból áll, és azok is csak valid értékek lehessenek.                                                                                                        |
