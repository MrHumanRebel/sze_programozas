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

//"X" Vízszintes "Y" Függőleges
int x = 1;
int y = 1;

string beker;

void mozog()
{
    string akt;
    string aktdb;
    int db = 0;
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
            // String to int konverzió STOI használata nélkül => STOI nem működik! Plusz fejléc: #include <sstream>
            stringstream darab(aktdb);
            darab >> db;
        }

        if (akt == "LEENGED")
        {
            rajzol = true;
            cout << "Rajzol => IGEN!" << endl;
        }
        if (akt == "FELEMEL")
        {
            rajzol = false;
            cout << "Rajzol => NEM!" << endl;
        }

        if (akt == "BALRA")
        {
            for (int j = 0; j < db; j++)
            {
                if (y >= 0 && y <= OSZL)
                {
                    cout << "BALRA OK!!!" << endl;
                    y--;
                    if (rajzol == true)
                    {
                        cout << "BALRA RAJZOLT!" << endl;
                        vaszon[x][y] = 'X';
                    }
                }
            }
        }
        if (akt == "JOBBRA")
        {
            for (int j = 0; j < db; j++)
            {
                if (y >= 0 && y <= OSZL)
                {
                    cout << "JOBBRA OK!!!" << endl;
                    y++;
                    if (rajzol == true)
                    {
                        cout << "JOBBRA RAJZOLT!" << endl;
                        vaszon[x][y] = 'X';
                    }
                }
            }
        }
        if (akt == "FEL")
        {
            for (int j = 0; j < db; j++)
            {
                if (x >= 0 && x <= OSZL)
                {
                    cout << "FEL OK!!!" << endl;
                    x++;
                    if (rajzol == true)
                    {
                        cout << "FEL RAJZOLT!" << endl;
                        vaszon[x][y] = 'X';
                    }
                }
            }
        }
        if (akt == "LE")
        {
            for (int j = 0; j < db; j++)
            {
                if (x >= 0 && x <= OSZL)
                {
                    cout << "LE OK!!!" << endl;
                    x--;
                    if (rajzol == true)
                    {
                        cout << "LE RAJZOLT!" << endl;
                        vaszon[x][y] = 'X';
                    }
                }
            }
        }

        if (rajzol == true)
        {
            cout << "RAJZOLT!" << endl;
            vaszon[x][y] = 'X';
        }
        // SPACE
        if (beker[i] == ' ' && !isdigit(beker[i + 1]))
        {
            cout << "A következő elem NEM szám, szó buffer ürítés..." << endl;
            akt = "\0";
        }
        if (beker[i] == ' ')
        {
            cout << "A mostani elem space, szám buffer ürítés..." << endl;
            aktdb = "\0";
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