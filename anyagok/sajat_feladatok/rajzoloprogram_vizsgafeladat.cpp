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
    for (long unsigned int i = 0; i <= beker.length(); i++)
    {
        bool stop = false;
        while (stop == false)
        {
            if (beker[i] != ' ')
            {
                akt += beker[i];
            }
            else
                stop = true;
        }
        if (akt == LE)
            rajzol = true;
        if (akt == FEL)
            rajzol = false;
        if (akt == LEFT)
            y++;
        if (akt == RIGHT)
            y--;
        if (akt == UP)
            x++;
        if (akt == DOWN)
            x--;
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