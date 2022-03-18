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
            // String to int konverzió STOI használata nélkül => STOI nem működik! Plusz fejléc: #include <sstream>
            stringstream darab(aktdb);
            darab >> db;
        }

        if (akt == "LEENGED")
        {
            rajzol = true;
            cout << "Rajzol? => IGEN!" << endl;
        }
        if (akt == "FELEMEL")
        {
            rajzol = false;
            cout << "Rajzol? => NEM!" << endl;
        }

        if (akt == "BALRA" && beker[i + 1] == ' ')
        {
            for (int j = 0; j < db; j++)
            {
                if (y == OSZL)
                    y -= OSZL;
                if (y >= 0)
                {
                    cout << "BALRA" << endl;
                    y--;
                    if (rajzol == true)
                    {
                        cout << "BALRA RAJZOLT!" << endl;
                        vaszon[x][y] = 'X';
                    }
                }
            }
        }
        if (akt == "JOBBRA" && beker[i + 1] == ' ')
        {
            for (int j = 0; j < db; j++)
            {
                if (y == OSZL)
                    y -= OSZL;
                if (y >= 0)
                {
                    cout << "JOBBRA" << endl;
                    y++;
                    if (rajzol == true)
                    {
                        cout << "JOBBRA RAJZOLT!" << endl;
                        vaszon[x][y] = 'X';
                    }
                }
            }
        }
        if (akt == "FEL" && beker[i + 1] == ' ')
        {
            for (int j = 0; j < db; j++)
            {
                if (x == OSZL)
                    x -= OSZL;
                if (x >= 0)
                {
                    cout << "FEL" << endl;
                    x--;
                    if (rajzol == true)
                    {
                        cout << "FEL RAJZOLT!" << endl;
                        vaszon[x][y] = 'X';
                    }
                }
            }
        }
        if (akt == "LE" && beker[i + 1] == ' ')
        {
            for (int j = 0; j < db; j++)
            {
                if (x == OSZL)
                    x -= OSZL;
                if (x >= 0)
                {
                    cout << "LE" << endl;
                    x++;
                    if (rajzol == true)
                    {
                        cout << "LE RAJZOLT!" << endl;
                        vaszon[x][y] = 'X';
                    }
                }
            }
        }

        // Pozíció független rajzolás
        if (rajzol == true && vaszon[x][y] != 'X')
        {
            cout << "POZ. FÜGG. RAJZOLT!" << endl;
            vaszon[x][y] = 'X';
        }

        // SPACE
        if (beker[i] == ' ' && (isalpha(beker[i + 1]))) // Mostani elem SPACE, következő elem nem szám vagy nem space
        {
            cout << "A következő elem betű, szó buffer ürítés..." << endl;
            akt = "\0";
        }
        if (beker[i] == ' ' && (isdigit(beker[i + 1])))
        {
            cout << "A következő elem szám, szám buffer ürítés..." << endl;
            aktdb = "\0";
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
    cout << "\nA BEMENET: " << beker << "\n"
         << endl;

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