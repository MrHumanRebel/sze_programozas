# 3. feladat

# Feladat

Írjon egy `string tri_result(string fbe)` függvényt, amely kiírja egy adott triatlon verseny győztesének az azonosítóját (licence), és a cél-idejét; `óra:perc:másodperc` alakban.

A cél-idő a következő részeredményekből tevődik össze: `úszás + kerékpár + futás + depo`. A kiírás pontos formátumát a példa mutatja!

A célba érkezett versenyzők számát és a részidőket egy adat-file tartalmazza,
amelynek a létezését ellenőrizni kell! A hibaüzenet formátumát a példa mutatja!

Ennek az állománynak az azonosítója lesz a `tri_result` függvény paramétere.

Az adat-file első sora egy pozitív egész szám, amely a célba érkezettek száma.
A további mindenegyes sora egy-egy sportolót azonosít és tartalmazza a részidejeit
másodpercben, a következők szerint:

```
licence úszás-idő kerékpár-idő futás-idő depó-idő
```

Az adatokat szóközök választják el egymástól! Például:

```
df-572ki 1500 4500 2500 125
…
do-565yy 1900 4900 2900 129
```

Az adat-file elemeit tárolja el egy struktúra-tömbbe, amihez használja a megadott
`struct triathlete` típust! A struktúra-tömböt a dinamikus memóriába hozza létre!

A versenyzők kiszámolt cél-idejeit (másodpercben) az `int sum` tagváltozókba
mentsék el. Ezen adatokból kell megállapítani a győztes és az utolsó versenyző
cél-idejeit. Ugyanis a függvény visszatérési értéke az utolsó versenyző licence legyen.

Ha az adat-file nem létezik, akkor a visszatérési érték az `N/A!` karaktersorozat legyen!

(A `cerr <<` utasítást NE használják! Moodle… :( )

# Példa

| Test                                                    | Result                                        |
| ------------------------------------------------------- | --------------------------------------------- |
| `string u=tri_result("Chip.txt");`<br>`std::cout << u;` | `nz-789zu => 1:58:40 [h:m:s]` <br> `do-565yy` |
| `string u=tri_result("Chi.txt");` <br> `std::cout << u` | `Sikertelen file-nyitás!`<br> `N/A!`          |
