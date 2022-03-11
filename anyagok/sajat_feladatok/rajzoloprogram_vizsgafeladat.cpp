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
    string db;
    for (long unsigned int i = 0; i <= beker.length(); i++)
    {
        bool stop = false;
        while (stop == false)
        {
            if (beker[i] != ' ' && isalpha(beker[i]))
            {
                akt += beker[i];
            }
            else if (beker[i] != ' ' && isdigit(beker[i]))
            {
                db += beker[i];
            }
            else
                stop = true;
        }
        if (akt == LE)
            rajzol = true;
        if (akt == FEL)
            rajzol = false;
        if (akt == LEFT)
            for (int j = 0; j < stoi(db); j++)
            {
                y++;
                if (rajzol == true)
                    vaszon[x][y] = 'X';
            }
        if (akt == RIGHT)
            for (int j = 0; j < stoi(db); j++)
            {
                y--;
                if (rajzol == true)
                    vaszon[x][y] = 'X';
            }
        if (akt == UP)
            for (int j = 0; j < stoi(db); j++)
            {
                x++;
                if (rajzol == true)
                    vaszon[x][y] = 'X';
            }
        if (akt == DOWN)
            for (int j = 0; j < stoi(db); j++)
            {
                x--;
                if (rajzol == true)
                    vaszon[x][y] = 'X';
            }
        akt = "\0";
        db = "\0";
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

int main()
{
    if (van_e_alap == false)
        alapvaszon();
    megjelenit();
    return 0;
}