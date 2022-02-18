#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int menu;
  int db = 1;
  double a, b, max, kerulet, terulet, atlo, alfa, beta, id, rad = 0;
  bool beker, menuker = true;

  cout << "Saját vagy randomizált adatokkal szeretné használni a téglalap kalkulátort?\n"
       << "___________________________________________________________________________________\n\n"
       << "Randomizáláshoz nyomja meg az 1-es gombot!\n"
       << "Adatmegadáshoz nyomja meg a 2-es gombot!" << endl;
  while (menuker)
  {
    cin >> menu;
    if (menu >= 1 && menu < 3)
      menuker = false;
    else
      cout << "Nem valós menüpont!\n";
  }

  if (menu == 1)
  {
    do
    {
      a = rand() % 25 + 5;
      max = a;
      b = rand() % 10 + 3;
      if (b > max)
        max = b;
      if (a > 0 and b > 0)
      {
        cout << "A randomizált téglalap megszerkeszthető!\n"
             << "Már számoljuk is a jellemzőit...\n"
             << endl;
        beker = false;
      }
      else
        db++;
    } while (beker == true);
    cout << "A randomizátor " << db << "-szer futott le mire megszerkeszthető téglalap állt elő!\n"
         << endl;
  }

  if (menu == 2)
  {
    cout << "Adja meg a téglalap oldalait!\n"
         << "_________________________________\n"
         << endl;
    do
    {
      cout << "Adja meg a téglalap első oldalát!" << endl;
      cin >> a;
      max = a;
      cout << "Adja meg a téglalap második oldalát!" << endl;
      cin >> b;
      if (b > max)
        max = b;
      if (a > 0 and b > 0)
      {

        cout << "Ez a téglalap megszerkeszthető!\n"
             << "Már számoljuk is a jellemzőit...\n"
             << endl;
        beker = false;
      }
      else
      {
        cout << "Ez a téglalap nem szerkeszthető meg, adjon meg új adatokat!" << endl;
        db++;
      }
    } while (beker == true);

    cout << "Az adatok az " << db << ". alkalommal tették lehetővé téglalap megszerkesztését!\n"
         << endl;
  }
  cout << "A téglalap a oldalának hossza: " << a << "\n"
       << "A téglalap b oldalának hossza: " << b << "\n"
       << "A téglalap leghosszabb oldalának hossza: " << max << "\n"
       << endl;

  atlo = sqrt((a * a) + (b * b));
  kerulet = 2 * (a + b);
  terulet = a * b;

  cout << "A téglalap kerülete: " << kerulet << "\n"
       << "A téglalap területe: " << terulet << "\n"
       << "A téglalap átlója: " << atlo << "\n"
       << endl;

  id = (a / atlo);
  alfa = asin(id);
  id = (b / atlo);
  beta = asin(id);

  // Radián átváltás fokba
  rad = 57.2957795131; // 180.0 / 3.141592653589793238463
  cout << rad;
  alfa = alfa * rad * 2;
  beta = beta * rad * 2;

  cout << "A téglalap alfa átló által bezárt szöge: " << alfa << "\n"
       << "A téglalap béta átló által bezárt szöge: " << beta << "\n"
       << endl;

  cout << "A négy szög összege ellenőrzésképpen: " << 2 * alfa + 2 * beta << endl;

  cout << "Minta téglalap printelése...\n"
       << endl;

  // felső sor print
  for (int i = 1; i <= b; i++)
  {
    cout << "*";
    cout << "\t";
  }

  // sor ugrás
  cout << "\n";

  // közepe print
  for (int i = 1; i <= a - 2; i++)
  {
    cout << "*";
    for (int j = 1; j <= b - 1; j++)
    {
      cout << "\t";
    }
    cout << "*";
    cout << "\n";
  }

  // alsó sor print

  for (int i = 1; i <= b; i++)
  {
    cout << "*";
    cout << "\t";
  }
  return 0;
}
