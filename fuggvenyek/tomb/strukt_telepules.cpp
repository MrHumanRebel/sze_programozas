struct Telepules
{
    std::string name;
    unsigned int lelekszam;
    std::string orszag;
};

void rendez(Telepules* cities, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (cities[i].lelekszam > cities[j].lelekszam)
            {
                // A példa kedvéért: egyszerű insertion sort
                Telepules t = cities[i];
                cities[i] = cities[j];
                cities[j] = t;
            }            
        }
    }
}

void kiir(Telepules* cities, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << cities[i].name << ' ' << cities[i].lelekszam << ' ' << cities[i].orszag << '\n';
    }
}

void osszegzes(Telepules* cities, int n)
{
    double mean = 0.0;
    for (int i = 0; i < n; i++)
    {
        mean += cities[i].lelekszam;
    }
    mean /= n;
    std::cout << "Atlagos lelekszam: " << mean << '\n';
    std::cout << "Legnagyobb varos: " << cities[0].lelekszam << '\n';
    std::cout << "Legkisebb varos: " << cities[n-1].lelekszam << '\n';
}
