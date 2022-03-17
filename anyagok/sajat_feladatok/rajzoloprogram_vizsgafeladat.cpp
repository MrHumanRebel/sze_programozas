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
int x = 0, y = 0; //"X" Függőleges "Y" Vízszintes
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
            cout << "RÉGI DARAB: " << db << "\t";
            db = 0;
            stringstream darab(aktdb);
            darab >> db;
            cout << "ÚJ DARAB: " << db << endl;
        }

        // A SPACE
        if (beker[i] == ' ')
        {
            aktdb = "\0";
            akt = "\0";
        }

        if (akt == "LEENGED")
            rajzol = true;
        if (akt == "FELEMEL")
            rajzol = false;

        if (akt == "BALRA")
        {
            for (int j = 0; j < db; j++)
            {
                cout << "IN FOR CYCLE..." << endl;
                if (y >= 0 && y <= OSZL)
                {
                    cout << "y OK!!!" << endl;
                    y++;
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
                    cout << "y OK!!!" << endl;
                    y--;
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
                    cout << "x OK!!!" << endl;
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
                    cout << "x OK!!!" << endl;
                    x--;
                    if (rajzol == true)
                    {
                        cout << "LE RAJZOLT!" << endl;
                        vaszon[x][y] = 'X';
                    }
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