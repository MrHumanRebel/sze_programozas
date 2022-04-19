#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

string kod, uzenet, ujkod, ujuzenet;
char kodtabla[12][6]{
    {'.', ',', '-', '?', '!', '1'},
    {'A', 'B', 'C', '2'},
    {'D', 'E', 'F', '3'},
    {'G', 'H', 'I', '4'},
    {'J', 'K', 'L', '5'},
    {'M', 'N', 'O', '6'},
    {'P', 'Q', 'R', 'S', '7'},
    {'T', 'U', 'V', '8'},
    {'W', 'X', 'Y', 'Z', '9'},
    {'\0'},
    {'+', '0'},
    {' ', '#'}};
int kodtablameret[12]{6, 4, 4, 4, 4, 4, 5, 4, 5, 1, 2, 2};

string decode()
{
    int szamlalo = 0;
    int akt;
    for (size_t i = 0; i <= kod.length(); i++)
    {
        bool nemjo = false;
        if (kod[i] == '1')
            akt = 0;
        else if (kod[i] == '2')
            akt = 1;
        else if (kod[i] == '3')
            akt = 2;
        else if (kod[i] == '4')
            akt = 3;
        else if (kod[i] == '5')
            akt = 4;
        else if (kod[i] == '6')
            akt = 5;
        else if (kod[i] == '7')
            akt = 6;
        else if (kod[i] == '8')
            akt = 7;
        else if (kod[i] == '9')
            akt = 8;
        else if (kod[i] == '*')
            akt = 9;
        else if (kod[i] == '0')
            akt = 10;
        else if (kod[i] == '#')
            akt = 11;
        else if (kod[i] == ' ')
        { // bug protection only
        }
        else
            nemjo = true;

        if (nemjo == false)
        {
            if (kod[i] == kod[i + 1]) // karakter db számláló
            {
                szamlalo++;
            }
            else if (kod[i + 1] == ' ') // space karakterek lekezelése
            {
                uzenet += "\0";
                szamlalo = 0;
            }
            else
            {
                if ((kod[i] != kod[i + 1] && kod[i + 1] == '*') or
                    (szamlalo == 1 && kod[i + 2] == '*') or
                    (szamlalo == 2 && kod[i + 3] == '*') or
                    (szamlalo == 3 && kod[i + 4] == '*') or
                    (szamlalo == 4 && kod[i + 5] == '*')) // nagybetűs kondíciók
                {
                    uzenet += kodtabla[akt][szamlalo];
                    szamlalo = 0;
                }
                else
                {
                    uzenet += tolower(kodtabla[akt][szamlalo]);
                    szamlalo = 0;
                }
            }
        }
    }
    return uzenet;
}

string olvasas()
{
    string filename;
    ifstream kodsorozat;
    kodsorozat >> std::noskipws;
    filename = "/home/szeke/uni/sze_programozas/anyagok/vizsgafeladatok_dani/smskod.txt"; //"/mnt/c/Users/szeke/uni/sze_programozas/anyagok/vizsgafeladatok_dani/smskod.txt";
    /*cout << "Adja meg a dekódolandó kódsorozatot tartalmazó fájl elérési útját! " << endl;
    getline(cin, filename);*/
    kodsorozat.open(filename);
    if (!kodsorozat.is_open())
    {
        cout << "Ilyen fájl nem létezik!" << endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        getline(kodsorozat, kod);
        kodsorozat.close();
    }
    return kod;
}

string iras()
{
    ofstream uzenetki;
    string irashely;
    /*cout << "Adja meg a dekodolt üzenetet tartalmazó fájl kívánt elérési útját! " << endl;
    getline(cin, irashely); */
    irashely = "/home/szeke/uni/sze_programozas/anyagok/vizsgafeladatok_dani/szoveg.txt"; //"/mnt/c/Users/szeke/uni/sze_programozas/anyagok/vizsgafeladatok_dani/szoveg.txt";
    uzenetki.open(irashely);
    uzenetki << uzenet;
    uzenetki.close();
    return uzenet;
}

string beker()
{
    uzenet = "\0";
    cout << "\nAdja meg a kódolandó szöveget!" << endl;
    getline(cin, ujuzenet);
    return ujuzenet;
}

string code()
{
    bool megvan = false;
    for (size_t i = 0; i < ujuzenet.length(); i++)
    {
        bool lower = false;
        if (islower(ujuzenet[i]))
        {
            lower = true;
            ujuzenet[i] = toupper(ujuzenet[i]);
        }
        megvan = false;
        for (int j = 0; j < 12; j++)
        {
            for (int k = 0; k < 6; k++)
            {
                if (ujuzenet[i] == kodtabla[j][k] && megvan == false)
                {
                    megvan = true;
                    if (ujuzenet[i] == ' ')
                        ujkod += '#';
                    else
                    {
                        if (k != 0)
                        {
                            for (int l = 0; l <= k; l++)
                            {
                                ujkod += to_string(j + 1);
                            }
                        }
                        else
                        {
                            ujkod += to_string(j + 1);
                        }
                        if (isupper(ujuzenet[i]) && lower == false)
                            ujkod += '*';
                    }
                    if (ujuzenet[i] == ujuzenet[i + 1])
                        ujkod += ' ';
                }
            }
        }
    }
    return ujkod;
}

int main()
{
    // Decode
    olvasas();
    decode();
    cout << uzenet;
    iras();
    // Code
    beker();
    code();
    cout << ujkod;
    return 0;
}