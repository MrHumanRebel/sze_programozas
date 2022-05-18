struct Lista
{
    double szam;
    Lista *kov;
};

// rendezve szúr be
Lista *listaRendezveBeszur(Lista *elso, double szam)
{
    Lista *iter, *uj, *ideSzur = NULL;
    uj = new Lista;
    uj->szam = szam;
    // az elejére szúrjuk, ha a lista üres, vagy ez a legjobb eredmény
    if (elso == NULL || elso->szam > szam)
    {
        uj->kov = elso;
        elso = uj;
    }
    // nem az elejére beszúrás
    else
    {
        for (iter = elso; iter != NULL && iter->szam <= szam; iter = iter->kov)
            ideSzur = iter;
        uj->kov = iter;
        ideSzur->kov = uj;
    }
    return elso;
}


// fájlból olvas listába
Lista *fajbolListaba(string fajlnev)
{
    Lista *ures = NULL;
    ifstream fajl(fajlnev.c_str());
    string adat;
    if (fajl.is_open())
    {
        while (getline(fajl, adat), !fajl.eof())
        {
            ures = listaRendezveBeszur(ures, atof(adat.c_str()) );
        }
    }
    return ures;
}
