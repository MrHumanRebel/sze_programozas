termek* hozzafuz(termek* horgony, string nev, int ar) {
  termek* uj = new termek;
  uj->nev = nev;
  uj->ar = ar;
  uj->kov = NULL;
  if(horgony == NULL) {
    horgony = uj;
  } else {
    termek* akt = horgony;
    while(akt->kov != NULL) {
      akt = akt->kov;
    }
    akt->kov = uj;
  }
  return horgony;
}
