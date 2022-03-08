#include <iostream>
#include <cstring>
using namespace std;

string tabla[5]{"Gizi", "piros", "kutya", "bicikli", "Karakoszorcsog"};
string input = "";
string uzenet = "";
int rszam;

int dekod()
{
    for (long unsigned int i = 0; i <= input.length(); i++)
    {

        if (input[i] == '$')
        {
            // nev
            if (input[i + 1] == 'n' && input[i + 2] == 'e' && input[i + 3] == 'v' && input[i + 4] == '$')
            {
                uzenet += tabla[0];
                i += tabla[0].length();
            }
            // szin
            if (input[i + 1] == 's' && input[i + 2] == 'z' && input[i + 3] == 'i' && input[i + 4] == 'n' && input[i + 5] == '$')
            {
                uzenet += tabla[1];
                i += tabla[1].length();
            }
            // allat
            if (input[i + 1] == 'a' && input[i + 2] == 'l' && input[i + 3] == 'l' && input[i + 4] == 'a' && input[i + 5] == 't' && input[i + 6] == '$')
            {
                uzenet += tabla[2];
                i += tabla[2].length();
            }
            // jarmu
            if (input[i + 1] == 'j' && input[i + 2] == 'a' && input[i + 3] == 'r' && input[i + 4] == 'm' && input[i + 5] == 'u' && input[i + 6] == '$')
            {
                uzenet += tabla[3];
                i += tabla[3].length();
            }
            // telepules
            if (input[i + 1] == 't' && input[i + 2] == 'e' && input[i + 3] == 'l' && input[i + 4] == 'e' && input[i + 5] == 'p' && input[i + 6] == 'u' && input[i + 7] == 'l' && input[i + 8] == 'e' && input[i + 9] == 's' && input[i + 10] == '$')
            {
                uzenet += tabla[4];
                i += tabla[4].length();
            }
            // randomszam
            if (input[i + 1] == '$')
            {
                rszam = rand() % 9999;
                uzenet += to_string(rszam);
                i += sizeof(rszam);
            }
        }
        else if (input[i] == '[' && input[i + 1] == 'v' && input[i + 2] == 'e' && input[i + 3] == 'g' && input[i + 4] == 'e' && input[i + 5] == ']')
        {
            return 0;
        }
        else
            uzenet += input[i];
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