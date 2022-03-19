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

// JOBBRA 2 LEENGED LE 5 FELEMEL
// JOBBRA 4 LEENGED LE 20 FELEMEL BALRA 20 FEL 5 LEENGED JOBBRA 10

void mozog()
{
    string akt;      // Aktuális vezérlőszó
    string aktdb;    // Aktuális szám
    int db = 0;      // Aktuális szám int-ként
    bool ok = false; // Szám beolvásás vége?

    for (long unsigned int i = 0; i <= beker.length(); i++)
    {
        ok = false;
        // BETŰ
        if (isalpha(beker[i]))
        {
            akt += beker[i];
            cout << akt << endl;
        }
        // SZÁM
        if (isdigit(beker[i]))
        {
            aktdb += beker[i];
            cout << aktdb << endl;
            if (!isdigit(beker[i + 1]))
            {
                stringstream darab(aktdb);
                darab >> db;
                ok = true;
                cout << "\nSzám OK!\n"
                     << endl;
            }
        }

        if (akt == "LEENGED")
            rajzol = true;
        else if (akt == "FELEMEL")
            rajzol = false;
        else if (ok == true)
        {
            if (akt == "BALRA" && !isalpha(beker[i + 1]))
            {
                for (int j = 0; j < db; j++)
                {
                    y--;
                    if (y >= OSZL)
                        y -= OSZL;
                    if (y < 0)
                        y = OSZL - 1;
                    cout << "Balra léptünk..." << endl;
                    if (rajzol == true)
                    {
                        cout << "Balra rajzolt!" << endl;
                        vaszon[x][y] = 'X';
                    }
                }
                ok = false;
            }
            else if (akt == "JOBBRA" && !isalpha(beker[i + 1]))
            {
                for (int j = 0; j < db; j++)
                {
                    y++;
                    if (y >= OSZL)
                        y -= OSZL;
                    if (y < 0)
                        y = OSZL - 1;
                    cout << "Jobbra léptünk..." << endl;
                    if (rajzol == true)
                    {
                        cout << "Jobbra rajzolt!" << endl;
                        vaszon[x][y] = 'X';
                    }
                }
                ok = false;
            }
            else if (akt == "FEL" && !isalpha(beker[i + 1]))
            {
                for (int j = 0; j < db; j++)
                {
                    x--;
                    if (x >= SOR)
                        x -= SOR;
                    if (x < 0)
                        x = SOR - 1;
                    cout << "Fel léptünk..." << endl;
                    if (rajzol == true)
                    {
                        cout << "Fel rajzolt!" << endl;
                        vaszon[x][y] = 'X';
                    }
                }
                ok = false;
            }
            else if (akt == "LE" && !isalpha(beker[i + 1]))
            {
                for (int j = 0; j < db; j++)
                {
                    x++;
                    if (x >= SOR)
                        x -= SOR;
                    if (x < 0)
                        x = SOR - 1;
                    cout << "Le léptünk..." << endl;
                    if (rajzol == true)
                    {
                        cout << "Le rajzolt!" << endl;
                        vaszon[x][y] = 'X';
                    }
                }
                ok = false;
            }
        }

        if (rajzol == true && vaszon[x][y] != 'X')
        {
            cout << "\nMozgás függetlenül rajzolt!\n"
                 << endl;
            vaszon[x][y] = 'X';
        }

        // SPACE
        if (beker[i] == ' ' && isalpha(beker[i + 1]))
        {
            cout << "\nA következő elem betű, szó buffer ürítés...\n"
                 << endl;
            akt = "\0";
        }
        if (beker[i] == ' ' && isdigit(beker[i + 1]))
        {
            cout << "\nA következő elem szám, szám buffer ürítés...\n"
                 << endl;
            aktdb = "\0";
            db = 0;
        }
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