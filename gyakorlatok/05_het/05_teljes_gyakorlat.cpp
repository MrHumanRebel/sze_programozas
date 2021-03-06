/***************************************************************************************/
// 5/1, amely a 3/4 függvényes verziója

#include <iostream>

using namespace std;

void kiir(int tomb[], int ig)
{
    for (int fut = 0; fut < ig; fut++)
    {
        cout << " A tömb " << fut + 1 << ". eleme a(z): '";
        cout.width(2);
        cout << tomb[fut] << "' amely a(z) " << fut << ". indexű!" << endl;
    }
}

void buborek(int tb[], int lt)
{
    for (int v = lt - 1; v >= 1; v--)
    {
        for (int e = 0, csere; e < v; e++)
        {
            if (tb[e] > tb[e + 1]) // '>'== növekvő ill. '<'== csökkenő
            {
                csere = tb[e];
                tb[e] = tb[e + 1];
                tb[e + 1] = csere;
            }
        } // belső rendező ciklus
    }     // külső rendező ciklus
    cout << endl;
}

int main()
{
    int prtln[] = {1, -3, 9, -7, 5};
    int n = sizeof(prtln) / sizeof(prtln[0]);
    kiir(prtln, n);
    buborek(prtln, n);
    kiir(prtln, n);
    return 0;
}
/***************************************************************************************/
// 5/2 beker() fgv

#include <iostream>

#define MAX 50

using namespace std;

int beker(int be_tb[])
{
    int i = 0;
    do
    {
        cout << " Kérem a tömb " << i + 1 << ". elemét: ";
        cin >> be_tb[i];
        if (be_tb[i] % 2 == 1 or be_tb[i] % 2 == -1)
        {
            i++;
            cout << endl;
        }
    } while (i < MAX and be_tb[i] != -2);
    cout << endl;
    return i;
}

void kiir(int tomb[], int ig)
{
    for (int fut = 0; fut < ig; fut++)
    {
        cout << " A tömb " << fut + 1 << ". eleme a(z): '";
        cout.width(2);
        cout << tomb[fut] << "' amely a(z) " << fut << ". indexű!" << endl;
    }
}

void buborek(int tb[], int lt)
{
    for (int v = lt - 1; v >= 1; v--)
    {
        for (int e = 0, csere; e < v; e++)
        {
            if (tb[e] > tb[e + 1]) // '>'== növekvő ill. '<'== csökkenő
            {
                csere = tb[e];
                tb[e] = tb[e + 1];
                tb[e + 1] = csere;
            }
        } // belső rendező ciklus
    }     // külső rendező ciklus
    cout << endl;
}

int main()
{
    int prtln[MAX] = {0};
    int n = beker(prtln);
    kiir(prtln, n);
    buborek(prtln, n);
    kiir(prtln, n);
    return 0;
}
/***************************************************************************************/
// 5/3 cím vs. érték szerinti paraméter átadás
#include <iostream>

#define MAX 50

using namespace std;

int beker(int be_tb[])
{
    int i = 0;
    do
    {
        cout << " Kérem a tömb " << i + 1 << ". elemét: ";
        cin >> be_tb[i];
        if (be_tb[i] % 2 == 1 or be_tb[i] % 2 == -1)
        {
            i++;
            cout << endl;
        }
    } while (i < MAX and be_tb[i] != -2);
    cout << endl;
    return i;
}

void kiir(int tomb[], int ig)
{
    for (int fut = 0; fut < ig; fut++)
    {
        cout << " A tömb " << fut + 1 << ". eleme a(z): '";
        cout.width(2);
        cout << tomb[fut] << "' amely a(z) " << fut << ". indexű!" << endl;
    }
}

void buborek(int tb[], int *lt)
{
    for (int v = (*lt) - 1; v >= 1; v--)
    {
        for (int e = 0, csere; e < v; e++)
        {
            if (tb[e] > tb[e + 1]) // '>'== növekvő ill. '<'== csökkenő
            {
                csere = tb[e];
                tb[e] = tb[e + 1];
                tb[e + 1] = csere;
            }
        } // belső rendező ciklus
    }     // külső rendező ciklus
    cout << endl;
    (*lt)++;
}

int main()
{
    int prtln[MAX] = {0};
    int n = beker(prtln);
    kiir(prtln, n);
    buborek(prtln, &n);
    kiir(prtln, n);
    return 0;
}
/***************************************************************************************/
// 5/4, amely a 3/6 függvényes verziója
#include <iostream>
//#include<cctype>  // ha nincs, nem működnek a makrók!?
#include <cstring> // strlen() fgv.-hez!

#define MAX 128
#define LT 7

using namespace std;

bool beker(char rszm[])
{
    cout << "\n Kérem a rendszámot: ";
    cin.getline(rszm, MAX);
    cout << endl;
    int hsz = strlen(rszm);
    if (hsz != LT)
        return (false);
    for (int i = 0; i < LT; i++)
    {
        if (i < 3 and not isalpha(rszm[i]))
            return (false);
        else if (i >= 4 and not isdigit(rszm[i]))
            return (false);
        else if (not(rszm[3] == '-' or rszm[3] == '_' or isspace(rszm[3])))
            return (false);
    }
    return (true);
}

void ertekel(char rszm[])
{
    bool es;
    for (int i = 0; i < LT; i++)
    {
        es = 0;
        if (isalnum(rszm[i]))
        {
            cout << "'" << rszm[i] << "' => alfanumerikus";
            es = 1;
        }
        if (islower(rszm[i]))
            cout << " és kisbetű";
        if (isupper(rszm[i]))
            cout << " és nagybetű";
        if (isprint(rszm[i]))
        {
            if (es)
                cout << " és nyomtatható!" << endl;
            else
                cout << "'" << rszm[i] << "' => nyomtatható!" << endl;
        }
        if (isspace(rszm[i]))
            cout << "'" << rszm[i] << "' => fehérkarakter!" << endl;
        if (not isxdigit(rszm[i]))
            cout << "'" << rszm[i] << "' => nem hexadecimális!" << endl;
        else
            cout << "'" << rszm[i] << "' => hexadecimális is!" << endl;
        rszm[i] = toupper(rszm[i]); // tolower(); kisbetűsre alakít
        if (i == 3 and rszm[i] != '-')
            rszm[i] = '-';
        cout << endl;
    } // for
    cout << "\n A rendszám helyes: " << rszm << endl;
}

int main()
{
    char rsz[MAX];
    bool helyes;
    do
    {
        if (helyes = beker(rsz))
            ertekel(rsz);
        else
            cout << " Helytelen a rendszám!";
    } while (not helyes);
    return 0;
}
/***************************************************************************************/
// 5/5, amely az 5/4 overloading-os verziója
#include <iostream>
//#include<cctype>  // ha nincs, nem működnek a makrók!?
#include <cstring> // strlen() fgv.-hez!

#define MAX 128
#define LT 7

using namespace std;

bool beker(char rszm[])
{
    cout << "\n Kérem a rendszámot: ";
    cin.getline(rszm, MAX);
    cout << endl;
    int hsz = strlen(rszm);
    if (hsz != LT)
        return (false);
    for (int i = 0; i < LT; i++)
    {
        if (i < 3 and not isalpha(rszm[i]))
            return (false);
        else if (i >= 4 and not isdigit(rszm[i]))
            return (false);
        else if (not(rszm[3] == '-' or rszm[3] == '_' or isspace(rszm[3])))
            return (false);
    }
    return (true);
}

void ertekel(char rszm[])
{
    bool es;
    for (int i = 0; i < LT; i++)
    {
        es = 0;
        if (isalnum(rszm[i]))
        {
            cout << "'" << rszm[i] << "' => alfanumerikus";
            es = 1;
        }
        if (islower(rszm[i]))
            cout << " és kisbetű";
        if (isupper(rszm[i]))
            cout << " és nagybetű";
        if (isprint(rszm[i]))
        {
            if (es)
                cout << " és nyomtatható!" << endl;
            else
                cout << "'" << rszm[i] << "' => nyomtatható!" << endl;
        }
        if (isspace(rszm[i]))
            cout << "'" << rszm[i] << "' => fehérkarakter!" << endl;
        if (not isxdigit(rszm[i]))
            cout << "'" << rszm[i] << "' => nem hexadecimális!" << endl;
        else
            cout << "'" << rszm[i] << "' => hexadecimális is!" << endl;
        rszm[i] = toupper(rszm[i]); // tolower(); kisbetűsre alakít
        if (i == 3 and rszm[i] != '-')
            rszm[i] = '-';
        cout << endl;
    } // for
    cout << "\n A rendszám helyes: " << rszm << endl;
}

void ertekel(char rszm[], bool eredet)
{
    bool es;
    char ment[LT];
    for (int i = 0; i < LT; i++)
    {
        es = 0;
        if (isalnum(rszm[i]))
        {
            cout << "'" << rszm[i] << "' => alfanumerikus";
            es = 1;
        }
        if (islower(rszm[i]))
            cout << " és kisbetű";
        if (isupper(rszm[i]))
            cout << " és nagybetű";
        if (isprint(rszm[i]))
        {
            if (es)
                cout << " és nyomtatható!" << endl;
            else
                cout << "'" << rszm[i] << "' => nyomtatható!" << endl;
        }
        if (isspace(rszm[i]))
            cout << "'" << rszm[i] << "' => fehérkarakter!" << endl;
        if (not isxdigit(rszm[i]))
            cout << "'" << rszm[i] << "' => nem hexadecimális!" << endl;
        else
            cout << "'" << rszm[i] << "' => hexadecimális is!" << endl;
        ment[i] = rszm[i];
        rszm[i] = toupper(rszm[i]); // tolower(); kisbetűsre alakít
        if (i == 3 and rszm[i] != '-')
            rszm[i] = '-';
        cout << endl;
    } // for
    cout << "\n A rendszám helyes: " << rszm << endl;
    cout << "\n A beviteli rendszám: " << ment << endl;
}

int main()
{
    char rsz[MAX];
    bool helyes;
    do
    {
        if (helyes = beker(rsz))
            ertekel(rsz);
        // if(helyes=beker(rsz)) ertekel(rsz,true);
        else
            cout << " Helytelen a rendszám!";
    } while (not helyes);
    return 0;
}
/***************************************************************************************/
// 5/6, amely az 5/5 kódismétlés nélküli verziója
#include <iostream>
//#include<cctype>  // ha nincs, nem működnek a makrók!?
#include <cstring> // strlen() fgv.-hez!

// HIBÁS FGV SORREND!!!

#define MAX 128
#define LT 7

using namespace std;

bool beker(char rszm[])
{
    cout << "\n Kérem a rendszámot: ";
    cin.getline(rszm, MAX);
    cout << endl;
    int hsz = strlen(rszm);
    if (hsz != LT)
        return (false);
    for (int i = 0; i < LT; i++)
    {
        if (i < 3 and not isalpha(rszm[i]))
            return (false);
        else if (i >= 4 and not isdigit(rszm[i]))
            return (false);
        else if (not(rszm[3] == '-' or rszm[3] == '_' or isspace(rszm[3])))
            return (false);
    }
    return (true);
}

void ertekel(char rszm[])
{
    for (int i = 0; i < LT; i++)
    {
        ism_ert(rszm, i);
        ism_ert(rszm, i, true);
    } // for
    cout << "\n A rendszám helyes: " << rszm << endl;
}

void ertekel(char rszm[], bool eredet)
{
    char ment[LT];
    for (int i = 0; i < LT; i++)
    {
        ism_ert(rszm, i);
        ment[i] = rszm[i];
        ism_ert(rszm, i, true);
    } // for
    cout << "\n A rendszám helyes: " << rszm << endl;
    cout << "\n A beviteli rendszám: " << ment << endl;
}

void ism_ert(char rszm[], int i)
{
    bool es;
    if (isalnum(rszm[i]))
    {
        cout << "'" << rszm[i] << "' => alfanumerikus";
        es = 1;
    }
    if (islower(rszm[i]))
        cout << " és kisbetű";
    if (isupper(rszm[i]))
        cout << " és nagybetű";
    if (isprint(rszm[i]))
    {
        if (es)
            cout << " és nyomtatható!" << endl;
        else
            cout << "'" << rszm[i] << "' => nyomtatható!" << endl;
    }
    if (isspace(rszm[i]))
        cout << "'" << rszm[i] << "' => fehérkarakter!" << endl;
    if (not isxdigit(rszm[i]))
        cout << "'" << rszm[i] << "' => nem hexadecimális!" << endl;
    else
        cout << "'" << rszm[i] << "' => hexadecimális is!" << endl;
}

void ism_ert(char rszm[], int i, bool vege)
{
    rszm[i] = toupper(rszm[i]); // tolower(); kisbetűsre alakít
    if (i == 3 and rszm[i] != '-')
        rszm[i] = '-';
    cout << endl;
}

int main()
{
    char rsz[MAX];
    bool helyes;
    do
    {
        if (helyes = beker(rsz))
            ertekel(rsz);
        // if(helyes=beker(rsz)) ertekel(rsz,true);
        else
            cout << " Helytelen a rendszám!";
    } while (not helyes);
    return 0;
}
/***************************************************************************************/
// 5/7, amely az 5/6 rekurzív verziója
#include <iostream>
//#include<cctype>  // ha nincs, nem működnek a makrók!?
#include <cstring> // strlen() fgv.-hez!

#define MAX 128
#define LT 7

using namespace std;

bool beker(char rszm[])
{
    cout << "\n Kérem a rendszámot: ";
    cin.getline(rszm, MAX);
    cout << endl;
    int hsz = strlen(rszm);
    if (hsz != LT)
        return (false);
    for (int i = 0; i < LT; i++)
    {
        if (i < 3 and not isalpha(rszm[i]))
            return (false);
        else if (i >= 4 and not isdigit(rszm[i]))
            return (false);
        else if (not(rszm[3] == '-' or rszm[3] == '_' or isspace(rszm[3])))
            return (false);
    }
    return (true);
}

void ism_ert(char rszm[], int i)
{
    bool es = 0;
    if (isalnum(rszm[i]))
    {
        cout << "'" << rszm[i] << "' => alfanumerikus";
        es = 1;
    }
    if (islower(rszm[i]))
        cout << " és kisbetű";
    if (isupper(rszm[i]))
        cout << " és nagybetű";
    if (isprint(rszm[i]))
    {
        if (es)
            cout << " és nyomtatható!" << endl;
        else
            cout << "'" << rszm[i] << "' => nyomtatható!" << endl;
    }
    if (isspace(rszm[i]))
        cout << "'" << rszm[i] << "' => fehérkarakter!" << endl;
    if (not isxdigit(rszm[i]))
        cout << "'" << rszm[i] << "' => nem hexadecimális!" << endl;
    else
        cout << "'" << rszm[i] << "' => hexadecimális is!" << endl;
}

void ism_ert(char rszm[], int i, bool vege)
{
    rszm[i] = toupper(rszm[i]); // tolower(); kisbetűsre alakít
    if (i == 3 and rszm[i] != '-')
        rszm[i] = '-';
    cout << endl;
}

int on_hiv(char rszm[], int i)
{
    ism_ert(rszm, i);
    ism_ert(rszm, i, true);
    i++;
    if (i >= LT)
    {
        cout << " Zárul a rekurzió, 'i' értéke: '" << i << "'.\n";
        return i;
    }
    else
    {
        cout << i << ". rekurzió!" << endl;
        return i + on_hiv(rszm, i);
    }
    // az "else" csak szemléltetés, de a return nem az!
}

void ertekel(char rszm[])
{
    int i = 0;
    i = on_hiv(rszm, i);
    cout << "\n A rendszám helyes: " << rszm << endl;
    cout << "\n Az 'i+=' értéke: " << i << "." << endl; // faktoriálisra is: 7! = 5.040
}

void ertekel(char rszm[], bool eredet)
{
    char ment[LT];
    for (int i = 0; i < LT; i++)
    {
        ism_ert(rszm, i);
        ment[i] = rszm[i];
        ism_ert(rszm, i, true);
    } // for
    cout << "\n A rendszám helyes: " << rszm << endl;
    cout << "\n A beviteli rendszám: " << ment << endl;
}

int main()
{
    char rsz[MAX];
    bool helyes;
    do
    {
        if (helyes = beker(rsz))
            ertekel(rsz);
        // if(helyes=beker(rsz)) ertekel(rsz,true);
        else
            cout << " Helytelen a rendszám!";
    } while (not helyes);
    return 0;
}
/***************************************************************************************/