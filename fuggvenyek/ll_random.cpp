#define MAX_DB 15
#define MAX_AR 1000000
termek* general() {
  int db = rand()%(MAX_DB+1);
  termek* horgony = NULL;
  string nevek[] = {
    "Asztal", "Szek", "Kanape", "Kisagy", "Konyhapult", "Allolampa",
    "Fogas", "Komod", "Tukor", "Vaza", "Dohanyzoasztal", "Hintaszek"
  };
  int nevDb = sizeof(nevek)/sizeof(nevek[0]);
  for(int i=0; i<db; i++) {
    termek* uj = new termek;
    uj->nev = nevek[rand()%nevDb];
    uj->ar = rand()%(MAX_AR+1);
    uj->kov = horgony;
    horgony = uj;
  }
  return horgony;
}
