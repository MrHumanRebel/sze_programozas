#include <iostream>
#include <fstream>

using namespace std;

string first_last(string fbe, string fki)
{
    // Beolvas
    ifstream fajl(fbe);
    if (fajl.is_open())
    {
        string aktSor;

        getline(fajl, aktSor);
        int adatdb = stoi(aktSor);
        string adat[adatdb][adatdb];
        for (int i = 0; i < adatdb; i++)
        {
            for (int j = 0; j < adatdb; j++)
            {
                adat[i][j] = "\0";
            }
        }

        int i = 0;
        while (getline(fajl, aktSor))
        {
            int spacehelye = aktSor.find_last_of(' ');

            adat[i][0] = aktSor.substr(0, spacehelye);  // Vezezéknél tárolása
            adat[i][1] = aktSor.substr(spacehelye + 1); // Maradék összes karakter tárolása, azaz keresztnevek

            i++;
        }

        // Kiir
        ofstream kimenet(fki);
        for (int i = 0; i < adatdb; i++)
        {
            string aktvezetek = adat[i][0];
            string aktkereszt = "\0";

            for (size_t j = 0; j < (adat[i][1].length() - 1); j++) //Így tűnik el a "\r" a stringből
            {
                aktkereszt += adat[i][1][j];
            }
            string akt = aktkereszt + ", " + aktvezetek;

            cout << akt << endl;
            kimenet << akt << endl;
        }

        return "Hibátlan futás!";
    }
    else
    {
        cout << "Sikertelen file-nyitás!" << endl;
        return "\0";
    }
}

int main()
{
    string ki = first_last("/home/szeke/uni/sze_programozas/vizsgak/eles/2022-05-19/05/Writers.txt",
                           "/home/szeke/uni/sze_programozas/vizsgak/eles/2022-05-19/05/Sretirw.txt");
    cout << ki;

    return 0;
}