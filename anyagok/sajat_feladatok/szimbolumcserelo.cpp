#include <iostream>
using namespace std;

string tabla[5]{"Gizi", "piros", "kutya", "bicikli", "Karakoszorcsog"};
string input = 0;
string uzenet = 0;

void dekod()
{
    for (long unsigned int i = 0; i <= input.length(); i++)
    {

        if (input[i] == '$')
        {
            if (input[i + 1] == 'n' && input[i + 2] == 'e' && input[i + 3] == 'v' && input[i + 4] == '$')
            {
                uzenet + tabla[1];
            }
        }
        else
            uzenet = uzenet + input[i];
    }
}

void beolv()
{

    cout << "Adja meg az üzenet szavait \"[vege]\" végjelig!" << endl;
    cin >> input;
    dekod();
}

int main()
{
    beolv();
    cout << uzenet;
    return 0;
}