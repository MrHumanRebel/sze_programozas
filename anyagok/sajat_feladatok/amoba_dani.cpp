#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

#define DB 10

char tabla[DB][DB];

bool sor_ok = false, oszl_ok = false, vege = false, van_e_palya = false;
int sor, c_oszl, jatekos, szamlalo;
int db = 0;
char oszl, aktjel;

void alap_palya()
{
    for (int i = 0; i < DB; i++)
    {
        for (int j = 0; j < DB; j++)
        {
            tabla[i][j] = '.';
        }
    }
    van_e_palya = true;
}

void beker()
{
    do
    {
        cout << "Sor: ";
        cin >> sor;
        if (sor >= 1 && sor <= 10)
            sor_ok = true;
        else
            cout << "Adjon meg 1-" << DB << " tartományba tartozó számot! ";

    } while (sor_ok == false);

    do
    {
        cout << "Oszlop: ";
        cin >> oszl;
        oszl = toupper(oszl);
        if ((oszl >= 'a' && oszl <= 'z') or (oszl >= 'A' && oszl <= 'Z'))
            oszl_ok = true;
        else
            cout << "Adjon meg A-J tartományba tartozó betűt! ";

    } while (oszl_ok == false);

    if (oszl_ok == true)
    {
        db = 0;
        for (int i = 65; i <= 90; i++)
        {
            if (oszl == i)
            {
                c_oszl = (oszl - (oszl - 1)) + db;
                cout << "Az oszlop sorszáma: " << c_oszl << "\n"
                     << endl;
            }
            else
                db = db + 1;
        }
    }
}

void allas()
{
    cout << "  \t";
    for (int i = 'A'; i < ('A' + DB); i++)
    {
        cout << char(i);
    }
    cout << endl;

    for (int i = 0; i < DB; i++)
    {
        if (i < DB - 1)
            cout << '0' << i + 1 << "\t";
        else
            cout << i + 1 << "\t";
        for (int j = 0; j < DB; j++)
        {
            cout << tabla[i][j];
        }
        cout << endl;
    }
}

void valaszt()
{
    if (jatekos == 1)
    {
        if (tabla[sor - 1][c_oszl - 1] != 'O')
            tabla[sor - 1][c_oszl - 1] = 'X';
        else
        {
            cout << "Ez a hely már foglalt, Ön csalni akart!" << endl;
            beker();
            valaszt();
        }
    }

    if (jatekos == 2)
    {
        if (tabla[sor - 1][c_oszl - 1] != 'X')
            tabla[sor - 1][c_oszl - 1] = 'O';
        else
        {
            cout << "Ez a hely már foglalt, Ön csalni akart!" << endl;
            beker();
            valaszt();
        }
    }
}

void ellenoriz() // ALL BETA VERSION
{
    int sorszamlal = 0, oszlszamlal = 0;
    // Sima jobbra balra le fel
    for (int i = 0; i < DB; i++)
    {
        for (int j = 0; j < DB; j++)
        {
            if (tabla[i][j] == aktjel && vege == false)
            {
                sorszamlal++;
                if (sorszamlal >= 5 &&
                    tabla[i][j] == tabla[i][j + 1] &&
                    tabla[i][j + 1] == tabla[i][j + 2] &&
                    tabla[i][j + 2] == tabla[i][j + 3] &&
                    tabla[i][j + 3] == tabla[i][j + 4])
                {
                    vege = true;
                    cout << "Vízszintes irányban nyert!" << endl;
                }
            }
            if (tabla[i][j] == aktjel && vege == false)
            {
                oszlszamlal++;
                if (oszlszamlal >= 5 &&
                    tabla[i][j] == tabla[i + 1][j] &&
                    tabla[i + 1][j] == tabla[i + 2][j] &&
                    tabla[i + 2][j] == tabla[i + 3][j] &&
                    tabla[i + 3][j] == tabla[i + 4][j])
                {
                    vege = true;
                    cout << "Függőleges irányban nyert!" << endl;
                }
            }
            if (vege == true)
            {
                sorszamlal = 5;
                oszlszamlal = 5;
            }
            if (j == DB - 1)
                sorszamlal = 0;
            if (i == DB - 1)
                oszlszamlal = 0;
        }
    }
    if (vege != true)
    {
        szamlalo = 0;
        // Balrol jobbra atló
        for (int i = 0; i < DB; i++)
        {
            for (int j = 0; j < DB - 4; j++) //"G" sornál álljon le
            {
                if (tabla[i][j] == aktjel && i == j)
                {
                    szamlalo++;
                    if (szamlalo >= 5)
                    {
                        vege = true;
                        cout << "Balról jobbra atlóval nyert!" << endl;
                    }
                }
            }
        }
    }
    if (vege != true)
    {
        szamlalo = 0;
        // Jobbról balra atló
        for (int i = 0; i < DB; i++)
        {
            for (int j = DB - 1; j > 4; j--) //"D" sornál álljon le
            {
                if (tabla[i][j] == aktjel && (DB - (i + 1) == j))
                {
                    szamlalo++;
                    if (szamlalo >= 5)
                    {
                        vege = true;
                        cout << "Jobbról balra atlóval nyert!" << endl;
                    }
                }
            }
        }
    }
}

void nyert()
{
    if (jatekos == 1)
    {
        aktjel = 'X';
        ellenoriz();
        if (szamlalo == 5)
            cout << "Az első játékos nyert!";
    }

    if (jatekos == 2)
    {
        aktjel = 'O';
        ellenoriz();
        if (szamlalo == 5)
            cout << "A második játékos nyert!";
    }
}

void olvasas()
{
    string olvashely;
    ifstream olvas;
    char akt;
    olvashely = "/mnt/c/Users/szeke/uni/sze_programozas/anyagok/sajat_feladatok/amoba_allas.txt";
    olvas.open(olvashely);
    if (!olvas.is_open())
    {
        cout << "Nincs mentett játékállás!\n"
             << endl;
        van_e_palya = false;
    }
    else
    {
        cout << "Van mentett játékállás, betöltés...\n"
             << endl;
        van_e_palya = true;
        for (int i = 0; i <= DB; i++)
        {
            for (int j = 0; j <= DB; j++)
            {
                olvas >> akt;
                tabla[i][j] = akt;
            }
        }
        olvas.close();
    }
}

void iras()
{
    ofstream allaski;
    string irashely;
    string akt;
    irashely = "/mnt/c/Users/szeke/uni/sze_programozas/anyagok/sajat_feladatok/amoba_allas.txt";
    allaski.open(irashely);
    for (int i = 0; i <= DB; i++)
    {
        for (int j = 0; j <= DB; j++)
        {
            akt = tabla[i][j];
            if (j == 10)
                allaski << "\n";
            allaski << akt;
        }
    }
    allaski.close();
    cout << "Játék állás sikeresen mentve!" << endl;
}

int main()
{

    cout << "Amőba játék\n"
         << endl;

    olvasas();
    if (van_e_palya == false)
        alap_palya();

    allas();
    vege = false;
    do
    {
        cout << "Első játékos lépése:" << endl;
        jatekos = 1;
        beker();
        valaszt();
        allas();
        nyert();
        if (vege == true)
            return 0;
        iras();

        cout << "Második játékos lépése:" << endl;
        jatekos = 2;
        beker();
        valaszt();
        allas();
        nyert();
        iras();

    } while (!vege);
    return 0;
}