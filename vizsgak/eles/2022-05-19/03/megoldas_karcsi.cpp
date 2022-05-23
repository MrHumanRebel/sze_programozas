#include <iostream>
#include <fstream>

using namespace std;

struct triathlete
{
  string lic;
  int swim;
  int cycle;
  int run;
  int depo;
  int sum;
};

string sorKiszed(string &sor, int &szokozHelye)
{
  if (szokozHelye > 0)
    sor = sor.substr(szokozHelye + 1);

  szokozHelye = sor.find(' ');
  string aktElem = sor.substr(0, szokozHelye);

  return aktElem;
}

triathlete versenyzoBeolvas(string aktSor)
{
  triathlete versenyzo;

  int szokozHelye = -1;
  versenyzo.lic = sorKiszed(aktSor, szokozHelye);

  versenyzo.swim = stoi(sorKiszed(aktSor, szokozHelye));
  versenyzo.cycle = stoi(sorKiszed(aktSor, szokozHelye));
  versenyzo.run = stoi(sorKiszed(aktSor, szokozHelye));
  versenyzo.depo = stoi(sorKiszed(aktSor, szokozHelye));

  versenyzo.sum = versenyzo.swim + versenyzo.cycle + versenyzo.run + versenyzo.depo;

  return versenyzo;
}

string mpIdobelyegge(int sum)
{
  int ora, perc, mp;

  perc = int((mp / 60) % 60);
  ora = int(perc / 60);
  mp = int(mp % 60);

  string eredmeny = to_string(ora) + ":" + to_string(perc) + ":" + to_string(mp);
}

string tri_result(string fbe)
{
  ifstream fajl(fbe);
  if (fajl.is_open())
  {
    string aktSor;
    getline(fajl, aktSor);
    int versenyzokDb = stoi(aktSor);

    triathlete versenyzok[versenyzokDb];

    int i = 0;
    while (getline(fajl, aktSor))
    {
      versenyzok[i] = versenyzoBeolvas(aktSor);
      i++;
    }

    int minIndex = 0;
    for (int i = 0; i < versenyzokDb; i++)
    {
      if (versenyzok[minIndex].sum > versenyzok[minIndex].sum)
        minIndex = i;
    }

    cout << versenyzok[minIndex].lic << " => " << mpIdobelyegge(versenyzok[minIndex].sum) << endl;

    return versenyzok[versenyzokDb - 1].lic;
  }
  else
  {
    cout << "Sikertelen file-nyitás!";
    return "N/A!";
  }
}

int main()
{
  string u = tri_result("Chip.txt");
  cout << u;

  return 0;
}
