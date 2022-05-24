Készítsen struktúrát települések tárolására. 
A tárolandó attribútumok: név, lélekszám, ország.
A városokat tömbben tároljuk.

Egy függvénnyel rendezze a városokat lélekszám szerint csökkenő sorrendben. (rendez(Telepules* cities, int n))

Egy másik függvénnyel írassa ki a városok rendezett listáját amiben soronként megjelenik a város neve, lélekszáma, országa.

Az egyes attribútumokat egy szóközzel válassza el (kiir(Telepules* cities, int n)).

Egy harmadik függvény írja ki a városok átlagos lélekszámát és írja ki a maximális és minimális lélekszámú városokat (osszegzes(Telepules* cities, int n))!

A kiiratás mintáját a megadott példa kimeneten láthatja.

For example:

Test	Result
Telepules cities[] = {
    {"Kunsziget", 2500, "Hungary"},
    {"Abda", 5000, "Hungary"},
    {"Csorna", 30000, "Hungary"}
};
rendez(cities, 3);
kiir(cities, 3);
osszegzes(cities, 3);
Csorna 30000 Hungary
Abda 5000 Hungary
Kunsziget 2500 Hungary
Atlagos lelekszam: 12500
Legnagyobb varos: 30000
Legkisebb varos: 2500


struct Telepules
{
};

void rendez(Telepules* cities, int n)
{
}

void kiir(Telepules* cities, int n)
{
}

void osszegzes(Telepules* cities, int n)
{
}
