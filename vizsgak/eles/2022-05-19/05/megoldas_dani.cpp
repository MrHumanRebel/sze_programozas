#include <iostream>
#include <fstream>

using namespace std;

#define MAX 16

// BETA VERSION
//  NOT WORKING

string first_last(string fbe, string fki)
{
    string nevek[MAX][MAX];

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            nevek[i][j] = "\0";
        }
    }

    int i = 0;
    int j = 0;
    ifstream fajl(fbe);
    string aktSor;
    int adatdb = 0;
    if (fajl.is_open())
    {
        while (getline(fajl, aktSor))
        {

            if (isdigit(aktSor[0]) == true)
            {
                adatdb = stoi(aktSor);
                i++;
                // cout << adatdb << endl;
            }
            else
            {
                string id1;
                string id2;
                string id3;
                string id4;
                int aktsorhossz = aktSor.length();

                int spacehelye = aktSor.find(' ');
                int spacecounter = 1;

                id1 = aktSor.substr(0, spacehelye);
                spacehelye++;

                int kardb = aktSor.find(' ', spacehelye) - spacehelye;
                spacecounter++;

                id2 = aktSor.substr(spacehelye, kardb);

                spacehelye += kardb + 1;

                if (spacehelye < aktsorhossz)
                {
                    kardb = aktSor.find(' ', spacehelye) - spacehelye;
                    spacecounter++;

                    id3 = aktSor.substr(spacehelye, kardb);
                }

                spacehelye += kardb + 1;

                if (spacehelye < aktsorhossz)
                {
                    kardb = aktSor.find(' ', spacehelye) - spacehelye;
                    spacecounter++;

                    id4 = aktSor.substr(spacehelye, kardb);
                }

                // Különböző névhosszok

                if (spacecounter == 1)
                {
                    nevek[i][j] += id1;
                    j++;
                    nevek[i][j] += id2;
                }
                else if (spacecounter == 2)
                {
                    nevek[i][j] += id1;
                    if (id1 != id2)
                    {
                        nevek[i][j] += " ";
                        nevek[i][j] += id2;
                        j++;
                    }
                    if (id1 != id3 && id2 != id3)
                    {
                        nevek[i][j] += " ";
                        nevek[i][j] += id3;
                    }
                }

                for (int i = 0; i < adatdb; i++)
                {
                    for (int j = 0; j < adatdb; j++)
                    {
                        if (nevek[i][j] != "\0")
                            cout << nevek[i][j];
                    }
                }

                // cout << id1 << " " << id2 << " " << id3 << " " << id4 << endl;
            }
        }
        i++;
    }
    else
    {
        cout << "A fájl nem létezik!" << endl;
    }
    return "\0";
}

int main()
{
    first_last("/home/szeke/uni/sze_programozas/vizsgak/eles/2022-05-19/05/Writers.txt",
               "/home/szeke/uni/sze_programozas/vizsgak/eles/2022-05-19/05/Sretirw.txt");
    return 0;
}