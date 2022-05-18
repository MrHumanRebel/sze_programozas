matrix* szorzas(const matrix& m, const double d) {
  matrix* mtx = new matrix;
  mtx->sorok = m.sorok;
  mtx->oszlopok = m.oszlopok;
  mtx->m = new double*[mtx->sorok];
  for(int s=0; s<mtx->sorok; s++) {
    mtx->m[s] = new double[mtx->oszlopok];
    for(int o=0; o<mtx->oszlopok; o++) {
      mtx->m[s][o] = m.m[s][o]*d;
    }
  }
  return mtx;
}
