Készítsen egy programot ami könyvek listáját tárolja. A fájlban soronként vesszővel elválasztva a könyv címét és oldalainak számát tároljuk.


A könyveket olvassa be a KonyvLista* konyvekBeolvas(const string filename) függvénnyel, ami a könyvek eltárolására alkalmas láncolt lista mutatójával tér vissza. 

A beolvasás során ügyeljen arra, hogy a könyvek a cím első karaktere szerint rendezetten tárolódjanak. 

Implementálja a konyvListaKiir(KonyvLista* lista) függvényt is, ami kiírja standard outputra az egyes attribútumokat szóközzel elválasztva. 

A maxOldalszam adja vissza a leghosszabb könyvet (ebben a függvényben ne írjon ki semmit a standard outputra)!


TIPP: készítsen külön beszur függvényt a sor beolvasására. A függvény egyrészt dolgozza fel a bemenetként kapott sort, másrészt szúrja be a kiolvasott elemet a listába!



kiskonyvtar.txt tartalma:

Harry Potter, 234

Lord of the Rings, 1123

Battle Royale, 840

Foundation, 340

For example:

Test	Result
KonyvLista* lista = konyvekBeolvas("kiskonyvtar.txt");
konyvListaKiir(lista);
std::cout << "Leghosszabb: " << maxOldalSzam(lista)->cim << '\n';
konyvFelszabadit(lista);
Battle Royale 840
Foundation 340
Harry Potter 234
Lord of the Rings 1123
Leghosszabb: Lord of the Rings

struct KonyvLista
{
};

KonyvLista* beszur(KonyvLista* lista, const std::string& line)
{
    return NULL;
}

KonyvLista* konyvekBeolvas(const std::string filename)
{
    return NULL;
}

void konyvListaKiir(KonyvLista* lista)
{
}

KonyvLista* maxOldalSzam(KonyvLista* lista)
{
    return NULL;
}
}
