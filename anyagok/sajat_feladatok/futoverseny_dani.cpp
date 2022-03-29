#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

#define TELL cout <<
#define ASK cin >>

#define FUTOMAX 10
#define IDOMAX 20

struct futo
{
    int sorszam;
    string nev;
};

struct ido
{
    int ora;
    int perc;
    int masodperc;
};

struct idoadat
{
    string sorszam;
    int ellszam;
    ido befido;
};

string filename_futo;
string filename_ido;

int olvasas(futo futok[FUTOMAX])
{
    struct idoadat id;
    filename_futo = "/mnt/c/Users/szeke/uni/sze_programozas/anyagok/sajat_feladatok/futok_nevei.txt";
    filename_ido = "/mnt/c/Users/szeke/uni/sze_programozas/anyagok/sajat_feladatok/idomeres.txt";
    // filename_futo = "/home/szeke/uni/sze_programozas/anyagok/sajat_feladatok/futok_nevei.txt";
    // filename_ido = "/home/szeke/uni/sze_programozas/anyagok/sajat_feladatok/idomeres.txt";

    /* cout<<"Adja meg a \"futok_nevei.txt\" elérési útját!"<<endl;
    cin.getline(filename);

    cout<<"Adja meg a \"idomeres_nevei.txt\" elérési útját!"<<endl;
    cin.getline(filename_2);*/

    ifstream futokInput;
    futokInput.open(filename_futo);

    if (!futokInput.is_open())
    {
        cout << "Ilyen fájl nem létezik!" << endl;
        exit(EXIT_FAILURE);
    }

    string akt;
    int db = 0;
    while (getline(futokInput, akt))
    {
        int szokozHelye = akt.find(' ');
        int aktSorszam = stoi(akt.substr(0, szokozHelye));
        string aktNev = akt.substr(szokozHelye + 1);
        futok[db].sorszam = aktSorszam;
        futok[db].nev = aktNev;
        db++;
    }
    futokInput.close();
    return db;
}

void teszt(futo futok[FUTOMAX], int db)
{
    for (int i = 0; i < db; i++)
    {
        TELL futok[i].sorszam << ' ' << futok[i].nev << endl;
    }
}

int main()
{
    futo futok[FUTOMAX];

    int db = olvasas(futok);
    teszt(futok, db);
    return 0;
}