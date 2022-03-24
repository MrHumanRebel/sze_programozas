#include <iostream>
#include <cstring>
using namespace std;

#define TELL cout <<
#define ASK cin >>

// Szia $nev$! Lattalak $telepules$ fele menet, amint hajtottad a $szin$ $jarmu$det, a $allat$ pedig kergetett. Sok $$-t adtam volna akkor es ott egy fenykepezogepert :) [vege]
// Szevasz $nev$!!! Néztem tegnap este a $allat$-ról szóló kisfilmet a Duna TV-n, $telepules$-en egy $jarmu$ elütötte a $szin$ színű buzit. Sok $$-t adtam volna hogy felvegyem, a $allat$t. [vege] ksufhkuhfhk

string beilleszt[5]{"Gizi", "piros", "kutya", "bicikli", "Karakoszorcsog"};
string karsorozat[6]{"nev", "szin", "allat", "jarmu", "telepules", "vege"};
string uzenet = "\0", input = "\0", cserel = "\0";

void dekod()
{

    for (long unsigned int i = 0; i < input.length(); i++)
    {
        cserel = "\0";
        if (input[i] == '[')
        {
            i++;
            while (input[i] != ']')
            {
                cserel += input[i];
                i++;
            }
        }
        if (cserel == karsorozat[5])
            return;

        if (input[i] == '$')
        {
            if (input[i + 1] == '$')
            {
                int rszam = rand() % 9999;
                uzenet += to_string(rszam);
            }

            i++;
            while (input[i] != '$')
            {
                cserel += input[i];
                i++;
            }

            for (int j = 0; j <= 4; j++)
            {
                if (cserel == karsorozat[j])
                    uzenet += beilleszt[j];
            }
        }
        else
        {
            uzenet += input[i];
        }
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