#include <iostream>
#include <cstring>
using namespace std;

// Szia $nev$! Lattalak $telepules$ fele menet, amint hajtottad a $szin$ $jarmu$det, a $allat$ pedig kergetett. Sok $$-t adtam volna akkor es ott egy fenykepezogepert :) [vege]
// Szevasz $nev$!!! Néztem tegnap este a $allat$-ról szóló kisfilmet a Duna TV-n, $telepules$-en egy $jarmu$ elütötte a $szin$ színű buzit. Sok $$-t adtam volna hogy felvegyem, a $allat$t. [vege]

string input = "";
string uzenet = "";

int dekod()
{
    string akt = "\0";
    string beilleszt[5]{"Gizi", "piros", "kutya", "bicikli", "Karakoszorcsog"};
    string karsorozat[7]{"$nev$", "$szin$", "$allat$", "$jarmu$", "$telepules$", "$$", "[vege]"};
    int rszam;
    bool ok = false;

    for (long unsigned int i = 0; i <= input.length(); i++)
    {
        ok == false;
        if (input[i] != ' ')
        {
            akt += input[i];
            cout << akt << endl;
        }
        else
            akt = "\0";

        for (long unsigned int j = 0; j <= 4; j++)
        {
            if (akt == karsorozat[j])
            {
                uzenet += beilleszt[j];
                ok = true;
            }
        }
        if (ok == false)
        {
            if (akt == karsorozat[5])
            {
                rszam = rand() % 9999;
                uzenet += to_string(rszam);
                ok = true;
            }
            else if (akt == karsorozat[6])
            {
                return 0;
            }
        }
    }
    if (ok == false)
    {
        uzenet += akt;
    }
}

void beolv()
{

    cout << "Adja meg az üzenet szavait \"[vege]\" végjelig!" << endl;
    getline(cin, input); // cin.getline(INPUT),MAXIMUM MÉRET)
    dekod();
}

int main()
{
    beolv();
    cout << uzenet;
    return 0;
}