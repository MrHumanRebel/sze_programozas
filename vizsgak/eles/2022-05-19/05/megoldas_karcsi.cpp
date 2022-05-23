#include <iostream>
#include <fstream>

using namespace std;

string first_last(string fbe, string fki)
{
  ifstream bemenet(fbe);
  if (bemenet.is_open())
  {
    string aktSor;

    getline(bemenet, aktSor);
    int szerzokDb = stoi(aktSor);
    string szerzok[szerzokDb][szerzokDb];

    int i = 0;
    while (getline(bemenet, aktSor))
    {
      int szokozHelye = aktSor.find_last_of(' ');

      szerzok[i][0] = aktSor.substr(0, szokozHelye);
      szerzok[i][1] = aktSor.substr(szokozHelye + 1);

      i++;
    }

    ofstream kimenet(fki);
    for (int i = 0; i < szerzokDb; i++)
    {
      string keresztNevek = szerzok[i][0];
      szerzok[i][0] = szerzok[i][1] + ",";
      szerzok[i][1] = keresztNevek;

      cout << szerzok[i][0] << " " << szerzok[i][1] << endl;
      kimenet << szerzok[i][0] << " " << szerzok[i][1] << endl;
    }

    return "Hibátlan futás!";
  }
  else
  {
    cout << "Sikertelen file-nyitás" << endl;
  }

  return "-1";
}

int main()
{
  string ki = first_last("Writer.txt", "Sretirw.txt");
  cout << ki;

  return 0;
}
