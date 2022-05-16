void akcio(termek* elem) {
  int maxAr = -1;
  termek* legdragabb = NULL;
  while(elem != NULL) {
    if(elem->ar > maxAr) {
      maxAr = elem->ar;
      legdragabb = elem;
    }
    elem = elem->kov;
  }
  if(legdragabb != NULL) {
    legdragabb->ar /= 2;
  }
}
