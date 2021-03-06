/***************************************************************************************/
// 7/1 a mutató-aritmetika és a "const" típusmódosító folytatása

#include <iostream>

#define SK 4  // Kiírandó sorok száma
#define T_E 3 // A tömb objektumainak a száma

using namespace std;

struct veg_sor
{
    string vs_tb; // kiirandó záró-karaktersorozat
};

struct sor_minta
{
    string const kar;        // kiirandó string
    int const ism;           // soron belüli ismétlődések száma
    bool const sor[SK];      // sorok száma
    const struct veg_sor zk; // sorvégi karaktersorozat
};

void kiir(int kfv, struct sor_minta *pnt)
{
    struct sor_minta *pnt1_3, *pnt4;
    cout << kfv + 1 << ". sor: ";
    for (int k = 0; k < T_E; k++, pnt++)
    {   // 1 sor kiírása
        // cout << "\n A cím amire a pnt mutat: " << pnt << endl;
        pnt1_3 = pnt;
        for (int j = 0; j < pnt->ism; j++)
        { // Soron belüli adott karakter kiírása
            if (pnt->sor[kfv])
                cout << pnt->kar;
            else
                cout << "-";
        }
    }
    // cout << "\n A sor kiírása utáni cím amire a pnt mutat: " << pnt << endl;
    pnt4 = pnt;
    if (pnt4 > pnt1_3)
        cout << "\n A pnt4 cím a nagyobb!" << endl;
    long pnt_k = (pnt4 - pnt1_3);
    cout << " Egy sorvektor/rekord mérete: " << pnt_k << " cím-egységnyi,";
    pnt_k *= sizeof(struct sor_minta);
    cout << "\n\t azaz: " << pnt_k << " byte!" << endl;
    if (kfv >= T_E)
        kfv %= 3;
    if (kfv == 0)
        pnt -= 3;
    else if (kfv == 1)
        pnt -= 2;
    else if (kfv == 2)
        pnt -= 1;
    cout << pnt->zk.vs_tb << endl;
    // pnt->ism=1;
    // pnt->kar="°";
    // pnt->sor[3]=0;
    // pnt->zk.vs_tb="▓";
}

int main(void)
{
    struct sor_minta str_tb[T_E] = {
        {"▲", 3, {1, 1, 1, 1}, "╦╦╗"},
        {"►", 2, {1, 1, 1, 1}, "╬╬╣"},
        {"▼", 4, {1, 1, 1, 1}, "╩╩╝"}}; /* Struktúra tömb definíciója
                                           és az elemeinek az inicializációja */
    int n, kr, im, sr, vs;
    n = ((kr = sizeof(str_tb[0].kar)) + (im = sizeof(str_tb[0].ism)) +
         (sr = sizeof(str_tb[0].sor)) + (vs = sizeof(str_tb[0].zk)));
    cout << "\n kar[] = " << kr << " + \n ism = " << im
         << " + \n sor[] = " << sr << " + \n vs_tb[] = " << vs
         << " => " << n << " byte\n\n";
    struct sor_minta *mutat;
    for (int i = 0; mutat = str_tb, i < SK; i++)
    {
        kiir(i, mutat);
    } // Sorok kiírása
    return 0;
}
/***************************************************************************************/
