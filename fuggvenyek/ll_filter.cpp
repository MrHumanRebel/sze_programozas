termek* szures(const termek* horgony, int min, int max) {
  termek* szurtHorgony = NULL;
  termek* szurtUtolso = NULL;
  while(horgony != NULL) {
    if(horgony->ar>=min and horgony->ar<=max) {
      termek* uj = new termek;
      uj->nev = horgony->nev;
      uj->ar = horgony->ar;
      uj->kov = NULL;
      if(szurtHorgony == NULL) {
        szurtHorgony = uj;
      } else {
        szurtUtolso->kov = uj;
      }
      szurtUtolso = uj;
    }
    horgony = horgony->kov;
  }
  return szurtHorgony;
}
