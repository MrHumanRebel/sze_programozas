double addMatrix(
	double** mtx1, const int dimr1, const int dimc1,
	double** mtx2, const int dimr2, const int dimc2,
	double** res)
{
	if (dimr1 == dimr2 && dimc1 == dimc2)
	{
		
		for (int i = 0; i < dimr1; i++)
		{
			for (int j = 0; j < dimc1; j++)
			{
				res[i][j] = mtx1[i][j] + mtx2[i][j];
			}
		}
		// Spur számítása
		if (dimr1 == dimc1)
		{
			double spur = 0.0;
			for (int i = 0; i < dimr1; i++)
			{
				spur += res[i][i];
			}
			return spur;
		}
	}
	return 0.0;
}
/*
Készítsen programot, ami dinamikusan allokált mátrixokat ad össze (addMatrix). Emlékeztetőül a szabály az összeadásra:

Az oszlopok és sorok száma mindkét mátrixnál megegyezik.
Elemenként adunk össze.
Amennyiben négyzetes a két mátrix, az eredményen számítsa ki a nyomvonalat (spurt), vagyis a főátló elemeinek összegét. Ha nem négyzetes, térjen vissza 0 eredménnyel!
*/
