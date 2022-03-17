#include <iostream>
using namespace std;

// Vászon mérete
#define SOR 10
#define OSZL 10
// Ceruza le-fel
#define FEL "FELEMEL"
#define LE "LEENGED"
// Ceruza mozgatás
#define LEFT "BALRA"
#define RIGHT "JOBBRA"
#define UP "FEL"
#define DOWN "LE"

// Globális változók
bool van_e_alap = false;
bool rajzol = false;
char vaszon[SOR][OSZL];
int x = 0, y = 0; //"X" Függőleges "Y" Vízszintes
string beker;

void mozog()
{
    string akt;
    string aktdb;
    int db;
    for (long unsigned int i = 0; i <= beker.length(); i++)
    {
        // BETŰ
        if (beker[i] != ' ' && isalpha(beker[i]))
        {
            akt += beker[i];
            cout << "BETŰ\t" << akt << endl;
        }
        // SZÁM
        if (beker[i] != ' ' && isdigit(beker[i]))
        {
            aktdb += beker[i];
            cout << "SZÁM\t" << aktdb << endl;
        }
        else
        {
            // String to int konverzió STOI használata nélkül => STOI nem működik!
            int hossz = aktdb.length();
            for (int i = 0; i < hossz; i++)
                db = db * 10 + (int(beker[i]) - 48);
        }

        // A SPACE
        if (beker[i] == ' ')
        {
            aktdb = "\0";
            akt = "\0";
            db = 0;
        }

        if (akt == LE)
            rajzol = true;
        if (akt == FEL)
            rajzol = false;

        if (akt == LEFT)
        {
            for (int j = 0; j < db; j++)
            {
                if (y <= 0 && y <= OSZL)
                {
                    y++;
                    if (rajzol == true)
                        vaszon[x][y] = 'X';
                }
            }
        }
        if (akt == RIGHT)
        {
            for (int j = 0; j < db; j++)
            {
                if (y <= 0 && y <= OSZL)
                {
                    y--;
                    if (rajzol == true)
                        vaszon[x][y] = 'X';
                }
            }
        }
        if (akt == UP)
        {
            for (int j = 0; j < db; j++)
            {
                if (x <= 0 && x <= OSZL)
                {
                    x++;
                    if (rajzol == true)
                        vaszon[x][y] = 'X';
                }
            }
        }
        if (akt == DOWN)
        {
            for (int j = 0; j < db; j++)
            {
                if (x <= 0 && x <= OSZL)
                {
                    x--;
                    if (rajzol == true)
                        vaszon[x][y] = 'X';
                }
            }
        }
    }
}

void alapvaszon()
{
    for (int i = 0; i <= SOR; i++)
    {
        for (int j = 0; j <= OSZL; j++)
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
    getline(cin, beker);
    for (long unsigned int i = 0; i <= beker.length(); i++)
    {
        if (isalpha(beker[i]))
        {
            beker[i] = toupper(beker[i]);
        }
    }
    cout << "\nA BEMENET: " << beker << "\n"
         << endl;

    return beker;
}

int main()
{
    if (van_e_alap == false)
        alapvaszon();
    megjelenit();
    input();
    mozog();
    megjelenit();
    return 0;
}