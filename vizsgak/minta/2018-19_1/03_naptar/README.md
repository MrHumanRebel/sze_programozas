# Szabadság nyilvántartó program

Készítsen szabadság nyilvántartó programot a 2019-es évre!

## Feladat

A program kérjen be zárt dátum intervallumokat (hónap, nap megadásával, a határok is beleesnek az intervallumba)! Változtassa a szabadságok állapotát ellenkezőjére a megadott intervallumban! (Ha eddig dolgoztak, akkor állítsa szabadságra, ha szabadságnak volt nyilvántartva, akkor pedig ledolgozott napra.)

A program indulásakor az év minden napja ledolgozott napként szerepel. Minden intervallum bevitele után jelenítse meg az egyes napok állapotát a következőképpen: a képernyő egymás alatti soraiban az egyes hónapokhoz tartozó napok állapotát kell megjeleníteni. Amelyik nap ledolgozottnak van beállítva, ott jelenjen meg – karakter, amelyik szabadságnak lett jelölve, ott `S` betű! Ismételje az intervallumok beolvasását mindaddig, amíg nem lesz pontosan **40** nap szabadság kiadva!

## Példa

```
Szabadsag nyilvantartas. Kilepes 40 nap szabadsag kiirasa utan.
Kezdo honap: 1
Kezdo nap: 24
Zaro honap: 2
Zaro nap: 7
            1111111111222222222233
   1234567890123456789012345678901
 1 -----------------------SSSSSSSS
 2 SSSSSSS---------------------
 3 -------------------------------
 4 ------------------------------
 5 -------------------------------
 6 ------------------------------
 7 -------------------------------
 8 -------------------------------
 9 ------------------------------
10 -------------------------------
11 ------------------------------
12 -------------------------------
Kezdo honap: 2
Kezdo nap: 1
Zaro honap: 3
Zaro nap: 11
            1111111111222222222233
   1234567890123456789012345678901
 1 -----------------------SSSSSSSS
 2 -------SSSSSSSSSSSSSSSSSSSSS
 3 SSSSSSSSSSS--------------------
 4 ------------------------------
 5 -------------------------------
 6 ------------------------------
 7 -------------------------------
 8 -------------------------------
 9 ------------------------------
10 -------------------------------
11 ------------------------------
12 -------------------------------
Pontosan 40 nap szabadsag, kilepes.
```

## Értékelés

Az alapfeladat megoldása 2 pont. Plusz, illetve mínusz pont adandó a következőkért:
| Pont | Megjegyzés |
|------|------------|
| –1 | Ha a program fordítása során egyetlen, szabvány fejfájlok be nem kapcsolásából (`#include`) adódó, figyelmeztető üzenet is akad. |
| –1, –2 | Ha az alapprogram működése bármiben is eltér a feladatban megfogalmazottól. |
| +1 | Ha a hétvégék napjait nem lehet kivenni szabadságként, és a megjelenítésnél ezeket a napokat `H` betűvel jelöli meg! |
| +1 | Ha ünnepnapokon nem lehet szabadságot kivenni, és a megjelenítésnél ezeket a napokat `U` betűvel jelöli meg! Az ünnepnapok listáját az `unnepnapok.txt` fájl adja meg. |
| +1 | Ha parancssori paraméterként megadható az év. Február napjainak számát ennek figyelembe vételével kell megállapítani! |
