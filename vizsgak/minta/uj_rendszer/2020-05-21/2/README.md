Készítsen függvényeket, amelyekkel fájlból olvas be lebegőpontos számokat és azokat beszúrja egy láncolt listába úgy, hogy annak növekvő rendezettsége mindvégig megmarad. 

Használja fel a függvény előtt már elkészített következő láncolt lista struktúradefiníciót:

struct Lista
{
    double szam;
    Lista *kov;
};
Valósítsa meg a 2 rövid függvényt:

Lista *listaRendezveBeszur(Lista *elso, double szam) - Beszúrja szam-ot abba a növekvő sorrendbe rendezett láncolt listába, melynek első elemét elso jelöli ki a tárban.
Lista *fajbolListaba(string fajlnev) - Feltételezheti, hogy a fajlnev-ben megadott szövegfájl sorai egy-egy racionális számot tartalmaznak (példát ld. alább). Olvassa be és konvertálja ezeket a számokat, majd a listaRendezveBeszur függvény hívásával helyezze el őket növekvően rendezetten egy láncolt listában!
Például a tadat3.txt tartalma:
3.
1
5.5
4
2.0


For example:

Test	Result
Lista *s;
s = fajbolListaba("tadat3.txt");
listaKiir(s);
1 2 3 4 5.5


struct Lista
{
    double szam;
    Lista *kov;
};

// rendezve szúr be
Lista *listaRendezveBeszur(Lista *elso, double szam)
{
    return elso;
}


// fájlból olvas listába
Lista *fajbolListaba(string fajlnev)
{
    Lista *ures = NULL;

    return ures;
}