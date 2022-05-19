unsigned int textSum(std::string text)
{
    unsigned int sum = 0;
    for (unsigned int i = 0; i < text.length(); i++)
    {
        if ((text[i] >= 'A' && text[i] <= 'Z') || 
            (text[i] >= 'a' && text[i] <= 'z') || 
            (text[i] >= '0' && text[i] <= '9'))
        {
            sum += text[i];
        }
    }
    return sum;
}
/*
Készítsen egy függvényt, ami egy tetszőleges szövegben található angol 
alfanumerikus karakterek (csak kis- és nagybetűk és számok)
ASCII kódjainak összegzett számértékét kiszámolja! 
Nagy és kisbetű között ne tegyen különbséget, mindig kisbetűket adjon hozzá a végösszeghez!
*/
