#include <iostream>
#include <sstream>
using namespace std;

// Vászon mérete
#define SOR 10
#define OSZL 10

// Globális változók
bool van_e_alap = false;
bool rajzol = false;
char vaszon[SOR][OSZL];

//"X" Vízszintes "Y" Függőleges  JOBBRA 2 LEENGED LE 5 FELEMEL
int x = 0;
int y = 0;

string beker;

void mozog()
{
    string akt;
    string aktdb;
    int db = 0;
    bool ok = false;

    for (long unsigned int i = 0; i <= beker.length(); i++)
    {
        ok = false;
        // BETŰ
        if (beker[i] != ' ' && isalpha(beker[i]))
        {
            akt += beker[i];
            cout << akt << endl;
        }
        // SZÁM
        if (beker[i] != ' ' && isdigit(beker[i]))
        {
            aktdb += beker[i];
            cout << aktdb << endl;
        }
        else
        {
            // String to int konverzió, STOI nem működik... Plusz fejléc kell, => #include <sstream>
            stringstream darab(aktdb);
            darab >> db;
        }

        // Van-e már szám és kétjegyű-e, ha már van és kétjegyű további feltételek bekapcsolása
        if (aktdb != "\0" && !isdigit(beker[i + 1]))
        {
            ok = true;
            // cout << "Megvan a teljes szám!" << endl;
        }

        if (akt == "LEENGED")
            rajzol = true;
        if (akt == "FELEMEL")
            rajzol = false;

        if (ok == true)
        {
            if (akt == "BALRA" && beker[i + 1] == ' ')
            {

                for (int j = 0; j <= db; j++)
                {
                    if (y > OSZL - 1)
                        y -= OSZL;
                    if (y < 0)
                        y = OSZL - y;

                    y--;
                    cout << "!!!BALRA!!!" << endl;
                    if (rajzol == true)
                    {
                        cout << "BALRA RAJZOLT!" << endl;
                        vaszon[x][y] = 'X';
                    }
                }
                ok = false;
            }
            if (akt == "JOBBRA" && beker[i + 1] == ' ')
            {

                for (int j = 0; j <= db; j++)
                {
                    if (y > OSZL - 1)
                        y -= OSZL;
                    if (y < 0)
                        y = OSZL - y;

                    y++;
                    cout << "!!!JOBBRA!!!" << endl;
                    if (rajzol == true)
                    {
                        cout << "JOBBRA RAJZOLT!" << endl;
                        vaszon[x][y] = 'X';
                    }
                }
                ok = false;
            }
            if (akt == "FEL" && beker[i + 1] == ' ')
            {

                for (int j = 0; j <= db; j++)
                {
                    if (x > OSZL - 1)
                        x -= OSZL;
                    if (x < 0)
                        x = OSZL - x;

                    x--;
                    cout << "!!!FEL!!!" << endl;
                    if (rajzol == true)
                    {
                        cout << "FEL RAJZOLT!" << endl;
                        vaszon[x][y] = 'X';
                    }
                }
                ok = false;
            }
            if (akt == "LE" && beker[i + 1] == ' ')
            {

                for (int j = 0; j <= db; j++)
                {
                    if (x > OSZL - 1)
                        x -= OSZL;
                    if (x < 0)
                        x = OSZL - x;

                    x++;
                    cout << "!!!LE!!!" << endl;
                    if (rajzol == true)
                    {
                        cout << "LE RAJZOLT!" << endl;
                        vaszon[x][y] = 'X';
                    }
                }
                ok = false;
            }
        }

        // Mozgás független rajzolás
        if (rajzol == true && vaszon[x][y] != 'X')
        {
            cout << "MOGÁS NÉLKÜL RAJZOLT!" << endl;
            vaszon[x][y] = 'X';
        }

        // SPACE
        if (beker[i] == ' ' && (isalpha(beker[i + 1])))
        {
            cout << "A következő elem betű, szó buffer ürítés..." << endl;
            akt = "\0";
        }
        if (beker[i] == ' ' && (isdigit(beker[i + 1])))
        {
            cout << "A következő elem szám, szám buffer ürítés..." << endl;
            aktdb = "\0";
            ok = false;
        }
    }
}

void alapvaszon()
{
    for (int i = 0; i < SOR; i++)
    {
        for (int j = 0; j < OSZL; j++)
        {
            vaszon[i][j] = '.';
        }
    }
    van_e_alap = true;
}

void megjelenit()
{
    for (int i = 0; i < SOR; i++)
    {
        for (int j = 0; j < OSZL; j++)
        {
            cout << vaszon[i][j];
        }
        cout << endl;
    }
}

string input()
{
    cout << "Adja meg a vezérlő parancssort..." << endl;
    getline(cin, beker);
    for (long unsigned int i = 0; i <= beker.length(); i++)
    {
        if (isalpha(beker[i]))
        {
            beker[i] = toupper(beker[i]);
        }
    }
    return beker;
}

int main()
{
    cout << "CMD rajzolóprogram indul...\n"
         << endl;
    if (van_e_alap == false)
        alapvaszon();
    megjelenit();
    input();
    mozog();
    megjelenit();
    return 0;
}