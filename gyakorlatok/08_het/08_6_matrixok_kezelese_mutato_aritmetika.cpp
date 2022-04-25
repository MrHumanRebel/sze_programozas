/***************************************************************************************/
// 8/3/S1 Mátrixok kezelése mutató aritmetikával/indirekcióval(közvetve)

void kiir(const char (*szk)[OP], char m[][OP], bool mit)
{
    int j;
    char t;
    string io;
    if (mit)
        io = " alap ";
    else
        io = " monogram ";
    for (int i = 0; i < SR; i++)
    {
        cout << "\n A(z)" << io << "mátrix " << i + 1 << ". eleme: "
             << *(szk + i); // szk, (*szk), (*szk)+i != *(szk+i)!!!
        if (mit)
        {
            m[i][0] = (*(szk + i))[0];
            m[i][1] = '.';
            m[i][2] = ' ';
            t = '!';
            for (j = 0; t != ' '; j++)
            {
                t = (*(szk + i))[j];
            }
            m[i][3] = (*(szk + i))[j];
            m[i][4] = '.';
            m[i][5] = '\0';
        }
    }
}
/******************/
// 8/3/S2 Mátrixok kezelése mutató aritmetikával/indirekcióval(közvetve)

void kiir(const char (*szk)[OP], char m[][OP], bool mit)
{
    int j;
    char t;
    string io;
    if (mit)
        io = " alap ";
    else
        io = " monogram ";
    for (int i = 0; i < SR; i++)
    {
        cout << "\n A(z)" << io << "mátrix " << i + 1 << ". eleme: "
             << *(szk + i); // szk, (*szk), (*szk)+i != *(szk+i)!!!
        if (mit)
        {
            m[i][0] = *((*(szk + i)) + 0);
            m[i][1] = '.';
            m[i][2] = ' ';
            t = '!';
            for (j = 0; t != ' '; j++)
            {
                t = *((*(szk + i)) + j);
            }
            m[i][3] = *((*(szk + i)) + j);
            m[i][4] = '.';
            m[i][5] = '\0';
        }
    }
}
/******************/
// 8/3/S3 Mátrixok kezelése mutató aritmetikával/indirekcióval(közvetve)

void kiir(const char (*szk)[OP], char (*m)[OP], bool mit)
{
    int j;
    char t;
    string io;
    if (mit)
        io = " alap ";
    else
        io = " monogram ";
    for (int i = 0; i < SR; i++)
    {
        cout << "\n A(z)" << io << "mátrix " << i + 1 << ". eleme: "
             << *(szk + i); // szk, (*szk), (*szk)+i != *(szk+i)!!!
        if (mit)
        {
            *((*(m + i)) + 0) = *((*(szk + i)) + 0);
            *((*(m + i)) + 1) = '.';
            *((*(m + i)) + 2) = ' ';
            t = '!';
            for (j = 0; t != ' '; j++)
            {
                t = *((*(szk + i)) + j);
            }
            *((*(m + i)) + 3) = *((*(szk + i)) + j);
            *((*(m + i)) + 4) = '.';
            *((*(m + i)) + 5) = '\0';
        }
    }
}