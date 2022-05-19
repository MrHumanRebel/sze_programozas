# Receptek

Írjon programot, ami megállapítja, hogy az otthon található alapanyagokból egy-egy adott étel elkészíthető-e (azaz főzési lehetőségeket analizál).

## Feladat

A program először egy sorban írja ki, hogy mit csinál! Ezután olvasson be a szavakat, amelyek különféle étel-alapanyagok lehetnek. Ez a beolvasás addig történjen, amíg kettőskeresztet nem adott meg a felhasználó!

Ezután a felhasználónak egy étel nevét (pl. `sutemeny`, `padlizsanfozelek`, vagy bármi egyéb) kell megadnia, ami egyetlen szóból áll. Amennyiben itt a kettőskeresztet gépeli be, a program befejeződik. Az étel nevét szintén egyetlen szóból álló étel-alapanyagok követik (pl. `cukor`, `liszt`, `teszta`, `szarazbab`, vagy bármi egyéb), kettőskereszt végjelig. Ha az adott étel teljes alapanyag-szükséglete megadásra került, a következő sorban írja ki, hogy a megadott nevű étel elkészíthető-e vagy sem!

Minden ételnek tartalmaznia kell legalább egy alapanyagot!

## Példa

```
Fozesi lehetosegeket analizalo program.
Milyen alapanyagok allnak rendelkezesre? Befejezes #-tel.
liszt
paradicsom
so
cukor
teszta
szarazbab
#
Etel neve: sutemeny
Milyen alapanyagokra van szukseg? Befejezes #-tel.
cukor
liszt
#
A(z) sutemeny elkeszitheto.
Etel neve: padlizsanfozelek
Milyen alapanyagokra van szukseg? Befejezes #-tel.
padlizsan
csapviz
so
#
A(z) padlizsanfozelek nem keszitheto el.
Etel neve: husosteszta
Milyen alapanyagokra van szukseg? Befejezes #-tel.
paradicsom
teszta
so
hus
#
A(z) husosteszta nem keszitheto el.
Etel neve: #
Kilepes.
```

## Értékelés

Az alapfeladat megoldása 2 pont. Plusz, illetve mínusz pont adandó a következőkért:
| Pont | Megjegyzés |
|------|------------|
| –1 | Ha a program fordítása során egyetlen, szabvány fejfájlok be nem kapcsolásából (`#include`) adódó, figyelmeztető üzenet is akad. |
| –1, –2 | Ha az alapprogram működése bármiben is eltér a feladatban megfogalmazottól. |
| +1 | Ha a rendelkezésre álló alapanyagok tárolásához bináris keresőfát használ. |
| +1 | Ha nem lehet elkészíteni az ételt, akkor azt is sorolja fel, hogy milyen alapanyagok hiányoznak! A hiányzó alapanyagokat tárolja láncolt listában! |
| +1 | Az alapanyagok megadását követően ezeket mentse el az `alapanyagok.txt` fájlba! Minden további programfuttatás során ennek a fájlnak a tartalmával dolgozzon, és ne a felhasználótól kérje be a listát ismét! |
| –1 | Ha a dinamikusan lefoglalt memóriaterületeket kilépés előtt nem szabadítja fel a program. |
