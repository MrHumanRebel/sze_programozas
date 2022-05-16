#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void gyorskeres(vector<int> tomb, int mitkeres)
{
    int bal = 0;
    int hossz = tomb.size();
    int pozicio = -1;
    int jobb = hossz - 1;
    for (bal = 0; bal <= jobb;)
    {
        if (tomb[bal] == mitkeres)
        {
            pozicio = bal;
            cout << "Találat: "
                 << pozicio + 1 << " Pozíciónál "
                 << bal + 1 << ". alkalommal";
            break;
        }

        if (tomb[jobb] == mitkeres)
        {
            pozicio = jobb;
            cout << "Találat: "
                 << pozicio + 1 << ". pozíciónál "
                 << hossz - jobb << ". alkalommal";
            break;
        }
        bal++;
        jobb--;
    }
    if (pozicio == -1)
        cout << "Nincs találat! "
             << bal << ". alkalommal";
}

int main()
{
    vector<int> tomb{1, 2, 3, 4, 5};
    int mitkeres = 5;
    gyorskeres(tomb, mitkeres);
}