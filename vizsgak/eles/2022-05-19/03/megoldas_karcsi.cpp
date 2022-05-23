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

void buborekrendez(triathlete versenyzok[], int db)
{
  for (int i = db - 1; i >= 1; i--)
  {
    for (int j = 0; j < i; j++)
    {
      if (versenyzok[j].sum > versenyzok[j + 1].sum)
      {
        triathlete csere = versenyzok[j];
        versenyzok[j] = versenyzok[j + 1];
        versenyzok[j + 1] = csere;
      }
    }
  }
}

string mpIdobelyegge(int sum)
{
  int ora, perc, mp;

  perc = int((sum / 60) % 60);
  ora = int(perc / 60);
  mp = int(sum % 60);

  string eredmeny = to_string(ora) + ":" + to_string(perc) + ":" + to_string(mp);
  return eredmeny;
}

string tri_result(string fbe)
{
  string eredmeny = "N/A!";

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

    buborekrendez(versenyzok, versenyzokDb);

    cout << versenyzok[0].lic << " => " << mpIdobelyegge(versenyzok[0].sum) << endl;

    eredmeny = versenyzok[versenyzokDb - 1].lic;
  }
  else
  {
    cout << "Sikertelen file-nyitás!" << endl;
  }

  return eredmeny;
}

int main()
{
  string u = tri_result("Chip.txt");
  cout << u;

  return 0;
}
