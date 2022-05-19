#include <iostream>
#include <fstream>

#define FAJLNEV "nemek.txt"

using namespace std;

enum nem {ferfi, no};

///// Binaris fa kezeles /////

struct csucs {
  string nev;
  csucs* bal;
  csucs* jobb;
};

csucs* beszurBF(csucs* cs, string n) {
  if(cs == NULL) {
    cs = new csucs;
    cs->nev = n;
    cs->bal = cs->jobb = NULL;
  } else if(n < cs->nev) {
    cs->bal = beszurBF(cs->bal, n);
  } else {
    cs->jobb = beszurBF(cs->jobb, n);
  }
  return cs;
}

void felszabaditBF(csucs* cs) {
  if(cs != NULL) {
    felszabaditBF(cs->bal);
    felszabaditBF(cs->jobb);
    delete cs;
  }
}

bool keresBF(csucs* cs, string n) {
  if(cs == NULL) {
    return false;
  } else if(cs->nev == n) {
    return true;
  } else if(n < cs->nev) {
    return keresBF(cs->bal, n);
  } else {
    return keresBF(cs->jobb, n);
  }
}

void bejarBF(ofstream& o, csucs* cs) {
  if(cs != NULL) {
    bejarBF(o, cs->bal);
    o << cs->nev << endl;
    bejarBF(o, cs->jobb);
  }
}

void ment(string f, csucs *ffiNev, csucs *noiNev) {
  ofstream o(f);
  if(o.is_open()) {
    bejarBF(o, ffiNev);
    o << endl;
    bejarBF(o, noiNev);
    o.close();
  }  
}

void betolt(string f, csucs **ffiNev, csucs **noiNev) {
  ifstream i(f);
  if(i.is_open()) {
    string nev;
    nem szemely = ferfi;
    while(getline(i, nev), not i.eof()) {
      if(nev == "") {
        szemely = no;
      } else if(szemely == ferfi) {
        *ffiNev = beszurBF(*ffiNev, nev);
      } else {
        *noiNev = beszurBF(*noiNev, nev);
      }
    }
    i.close();
  }
}

///// Lancolt lista (sor) kezeles /////

struct lista {
  string nev;
  lista* kov;
};

void berak(lista*& eleje, lista*& vege, string n) {
  lista* uj = new lista;
  uj->nev = n;
  uj->kov = NULL;
  if(vege != NULL) {
    vege->kov = uj;
  } else {
    eleje = uj;
  }
  vege = uj;
}

bool kivesz(lista*& eleje, lista*& vege, string& n) {
  if(eleje == NULL) {
    return false;
  } else {
    n = eleje->nev;
    lista* kov = eleje->kov;
    delete eleje;
    eleje = kov;
    if(eleje == NULL) {
      vege = NULL;
    }
    return true;
  }
}

void urit(lista*& eleje, lista*& vege, string fejlec) {
  if(eleje) {
    cout << "\nPar nelkul maradt " << fejlec << ": ";
  }
  string nev;
  while(kivesz(eleje, vege, nev)) {
    cout << nev << ' ';
  }
}

///// Foprogram /////

int main() {
  cout << "Parokat adminisztralo program; kilepes ures sor megadasaval.\n";
  csucs *ferfiNevek=NULL, *noiNevek=NULL;
  lista *ffiEleje=NULL, *noEleje=NULL, *ffiVege=NULL, *noVege=NULL;
  string nev;
  betolt(FAJLNEV, &ferfiNevek, &noiNevek);
  while(cout<<"Nev: ", getline(cin, nev), nev.length()!=0) {
    nem szemely;
    if(keresBF(ferfiNevek, nev)) {
      szemely = ferfi;
    } else if(keresBF(noiNevek, nev)) {
      szemely = no;
    } else {
      string nem;
      cout << "Ez (f)erfi vagy (n)oi nev? ";
      getline(cin, nem);
      if(nem == "f") {
        ferfiNevek = beszurBF(ferfiNevek, nev);
        szemely = ferfi;
      } else {
        noiNevek = beszurBF(noiNevek, nev);
        szemely = no;
      }
    }
    if(szemely == ferfi) {
      string no;
      if(kivesz(noEleje, noVege, no)) {
        cout << "Uj par: " << nev << " - " << no << endl;
      } else {
        berak(ffiEleje, ffiVege, nev);
      }
    } else {
      string ffi;
      if(kivesz(ffiEleje, ffiVege, ffi)) {
        cout << "Uj par: " << ffi << " - " << nev << endl;
      } else {
        berak(noEleje, noVege, nev);
      }
    }
  }
  cout << "Ures sor, kilepes.";
  ment(FAJLNEV, ferfiNevek, noiNevek);
  felszabaditBF(ferfiNevek);
  felszabaditBF(noiNevek);
  urit(ffiEleje, ffiVege, "ferfiak");
  urit(noEleje, noVege, "nok");
  return 0;
}
