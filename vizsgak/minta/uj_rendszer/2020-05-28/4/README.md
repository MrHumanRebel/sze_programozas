Készítsen egy függvényt, ami egy bemenetként kapott 2x2-es mátrixnak kiszámolja a determinánsát.

Emlékeztetőül, a determinánst 2x2-es mátrixon (ahol a mátrix [a b; c d]) az alábbi módon számíthatja ki:

D = a*d - c*b

Ellenőrizze, hogy a mátrix megfelelő méretű-e, vagyis pontosan 2x2-es.
Ha nem megfelelő a mátrix mérete, akkor térjen vissza 0-as értékkel!

For example:

Test	Result
double** m1;
m1 = newMatrix(2, 2);
m1[0][0] = 1;	m1[0][1] = 0;
m1[1][0] = 0;	m1[1][1] = 1;
double det = determinant2x2(m1, 2, 2);
std::cout << "Determináns: " << det << '\n';
deleteMatrix(m1, 2);
Determináns: 1


double determinant2x2(double** mtx, const int dimr, const int dimc)
{
    return -1024.0;
}