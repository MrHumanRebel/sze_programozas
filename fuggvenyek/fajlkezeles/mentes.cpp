/* Random (igazából nem) adatok kiírása fájlba, opcionális fájlnév paraméterrel (parancssor) */
#include <fstream>
using namespace std;

#define ADATOK_N 10
#define DEF_FN "kimenet.txt"

/* Egy egyszerű metódus, amivel feltöltjük a kiirandó tömböt  */
void adatokGeneral(int adatok[], int meret)
{
  for (int i = 0; i < meret; i++)
  {
    adatok[i] = i;
  }
}

void adatokKiir(int adatok[], int meret, string fajlnev)
{
  ofstream fajl(fajlnev);
  if (fajl.is_open())
  {
    for (int i = 0; i < meret; i++)
    {
      // Soronként egy szám
      fajl << adatok[i] << endl;
    }

    fajl.close();
  }
}

int main(int argc, char const *argv[])
{
  int kimenet[ADATOK_N];
  adatokGeneral(kimenet, ADATOK_N);

  /* Magyarázat:
     Ha pontosan (!) 2 db argumentum van (értsd: maga a program és fájlnév),
     akkor az argv tömb 2. eleme lesz a fajlnev változó értéke,
     ellenkező esetben a DEF_FN konstans lesz
  */
  string fajlnev = argc == 2 ? argv[1] : DEF_FN;
  adatokKiir(kimenet, ADATOK_N, fajlnev);

  return 0;
}
