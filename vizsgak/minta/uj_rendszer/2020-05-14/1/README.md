Egy hangszerbolt gitárjait egyirányú láncolt listában szeretnénk tárolni.

Minden gitárról ismert a húrjainak száma, ami 6, 7, 8 vagy 12 lehet.

Tudjuk az árát, ami legalább 200.000 forint, de 5.000.000 forintnál alacsonyabb.

Illetve tároljuk a hangszedője típusát, ami vagy "humbucker" vagy "single coil".

Készítsen general nevű függvényt, ami létrehoz egy gitárokból álló láncolt listát.

A listán található gitárok száma legalább nulla és maximum 10.

A maximális darabszámot, a minimális árat és a maximális árat a következő szimbolikus állandókkal adja meg: MAX_DB, MIN_AR és MAX_AR. 

Véletlenszerűen döntse el, hogy hány darab gitár kerül a listára és a gitárok minden paramétere (húrok száma, ár, hangszedő típusa) szintén véletlenszerűen kerüljön meghatározásra, a fenti szabályok figyelembe vételével. 

A véletlenszám generálás inicializálásáról nem kell gondoskodnia. 

A függvény visszatérési értéke a generált listában az első gitár címe. A függvénynek bemeneti paraméterei nincsenek.

A lista egy elemének a szerkezetét a következő struktúra adja meg (ennek létrehozásáról nem kell gondoskodnia):

struct gitar {
  int hurok_szama;
  int ar;
  string hangszedo;
  gitar* kov;
};


gitar* general() {}