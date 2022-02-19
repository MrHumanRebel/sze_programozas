#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
    ifstream nevek;
    // cin.getline(filename, 50);
    const char *filename = "E:\Downloads\names.txt";
    nevek.open(filename);
    if (!nevek.is_open())
    {
        exit(EXIT_FAILURE);
    }

    char akt[50];
    nevek >> akt;
    while (nevek.good())
    {
        cout << akt << "\t" << endl;
        nevek >> akt;
    }

    return 0;
}