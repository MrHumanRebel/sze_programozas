void fajbolOlvas(string fajlnev, int adatok[], int db)
{
    ifstream fajl(fajlnev);
    string sor;
    int i=0;
    if(fajl.is_open()){
        while(getline(fajl, sor) && i<db){
            adatok[i] = stoi(sor);
            i++;
        }
    }
    fajl.close();
}
