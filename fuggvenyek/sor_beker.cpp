#include <iostream>
#include <cstring>
using namespace std;
#define TELL cout <<
#define ASK cin >>

string beolv()
{
    cout << "Adja meg a szöveget \"[vege]\" végjelig!" << endl;
    string input;
    getline(cin, input);
    return input;
}

int main()
{
    TELL beolv();
    return 0;
}