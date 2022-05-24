Készítsen programot, ami dinamikusan allokált mátrixokat ad össze (addMatrix). Emlékeztetőül a szabály az összeadásra:


Az oszlopok és sorok száma mindkét mátrixnál megegyezik.
Elemenként adunk össze.
Amennyiben négyzetes a két mátrix, az eredményen számítsa ki a nyomvonalat (spurt), vagyis a főátló elemeinek összegét. Ha nem négyzetes, térjen vissza 0 eredménnyel!


A mátrixok létrehozásával függvényen belül nem kell foglalkozni.


TIPP: a fejléc legyen a következő


double addMatrix(double** mtx1, const int dimr1, const int dimc1, double** mtx2, const int dimr2, const int dimc2, double** res)


For example:

Test	Result
double** n0 = newMatrix(3, 2);
double** n1 = newMatrix(3, 2);
n0[0][0] = 2; n0[0][1] = 2;
n0[1][0] = 4; n0[1][1] = 5;
n0[2][0] = 1; n0[2][1] = 3;

n1[0][0] = 1; n1[0][1] = 1;
n1[1][0] = 4; n1[1][1] = 2;
n1[2][0] = 8; n1[2][1] = 7;

double** n2 = newMatrix(3, 2);
double spur = addMatrix(n0, 3, 2, n1, 3, 2, n2);
printMatrix(n2, 3, 2);
std::cout << "Spur: " << spur << '\n';
deleteMatrix(n0, 3);
deleteMatrix(n1, 3);
deleteMatrix(n2, 3);
3,3
8,7
9,10
Spur: 0
double** n0 = newMatrix(2, 2);
double** n1 = newMatrix(2, 2);
n0[0][0] = 2; n0[0][1] = 2;
n0[1][0] = 4; n0[1][1] = 5;

n1[0][0] = 1; n1[0][1] = 1;
n1[1][0] = 4; n1[1][1] = 2;

double** n2 = newMatrix(2, 2);
double spur = addMatrix(n0, 2, 2, n1, 2, 2, n2);
printMatrix(n2, 2, 2);
std::cout << "Spur: " << spur << '\n';
deleteMatrix(n0, 2);
deleteMatrix(n1, 2);
deleteMatrix(n2, 2);
3,3
8,7
Spur: 10


double addMatrix(
	double** mtx1, const int dimr1, const int dimc1,
	double** mtx2, const int dimr2, const int dimc2,
	double** res)
{
    return -1024.0;
}
