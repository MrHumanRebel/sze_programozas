Írjon egy minoszlop nevű függvényt, ami paraméterként kap egy dinamikusan, soronként foglalt int mátrixot (a sorok kezdőcímeinek tömbjét), a sorok számát, és oszlopok számát; és visszaadja annak az oszlopnak az indexét, amelyikben az elemek összege a legkisebb.

Ha több minimális összegű oszlop is van, ezek közül a legkisebb indexű oszlop indexét adja vissza.

Megjegyzés: A tesztekben található letrehoz, feltolt, és felszabadit függvényeket nem kell megírnia.


For example:

Test	Result
int sorok = 4, oszlopok = 5;
int **mtx = letrehoz(sorok, oszlopok);
feltolt(mtx, sorok, oszlopok, 0);
cout << "A legkisebb osszegu oszlop indexe: " << minoszlop(mtx, sorok, oszlopok) << "\n";
felszabadit(mtx, sorok);
A legkisebb osszegu oszlop indexe: 3


#include <climits>

int minoszlop(int **mtx, int s, int o) {
    
    return -1; //
}