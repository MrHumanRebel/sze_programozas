#include <iostream>
#include <sstream>
using namespace std;

#define SOR 10
#define OSZL 10

bool van_e_alap = false;
bool rajzol = false;
char vaszon[SOR][OSZL];

int x = 0;
int y = 0;
string beker;

// JOBBRA 4 LEENGED LE 20 FELEMEL BALRA 20 FEL 5 LEENGED JOBBRA 10

void y_ell()
{
    if (y >= OSZL)
        y -= OSZL;
    if (y < 0)
        y = OSZL - 1;
}

void x_ell()
{
    if (x >= SOR)
        x -= SOR;
    if (x < 0)
        x = SOR - 1;
}

void if_rajzol()
{
    if (rajzol == true)
    {
        vaszon[x][y] = 'X';
    }
}

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
                    y_ell();
                    if_rajzol();
                }
            }
            else if (akt == "JOBBRA" && !isalpha(beker[i + 1]))
            {
                for (int j = 0; j < db; j++)
                {
                    y++;
                    y_ell();
                    if_rajzol();
                }
            }
            else if (akt == "FEL" && !isalpha(beker[i + 1]))
            {
                for (int j = 0; j < db; j++)
                {
                    x--;
                    x_ell();
                    if_rajzol();
                }
            }
            else if (akt == "LE" && !isalpha(beker[i + 1]))
            {
                for (int j = 0; j < db; j++)
                {
                    x++;
                    x_ell();
                    if_rajzol();
                }
            }
        }

        if (rajzol == true && vaszon[x][y] != 'X')
        {
            vaszon[x][y] = 'X';
        }

        // SPACE
        if (beker[i] == ' ' && isalpha(beker[i + 1]))
        {
            akt = "\0";
        }
        if (beker[i] == ' ' && isdigit(beker[i + 1]))
        {
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