Készítsen egy függvényt, ami egy tetszőleges szövegben található angol alfanumerikus karakterek (csak kis- és nagybetűk és számok) ASCII kódjainak összegzett számértékét kiszámolja!

Nagy és kisbetű között ne tegyen különbséget, mindig kisbetűket adjon hozzá a végösszeghez!

Ha a fordítóprogram szintaktikai hibát jelez a forrásszöveg valamelyik sorában, akkor abból 10-et kivonva kapja meg a szerkesztőben olvasható sorszámot.

For example:

Test	Result
std::string s("Vizsgafeladat");
unsigned d0 = textSum(s);
std::cout << "Textsum: " << d0 << '\n';
Textsum: 1349


unsigned int textSum(std::string text) {
    return -1;
}