#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

#define TELL cout <<
#define ASK cin >>

#define MIN 5
#define MAX 20

int random(int tol, int db)
{
    return ((rand() % tol) + db);
}

string jelszogen(int db, int hossz)
{
    int aktdb = 0;
    string jelszo;
    char kisbetu, nagybetu;
    int szam;
    do
    {
        for (int i = 0; i < hossz; i++)
        {
            kisbetu = random(97, 25);
            nagybetu = random(65, 25);
            szam = random(9, 0);
            TELL kisbetu << nagybetu << szam << endl;
        }

        aktdb++;

    } while (aktdb < db);

    return jelszo;
}

int main()
{
    int db, hossz;
    db = 1;
    hossz = 5;
    jelszogen(db, hossz);
    return 0;
}