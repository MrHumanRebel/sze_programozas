#include <iostream>
#include <math.h>
using namespace std;

#define TELL cout <<
#define ASK cin >>

int main()
{
  TELL "Másodfokú egyenlet kalkulátor" << endl;
  TELL "Amennyiben tiezed törttel számolna, pont operátorral adja meg a számokat. ";
  TELL "(Például: 1.5)" << endl;
  double a, b, c, x1, x2, diszkriminans, komp1, komp2, gyok;
  // Adatok bekérése
  TELL "Adja meg 'a' együtthatót:";
  ASK a;
  TELL "Adja meg 'b' együtthatót:";
  ASK b;
  TELL "Adja meg 'c' együtthatót:";
  ASK c;
  // Az 'a' együttható nem lehet 0 mivel akkor 0-ás osztó keletkezik.
  if (a == 0)
  {
    TELL "Hiba, az egyenlet nem másodfokú. (0-ás osztó!)";
    return 0;
  }
  // Ha a 'b' és 'c' együtthatók nullák, akkor az eredmény 0.
  if ((b == 0) && (c == 0))
  {
    TELL "A feladat megoldása: 0";
    return 0;
  }
  // Az adatokból a képlet kiírása.
  TELL "Az ön által megadott képlet: ";
  if (b >= 0 && c >= 0)
  {
    TELL a << "x^2+" << b << "x+" << c << "=0" << endl;
  }
  else if (b <= 0 && c >= 0)
  {
    TELL a << "x^2" << b << "x+" << c << "=0" << endl;
  }
  else if (b >= 0 && c <= 0)
  {
    TELL a << "x^2+" << b << "x" << c << "=0" << endl;
  }
  else if (b <= 0 && c <= 0)
  {
    TELL a << "x^2" << b << "x" << c << "=0" << endl;
  }
  // Diszkrimináns és a gyökös tag meghatározása.
  diszkriminans = (b * b - 4 * a * c);
  gyok = sqrt(diszkriminans);
  // Ha két megoldása van az egyenletnek:
  if (diszkriminans > 0)
  {
    x1 = (-b + gyok) / (2 * a);
    x2 = (-b - gyok) / (2 * a);
    TELL "Az ön képletének két megoldása:" << endl;
    TELL "X1=" << x1 << endl;
    TELL "X2=" << x2 << endl;
    // Ha egy megoldása van az egyenletnek:
  }
  else if (diszkriminans == 0)
  {
    TELL "Az ön képletének egy megoldása van:" << endl;
    TELL "X1=X2=" << x1;
    // Ha komplex megoldása van az egyenletnek:
  }
  else if (diszkriminans < 0)
  {
    TELL "A gyök alatt negatív szám jött ki:" << diszkriminans << endl;
    komp1 = abs(diszkriminans);
    komp2 = (-b) / (2 * a);
    TELL "Diszkrimináns komplexként: " << sqrt(komp1) << "i" << endl;
    TELL "Az ön képletének komplex megoldásai:" << endl;
    TELL "X1=" << komp2 << "+"
         << "(" << sqrt(-diszkriminans) / (2 * a) << "i"
         << ")" << endl;
    TELL "X2=" << komp2 << "-"
         << "(" << sqrt(-diszkriminans) / (2 * a) << "i"
         << ")" << endl;
  }
  return 0;
}
