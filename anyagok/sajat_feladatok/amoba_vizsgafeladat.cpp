#include <iostream>
#include <stdlib.h>
using namespace std;
#define DB 10
char tabla[DB][DB];
bool van_e_palya = false;
bool vege;
bool sor_ok, oszl_ok = false;
int sor, c_oszl, jatekos, szamlalo;
int db = 0;
char oszl;
char aktjel;

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
        if (sor >= 1 && sor <= 10) // Számok
            sor_ok = true;
        else
            cout << "Adjon meg 1-" << DB << " tartományba tartozó számot! ";

    } while (sor_ok == false);

    do
    {
        cout << "Oszlop: ";
        cin >> oszl;
        oszl = toupper(oszl);
        if ((oszl >= 'a' && oszl <= 'z') or (oszl >= 'A' && oszl <= 'Z')) // Betűk
            oszl_ok = true;
        else
            cout << "Adjon meg A-J tartományba tartozó betűt! ";

    } while (oszl_ok == false);

    db = 0;
    for (int i = 65; i <= 90; i++)
    {
        if (oszl == i)
        {
            c_oszl = (oszl - (oszl - 1)) + db;
            cout << "Az oszlop sorszáma:\t" << c_oszl << endl;
        }
        else
            db = db + 1;
    }
}

void allas()
{
    cout << "  \t";
    for (int i = 65; i < (65 + DB); i++) // 65 => "A" betű ASCII
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
            if (tabla[i][j] == aktjel)
            {
                sorszamlal++;
                if (sorszamlal == 5)
                {
                    vege = true;
                    cout << "Vízszintes irányban nyert!" << endl;
                }
            }
            if (tabla[j][i] == aktjel)
            {
                oszlszamlal++;
                if (oszlszamlal == 5)
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
                    if (szamlalo == 5)
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
            for (int j = DB - 4; j > 0; j--) //"D" sornál álljon le
            {
                if (tabla[i][j] == aktjel && ((DB + 1) - i) == j)
                {
                    szamlalo++;
                    if (szamlalo == 5)
                    {
                        vege = true;
                        cout << "Jobbról jobbra atlóval nyert!" << endl;
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
        // szamlalo = 0;
        aktjel = 'X';
        ellenoriz();
        if (szamlalo == 5)
            cout << "Az első játékos nyert!";
    }

    if (jatekos == 2)
    {
        // szamlalo = 0;
        aktjel = 'O';
        ellenoriz();
        if (szamlalo == 5)
            cout << "A második játékos nyert!";
    }
}

int main()
{

    cout << "Amőba játék\n"
         << endl;

    // Ha még nincs nincs pálya generáljuk egyet
    if (van_e_palya == false)
        alap_palya();

    // Alap állás printelése
    allas();
    vege = false;
    do
    {
        // system("clear"); // Console clear
        cout << "Első játékos lépése:" << endl;
        jatekos = 1;
        beker();
        valaszt();
        allas();
        nyert();
        if (vege == true)
            return 0;

        // system("clear"); // Console clear
        cout << "Második játékos lépése:" << endl;
        jatekos = 2;
        beker();
        valaszt();
        allas();
        nyert();

    } while (!vege);
    return 0;
}