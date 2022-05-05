#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

#define MAX 50

struct Lista
{
    int adat;
    Lista *kov;
};

// Beszúrunk egy elemet az előző után
Lista *beszur(int adat, Lista *elozo)
{
    Lista *uj = new Lista;
    if (uj)
    {
        uj->adat = adat;

        if (elozo)
        {
            uj->kov = elozo->kov;
            elozo->kov = uj;
        }
        else
        {
            uj->kov = NULL;
        }
    }

    return uj;
}

void kiir(Lista *horgony)
{
    Lista *seged;
    for (seged = horgony; seged; seged = seged->kov)
    {
        cout << seged->adat << endl;
    }
}

// Láncolt listák használata után mindig törölnünk kell őket a memóriából
void torolMindent(Lista *horgony)
{
    while (horgony)
    {
        Lista *kovSzimb = horgony->kov;
        delete horgony;
        horgony = kovSzimb;
    }
}

int main()
{
    Lista *horgony = NULL;        // Lista eleje
    Lista *akt = NULL;            // Aktuális címérték
    horgony = beszur(0, horgony); // Első elem feltöltése
    akt = horgony;
    for (int i = 1; i < MAX; i++)
    {
        akt = beszur(i, akt);
    }
    kiir(horgony);
    torolMindent(horgony); // Memória felszabadítás

    return 0;
}