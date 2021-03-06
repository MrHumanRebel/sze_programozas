/***************************************************************************************/
// 6/1 Struktúrák, tag-változókkal

#include <iostream>

#define DB 2

using namespace std;

struct step
{
    char kar;
    int lep;
};

void kiir(struct step sp1, struct step sp2)
{
    cout << "\n A kódolás 1. karaktere a léptetés után: '" << sp1.kar << "' lett!";
    cout << "\n A kódolás 2. karaktere a léptetés után: '" << sp2.kar << "' lett!\n";
}

int main(void)
{
    struct step s1, s2;
    for (int fut = 0; fut < DB; fut++)
    {
        cout << "\n Kérem a kódolás " << fut + 1 << ". karakterét: ";
        if (fut == 0)
            cin >> s1.kar;
        else
            cin >> s2.kar;
        cout << "\t Kérem a kódolás " << fut + 1 << ". karakterének a lépésszámát: ";
        if (fut == 0)
            cin >> s1.lep;
        else
            cin >> s2.lep;
    }
    s1.kar += s1.lep;
    s2.kar += s2.lep;
    kiir(s1, s2);
    return 0;
}
/***************************************************************************************/
// 6/2 Struktúrák, tag-tömbökkel (DB 4)

#include <iostream>

#define DB 2

using namespace std;

struct step
{
    char kar[DB];
    int lep[DB];
};

void kiir(struct step sp1)
{
    for (int fut = 0; fut < DB; fut++)
    {
        cout << "\n A kódolás " << fut + 1 << ". karaktere a léptetés után: '"
             << sp1.kar[fut] << "' lett!";
    }
    cout << endl;
}

int main(void)
{
    struct step s1;
    for (int fut = 0; fut < DB; fut++)
    {
        cout << "\n Kérem a kódolás " << fut + 1 << ". karakterét: ";
        cin >> s1.kar[fut];
        cout << "\t Kérem a kódolás " << fut + 1 << ". karakterének a lépésszámát: ";
        cin >> s1.lep[fut];
    }
    for (int fut = 0; fut < DB; fut++)
    {
        s1.kar[fut] += s1.lep[fut];
    }
    kiir(s1);
    return 0;
}
/***************************************************************************************/
// 6/3 Struktúrák, visszatérési érték vs. cím szerinti átadás

#include <iostream>

#define DB 2

using namespace std;

struct step
{
    char kar[DB];
    int lep[DB];
};

void beker(struct step st1)
// struct step beker(struct step st1)
// void beker(struct step *st1)
{
    for (int fut = 0; fut < DB; fut++)
    {
        cout << "\n Kérem a kódolás " << fut + 1 << ". karakterét: ";
        cin >> st1.kar[fut];
        // cin >> (*st1).kar[fut];  // cin >> st1->kar[fut];  // "->" struktúra-mutató operátor
        cout << "\t Kérem a kódolás " << fut + 1 << ". karakterének a lépésszámát: ";
        cin >> st1.lep[fut];
        // cin >> (*st1).lep[fut];  // cin >> st1->lep[fut];  // "->" struktúra-mutató operátor
    }
    // return st1;
}

void kiir(struct step sp1)
{
    for (int fut = 0; fut < DB; fut++)
    {
        cout << "\n A kódolás " << fut + 1 << ". karaktere a léptetés után: '"
             << sp1.kar[fut] << "' lett!";
    }
    cout << endl;
}

int main(void)
{
    struct step s1;
    beker(s1); // érték szeinti átadás!
    // s1=beker(s1);
    // beker(&s1);
    for (int fut = 0; fut < DB; fut++)
    {
        s1.kar[fut] += s1.lep[fut];
    }
    kiir(s1);
    return 0;
}
/***************************************************************************************/
// 6/4 Struktúrák, objektum-inicializációval

#include <iostream>

#define SK 4 // Kiírandó sorok száma

using namespace std;

struct sor_minta
{
    char kar; // kiirandó karakter
    int ism;  // soron belüli ismétlődések száma
    int sor;  // sorok száma, amennyiben megjelenjen
};

int main(void)
{
    struct sor_minta nyzj, es, zzj;
    nyzj.kar = '[';
    nyzj.ism = 2;
    nyzj.sor = 2;      // inicializáció tagonként
    es = {'&', 2, 3};  // inicializátorlista
    zzj = {']', 4, 1}; // inicializátorlista
    cout << endl;
    for (int i = 0; i < SK; i++)
    { // Sorok kiírása
        for (int j = 0; j < nyzj.ism; j++)
        { // Soron belüli kiírás
            if (i < nyzj.sor)
                cout << nyzj.kar;
            else
                cout << "-";
        }
        for (int j = 0; j < es.ism; j++)
        { // Soron belüli kiírás
            if (i < es.sor)
                cout << es.kar;
            else
                cout << "-";
        }
        for (int j = 0; j < zzj.ism; j++)
        { // Soron belüli kiírás
            if (i < zzj.sor)
                cout << zzj.kar;
            else
                cout << "-";
        }
        cout << endl;
    }
    return 0;
}
/***************************************************************************************/
// 6/5 Struktúrák, struktúratömb-inicializációval

#include <iostream>

#define SK 4  // Kiírandó sorok száma
#define T_E 3 // A tömb objektumainak a száma

using namespace std;

struct sor_minta
{
    char kar; // kiirandó karakter
    int ism;  // soron belüli ismétlődések száma
    int sor;  // sorok száma, amennyiben megjelenjen
};

struct sor_minta str_tb[T_E] = {
    {'[', 3, 2},
    {'&', 2, 3},
    {']', 4, 1}}; /* Struktúra tömb definíciója
                     és az elemeinek az inicializációja */

void kiir(int kfv)
{
    for (int k = 0; k < T_E; k++)
    { // 1 sor kiírása
        for (int j = 0; j < str_tb[k].ism; j++)
        { // Soron belüli adott karakter kiírása
            if (kfv < str_tb[k].sor)
                cout << str_tb[k].kar;
            else
                cout << "-";
        }
    }
    cout << endl;
}

int main(void)
{
    cout << endl;
    for (int i = 0; i < SK; i++)
    {
        kiir(i);
    } // Sorok kiírása
    return 0;
}
/***************************************************************************************/
// 6/6 Struktúrák, tag-struktúrával és LOKÁLIS struktúratömbbel
// Debugger használata, 29. sor breakpoints!
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
    string kar;        // kiirandó string
    int ism;           // soron belüli ismétlődések száma
    bool sor[SK];      // sorok száma, amennyiben megjelenjen
    struct veg_sor zk; // sorvégi karaktersorozat
};

void kiir(int kfv, /*const*/ struct sor_minta /*const*/ str_tb[])
{ // objektum-védelem!
    cout << kfv + 1 << ". sor: ";
    for (int k = 0; k < T_E; k++)
    { // 1 sor kiírása
        for (int j = 0; j < str_tb[k].ism; j++)
        { // Soron belüli adott karakter kiírása
            if (str_tb[k].sor[kfv])
                cout << str_tb[k].kar;
            else
                cout << "-";
        }
    }
    if (kfv >= T_E)
        kfv %= 3;
    cout << str_tb[kfv].zk.vs_tb << endl;
    // str_tb[0].ism=1; // cím-szerinti kezelés!
}

int main(void)
{
    struct sor_minta str_tb[T_E] = {
        {"▲", 3, {1, 0, 1, 0}, "╦╦╗"},
        {"►", 2, {1, 1, 1, 0}, "╬╬╣"},
        {"▼", 4, {0, 0, 1, 1}, "╩╩╝"}}; /* Struktúra tömb definíciója
                                           és az elemeinek az inicializációja */
    cout << endl;
    for (int i = 0; i < SK; i++)
    {
        kiir(i, str_tb);
    } // Sorok kiírása
    // cout << endl;
    // for(int i=0; i<SK; i++) { kiir(i,str_tb); }     // Sorok kiírása
    return 0;
}
/***************************************************************************************/
// 6/7 Struktúrák, mutatós tömbkezelés, a "const" típusmódosító

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
    string kar;        // kiirandó string
    int ism;           // soron belüli ismétlődések száma
    bool sor[SK];      // sorok száma, amennyiben megjelenjen
    struct veg_sor zk; // sorvégi karaktersorozat
};

void kiir(int kfv, /*const*/ struct sor_minta * /*const*/ pnt)
{ // pt // objektum- ill. mutató-védelem!
    cout << kfv + 1 << ". sor: ";
    // struct sor_minta* pnt=pt;
    for (int k = 0; k < T_E; k++, pnt++)
    { // 1 sor kiírása
        // cout << "\n A cím amire a pnt mutat: " << pnt << endl;
        for (int j = 0; j < pnt->ism; j++)
        { // Soron belüli adott karakter kiírása
            if (pnt->sor[kfv])
                cout << pnt->kar;
            else
                cout << "-";
        }
    }
    // cout << "\n A sor kiírása utáni cím amire a pnt mutat: " << pnt << endl;
    if (kfv >= T_E)
        kfv %= 3;
    /*if(kfv==0) pnt-=3;
    else if(kfv==1) pnt-=2;
    else if(kfv==2) pnt-=1;*/
    cout << pnt->zk.vs_tb << endl;
    pnt->ism = 1;
}

int main(void)
{
    struct sor_minta str_tb[T_E] = {
        {"▲", 3, {1, 0, 1, 0}, "╦╦╗"},
        {"►", 2, {1, 1, 1, 0}, "╬╬╣"},
        {"▼", 4, {0, 0, 1, 1}, "╩╩╝"}}; /* Struktúra tömb definíciója
                                           és az elemeinek az inicializációja */
    int n, kr, im, sr, vs;
    n = ((kr = sizeof(str_tb[0].kar)) + (im = sizeof(str_tb[0].ism)) +
         (sr = sizeof(str_tb[0].sor)) + (vs = sizeof(str_tb[0].zk)));
    cout << "\n kar[] = " << kr << " + \n ism = " << im
         << " + \n sor[] = " << sr << " + \n vs_tb[] = " << vs
         << " => " << n << " byte\n\n";
    /*const*/ struct sor_minta * /*const*/ mutat;
    for (int i = 0; mutat = str_tb, i < SK; i++)
    {
        kiir(i, mutat);
    } // Sorok kiírása
    // cout << endl;
    // for(int i=0; i<SK; i++) { kiir(i,mutat); } // Sorok kiírása
    return 0;
}
/***************************************************************************************/
